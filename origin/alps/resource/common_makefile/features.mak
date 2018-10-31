################################################
#默认手机信息配置
################################################
#设置默认时区
LYCONFIG_DEFAULT_TIMEZONE=Asia/Shanghai
################################################
#功能宏配置
################################################
####### 项目信息 START #######
# 客户子名 [Author:lijun]
LYCONFIG_COMB_CUST_PROJECT_SUB_NAME = null
####### 项目信息 END #######

####### 开关机 START #######
# 关机/重启显示关机动画
LYCONFIG_FEA_SHOW_SHUTDOWN_ANIMATION = no
                                    ### yes
                                    ### no

# 是否支持多套开关机
LYCONFIG_FEA_MUL_POWER_ANIM_SUPPORT = no
                                    ### yes
                                    ### no

# 多套开关机支持几套(默认是1,only default power)
LYCONFIG_FEA_MUL_POWER_ANIM_NUM = 1
                                    ### 1
                                    ### 2

#使用工具写入SN号，和自动生成唯一SN号互斥
LYCONFIG_FEA_SN_WRITE_BY_TOOL = no
                                    ### yes
                                    ### no
####### 开关机 END #######

####### 设置 - 智能辅助 START #######
# 功能:TP智能唤醒
LYCONFIG_FEA_TP_WAKEUP_SUPPORT = yes
                                    ### yes
                                    ### no

# 功能:TP唤醒 - 双击HOME灭屏
LYCONFIG_FEA_DOUBLE_CLICK_HOME_OFF_SCREEN = yes
                                    ### yes
                                    ### no

# 功能:三指截屏[Author:tauren]
LYCONFIG_FEA_THREETOUCH_SCREENSHOT_SUPPORT = yes
                                    ### yes
                                    ### no

# 功能:悬浮窗
LYCONFIG_FEA_POPWINDOW_SUPPORT = yes
                                    ### yes
                                    ### no

# 功能:翻转静音
LYCONFIG_FEA_FLIP_MUTE_SUPPORT = yes
                                    ### yes
                                    ### no

# 功能:智能接听
LYCONFIG_FEA_SMART_ANSWER_SUPPORT = yes
                                    ### yes
                                    ### no

# 功能:口袋模式
LYCONFIG_FEA_POCKET_MODE_SUPPORT = yes
                                    ### yes
                                    ### no

# 功能:隔空操作
LYCONFIG_FEA_DEFAULT_AIROPERATOR_ADD = yes
                                    ### yes
                                    ### no

# 功能:隔空操作-隔空解锁
LYCONFIG_FEA_AIR_OPERATOR_UNLOCK_SUPPORT = yes
                                    ### yes
                                    ### no

# 功能:隔空操作-待机滑页
LYCONFIG_FEA_AIR_OPERATOR_LAUNCHER_SUPPORT = yes
                                    ### yes
                                    ### no

# 功能:隔空操作-音乐操作
LYCONFIG_FEA_AIR_OPERATOR_MUSIC_SUPPORT = yes
                                      ### yes
                                      ### no

# 功能:隔空操作-图库操作
LYCONFIG_FEA_AIR_OPERATOR_GALLREY_SUPPORT = yes
                                      ### yes
                                      ### no
####### 设置 - 智能辅助 END #######

####### 设置 - 指纹 START #######
# 指纹功能-应用锁、快捷应用、指纹拍照
LYCONFIG_FEA_FINGERPRINT_MORE_FUNC_SUPPORT = yes
                                    ### yes
                                    ### no
####### 设置 - 指纹 START #######

#CDfinger指纹
LYCONFIG_FEA_CDFINGER_FINGERPRINT = yes
                                            ### yes
                                            ### no

# CDfinger指纹拍照移动到智能辅助
LYCONFIG_FEA_CDFINGER_SMART_CAMERA_CONTROL = no

