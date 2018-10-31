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
//	#include <mach/mt_gpio.h>
//	#include <mach/mt_pm_ldo.h>
	#include <mt-plat/upmu_common.h>
//    #include <linux/i2c.h>

#endif
// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH  										(720)
#define FRAME_HEIGHT 										(1280)

#define REGFLAG_DELAY             							0xFE
#define REGFLAG_END_OF_TABLE      							0xFFF   // END OF REGISTERS MARKER

#define LCM_DSI_CMD_MODE									0
#define LCM_ID_ST7703                                      0x3821

// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

extern int lcm_ata_check_flag;

//#define GPIO_LCD_RST_EN      (GPIO70 | 0x80000000)
#define SET_RESET_PIN(v)    								(lcm_util.set_reset_pin((v)))

#define UDELAY(n) 											(lcm_util.udelay(n))
#define MDELAY(n) 											(lcm_util.mdelay(n))

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

static struct LCM_setting_table lcm_initialization_setting[] = {
#if 0
{0xB9,3,{0xF1,0x12,0x83}},

{0xBA,27,{0x32,0x81,0x05,0xF9,0x0E,0x0E,0x00,0x00,0x00,0x00,
          0x00,0x00,0x00,0x00,0x44,0x25,0x00,0x91,0x0A,0x00,
          0x00,0x02,0x4F,0x01,0x00,0x00,0x37}},

{0xB8,1,{0x26}},

{0xBF,3,{0x02,0x11,0x00}},

{0xB3,10,{0x0C,0x10,0x0A,0x50,0x03,0xFF,0x00,0x00,0x00,0x00}},

{0xC0,9,{0x73,0x73,0x50,0x50,0x00,0x00,0x08,0x70,0x00}},

{0xBC,1,{0x46}},

{0xCC,1,{0x0B}},//0x07

{0xB4,1,{0x80}},

{0xB2,3,{0xC8,0x12,0x30}},

{0xE3,14,{0x07,0x07,0x0b,0x0b,0x03,0x0b,0x00,0x00,0x00,0x00,0xFF,0x00,0xC0,0x10}},//12st 80-->00

{0xC1,12,{0x53,0x00,0x1E,0x1E,0x77,0xE1,0xCC,0xDD,0x67,0x77,0x33,0x33}},

{0xC6,6,{0x00,0x00,0xFF,0xFF,0x01,0xFF}},

{0xB5,2,{0x09,0x09}},

{0xB6,2,{0x85,0x90}},//86,hjp


{0xE9,63,{0xC2,0x10,0x05,0x05,0x01,0x05,0xA0,0x12,0x31,0x23,
	  0x3F,0x81,0x0A,0xA0,0x37,0x18,0x00,0x80,0x01,0x00,
          0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x48,0xF8,
          0x86,0x42,0x08,0x88,0x88,0x80,0x88,0x88,0x88,0x58,
          0xF8,0x87,0x53,0x18,0x88,0x88,0x81,0x88,0x88,0x88,
          0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

{0xEA,61,{0x00,0x1A,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
	  0x00,0x00,0x1F,0x88,0x81,0x35,0x78,0x88,0x88,0x85,
	  0x88,0x88,0x88,0x0F,0x88,0x80,0x24,0x68,0x88,0x88,
	  0x84,0x88,0x88,0x88,0x23,0x10,0x00,0x00,0x1C,0x00,
	  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	  0x00,0x00,0x00,0x00,0x30,0x05,0xA0,0x00,0x00,0x00,0x00}},

		  
{0xE0,34,{0x00,0x06,0x08,0x2A,0x31,0x3F,0x38,0x36,0x07,0x0C,
          0x0D,0x11,0x13,0x12,0x13,0x11,0x18,0x00,0x06,0x08,
	  0x2A,0x31,0x3F,0x38,0x36,0x07,0x0C,0x0D,0x11,0x13,0x12,0x13,0x11,0x18}},//GAMMA2.2	


{0x11,1,{0x00}},

{REGFLAG_DELAY,250,{}},

{0x29,1,{0x00}},

{REGFLAG_DELAY,50,{}},
{REGFLAG_END_OF_TABLE, 0x00, {}}
#endif 

{0xB9,3,{0xF1,0x12,0x83}},

{0xBA,27,{0x32,0x81,0x05,0xF9,0x0E,0x0E,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x25,0x00,0x91,0x0A,0x00,0x00,0x02,0x4F,0xD1,0x00,0x00,0x37}},//BAH 7th = 0x20 (improve coverage with weak FPC)

{0xB8,4,{0x25,0x22,0x20,0x03}},

{0xBF,3,{0x02,0x10,0x00}},

{0xB3,10,{0x0C,0x10,0x0A,0x50,0x03,0xFF,0x00,0x00,0x00,0x00}},

{0xC0,9,{0x73,0x73,0x50,0x50,0x00,0x00,0x08,0x70,0x00}},

{0xBC,1,{0x4F}},

{0xCC,1,{0x0B}},

{0xB4,1,{0x80}},

{0xB2,2,{0xC8,0x12}},

{0xE3,14,{0x07,0x07,0x0B,0x0B,0x03,0x03,0x03,0x03,0x00,0x00,0xFF,0x00,0xC0,0x10}},

{0xC1,12,{0x65,0x00,0x1E,0x1E,0x77,0xF1,0xFF,0xFF,0xCC,0xCC,0x77,0x77}},

{0xB5,2,{0x09,0x09}},

{0xB6,2,{0x7C,0x7C}},

{0xE9,63,{0xC2,0x10,0x06,0x05,0x01,0x05,0xA0,0x12,0x31,0x23,0x3F,0x82,0x05,0xA0,0x37,0x0A,0x20,0x00,0x01,0x00,0x00,0x00,0x20,0x00,0x01,0x00,0x00,0x00,0x00,0x24,0x68,0x88,0x88,0x88,0x88,0x88,0x88,0x8F,0x84,0x11,0x35,0x78,0x88,0x88,0x88,0x88,0x88,0x88,0x8F,0x85,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

{0xEA,61,{0x00,0x1A,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x57,0x53,0x18,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xF1,0x46,0x42,0x08,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xF0,0x23,0x10,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x02,0xA0,0x00,0x00,0x00,0x00}},

{0xE0,34,{0x00,0x04,0x08,0x2A,0x30,0x38,0x39,0x39,0x06,0x0B,0x0D,0x11,0x13,0x12,0x13,0x12,0x19,0x00,0x04,0x08,0x2A,0x30,0x38,0x39,0x39,0x06,0x0B,0x0D,0x11,0x13,0x12,0x13,0x12,0x19}},

{0x11,1,{0x00}},

{REGFLAG_DELAY,250,{}},

{0x29,1,{0x00}},

{REGFLAG_DELAY,50,{}},
{REGFLAG_END_OF_TABLE, 0x00, {}}


};

#if 0
static struct LCM_setting_table lcm_sleep_out_setting[] = {
	// Sleep Out 
	{0x11, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},
	// Display ON
	{0x29, 1, {0x00}},
	{REGFLAG_DELAY, 100, {}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};
#endif

static struct LCM_setting_table lcm_deep_sleep_mode_in_setting[] = {
	{0x28, 0, {0x00}},
 	{REGFLAG_DELAY, 100, {}},
    // Sleep Mode On
	{0x10, 0, {0x00}},
 	{REGFLAG_DELAY, 100, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};

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
				//MDELAY(10);//soso add or it will fail to send register
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
    
    //add by kevin for actual size of w & h 20160411 start
    params->physical_width  = 110;
    params->physical_height = 62;
    //add by kevin for actual size of w & h 20160411 end    
    
    params->dsi.mode   = SYNC_PULSE_VDO_MODE;
    
    // DSI
    /* Command mode setting */
    params->dsi.LANE_NUM				= LCM_THREE_LANE;//LCM_THREE_LANE; 
    
    //The following defined the fomat for data coming from LCD engine.
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;
       
    	params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;

	/* Video mode setting */
	params->dsi.intermediat_buffer_num = 2;

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;
	params->dsi.packet_size = 256;


	params->dsi.vertical_sync_active = 3;
	params->dsi.vertical_backporch =10;
	params->dsi.vertical_frontporch = 16;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 4;//20
	params->dsi.horizontal_backporch = 45;//80
	params->dsi.horizontal_frontporch = 45;//80
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	/* Bit rate calculation */
	params->dsi.HS_TRAIL=15;
	params->dsi.PLL_CLOCK = 246;//212

	
#if 0
	params->dsi.cont_clock=1;   
	params->dsi.esd_check_enable = 1;
	params->dsi.customization_esd_check_enable = 1;
	
	params->dsi.lcm_esd_check_table[0].cmd = 0xb0;
	params->dsi.lcm_esd_check_table[0].count = 4;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0xa1;
	params->dsi.lcm_esd_check_table[0].para_list[1] = 0x03;	
	params->dsi.lcm_esd_check_table[0].para_list[2] = 0xb5;	
	params->dsi.lcm_esd_check_table[0].para_list[3] = 0x3a;

	params->dsi.lcm_esd_check_table[1].cmd = 0xC1;
	params->dsi.lcm_esd_check_table[1].count = 10;
	params->dsi.lcm_esd_check_table[1].para_list[0] = 0x53;
	params->dsi.lcm_esd_check_table[1].para_list[1] = 0x00;	
	params->dsi.lcm_esd_check_table[1].para_list[2] = 0x1E;	
	params->dsi.lcm_esd_check_table[1].para_list[3] = 0x1E;	
	params->dsi.lcm_esd_check_table[1].para_list[4] = 0x77;
	params->dsi.lcm_esd_check_table[1].para_list[5] = 0xE1;	
	params->dsi.lcm_esd_check_table[1].para_list[6] = 0xCC;	
	params->dsi.lcm_esd_check_table[1].para_list[7] = 0xDD;	
	params->dsi.lcm_esd_check_table[1].para_list[8] = 0x67;	
	params->dsi.lcm_esd_check_table[1].para_list[9] = 0x77;		
	
	params->dsi.lcm_esd_check_table[2].cmd = 0x09;
	params->dsi.lcm_esd_check_table[2].count = 1;
	params->dsi.lcm_esd_check_table[2].para_list[0] = 0x80;
	
	params->dsi.lcm_esd_check_table[3].cmd = 0xAF;
	params->dsi.lcm_esd_check_table[3].count = 1;
	params->dsi.lcm_esd_check_table[3].para_list[0] = 0xFD;
#endif
}

static void lcm_init(void)
{
	lcd_power_en(1);
	MDELAY(50);
	SET_RESET_PIN(1);
	MDELAY(25);
	SET_RESET_PIN(0);
	MDELAY(25);

	SET_RESET_PIN(1);
	MDELAY(120);

	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_suspend(void)
{
	push_table(lcm_deep_sleep_mode_in_setting, sizeof(lcm_deep_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
	//SET_RESET_PIN(0);
	MDELAY(20);
	lcd_power_en(0);
}

static void lcm_resume(void)
{
	//push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
	lcm_init();
}

static unsigned int lcm_compare_id(void)
{

	int data_array[4];
	char buffer[5];
	unsigned int id=0,id1=0,id2=0;
	
	//Do reset here
	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(25);

	SET_RESET_PIN(1);
	MDELAY(150);      

	data_array[0]=0x00033700; 
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(10);

	read_reg_v2(0x04, buffer, 3);
	id1= buffer[0]; //should be 0x38
	id2= buffer[1]; //should be 0x21
    	id=(id1 << 8) | id2;

#ifdef BUILD_LK
	printf("LK st7701 id = 0x%08x\n", id);
#else
	printk("Kernel st7701 id = 0x%08x\n", id);
#endif
	return (LCM_ID_ST7703 == id)?1:0;
	//return 1;
}

static unsigned int lcm_ata_check(unsigned char *buffer)
{
	if(lcm_ata_check_flag){
		return 1;
	}else{
		return 0;
	}
}

LCM_DRIVER st7703_dsi_vdo_hd720_f7_hy_lcm_drv = 
{
	.name           = "st7703_dsi_vdo_hd720_f7_hy",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.compare_id     = lcm_compare_id,
    .ata_check		= lcm_ata_check,
};
