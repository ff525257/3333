# Copyright (C) 2011 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# We have to use BUILD_PREBUILT instead of PRODUCT_COPY_FIES,
# because SMALLER_FONT_FOOTPRINT is only available in Android.mks.
#LOCAL_PATH:= frameworks/base/data/poweranim
-include resource/LyFeatures.mk

#-include shly/preinstall/preinstall_apk.mk

DEVICE_PACKAGE_OVERLAYS += vendorshly/ShlyOverlays
#DEVICE_PACKAGE_OVERLAYS += packages/shlythemes/$(LYCONFIG_FEA_SYSTEMS_UI_STYLE)/Overlays

PRODUCT_PROPERTY_OVERRIDES += mul_lang_support=true

#PRODUCT_PROPERTY_OVERRIDES += shlyandroid_for_native_system=true

##########################################
#
# 工厂软件不需要部分
#
##########################################
ifeq ($(LYCONFIG_COMB_CUST_PROJECT_NAME_FACTORY), true)

    PRODUCT_PACKAGES += Home
    PRODUCT_PACKAGES += Camera
    PRODUCT_PACKAGES += ShlyIcons-en
    # 地磁指南针
    ifeq ($(CUSTOM_KERNEL_MAGNETOMETER), yes)
        PRODUCT_PROPERTY_OVERRIDES += ro.shly.magnetometer_support=true
    else
        PRODUCT_PROPERTY_OVERRIDES += ro.shly.magnetometer_support=false
    endif
    # 副麦克
    ifeq ($(strip $(MTK_DUAL_MIC_SUPPORT)),yes)
        PRODUCT_PROPERTY_OVERRIDES += ro.shly.dualmic_support=true
    else
        PRODUCT_PROPERTY_OVERRIDES += ro.shly.dualmic_support=false
    endif
	
   # 工程测试模式
   PRODUCT_PACKAGES += ShlyFactoryMode

   # 隔空操作
   ifeq ($(LYCONFIG_KERNEL_ALSPS_SUPPORT), true)
       ifeq ($(LYCONFIG_FEA_DEFAULT_AIROPERATOR_ADD), true)
          PRODUCT_PACKAGES += ShlyAirOperator
       endif
       PRODUCT_PROPERTY_OVERRIDES += ro.shly.alsps_support=true
   else
       PRODUCT_PROPERTY_OVERRIDES += ro.shly.alsps_support=false
   endif
  
else

#USB连接后通知栏中默认选择的功能[Author:liuyougen]
ifneq ($(LYCONFIG_COMPILEMODE), ENG)
ifeq ($(LYCONFIG_DEFAULT_USB_DEFAULT_CONFIG), mtp)
ifneq ($(LYCONFIG_DEFAULT_USB_DEBUG), true)
PRODUCT_PROPERTY_OVERRIDES += persist.sys.usb.config=mtp
else
PRODUCT_PROPERTY_OVERRIDES += persist.sys.usb.config=mtp,adb
endif
endif
endif

# 副麦克
ifeq ($(strip $(MTK_DUAL_MIC_SUPPORT)),yes)
PRODUCT_PROPERTY_OVERRIDES += ro.shly.dualmic_support=true
else
PRODUCT_PROPERTY_OVERRIDES += ro.shly.dualmic_support=false
endif

# 工程测试模式
PRODUCT_PACKAGES += ShlyFactoryMode

PRODUCT_PACKAGES += LatinIME

#TP手势唤醒
ifeq ($(LYCONFIG_FEA_TP_WAKEUP_SUPPORT), true)
PRODUCT_PROPERTY_OVERRIDES += shly_tpgestures_support=true
PRODUCT_PACKAGES += ShlyTPSmartWakeUp
else
PRODUCT_PROPERTY_OVERRIDES += shly_tpgestures_support=false
endif

# TP模拟通话灭屏
ifeq ($(LYCONFIG_TP_PROXIMITY_SUPPORT),true)
    PRODUCT_PROPERTY_OVERRIDES += ro.shly.tp_proximity_support=true
else
    PRODUCT_PROPERTY_OVERRIDES += ro.shly.tp_proximity_support=false
endif

# LED灯开关
ifeq ($(LYCONFIG_RGB_LEDS_SUPPORT), true)
    PRODUCT_PROPERTY_OVERRIDES += ro.shly.rgb_led_support=true
else
    PRODUCT_PROPERTY_OVERRIDES += ro.shly.rgb_led_support=false
endif

PRODUCT_PACKAGES += ShlyIcons-en

#Launcher
ifeq ($(LYCONFIG_FEA_USE_SHLYLAUNCHER3), true)
PRODUCT_PACKAGES += ShlyLauncher3
endif

#Launcher
ifeq ($(LYCONFIG_FEA_DEFAULT_USE_PLAUNCHER), true)
PRODUCT_PACKAGES += PLauncher
endif

#HZLauncher
ifeq ($(LYCONFIG_DEFAULT_USE_HZLAUNCHER), true)
PRODUCT_PACKAGES += HZLauncher
endif

# i音乐
PRODUCT_PACKAGES += Music