####### 设置 菜单#######
#设置存储显示总容量(可用+已使用=总容量)[Author:lanhua]
LYCONFIG_FEA_SETTING_STORAGE_SHOW_TOTAL = no
                                      ### yes
                                      ### no
####### 设置 菜单 #######

####### SystemUI START #######
#软件是否带有NAVIGATION BAR[zhuxiaoyin]
LYCONFIG_FEA_NAVIGATION_BAR_SUPPORT = no
                                    ### yes
                                    ### no

#一键清除是否开启[Author:jixiang]
LYCONFIG_FEA_DEFAULT_ONEKEY_CLEAN = yes
                                    ### yes
                                    ### no
####### SystemUI END #######

####### 工厂模式 START #######
#设置/工厂增加Sensor校准菜单[Author:lanhua]
LYCONFIG_FEA_SENSOR_CALIBRATION_SUPPORT = no
                                    ### yes
                                    ### no

# 是否有CAMERA按键
LYCONFIG_FEA_HAS_CAMERA_KEY = no
                                    ### yes
                                    ### no

# 工程模式中是否添加RTC项[Author:lijun]
LYCONFIG_FEA_FACTORY_SHOW_RTC_SUPPORT = no
                                    ### yes
                                    ### no
####### 工厂模式 END #######

####### 相机 START #######
#拍照补光采用简单的还是OPPO样式的补光[Author:jixiang]
LYCONFIG_FEA_WHITE_BALANCE_TAKE_PICTURE = 0
                                    ### 0(简单的View)
                                    ### 1(OPPO样式)

# 相机预览界面4:3
LYCONFIG_FEA_CAMERA_DEFAULT_PICTURE_RATIO_4_3 = no
                                    ### yes
                                    ### no

# 照片尺寸默认像素允许自定义
LYCONFIG_FEA_CAMERA_DEFAULT_PICTURE_SIZE = no
                                    ### yes
                                    ### no

# 相机预览(全屏与4:3)切换规则
LYCONFIG_FEA_CAMERA_DEFAULT_PREVIEW_SWITCH_RULE= no
                                    ### yes 像素相似
                                    ### no  最高像素

# 前后摄零延时默认开启
LYCONFIG_FEA_CAMERA_ZERO_DELAY_PICTURES_ON = 11
                                    ### 11 不开启
                                    ### 0 开启后摄
                                    ### 1 开启前摄
                                    ### 2 前后都开启

# 去除零延时菜单
LYCONFIG_FEA_CAMERA_ZSD_MENU_OFF = no
                                    ### yes
                                    ### no

# Camera设置菜单中是否添加开门声音的开关[Author:lijun]
LYCONFIG_FEA_CAMERA_SHUTTER_SOUND_SWITCH = no
                                    ### yes
                                    ### no

# Camera设置菜单中是否添加聚焦声音的开关[Author:lijun]
LYCONFIG_FEA_CAMERA_FOCUS_SOUND_SWITCH = no
                                    ### yes
                                    ### no

# Camera侧边选项中是否显示慢动作菜单[Author:lijun]
LYCONFIG_FEA_CAMERA_SLOW_MOTION_PICKER = yes
                                    ### yes
                                    ### no

# ShlyCamera自动对焦是否发声
LYCONFIG_FEA_AUTO_FOCUS_SOUND_ENABLE = no
                                    ### yes
                                    ### no

# ShlyCamera设置菜单中是否添加音量键功能的开关
LYCONFIG_FEA_CAMERA_VOLUME_KEY_FUNC_SWITCH = no
                                    ### yes
                                    ### no

# 去掉色彩效果菜单
LYCONFIG_FEA_REMOVE_CAMERA_COLOR_EFFECT_MENU = no
                                    ### yes
                                    ### no

# VIEDO EIS默认开启
LYCONFIG_FEA_CAMERA_EIS = no
                                    ### yes
                                    ### no

#前摄5M 
LYCONFIG_FEA_FRONT_CAMERA_PIC_SIZE_5M = no
                                    ### yes
                                    ### no

