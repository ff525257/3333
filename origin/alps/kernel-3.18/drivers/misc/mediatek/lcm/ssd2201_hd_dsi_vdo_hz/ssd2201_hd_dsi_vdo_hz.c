#ifndef BUILD_LK
#include <linux/string.h>
#endif
#include "lcm_drv.h"
#ifdef BUILD_LK
    #include <platform/mt_gpio.h>
    #include <platform/mt_i2c.h> 
    #include <platform/mt_pmic.h>
#elif defined(BUILD_UBOOT)
    #include <asm/arch/mt_gpio.h>
#else
    //#include <mach/mt_gpio.h>
    //#include <mach/mt_pm_ldo.h>
    #include <mt-plat/upmu_common.h>
    //#include <linux/i2c.h>

#endif
#include "lcm_drv.h"
#include <mach/gpio_const.h>
#include <mt-plat/mt_gpio.h>

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH  (720)
#define FRAME_HEIGHT (1280)

#define REGFLAG_DELAY             							0XFFE
#define REGFLAG_END_OF_TABLE      							0xFFF   // END OF REGISTERS MARKER
//static unsigned int lcm_esd_test = 0;      ///only for ESD test
#define LCM_ID_SSD2201       					(0x0157)

// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))

#define LCM_ID_S6D7AA0X62	0x0802

//#define GPIO_LCD_ID_PIN GPIO_LCM_ID_PIN 
//static unsigned int lcm_compare_id(void);
//static int get_lcd_id(void);
// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)									lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)				lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)											lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   				lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)    

struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};

/*
static struct LCM_setting_table lcm_sleep_out_setting[] = {
    // Sleep Out
    {0x11, 1, {0x00}},
    {REGFLAG_DELAY, 120, {}},
    
    // Display ON
    {0x29, 1, {0x00}},
    {REGFLAG_END_OF_TABLE, 0x00, {}}
};
*/

static struct LCM_setting_table lcm_deep_sleep_mode_in_setting[] = {
    // Display off sequence
    {0x28, 1, {0x00}},
    {REGFLAG_DELAY, 10, {}},
    
    // Sleep Mode On
    {0x10, 1, {0x00}},
    {REGFLAG_DELAY, 120, {}},
    
    {REGFLAG_END_OF_TABLE, 0x00, {}}
};

