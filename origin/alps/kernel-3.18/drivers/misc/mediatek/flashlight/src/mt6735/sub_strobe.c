
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/wait.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/time.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include "kd_camera_typedef.h"
#include <linux/hrtimer.h>
#include <linux/ktime.h>
#include <linux/version.h>
#ifdef CONFIG_COMPAT
#include <linux/fs.h>
#include <linux/compat.h>
#endif
#include "kd_flashlight.h"

#include <mach/gpio_const.h>
#include <mt-plat/mt_gpio.h>
/******************************************************************************
 * Debug configuration
******************************************************************************/
/* availible parameter */
/* ANDROID_LOG_ASSERT */
/* ANDROID_LOG_ERROR */
/* ANDROID_LOG_WARNING */
/* ANDROID_LOG_INFO */
/* ANDROID_LOG_DEBUG */
/* ANDROID_LOG_VERBOSE */
#define TAG_NAME "[sub_strobe.c]"
#define PK_DBG_NONE(fmt, arg...)    do {} while (0)
#define PK_DBG_FUNC(fmt, arg...)    pr_debug(TAG_NAME "%s: " fmt, __func__ , ##arg)

/*#define DEBUG_LEDS_STROBE*/
#ifdef DEBUG_LEDS_STROBE
#define PK_DBG PK_DBG_FUNC
#else
#define PK_DBG(a, ...)
#endif


static DEFINE_SPINLOCK(g_substrobeSMPLock); /* cotta-- SMP proection */


static u32 substrobe_Res;
static u32 substrobe_Timeus;
static BOOL g_substrobe_On;

static int g_subduty = -1;
static int g_subtimeOutTimeMs;

static DEFINE_MUTEX(g_substrobeSem);

static struct work_struct subworkTimeOut;
int custom_setsubstrobe(int level);
/*****************************************************************************
Functions
*****************************************************************************/
#define GPIO_FLASH_EN  	(GPIO19 | 0x80000000)	//flash
#define GPIO_TORCH_EN  	(GPIO14 | 0x80000000)	//torch

static void subwork_timeOutFunc(struct work_struct *data);

extern void flashlight_subflash_en_gpio_output( int level);
extern void blue_led_en_gpio_output( int level);

static int SUBFL_Enable(void)
{
	PK_DBG(" SUBFL_Enable g_subduty = %d\n", g_subduty);
#if defined(LYCONFIG_AUTO_PLATFORM_NAME_F5B) || defined(LYCONFIG_AUTO_PLATFORM_NAME_F5C) || defined(LYCONFIG_AUTO_PLATFORM_NAME_F900) || defined(LYCONFIG_AUTO_PLATFORM_NAME_F5BS) || defined(LYCONFIG_AUTO_PLATFORM_NAME_F5CS) || defined(LYCONFIG_AUTO_PLATFORM_NAME_F900S)
	blue_led_en_gpio_output(1);
#else
	flashlight_subflash_en_gpio_output(1);
#endif
	return 0;
}

static int SUBFL_Disable(void)
{
	printk(" SUBFL_Disable\n");
#if defined(LYCONFIG_AUTO_PLATFORM_NAME_F5B) || defined(LYCONFIG_AUTO_PLATFORM_NAME_F5C)|| defined(LYCONFIG_AUTO_PLATFORM_NAME_F900) || defined(LYCONFIG_AUTO_PLATFORM_NAME_F5BS) || defined(LYCONFIG_AUTO_PLATFORM_NAME_F5CS)|| defined(LYCONFIG_AUTO_PLATFORM_NAME_F900S)
	blue_led_en_gpio_output(0);
#else
	flashlight_subflash_en_gpio_output(0);
#endif
	//custom_setsubstrobe(0);
	return 0;
}

static int SUBFL_dim_duty(kal_uint32 duty)
{
	g_subduty=duty;
	printk("FL_dim_duty g_subduty = %d\n",g_subduty);
	return 0;
}


static int SUBFL_Init(void)
{
    printk("SUBFL_Init\n");
	//if(mt_set_gpio_mode(GPIO_FLASH_EN,GPIO_MODE_00)){printk("[constant_flashlight] set gpio mode failed!! \n");}
	// if(mt_set_gpio_dir(GPIO_FLASH_EN,GPIO_DIR_OUT)){printk("[constant_flashlight] set gpio dir failed!! \n");}
	// if(mt_set_gpio_out(GPIO_FLASH_EN,GPIO_OUT_ZERO)){printk("[constant_flashlight] set gpio failed!! \n");}

	/*Init. to disable*/
	// if(mt_set_gpio_mode(GPIO_TORCH_EN,GPIO_MODE_00)){printk("[constant_flashlight] set gpio mode failed!! \n");}
	// if(mt_set_gpio_dir(GPIO_TORCH_EN,GPIO_DIR_OUT)){printk("[constant_flashlight] set gpio dir failed!! \n");}
	// if(mt_set_gpio_out(GPIO_TORCH_EN,GPIO_OUT_ZERO)){printk("[constant_flashlight] set gpio failed!! \n");}
	SUBFL_Disable();

	INIT_WORK(&subworkTimeOut, subwork_timeOutFunc);
	return 0;
}