#前摄8M（需要同时开启5M）
LYCONFIG_FEA_FRONT_CAMERA_PIC_SIZE_8M = no
                                    ### yes
                                    ### no

#后摄5M 
LYCONFIG_FEA_REAR_CAMERA_PIC_SIZE_5M = no
                                    ### yes
                                    ### no

#后摄8M（需要同时开启5M）
LYCONFIG_FEA_REAR_CAMERA_PIC_SIZE_8M = no
                                    ### yes
                                    ### no

#后摄13M（需要同时开启5M, 8M）
LYCONFIG_FEA_REAR_CAMERA_PIC_SIZE_13M = no
                                    ### yes
                                    ### no
#相机增加美颜[Author:lanhua]                                
GANGYUN_CAMERA_BEAUTY = yes 
					### yes
					### no                                   
####### 相机 END #######

####### Launcher START #######
# Launcher3  上面是否带 心情相册, 音乐 等组件 [Author:jixiang]
LYCONFIG_FEA_LAUNCHER_GALLERY_MUSIC_ISSHOW = yes
                                    ### yes
                                    ### no
####### Launcher END #######

#霍尔时钟界面显示[Author:lanhua]
LYCONFIG_FEA_HALL_VIEW_SUPPORT = 0
                                    ### 0(解锁)
                                    ### 1(圆形时钟)
                                    ### 2(方型时钟)

# 设置中电池百分比是否显示
LYCONFIG_FEA_BATTERY_PERCENTAGE = yes
                                    ### yes 
                                    ### no
# 功能:公司LOGO[Author:lijun]
LYCONFIG_FEA_COMPANY_LOGO_SUPPORT = no
                                    ### yes
                                    ### no

# 功能:使用客户自己的LOGO[Author:lijun]
LYCONFIG_FEA_USE_CUSTOM_COMPANYLOGO = no
                                    ### yes
                                    ### no
                                    
#隐藏双开助手图标在设置里显示[Author:lanhua] 
LYCONFIG_FEA_HIDE_DOUBLE_ASSISTSTANT_ICON = yes
                                    ### yes
                                    ### no
#隐藏型号显示[Author:lanhua] 
LYCONFIG_FEA_HIDE_PHONE_MODEL = no
                           ### yes
                           ### no
                           
#camera真假对焦兼容 不用开假对焦
LYCONFIG_FEA_FOUCS_TRUE_AND_FALSE_COMPATIBLIT = no
                           					### yes
                           					### no
################################################
#资源配置宏
################################################
# 默认主题
LYCONFIG_FEA_SHLY_ITHEME_DEFAULT = default
                                    ### default      默认源生主题
                                    ### extreme      极致人生
                                    ### freshness    清新
                                    ### gold         金致
                                    ### letv         乐视
                                    ### singularity  奇点
# 支持极致人生主题
LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_EXTREME = yes
                                    ### yes
                                    ### no
# 支持清新主题
LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_FRESHNESS = yes
                                    ### yes
                                    ### no
# 支持金致主题
LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_GOLD = yes
                                    ### yes
                                    ### no
# 支持乐视主题
LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_LETV = yes
                                    ### yes
                                    ### no
# 支持奇点主题
LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_SINGULARITY = no
                                    ### yes
                                    ### no
# wait
LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_WAIT = yes
                                    ### yes
                                    ### no
# yuan
LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_YUAN = yes
                                    ### yes
                                    ### no
################################################
#系统默认值配置
################################################
#工厂模式默认语言[Author:wanggang]
LYCONFIG_FEA_FACTORYLANGUAGE = default
                                    ### zh_cn (中文)
                                    ### en_us (英文)
                                    ### default (系统语言)

# USB调试是否开启
LYCONFIG_DEFAULT_USB_DEBUG = no
                                    ### yes
                                    ### no