static struct LCM_setting_table lcm_initialization_setting[] = {
	#if 1		
{0x11, 1,{0x00}},
{REGFLAG_DELAY, 10, {}},
{0x11, 1,{0x00}},
{REGFLAG_DELAY, 10, {}},
{0x11, 1,{0x00}},
{REGFLAG_DELAY, 10, {}},
{0xB0,3,{0x00,0x32,0x05}},                                                                                                                      
{0xB0,5,{0x0A,0x00,0x17,0x00,0x2f}},                                                                                                              
{0xB0,3,{0x1E,0xB0,0x00}},                                                                                                                                                                                                                                                   
{0xB3,2,{0x00,0xBA}},                                                                                                                                      
{0xB3,6,{0x02,0xDC,0x00,0xC4,0x04,0x0E}},                                                       
{0xB3,2,{0x0F,0x8F}},                                                                                                  
{0xB4,2,{0x02,0x18}},                                                                                                                 
{0xB8,3,{0x00,0x40,0x70}},                                                                                                                                 
{0xB8,2,{0x12,0xD0}},                                                                                                                 
{0xB8,4,{0x17,0x51,0x15,0x20}},                                                                                                                            
{0xB8,4,{0x25,0x66,0xA0,0x06}},                                                                                                                            
{0xB9,2,{0x0B,0x0A}},                                                                                                                                      
{0xB9,3,{0x13,0x90,0x90}},                                                                               
{0xBA,4,{0x02,0x0A,0x00,0x0B}},                                                                                                                   
{0xBB,14,{0x01,0xFC,0xFF,0xFF,0xF8,0x2F,0xF0,0x3F,0xF1,0x4F,0xFF,0xFF,0xBE,0x66}},                                                                         
{0xBB,14,{0x0F,0xFC,0xFF,0xFF,0xF8,0x2F,0xF0,0x3F,0xF1,0x4F,0xFF,0xFF,0xBE,0x66}},                                                                         
{0xBC,10,{0x0C,0x17,0x06,0x1A,0x17,0x06,0x02,0x0b,0x02,0x04}},                                                                         
{0xBC,7,{0x26,0x44,0x44,0x33,0x60,0x33,0x40}},                                                                                                             
{0xBC,7,{0x32,0x44,0x44,0x33,0x60,0x33,0x40}},                                                               
{0xBD,2,{0x04,0x10}},                                                                                                                       
{0xBD,3,{0x09,0x51,0x10}},                                                                                                                 
{0xBD,2,{0x18,0x00}},                                                                                                                       
{0xBD,3,{0x1D,0x51,0x00}},                                                                                                                 
{0xBD,7,{0x28,0x0A,0x10,0xA1,0x0A,0x20,0xA2}},                                                                                    
{0xBD,7,{0x31,0x0A,0x10,0xA1,0x0A,0x20,0xA2}},                                                                                   
{0xC0,2,{0x01,0xCC}},                                                                                                    
{0xC0,4,{0x05,0x17,0x5F,0x20}},                                                                                                                            
{0xC1,2,{0x08,0xFF}},                                                                                                                                      
{0xC1,3,{0x0D,0x68,0x68}},              
//{0xC3,22,{0x00,0x00,0x12,0x20,0x29,0x37,0x41,0x4F,0x59,0x6A,0x76,0x82,0x8D,0x98,0xA3,0xAB,0xB5,0xC0,0x4D,0x57,0x65,0x7F}},
//{0xC3,22,{0x15,0x00,0x12,0x20,0x29,0x37,0x41,0x4F,0x59,0x6A,0x76,0x82,0x8D,0x98,0xA3,0xAB,0xB5,0xC0,0x4D,0x57,0x65,0x7F}},  
{0xC3,22,{0x00,0x0f,0x23,0x30,0x38,0x45,0x4F,0x59,0x63,0x72,0x7e,0x8a,0x94,0x9c,0xA7,0xaf,0xb8,0xc2,0x4e,0x57,0x60,0x6c}},
{0xC3,22,{0x15,0x00,0x16,0x21,0x29,0x36,0x3d,0x4c,0x56,0x66,0x73,0x7f,0x8b,0x94,0xA2,0xA9,0xB3,0xbd,0x4a,0x54,0x5d,0x69}},                                                                                                
{0xE1,2,{0x00,0x01}},                                                                                                                       
{0xE1,3,{0x0E,0x01,0x1F}},                                                                           
{0xE1,3,{0x12,0x80,0xFF}},    

//Modified on 20171215
{0xB1,2,{0x01,0x28}}, 
{0xB1,2,{0x03,0x1C}},
{0xB1,2,{0x02,0x1D}},
{0xB1,2,{0x05,0x54}},
{0xC2,2,{0x00,0xA0}},
{0xB3,2,{0x04,0xE6}},
//Modified on 20171215

//Modified on 20180507
{0xE1,2,{0x11,0x01}},
{0xB2,2,{0x00,0x1B}},
{0xB3,2,{0x04,0xE4}},
{0xC1,2,{0x03,0x05}},
{0xE1,3,{0x0A,0x80,0x00}},

{0xB4,2,{0x02,0x03}},
{0xB4,2,{0x13,0x00}},
{0xB4,2,{0x14,0x02}},
{0xB4,2,{0x15,0x01}},
{0xB4,2,{0x16,0x00}},
{0xB4,2,{0x17,0x02}},
{0xB4,2,{0x18,0x01}},
{0xB4,2,{0x19,0x00}},
{0xB4,2,{0x1A,0x02}},
{0xB4,2,{0x1B,0x01}},
{0xB0,2,{0x20,0x00}},
{0xC1,2,{0x02,0xAA}}, 
//Modified on 20180507

//Modified on 20171107
  {0xEC,2,{0x02,0x9F}},
  {0xEC,2,{0x06,0x68}}, //For TE detection,if TE connected to GPIO8
//Modified on 20171107

//Modified on 20171229
{0xE2,2,{0x19,0x01}}, 
{0xB0,2,{0x1F,0x83}},
{0xE2,2,{0x1A,0x06}},
{0xE2,3,{0x1E,0x01,0xC0}},
{0xB0,3,{0x04,0x01,0xC0}},

{0xEC,2,{0x00,0xAA}},
{0xEC,2,{0x09,0xA5}}, //If PMIC PSYNC connected to GPIO5
//Modified on 20171229

{0xC0,2,{0x03,0x0F}},   //Internal discharge resistor

//Modified on 20180118
{0xB0,2,{0x1C,0x18}},
{0xB0,2,{0x1D,0x16}},
{0xB3,2,{0x0F,0x9F}},
//Modified on 20180118


{0x11, 1,{0x00}},
{REGFLAG_DELAY, 50, {}},
{0x29, 1,{0x00}},
{REGFLAG_DELAY, 20, {}},
{REGFLAG_END_OF_TABLE, 0x00, {}}

#endif   
};

