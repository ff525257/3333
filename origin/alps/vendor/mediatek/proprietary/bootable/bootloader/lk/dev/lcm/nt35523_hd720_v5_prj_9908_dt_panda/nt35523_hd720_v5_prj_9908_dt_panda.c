/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
#ifndef BUILD_LK
#include <linux/string.h>
#endif
#include "lcm_drv.h"

#define FRAME_WIDTH  										(720)
#define FRAME_HEIGHT 										(1280)


#define REGFLAG_DELAY														0xFE
#define REGFLAG_END_OF_TABLE      							0xFFF   


#ifndef TRUE
    #define TRUE 1
#endif

#ifndef FALSE
    #define FALSE 0
#endif
//static unsigned int lcm_esd_test = FALSE;      ///only for ESD test								1

// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    								(lcm_util.set_reset_pin((v)))

#define UDELAY(n) 											(lcm_util.udelay(n))
#define MDELAY(n) 											(lcm_util.mdelay(n))

#define LCM_ID_NT35523										0x5523


// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)										lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   			lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)    

struct LCM_setting_table {
    unsigned char cmd;
    unsigned char count;
    unsigned char para_list[64];
};

static struct LCM_setting_table lcm_initialization_setting[] = 
{

{0xF0,5,{0x55,0xAA,0x52,0x08,0x01}},//////////page 1    For 2 POWER to 3 power IC  NT50198B control
{0xC0,1,{0x00}},/////////////////               For 2 POWER to 3 power IC  NT50198B control
{0xB5,2,{0x08,0x08}},/////////////////  

{0xFF,4,{0xAA,0x55,0xA5,0x80}},
{0xF3,1,{0xC0}},           

{0xF0,5,{0x55,0xAA,0x52,0x08,0x00}},///page 0  
//{0xC0,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x02}}, //此处为控制TE与PWM，模组厂需根据自己的FPC实际设计进行匹配
{0xC8,1,{0x80}},
{0xB1,2,{0xE8,0x21}},
{0xB5,2,{0x05,0x00}},
{0xBB,2,{0x93,0x93}},
{0xBC,2,{0x0F,0x00}},
{0xBD,4,{0x11,0x30,0x10,0x10}},
{0xF0,5,{0x55,0xAA,0x52,0x08,0x01}},/////page 1
{0xD7,2,{0x00,0xFF}},
{0xB7,2,{0x00,0x6C}},
{0xCE,1,{0x00}},
{0xCA,1,{0x03}},
{0xB3,2,{0x23,0x23}},
{0xB4,2,{0x23,0x23}},
{0xC3,2,{0x5A,0x5A}},
{0xC4,2,{0x5A,0x5A}},
{0xC2,2,{0x5A,0x5A}},

{0xB9,2,{0x34,0x34}},  //24
{0xBA,2,{0x34,0x34}},  //24

{0xBC,2,{0x50,0x00}},
{0xBD,2,{0x50,0x00}},
{0xBE,2,{0x00,0x71}}, ////BE寄存器是VCOM设置，需每片都调整
{0xBF,2,{0x00,0x71}}, ///建议BF寄存器设置等于BE寄存器

{0xF0,5,{0x55,0xAA,0x52,0x08,0x03}},///page 3
{0xB0,4,{0x00,0x00,0x00,0x00}},
{0xB1,4,{0x00,0x00,0x00,0x00}},
{0xB2,7,{0x00,0x00,0x0A,0x06,0x00,0xF0,0x5B}},
{0xB3,7,{0x00,0x00,0x09,0x06,0x00,0xF0,0x5B}},
{0xB6,10,{0xF0,0x05,0x06,0x03,0x00,0x00,0x00,0x00,0x10,0x10}},
{0xB7,10,{0xF0,0x05,0x07,0x03,0x00,0x00,0x00,0x00,0x10,0x10}},
{0xBC,7,{0xC5,0x03,0x00,0x08,0x00,0xF0,0x5B}},
{0xC4,2,{0x00,0x00}},
{0xF0,5,{0x55,0xAA,0x52,0x08,0x05}},////page 5
{0xB0,4,{0x33,0x04,0x00,0x01}},
{0xB1,2,{0x40,0x00}},
{0xB2,3,{0x03,0x02,0x02}},

{0xB3,4,{0x83,0x23,0x42,0x97}},///// B3寄存器的第3和第4个参数含有VCOMDCOFF[8:0]设置，是sleep in 时VCOM大小，其对应电压大小应为BE处设置的VCOM电压的值的大小的一半，需每片都调整
{0xB4,4,{0xC5,0x35,0x77,0x53}},
{0xB5,7,{0x4C,0xE5,0x31,0x33,0x33,0xA3,0x0A}},
{0xB6,6,{0x00,0x00,0xD5,0x31,0x77,0x53}},
{0xB9,5,{0x00,0x00,0x00,0x05,0x00}},
{0xC0,5,{0x35,0x33,0x33,0x50,0x05}},
{0xC6,4,{0x00,0x00,0x00,0x00}},
{0xCE,2,{0xF0,0x1F}},
{0xD2,5,{0x00,0x25,0x02,0x00,0x00}},
{0xE7,2,{0xE8,0xFF}},
{0xE8,2,{0xFF,0xFF}},
{0xE9,1,{0x00}},
{0xEA,1,{0xAA}},
{0xEB,1,{0xAA}},
{0xEC,1,{0xAA}},
{0xEE,1,{0xAA}},
{0xF0,5,{0x55,0xAA,0x52,0x08,0x06}},////page 6
{0xB0,5,{0x7D,0x4A,0x7D,0x7D,0x7D}},
{0xB1,5,{0x7D,0x7D,0x42,0x5d,0x7D}},
{0xB2,5,{0x7D,0x63,0x61,0x7D,0x7D}},
{0xB3,5,{0x5f,0x72,0x7d,0x7D,0x7D}},
{0xB4,2,{0x7D,0x7D}},
{0xB5,5,{0x7D,0x48,0x7D,0x7D,0x7D}},
{0xB6,5,{0x7D,0x7D,0x40,0x5c,0x7D}},
{0xB7,5,{0x7D,0x62,0x60,0x7D,0x7D}},
{0xB8,5,{0x5e,0x72,0x7d,0x7D,0x7D}},
{0xB9,2,{0x7D,0x7D}},
{0xF0,5,{0x55,0xAA,0x52,0x08,0x02}},////page 2
{0xB0,1,{0x42}},
{0xD1,16,{0x00,0x00,0x00,0x1B,0x00,0x3F,0x00,0x5B,0x00,0x71,0x00,0x97,0x00,0xB5,0x00,0xE6}},
{0xD2,16,{0x01,0x0D,0x01,0x4A,0x01,0x7B,0x01,0xC7,0x02,0x03,0x02,0x05,0x02,0x3A,0x02,0x73}},
{0xD3,16,{0x02,0x97,0x02,0xCB,0x02,0xEE,0x03,0x20,0x03,0x41,0x03,0x6D,0x03,0x8C,0x03,0xAB}},
{0xD4,4,{0x03,0xBC,0x03,0xBE}},
//{0xFF,4,{0xAA,0x55,0xA5,0x80}},//command 3
//{0xF3,1,{0xC0}},
{0x35,1,{0x00}},

{0x11,1,{0x00}}, 
{REGFLAG_DELAY, 20, {}},
{0x29,1,{0x00}}, 
{REGFLAG_DELAY, 50, {}},


};