# 默认字体大小
LYCONFIG_DEFAULT_FONTSIZE = Normal
                                    ### Extra、Large、Normal、Small
# 默认来电铃声音量
LYCONFIG_DEFAULT_VOLUME_RING = 15
                                    ### 0 ~ 15
# 默认通知铃声音量
LYCONFIG_DEFAULT_NOTIFICATION_VOLUME = 15
                                    ### 0 ~ 15
# 默认闹钟音量
LYCONFIG_DEFAULT_VOLUME_ALARM = 15
                                    ### 0 ~ 15
# 默认屏幕亮度
LYCONFIG_DEFAULT_SCREEN_BRIGHTNESS = 102
                                    ### 0 ~ 255
# 默认屏幕休眠时间[Author:lijun]
LYCONFIG_DEFAULT_SCREEN_OFF_TIMEOUT = 30000
                                    ### 15000 ~ 15s; 30000 ~ 30s; 60000 ~ 1min; 120000 ~ 2min
                                    ### 300000 ~ 5min; 600000 ~ 10min; 1800000 ~ 30min
# TP唤醒 总开关默认值
LYCONFIG_DEFAULT_TP_WAKEUP = 0
                                    ### 0
                                    ### 1

# TP唤醒 双击home灭屏
LYCONFIG_DEFAULT_TP_WAKEUP_DOUBLE_TAP_HOME = 0
                                    ### 0
                                    ### 1

# TP唤醒 双击默认唤醒屏幕
LYCONFIG_DEFAULT_TP_WAKEUP_DOUBLE_CLICK = 0
                                    ### 0
                                    ### 1
# TP唤醒 上滑默认值
LYCONFIG_DEFAULT_TP_WAKEUP_DIRECTION_UP = 0
                                    ### 0
                                    ### 1
# TP唤醒 下滑默认值
LYCONFIG_DEFAULT_TP_WAKEUP_DIRECTION_DOWN = 0
                                    ### 0
                                    ### 1
# TP唤醒 左滑默认值
LYCONFIG_DEFAULT_TP_WAKEUP_DIRECTION_LEFT = 0
                                    ### 0
                                    ### 1
# TP唤醒 右滑默认值
LYCONFIG_DEFAULT_TP_WAKEUP_DIRECTION_RIGHT = 0
                                    ### 0
                                    ### 1
# TP唤醒 画C默认值
LYCONFIG_DEFAULT_TP_WAKEUP_GESTURE_C = 0
                                    ### 0
                                    ### 1
# TP唤醒 画M默认值
LYCONFIG_DEFAULT_TP_WAKEUP_GESTURE_M = 0
                                    ### 0
                                    ### 1
# TP唤醒 画E默认值
LYCONFIG_DEFAULT_TP_WAKEUP_GESTURE_E = 0
                                    ### 0
                                    ### 1
# TP唤醒 画O默认值
LYCONFIG_DEFAULT_TP_WAKEUP_GESTURE_O = 0
                                    ### 0
                                    ### 1
# TP唤醒 画V默认值
LYCONFIG_DEFAULT_TP_WAKEUP_GESTURE_V = 0
                                    ### 0
                                    ### 1
# TP唤醒 画W默认值
LYCONFIG_DEFAULT_TP_WAKEUP_GESTURE_W = 0
                                    ### 0
                                    ### 1
# TP唤醒 画S默认值
LYCONFIG_DEFAULT_TP_WAKEUP_GESTURE_S = 0
                                    ### 0
                                    ### 1

# 功能:三指截屏默认是否开启[Author:jxring]
LYCONFIG_DEFAULT_THREETOUCH_SCREENSHOT = 0
                                    ### 0 close
                                    ### 1 open

# 翻转静音 默认值
LYCONFIG_DEFAULT_FLIP_MUTE = 0
                                    ### 0
                                    ### 1

# 智能接听 默认值
LYCONFIG_DEFAULT_SMART_ANSWER = 0
                                    ### 0
                                    ### 1