/*
static void dsi_send_cmdq_tinno(unsigned char cmd, unsigned char count, unsigned char *para_list, unsigned char force_update)
{
	unsigned int item[16];
	unsigned char dsi_cmd = (unsigned char)cmd;
	unsigned char dc;
	int index = 0, length = 0;
	
	memset(item,0,sizeof(item));
	if(count+1 > 60)
	{
		 
		return;
	}
//
	Data ID will depends on the following rule.
	
		count of parameters > 1	=> Data ID = 0x39
		count of parameters = 1	=> Data ID = 0x15
		count of parameters = 0	=> Data ID = 0x05
//
	if(count == 0)
	{
		item[0] = 0x0500 | (dsi_cmd<<16);
		length = 1;
	}
	else if(count == 1)
	{
		item[0] = 0x1500 | (dsi_cmd<<16) | (para_list[0]<<24);
		length = 1;
	}
	else
	{
		item[0] = 0x3902 | ((count+1)<<16);//Count include command.
		++length;
		while(1)
		{
			if (index == count+1)
				break;
			if ( 0 == index ){
				dc = cmd;
			}else{
				dc = para_list[index-1];
			}
			// an item make up of 4data. 
			item[index/4+1] |= (dc<<(8*(index%4)));  
			if ( index%4 == 0 ) ++length;
			++index;
		}
	}
	
	dsi_set_cmdq(&item, length, force_update);
	MDELAY(10);
}*/
static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
    unsigned int i;
    
    for(i = 0; i < count; i++) {
        unsigned cmd;
        cmd = table[i].cmd;
        
        switch (cmd) {
            case REGFLAG_DELAY :
                MDELAY(table[i].count);
                break;
            
            case REGFLAG_END_OF_TABLE :
                break;
            
            default:
                dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);	
//                dsi_send_cmdq_tinno(cmd, table[i].count, table[i].para_list, force_update);				
            /*
                if (cmd != 0xFF && cmd != 0x2C && cmd != 0x3C) {
                    //#if defined(BUILD_UBOOT)
                    //	printf("[DISP] - uboot - REG_R(0x%x) = 0x%x. \n", cmd, table[i].para_list[0]);
                    //#endif
                    while(read_reg(cmd) != table[i].para_list[0]);		
                }
				*/
        }
    }
}


// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------
static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
    memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}

static void lcm_get_params(LCM_PARAMS *params)
{
    memset(params, 0, sizeof(LCM_PARAMS));
    
    params->type   = LCM_TYPE_DSI;
    
    params->width  = FRAME_WIDTH;
    params->height = FRAME_HEIGHT;
    
    // enable tearing-free
		params->dbi.te_mode = LCM_DBI_TE_MODE_DISABLED;
		params->dbi.te_edge_polarity = LCM_POLARITY_RISING;

		params->dsi.mode   = SYNC_EVENT_VDO_MODE;
    
    // DSI
    /* Command mode setting */
		params->dsi.LANE_NUM				= LCM_FOUR_LANE;

    //The following defined the fomat for data coming from LCD engine.
    params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
    params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
    params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
    params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;
    
		// Highly depends on LCD driver capability.
		// Not support in MT6573
		params->dsi.packet_size=256;

		// Video mode setting		
		params->dsi.intermediat_buffer_num = 2;
		params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
    
  
		params->dsi.vertical_sync_active				= 2;
		params->dsi.vertical_backporch					= 10;
		params->dsi.vertical_frontporch	= 14;
		params->dsi.vertical_active_line				= FRAME_HEIGHT; 

		params->dsi.horizontal_sync_active				= 2;
		params->dsi.horizontal_backporch				= 10;
		params->dsi.horizontal_frontporch				= 45;
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;

		// Bit rate calculation
		//params->dsi.pll_div1=37;		// fref=26MHz, fvco=fref*(div1+1)	(div1=0~63, fvco=500MHZ~1GHz)
		//params->dsi.pll_div2=1; 		// div2=0~15: fout=fvo/(2*div2)
	params->dsi.PLL_CLOCK = 260;	/* this value must be in MTK suggested table */
}


static void lcd_power_en(unsigned char enabled)
{
    if (enabled)
    {
	#ifdef BUILD_LK
	#else	
		pmic_config_interface(MT6328_PMIC_RG_VGP1_VOSEL_ADDR, 0x6, MT6328_PMIC_RG_VGP1_VOSEL_MASK, MT6328_PMIC_RG_VGP1_VOSEL_SHIFT);
		pmic_config_interface(MT6328_PMIC_RG_VGP1_EN_ADDR, 0x1, MT6328_PMIC_RG_VGP1_EN_MASK, MT6328_PMIC_RG_VGP1_EN_SHIFT);
		MDELAY(50);
	#endif
    }
    else
    {
	#ifdef BUILD_LK
	#else
		pmic_config_interface(MT6328_PMIC_RG_VGP1_VOSEL_ADDR, 0, MT6328_PMIC_RG_VGP1_VOSEL_MASK, MT6328_PMIC_RG_VGP1_VOSEL_SHIFT);
	  	pmic_config_interface(MT6328_PMIC_RG_VGP1_EN_ADDR, 0, MT6328_PMIC_RG_VGP1_EN_MASK, MT6328_PMIC_RG_VGP1_EN_SHIFT);
		MDELAY(50);
	#endif
    }
}