# 文件管理器
ifeq ($(LYCONFIG_APP_LINGYANG_FILEMANAGER), true)
PRODUCT_PACKAGES += ShlyFileExplorer
endif

# 系统浏览器
ifeq ($(LYCONFIG_APP_SYSTEM_BROWSER_SUPPORT), true)
PRODUCT_PACKAGES += Browser
endif

# 手电筒
ifeq ($(LYCONFIG_APP_LINGYANG_FLASH_LIGHT), true)
PRODUCT_PACKAGES += ShlyFlashlight
endif

# 地磁指南针
ifeq ($(CUSTOM_KERNEL_MAGNETOMETER), yes)
PRODUCT_PACKAGES += ShlyCompass
PRODUCT_PROPERTY_OVERRIDES += ro.shly.magnetometer_support=true
else
PRODUCT_PROPERTY_OVERRIDES += ro.shly.magnetometer_support=false
endif

#悬浮窗口
ifeq ($(LYCONFIG_FEA_POPWINDOW_SUPPORT), true)
PRODUCT_PACKAGES += ShlyFloatMultiTask
PRODUCT_PACKAGES += ShlyFloatScreenshot
#PRODUCT_PACKAGES += ShlyFloatVideoView
endif

# 相机 OPPO模式
ifeq ($(LYCONFIG_APP_LINGYANG_OPPO_CAMERA), true)
PRODUCT_PACKAGES += ShlyCamera
else
PRODUCT_PACKAGES += Camera
endif

# 系统搜索
PRODUCT_PACKAGES += QuickSearchBox

# Dialer search provider
PRODUCT_PACKAGES += ShlyProviderReadData

# 日历
PRODUCT_PACKAGES += Calendar

PRODUCT_PACKAGES += DeskClock

#在线主题壁纸
ifeq ($(LYCONFIG_APP_SHLY_IROMTHEME), true)
PRODUCT_PACKAGES += ShlyIRomITheme

#在线主题系统支持
PRODUCT_PACKAGES += ShlyThemeHelper
# 主题
# 多啦A梦
ifeq ($(LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_DORAEMON), true)
PRODUCT_PACKAGES += theme-doraemon-en
endif
# 极致人生
ifeq ($(LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_EXTREME), true)
PRODUCT_PACKAGES += theme-extreme-en
endif
# 清新
ifeq ($(LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_FRESHNESS), true)
PRODUCT_PACKAGES += theme-freshness-en
endif
# 金致
ifeq ($(LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_GOLD), true)
PRODUCT_PACKAGES += theme-gold-en
endif
# 乐视
ifeq ($(LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_LETV), true)
PRODUCT_PACKAGES += theme-letv-en
endif
# 海贼王
ifeq ($(LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_ONEPIECE), true)
PRODUCT_PACKAGES += theme-onepiece-en
endif
# 奇点
ifeq ($(LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_SINGULARITY), true)
PRODUCT_PACKAGES += theme-singularity-en
endif
# 蓝精灵
ifeq ($(LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_SMURFS), true)
PRODUCT_PACKAGES += theme-smurfs-en
endif
# 变形金刚
ifeq ($(LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_TRANSFORMERS), true)
PRODUCT_PACKAGES += theme-transformers-en
endif
# yuan
ifeq ($(LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_YUAN), true)
PRODUCT_PACKAGES += theme-yuan-en
endif
# wait
ifeq ($(LYCONFIG_APP_LINGYANG_MLLED_THEME_SUPPORT_WAIT), true)
PRODUCT_PACKAGES += theme-wait-en
endif

else
PRODUCT_PACKAGES += ShlyWallPaper
endif

# add by kevin for mul_power_anim 20160323 start
ifeq ($(LYCONFIG_FEA_MUL_POWER_ANIM_SUPPORT), true)
PRODUCT_PACKAGES += ShlyBootAnimSwitcher
endif
# add by kevin for mul_power_anim 20160323 end

# 隔空操作
ifeq ($(LYCONFIG_KERNEL_ALSPS_SUPPORT), true)
    ifeq ($(LYCONFIG_FEA_DEFAULT_AIROPERATOR_ADD), true)
        PRODUCT_PACKAGES += ShlyAirOperator
    endif
    PRODUCT_PROPERTY_OVERRIDES += ro.shly.alsps_support=true
else
    PRODUCT_PROPERTY_OVERRIDES += ro.shly.alsps_support=false
endif

ifeq ($(LYCONFIG_APP_MUL_MIFEI), true)
    PRODUCT_PACKAGES += CallerIdSearch
    PRODUCT_PROPERTY_OVERRIDES += ro.support.foreign.callerid=1
endif

# 优普客户定制软件
ifeq ($(LYCONFIG_APP_CUSTOMER_YP_APK), true)
    PRODUCT_PACKAGES += ShlyYpCustomer
endif

# LYCONFIG_COMB_CUST_PROJECT_NAME_FACTORY
endif

PRODUCT_COPY_FILES += resource/common_resource/notification_policy.xml:system/etc/notification_policy.xml
PRODUCT_COPY_FILES += resource/tools/smart_audio.sh:system/bin/smart_audio.sh