#口袋模式 默认值
LYCONFIG_DEFAULT_POCKET_MODE = 0
                                    ### 0
                                    ### 1

# 隔空操作 解锁默认值
LYCONFIG_DEFAULT_AIR_OPERATOR_UNLOCK = 0
                                      ### 0
                                      ### 1
# 隔空操作 待机默认值
LYCONFIG_DEFAULT_AIR_OPERATOR_LAUNCHER = 0
                                      ### 0
                                      ### 1
# 隔空操作 音乐默认值
LYCONFIG_DEFAULT_AIR_OPERATOR_MUSIC = 0
                                      ### 0
                                     ### 1
# 隔空操作 图库默认值
LYCONFIG_DEFAULT_AIR_OPERATOR_GALLERY = 0
                                      ### 0
                                      ### 1
# 默认输入法（缺省default表示LatinIME）
LYCONFIG_DEFAULT_INPUT_METHOD = "com.qisiemoji.inputmethod/com.android.inputmethod.latin.LatinIME"


# 时间格式
LYCONFIG_DEFAULT_TIME_FORMAT = "24"
                                    ### "12"
                                    ### "24"

# 工程模式
LYCONFIG_DEFAULT_ENG_MODEL_CODE="*#8501#"

# 版本信息
LYCONFIG_DEFAULT_VERSION_INFO_CODE="*#8502#"

# 内部版本信息
LYCONFIG_DEFAULT_INWARD_VERSION_INFO_CODE="*#*#8502#*#*"

# 工厂测试
LYCONFIG_DEFAULT_FACTORY_TEST_CODE="*#8509#"

# 硬件信息
LYCONFIG_DEFAULT_HW_INFO_CODE="*#8510#"

# TP 测试全面
LYCONFIG_DEFAULT_TP_TEST_FULL_CODE="*#8513#"

# 手写IEMI号
LYCONFIG_DEFAULT_SET_IMEI_TEST_CODE="*#6864#"

# 多套开关机客户暗码
LYCONFIG_DEFAULT_MUL_POWERANIM_SELECT_CODE = "*#8520#"

# 设置-提示音和通知-标准-振动
LYCONFIG_DEFAULT_VIBRATE_ON = no
                                    ### yes
                                    ### no

# 拨号键盘触摸音效
LYCONFIG_DEFAULT_DIALER_CLICK_SOUND_ENABLED = yes
                                    ### yes
                                    ### no

# 触摸提示音
LYCONFIG_DEFAULT_SOUND_EFFECTS_ENABLED = no
                                    ### yes
                                    ### no

# 锁屏提示音
LYCONFIG_DEFAULT_LOCK_SCREEN_SOUND_ENABLED = yes
                                    ### yes
                                    ### no

# 默认来电铃声
LYCONFIG_DEFAULT_CALL_RINGTONE = "Party.ogg"

# 默认通知铃声
LYCONFIG_DEFAULT_NOTIFICATION_RINGTONE = "Ukulele.ogg"

# 默认闹钟铃声
LYCONFIG_DEFAULT_ALARM_RINGTONE = "Fantasy.ogg"

# 状态栏是否显示电池百分比
LYCONFIG_DEFAULT_BATTERY_PERCENTAGE_ON = 0
                                    ### 0 
                                    ### 1

# 悬浮窗口是否开启
LYCONFIG_DEFAULT_POPWINDOW_MENU_DISPLAY = 0
                                    ### 0
                                    ### 1

# 触摸时振动[Author:lanhua]
LYCONFIG_DEFAULT_HAPTIC_FEEDBACK_ENABLED = yes
                                    ### yes
                                    ### no

# USB连接后通知栏中默认选择的功能[Author:liuyougen]
LYCONFIG_DEFAULT_USB_DEFAULT_CONFIG = mtp
                                    ### none (default/usb)
                                    ### mass_storage (usb)
                                    ### mtp (mtp)

