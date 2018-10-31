# Copyright (C) 2012 shanghai leadexceed  . All Rights Reserved.
##############################################################################
#客户项目配置
##############################################################################
#外部软件版本号
LYCONFIG_SW_USER_VERSION=F200C-HZ-P128-T-B4S-16+2-20171104

#内部软件版本号
LYCONFIG_SW_ENGINEER_VERSION=F200C_HZ_B4S.37M0.MUL.E1

#硬件版本号
LYCONFIG_HW_NUMBER=F200C

#客户名
LYCONFIG_COMB_CUST_PROJECT_NAME=F200C_HZ

# 客户子名 [Author:lijun]
LYCONFIG_COMB_CUST_PROJECT_SUB_NAME=F200C_HZ_B3

#平台名

#型号 ro.product.model
LYCONFIG_PRODUCT_MODEL=Android
#研发型号（暂用型号代替） ro.product.name
LYCONFIG_PRODUCT_NAME=Android
#研发型号（暂用型号代替） ro.product.device
LYCONFIG_PRODUCT_DEVICE=Android
#研发型号（暂用型号代替） ro.product.product
LYCONFIG_PRODUCT_PRODUCT=Android
#品牌 ro.product.brand
LYCONFIG_PRODUCT_BRAND=MediaTek
#基带套片（没要求就不改动） ro.product.board
LYCONFIG_PRODUCT_BOARD=MT6737
#制造商（没要求就不改动） ro.product.manufacturer
LYCONFIG_PRODUCT_MANUFACTURER=MediaTek

##############################################################################
#客户软件配置
##############################################################################
# CDfinger指纹拍照移动到智能辅助
LYCONFIG_FEA_CDFINGER_SMART_CAMERA_CONTROL = no

# 相机预览界面4:3
LYCONFIG_FEA_CAMERA_DEFAULT_PICTURE_RATIO_4_3 = yes

#霍尔时钟界面显示[Author:lanhua]
LYCONFIG_FEA_HALL_VIEW_SUPPORT = 1

#隐藏双开助手图标在设置里显示[Author:lanhua] 
LYCONFIG_FEA_HIDE_DOUBLE_ASSISTSTANT_ICON = no

#camera真假对焦兼容 不用开假对焦
LYCONFIG_FEA_FOUCS_TRUE_AND_FALSE_COMPATIBLIT = yes

# 功能:三指截屏[Author:tauren]
LYCONFIG_FEA_THREETOUCH_SCREENSHOT_SUPPORT = no
##############################################################################
#客户默认值配置
##############################################################################
# 默认输入法（缺省default表示LatinIME）
LYCONFIG_DEFAULT_INPUT_METHOD = default
# USB调试是否开启
LYCONFIG_DEFAULT_USB_DEBUG = yes

##############################################################################
#客户应用配置
##############################################################################
#应用：OPPO界面Camera [Author:lanhua]
LYCONFIG_APP_LINGYANG_OPPO_CAMERA = no

#在线主题壁纸
LYCONFIG_APP_SHLY_IROMTHEME = no
##############################################################################
#客户驱动配置
##############################################################################
#屏配置
LYCONFIG_CUSTOM_KERNEL_LCM="ili9881c_hd720_dsi_vdo_auo rm68200_hd720_dsi_vdo_auo s6d7aa0x62_hd_dsi_vdo_boe_sh_hz nt35523_hd720_v5_prj_9908_dt_panda st7703_dsi_vdo_hd720_f7_hy"

#摄像头配置
LYCUSTOM_HAL_IMGSENSOR=gc2365_mipi_raw  ov9760_mipi_raw gc5005_mipi_raw  gc2355_mipi_raw imx219_mipi_raw gc2375_mipi_raw gc5025_mipi_raw gc8024_mipi_raw_f200c_hz_b 
LYCONFIG_CUSTOM_KERNEL_IMGSENSOR=gc2365_mipi_raw  ov9760_mipi_raw gc5005_mipi_raw  gc2355_mipi_raw imx219_mipi_raw gc2375_mipi_raw gc5025_mipi_raw gc8024_mipi_raw_f200c_hz_b 

#Modem
CUSTOM_MODEM=long6737m_65_m0_lwg_dsds_fdd_3m_rda_f200c_eur_b8b20

#功放类型，K类或者D类
LYCONFIG_COMB_SPEAKER_SUPPORT=CLASS_K

#充电IC
LYCONFIG_COMB_CHARGER_IC=MTK_FAN5405_SUPPORT

#充电IC:MTK_FAN5405_SUPPORT 有效时，yes 1.5A， no 2A
LYCONFIG_CHARGER_FAN5405_SUPPORT_HL7005=yes

#霍尔
LYCONFIG_MTK_FLIP_HALL_SUPPORT=yes

#指纹型号
LYCONFIG_COMB_FINGERPRINT_SUPPORT=null

#前摄闪光灯
LYCONFIG_SUB_FLASHLIGHT_SUPPORT=no

#前后摄像头共用VCAMA
LYCONFIG_DUAL_CAMERA_USE_VCAMA_SUPPORT=yes

#高压电池4.35V
HIGH_BATTERY_VOLTAGE_SUPPORT=no

#光距感 - alsps support
LYCONFIG_KERNEL_ALSPS_SUPPORT=yes

#OTG 
LYCONFIG_CHARGE_IC_OTG_SUPPORT=yes
#前摄5M 
LYCONFIG_FEA_FRONT_CAMERA_PIC_SIZE_5M = no

#后摄5M 
LYCONFIG_FEA_REAR_CAMERA_PIC_SIZE_5M = yes

#后摄8M（需要同时开启5M）
LYCONFIG_FEA_REAR_CAMERA_PIC_SIZE_8M = yes

LYCONFIG_DEFAULT_SCREEN_BRIGHTNESS=178
LYCONFIG_FEA_HAS_SOS_KEY=yes
LYCONFIG_MTK_GPIO_SOS_SUPPORT=yes
##############################################################################