static int SUBFL_Uninit(void)
{
	SUBFL_Disable();
    return 0;
}

/*****************************************************************************
User interface
*****************************************************************************/

static void subwork_timeOutFunc(struct work_struct *data)
{
    SUBFL_Disable();
}


static enum hrtimer_restart subledTimeOutCallback(struct hrtimer *timer)
{
    schedule_work(&subworkTimeOut);
    return HRTIMER_NORESTART;
}
static struct hrtimer g_subtimeOutTimer;
static void subtimerInit(void)
{
	g_subtimeOutTimeMs = 1000;
	hrtimer_init(&g_subtimeOutTimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	g_subtimeOutTimer.function = subledTimeOutCallback;
}

static int sub_strobe_ioctl(unsigned int cmd, unsigned long arg)
{
	int i4RetValue = 0;
	int ior_shift;
	int iow_shift;
	int iowr_shift;
	ior_shift = cmd - (_IOR(FLASHLIGHT_MAGIC,0, int));
	iow_shift = cmd - (_IOW(FLASHLIGHT_MAGIC,0, int));
	iowr_shift = cmd - (_IOWR(FLASHLIGHT_MAGIC,0, int));
	//printk("constant_flashlight_ioctl() line=%d ior_shift=%d, iow_shift=%d iowr_shift=%d arg=%d\n",__LINE__, ior_shift, iow_shift, iowr_shift, arg);
    switch(cmd)
    {

		case FLASH_IOC_SET_TIME_OUT_TIME_MS:
			//printk("FLASH_IOC_SET_TIME_OUT_TIME_MS: %d\n",arg);
			g_subtimeOutTimeMs=arg;
		break;


    	case FLASH_IOC_SET_DUTY :
    		//printk("FLASHLIGHT_DUTY: %d\n",arg);
    		SUBFL_dim_duty(arg);
    		break;


    	case FLASH_IOC_SET_STEP:
    		//printk("FLASH_IOC_SET_STEP: %d\n",arg);

    		break;

    	case FLASH_IOC_SET_ONOFF :
    		//printk("FLASHLIGHT_ONOFF: %d\n",arg);
    		if(arg==1)
    		{
				if(g_subtimeOutTimeMs!=0)
	            {
	            	ktime_t ktime;
					ktime = ktime_set( 0, g_subtimeOutTimeMs*1000000 );
					hrtimer_start( &g_subtimeOutTimer, ktime, HRTIMER_MODE_REL );
	            }
    			SUBFL_Enable();
    		}
    		else
    		{
    			SUBFL_Disable();
				hrtimer_cancel( &g_subtimeOutTimer );
    		}
    		break;
		default :
    		printk(" No such command \n");
    		i4RetValue = -EPERM;
    		break;
    }
    return i4RetValue;
}

static int sub_strobe_open(void *pArg)
{
	int i4RetValue = 0;
	printk("sub flashlight open");
	if (0 == substrobe_Res)
	{
	    SUBFL_Init();
		subtimerInit();
	}
	spin_lock_irq(&g_substrobeSMPLock);


    if(substrobe_Res)
    {

        i4RetValue = -EBUSY;
    }
    else
    {
        substrobe_Res += 1;
    }


    spin_unlock_irq(&g_substrobeSMPLock);

    return i4RetValue;
}

static int sub_strobe_release(void *pArg)
{
	printk("sub flashlight release");

    if (substrobe_Res)
    {
        spin_lock_irq(&g_substrobeSMPLock);

        substrobe_Res = 0;
        substrobe_Timeus = 0;

        /* LED On Status */
        g_substrobe_On = FALSE;

        spin_unlock_irq(&g_substrobeSMPLock);

    	SUBFL_Uninit();
    }

	return 0;

}

FLASHLIGHT_FUNCTION_STRUCT subStrobeFunc = {
	sub_strobe_open,
	sub_strobe_release,
	sub_strobe_ioctl
};


MUINT32 subStrobeInit(PFLASHLIGHT_FUNCTION_STRUCT *pfFunc)
{
	if (pfFunc != NULL)
		*pfFunc = &subStrobeFunc;
	return 0;
}