# 拼写检查工具默认是否开启
LYCONFIG_DEFAULT_SPELL_CHECKER = 1
                                    ### 0 关闭
                                    ### 1  开启

# 设置菜单风格默认设置[Author:zuoyong];
LYCONFIG_DEFAULT_SETTINGS_STYLE = default
                                    ### list
                                    ### grid
                                    ### default

# 设置菜单使用圆形彩色图标
LYCONFIG_RESOURCE_SYSTEMS_SETTINGS_ICON_STYLE = colorIcon
                                    ### colorIcon
                                    ### default
################################################
#上海领阳应用添加配置
################################################
#desktop launcher
LYCONFIG_FEA_USE_SHLYLAUNCHER3 = no

# Itheme是否添加(不添加Itheme则使用Wallpaper)
LYCONFIG_APP_SHLY_IROMTHEME = yes
                                    ### yes
                                    ### no

# 应用:领阳文件管理器
LYCONFIG_APP_LINGYANG_FILEMANAGER = no
                                    ### yes
                                    ### no

# 应用:系统原生浏览器
LYCONFIG_APP_SYSTEM_BROWSER_SUPPORT = yes
                                    ### yes
                                    ### no

#应用：OPPO界面Camera [Author:lanhua]
LYCONFIG_APP_LINGYANG_OPPO_CAMERA = no
                                    ### yes
                                    ### no
#应用：皇族Launcher                                    
LYCONFIG_DEFAULT_USE_HZLAUNCHER = yes
                                    ### yes
                                    ### no 
################################################
#第三方应用添加配置
################################################

################################################
#外单第三方配置
################################################
#GOOGLE SETUPWIZARD(谷歌开机向导)
LYCONFIG_APP_MUL_SETUPWIZARD = no

#Google Chrome
LYCONFIG_APP_MUL_CHROME = no

#Google Chrome(自动取代Browser)
LYCONFIG_APP_MUL_CHROME_WITHOUT_BROWSER = no

#Google News and Weather
LYCONFIG_APP_MUL_NEWSWEATHER = no

#YouTube
LYCONFIG_APP_MUL_YOUTUBE=yes

#Opera Mini
LYCONFIG_APP_MUL_OPERA=yes

#Kika input method
LYCONFIG_APP_MUL_KIKA_INPUT = yes
################################################
#MTK原生宏
################################################
#屏幕像素宽度
LCM_WIDTH=720

#屏幕像素高度
LCM_HEIGHT=1280

#LOGO定义
BOOT_LOGO=hd720

#IRTX 
MTK_IRTX_SUPPORT = no
MTK_IRTX_PWM_SUPPORT = no

#DUAL MIC - 双MIC
MTK_DUAL_MIC_SUPPORT = no
MTK_INCALL_NORMAL_DMNR = no
MTK_HAC_SUPPORT = yes

MTK_AUDIO_HD_REC_SUPPORT = yes
MTK_HANDSFREE_DMNR_SUPPORT = yes
MTK_VOIP_ENHANCEMENT_SUPPORT = yes

#PIP SUPPORT - 画中画 
MTK_CAM_NATIVE_PIP_SUPPORT = no

#MODEM 5模 yes,  其他 no
MTK_WORLD_PHONE=no

#SIM卡热插拔
MTK_SIM_HOT_SWAP = no
MTK_SIM_HOT_SWAP_COMMON_SLOT = no

#HOTKNOT
MTK_HOTKNOT_SUPPORT = no
################################################
#驱动配置
################################################
#SmartAudio
LYCONFIG_KERNEL_SMARTPA_TFA98XX=no
LYCONFIG_KERNEL_SMARTPA_ESD_CHECK=no
LYCONFIG_SMARTPA_USE_SPK_6_OHM=no
LYCONFIG_SMARTPA_PARAMETER=NONE
LYCONFIG_SMARTPA_USE_BYPASS_DURING_SPEECH=yes
LYCONFIG_SMARTPA_VERSION_NEW=yes