//[denqin begin] gaokai 2015.07.25
//[reason]:complie error: defined but not used
#if 0
static struct LCM_setting_table lcm_compare_id_setting[] = {
	// Display off sequence
	{0xB9,	3,	{0xFF, 0x83, 0x69}},
	{REGFLAG_DELAY, 10, {}},

    // Sleep Mode On
//	{0xC3, 1, {0xFF}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};

static struct LCM_setting_table lcm_backlight_level_setting[] = {
	{0x51, 1, {0xFF}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};
#endif
//[denqin end]

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;
	for(i = 0; i < count; i++) 
	{
		
		unsigned cmd;
		cmd = table[i].cmd;
		switch (cmd) 
		{
			
			case REGFLAG_DELAY :
				MDELAY(table[i].count);
				break;
				
			case REGFLAG_END_OF_TABLE :
				break;
				
			default:
					dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
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
		params->dbi.te_mode 				= LCM_DBI_TE_MODE_DISABLED;
		//params->dbi.te_mode 				= LCM_DBI_TE_MODE_VSYNC_ONLY;
		params->dbi.te_edge_polarity		= LCM_POLARITY_RISING;

#ifdef LCM_DSI_CMD_MODE
		params->dsi.mode   = CMD_MODE;
#else
	params->dsi.mode   = BURST_VDO_MODE; //SYNC_EVENT_VDO_MODE;BURST_VDO_MODE
#endif
	
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
		params->dsi.intermediat_buffer_num = 0;

		params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;

		params->dsi.vertical_sync_active				         = 4;    //4
		params->dsi.vertical_backporch					= 40;   //4
		params->dsi.vertical_frontporch					= 40;   //12
		params->dsi.vertical_active_line				= FRAME_HEIGHT; 

		params->dsi.horizontal_sync_active				= 10;  //50
		params->dsi.horizontal_backporch				= 40;
		params->dsi.horizontal_frontporch				= 40;
		params->dsi.horizontal_active_pixel			= FRAME_WIDTH;

	//	params->dsi.HS_PRPR=3;
	//	params->dsi.CLK_HS_POST=22;
	//	params->dsi.DA_HS_EXIT=20;

		params->dsi.PLL_CLOCK = 225;//400;//230
		//params->dsi.ssc_disable=true;

		params->dsi.clk_lp_per_line_enable = 1;
		params->dsi.esd_check_enable = 1;
		params->dsi.customization_esd_check_enable = 1;
		params->dsi.lcm_esd_check_table[0].cmd          = 0x0A;
		params->dsi.lcm_esd_check_table[0].count        = 1;
		params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9C;

}

static unsigned int lcm_compare_id(void)
{
	unsigned int id=0;
	unsigned char buffer[2];
	unsigned int array[16];  

	SET_RESET_PIN(1);	
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(10);
	SET_RESET_PIN(1);
	MDELAY(10);//Must over 6 ms
//	{0xF0,5,{0x55,0xAA,0x52,0x08,0x01}},
	array[0]=0x00063902;
	array[1]=0x52AA55F0;
	array[2]=0x00000108;
	dsi_set_cmdq(array, 3, 1);
	MDELAY(10);

	array[0] = 0x00023700;// return byte number
	dsi_set_cmdq(array, 1, 1);
	MDELAY(10);

	read_reg_v2(0xC5, buffer,2);
	id = buffer[0]<<8| buffer[1];
	
#if defined(BUILD_LK)
	printf("Linc LCM_ID_NT35523  = 0x%x  \n", id);
#endif
	return (LCM_ID_NT35523 == id)?1:0;
}

static void lcm_init(void)
{
    SET_RESET_PIN(1);
    MDELAY(10);
    SET_RESET_PIN(0);
    MDELAY(50);
    SET_RESET_PIN(1);
    MDELAY(120);
   // lcm_init_registers();
push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_suspend(void)
{
	unsigned int data_array[16];

	data_array[0]=0x00280500; // Display Off
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(20);
	
	data_array[0] = 0x00100500; // Sleep In
	dsi_set_cmdq(data_array, 1, 1);
    MDELAY(120);
	
	//SET_RESET_PIN(1);	
//	SET_RESET_PIN(0);
	//MDELAY(5); // 1ms
	
//	SET_RESET_PIN(1);
	//MDELAY(120); 

	//push_table(lcm_deep_sleep_mode_in_setting, sizeof(lcm_deep_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
}


static void lcm_resume(void)
{
	lcm_init();
	
	//push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
}



// ---------------------------------------------------------------------------
//  Get LCM Driver Hooks
// ---------------------------------------------------------------------------
LCM_DRIVER nt35523_hd720_v5_prj_9908_dt_panda_drv = 
{
    .name			= "nt35523_hd720_v5_prj_9908_dt_panda",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.compare_id    = lcm_compare_id,
};