extern void lcm_gpio_output(int pin, int level);
static void lcm_init(void)
{
/*
		pmic_set_register_value(PMIC_RG_VGP1_VOSEL,5);
		pmic_set_register_value(PMIC_RG_VGP1_EN,1);
MDELAY(50);		
		pmic_set_register_value(PMIC_RG_VGP3_VOSEL,3);
		pmic_set_register_value(PMIC_RG_VGP3_EN,1);
MDELAY(50);
  */
	//SET_RESET_PIN(1);
	//MDELAY(100);
	lcd_power_en(1);
	MDELAY(100);
    lcm_gpio_output(0,0);
	MDELAY(100);
    lcm_gpio_output(0,1);
	MDELAY(100);
		push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}


static void lcm_suspend(void)
{
    unsigned int data_array[16];
    data_array[0] = 0x00280500;
    dsi_set_cmdq(data_array, 1, 1);
    MDELAY(5);
    data_array[0] = 0x00100500;
    dsi_set_cmdq(data_array, 1, 1);
    MDELAY(5);
	push_table(lcm_deep_sleep_mode_in_setting, sizeof(lcm_deep_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
	lcd_power_en(0);
	MDELAY(300);
	lcm_gpio_output(0,0);
	MDELAY(100);
}


static void lcm_resume(void)
{  
    lcm_init();
}

static struct LCM_setting_table lcm_sleep_out_0x11_setting[] = {

    {0x11,0,{0x00}},
    {REGFLAG_DELAY, 10, {0}},
	{0x11,0,{0x00}},
    {REGFLAG_DELAY, 10, {0}},
	{0x11,0,{0x00}},
    {REGFLAG_DELAY, 10, {0}},
	
	{0xB1,2,{0x01,0x28}}, 
    {0xB1,2,{0x03,0x1C}},
    {0xB1,2,{0x02,0x1D}},
    {0xB1,2,{0x05,0x54}},
    {0xC2,2,{0x00,0xA0}},
    {0xB3,2,{0x04,0xE6}},
    
    {0xB0,2,{0x1C,0x18}},
    {0xB0,2,{0x1D,0x16}},
    {0xB3,2,{0x0F,0x9F}},

};

static unsigned int read_lcm_compare_id(void)
{

	unsigned int id=0;
    int array[4]={0};
    char buffer[3]={0};

	push_table(lcm_sleep_out_0x11_setting, sizeof(lcm_sleep_out_0x11_setting) / sizeof(struct LCM_setting_table), 1); 
	

    
	array[0] = 0x00053902;
	array[1] = 0xFFB800F2;
	array[2] = 0x000000FF;
	dsi_set_cmdq(array, 3, 1);

	array[0] = 0x00023700;
	dsi_set_cmdq(array, 1, 1);
	MDELAY(5);

    read_reg_v2(0xa1,buffer,2);
    read_reg_v2(0xa1,buffer,2); //read 2nd 

	id = (buffer[0]<<8)|buffer[1];

	#ifdef BUILD_LK
		printf(" ssd2201---id=0x%x\n",id);
		#else
		printk("kernel ssd2201---id=0x%x\n",id);
	#endif	

	return id;
}


static unsigned int lcm_compare_id(void)
{
	unsigned short i;
	unsigned int id=0;

    SET_RESET_PIN(1);
    MDELAY(20);
    SET_RESET_PIN(0);
    MDELAY(100);
    SET_RESET_PIN(1);
    MDELAY(600);

	for(i=0;i<4;i++){

		id = read_lcm_compare_id();

		if(id != 0)
			break;
	}

	#ifdef BUILD_LK
	printf(" LK ssd2201 id = 0x%08x\n", id);
	#else
		printk("kernel ssd2201---id=0x%x\n",id);
	#endif

  return (id == LCM_ID_SSD2201)?1:0;
    
}

// ---------------------------------------------------------------------------
//  Get LCM Driver Hooks
// ---------------------------------------------------------------------------
LCM_DRIVER ssd2201_hd_dsi_vdo_hz_lcm_drv = 
{
	.name = "ssd2201_hd_dsi_vdo_hz",
    .set_util_funcs = lcm_set_util_funcs,
    .get_params     = lcm_get_params,
    .init           = lcm_init,
    .suspend        = lcm_suspend,
    .resume         = lcm_resume,
    .compare_id    = lcm_compare_id,
};