#双摄像头
LYCONFIG_DUAL_CAMERA_BOTH_WORK_SUPPORT=yes

#闪光灯芯片 LM3643
LYCONFIG_MTK_LM3643_SUPPORT=no

#霍尔
LYCONFIG_MTK_FLIP_HALL_SUPPORT=no

#前后摄驱动层对调
LYCONFIG_EXCHANGE_BACK_FRONT_CAMERA_SUPPORT=no

#地磁
CUSTOM_KERNEL_MAGNETOMETER = no

#相机马达
CUSTOM_HAL_LENS = fm50af sensordrive ad5823af vm149caf dw9719af dw9714af dummy_lens

#前后摄像头共用VCAMA
LYCONFIG_DUAL_CAMERA_USE_VCAMA_SUPPORT=no

#前摄闪光灯
LYCONFIG_SUB_FLASHLIGHT_SUPPORT=no

#前摄闪光灯型号
LYCONFIG_COMB_SUB_FLASHLIGHT_TYPE=NONE

#电池曲线保留 CS_P/CS_N
LYCONFIG_FGU_REVERSE_CS_SUPPORT = no

#指纹型号
LYCONFIG_COMB_FINGERPRINT_SUPPORT = null

#2秒重启还是开机, no:reboot, yes:power off
LYCONFIG_RTC_2SEC_POWER_OFF_ENABLE = no

#高压电池4.4V
LYCONFIG_HIGH_BATTERY_VOLTAGE_44_SUPPORT=no

#高压电池4.35V
HIGH_BATTERY_VOLTAGE_SUPPORT=yes

#电池温控电阻,yes:关闭, no:开启
LYCONFG_DISABLE_BATTERY_NTC_RESISTOR=no

#充电IC
LYCONFIG_COMB_CHARGER_IC=null
                              ### MTK_FAN5405_SUPPORT
                              ### MTK_SM5414_SUPPORT
                              ### null

#充电IC:MTK_FAN5405_SUPPORT 有效时，yes 1.5A， no 2A
LYCONFIG_CHARGER_FAN5405_SUPPORT_HL7005=no

#三色灯支持
LYCONFIG_RGB_LEDS_SUPPORT = no

#硬件信息
LYCONFIG_DETECT_HW_INFO_SUPPORT = yes

#是否支持GPIO控制的闪光灯
LYCONFIG_GPIO_FLASHLIGHT_SUPPORT = yes

#陀螺仪
CUSTOM_KERNEL_GYROSCOPE = no

#陀螺仪 - MXG2320
LYCONFIG_CUSTOM_KERNEL_GYROSCOPE_MXG2320 = no

#光距感 - alsps support
LYCONFIG_KERNEL_ALSPS_SUPPORT=yes

#F5B冠群将GPIO85, KPD_KCOL1 定义为Camera按键 
LYCONFIG_MTK_GPIO_CAM_SUPPORT=no

#B3皇族将GPIO81, KPD_ROW0 定义为sos按键 
LYCONFIG_MTK_GPIO_SOS_SUPPORT=no

#GPS 省晶体
LYCONFIG_SAVE_CRYSTAL_VCTCXO_SUPPORT=yes

#屏幕分辨率，根据屏幕像素和尺寸得出。
#在线计算网址http://www.lukiya.com/App/PPICalculator
LYCONFIG_LCD_PPI = null

#功放类型，K类或者D类
LYCONFIG_COMB_SPEAKER_SUPPORT=CLASS_D

#双喇叭
LYCONFIG_DUAL_SPEAKER_SUPPORT=no

#OTG 
LYCONFIG_CHARGE_IC_OTG_SUPPORT=yes

#TP模拟通话灭屏
LYCONFIG_TP_PROXIMITY_SUPPORT = no

HAVE_AACENCODE_FEATURE = yes
