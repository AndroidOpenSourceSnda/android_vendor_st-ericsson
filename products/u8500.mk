# Copyright (C) 2014 The XianGxin
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

# Added platform feature permissions
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.distinct.xml:system/etc/permissions/android.hardware.touchscreen.multitouch.distinct.xml \
    frameworks/native/data/etc/handheld_core_hardware.xml:system/etc/permissions/handheld_core_hardware.xml \
    frameworks/native/data/etc/android.hardware.camera.autofocus.xml:system/etc/permissions/android.hardware.camera.autofocus.xml \
    frameworks/native/data/etc/android.hardware.camera.flash-autofocus.xml:system/etc/permissions/android.hardware.camera.flash-autofocus.xml \
    frameworks/native/data/etc/android.hardware.camera.front.xml:system/etc/permissions/android.hardware.camera.front.xml \
    frameworks/native/data/etc/android.hardware.sensor.gyroscope.xml:system/etc/permissions/android.hardware.sensor.gyroscope.xml \
    frameworks/native/data/etc/android.hardware.sensor.light.xml:system/etc/permissions/android.hardware.sensor.light.xml \
    frameworks/native/data/etc/android.hardware.sensor.proximity.xml:system/etc/permissions/android.hardware.sensor.proximity.xml \
    frameworks/native/data/etc/android.hardware.sensor.barometer.xml:system/etc/permissions/android.hardware.sensor.barometer.xml \
    frameworks/native/data/etc/android.hardware.telephony.gsm.xml:system/etc/permissions/android.hardware.telephony.gsm.xml \
    frameworks/native/data/etc/android.hardware.location.gps.xml:system/etc/permissions/android.hardware.location.gps.xml \
    frameworks/native/data/etc/android.hardware.wifi.xml:system/etc/permissions/android.hardware.wifi.xml \
    frameworks/native/data/etc/android.hardware.wifi.direct.xml:system/etc/permissions/android.hardware.wifi.direct.xml \
    frameworks/native/data/etc/android.hardware.usb.accessory.xml:system/etc/permissions/android.hardware.usb.accessory.xml \
    frameworks/native/data/etc/android.hardware.usb.host.xml:system/etc/permissions/android.hardware.usb.host.xml \
    packages/wallpapers/LivePicker/android.software.live_wallpaper.xml:system/etc/permissions/android.software.live_wallpaper.xml \
    frameworks/native/data/etc/com.stericsson.hardware.fm.receiver.xml:system/etc/permissions/com.stericsson.hardware.fm.receiver.xml \
    frameworks/native/data/etc/com.stericsson.hardware.fm.transmitter.xml:system/etc/permissions/com.stericsson.hardware.fm.transmitter.xml

# ALSA configuration files
PRODUCT_COPY_FILES += \
    external/alsa-lib/src/conf/alsa.conf:system/usr/share/alsa/alsa.conf \
    external/alsa-lib/src/conf/cards/aliases.conf:system/usr/share/alsa/cards/aliases.conf \
    external/alsa-lib/src/conf/pcm/center_lfe.conf:system/usr/share/alsa/pcm/center_lfe.conf \
    external/alsa-lib/src/conf/pcm/default.conf:system/usr/share/alsa/pcm/default.conf \
    external/alsa-lib/src/conf/pcm/dmix.conf:system/usr/share/alsa/pcm/dmix.conf \
    external/alsa-lib/src/conf/pcm/dpl.conf:system/usr/share/alsa/pcm/dpl.conf \
    external/alsa-lib/src/conf/pcm/dsnoop.conf:system/usr/share/alsa/pcm/dsnoop.conf \
    external/alsa-lib/src/conf/pcm/front.conf:system/usr/share/alsa/pcm/front.conf \
    external/alsa-lib/src/conf/pcm/iec958.conf:system/usr/share/alsa/pcm/iec958.conf \
    external/alsa-lib/src/conf/pcm/modem.conf:system/usr/share/alsa/pcm/modem.conf \
    external/alsa-lib/src/conf/pcm/rear.conf:system/usr/share/alsa/pcm/rear.conf \
    external/alsa-lib/src/conf/pcm/side.conf:system/usr/share/alsa/pcm/side.conf \
    external/alsa-lib/src/conf/pcm/surround40.conf:system/usr/share/alsa/pcm/surround40.conf \
    external/alsa-lib/src/conf/pcm/surround41.conf:system/usr/share/alsa/pcm/surround41.conf \
    external/alsa-lib/src/conf/pcm/surround50.conf:system/usr/share/alsa/pcm/surround50.conf \
    external/alsa-lib/src/conf/pcm/surround51.conf:system/usr/share/alsa/pcm/surround51.conf \
    external/alsa-lib/src/conf/pcm/surround71.conf:system/usr/share/alsa/pcm/surround71.conf

# input device configurations and keyboard layouts
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/synaptics_rmi4_i2c.idc:system/usr/idc/synaptics_rmi4_i2c.idc \
    vendor/st-ericsson/u8500/bu21013_ts.idc:system/usr/idc/bu21013_ts.idc \
    vendor/st-ericsson/u8500/cyttsp-spi.idc:system/usr/idc/cyttsp-spi.idc \
    vendor/st-ericsson/u8500/tp_ft5306.idc:system/usr/idc/tp_ft5306.idc \
    vendor/st-ericsson/u8500/STMPE-keypad.kl:system/usr/keylayout/STMPE-keypad.kl \
    vendor/st-ericsson/u8500/tc3589x-keypad.kl:system/usr/keylayout/tc3589x-keypad.kl \
    vendor/st-ericsson/u8500/ux500-ske-keypad.kl:system/usr/keylayout/ux500-ske-keypad.kl \
    vendor/st-ericsson/u8500/ux500-ske-keypad-qwertz.kl:system/usr/keylayout/ux500-ske-keypad-qwertz.kl \
    vendor/st-ericsson/u8500/AB8500_Hs_Button.kl:system/usr/keylayout/AB8500_Hs_Button.kl

# AGPS configuration files
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/LbsConfig.cfg:system/etc/LbsConfig.cfg \
    vendor/st-ericsson/u8500/LbsLogConfig.cfg:system/etc/LbsLogConfig.cfg \
    vendor/st-ericsson/u8500/LbsPgpsConfig.cfg:system/etc/LbsPgpsConfig.cfg \
    vendor/st-ericsson/u8500/LbsPltConfig.cfg:system/etc/LbsPltConfig.cfg \
    vendor/st-ericsson/u8500/cacert.txt:system/etc/cacert.txt

# Media configuration files
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/media_profiles_u8500.xml:system/etc/media_profiles.xml \
    vendor/st-ericsson/u8500/media_codecs_u8500.xml:system/etc/media_codecs.xml

# WI-FI configuration files
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/wpa_supplicant.conf:system/etc/wifi/wpa_supplicant.conf \
    vendor/st-ericsson/u8500/p2p_supplicant.conf:system/etc/wifi/p2p_supplicant.conf \

# DBus configuration files
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/dbus.conf:system/etc/dbus.conf

# Blue-up.sh script
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/blue-up.sh:system/bin/blue-up.sh

# Bluetooth configs
PRODUCT_COPY_FILES += \
    system/bluetooth/data/main.conf:system/etc/bluetooth/main.conf

# CG2900 initialization script
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/cg2900-channel_init.sh:system/bin/cg2900-channel_init.sh

# USB Device ID initialization script
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/usbid_init.sh:system/bin/usbid_init.sh

# RIL initialization script
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/ste_modem.sh:system/etc/ste_modem.sh

# ZRAM initialization script
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/zram_config.sh:system/etc/zram_config.sh

# APN configuration file
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/apns_u8500.xml:system/etc/apns-conf.xml

# Automount SD-Card
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/vold.fstab:system/etc/vold.fstab

# Fstab files
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/fstab.st-ericsson:root/fstab.st-ericsson

# charge resource
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/charge/pic_0.rle:/system/usr/share/charge/res/pic_0.rle \
    vendor/st-ericsson/u8500/charge/pic_1.rle:/system/usr/share/charge/res/pic_1.rle \
    vendor/st-ericsson/u8500/charge/pic_2.rle:/system/usr/share/charge/res/pic_2.rle \
    vendor/st-ericsson/u8500/charge/pic_3.rle:/system/usr/share/charge/res/pic_3.rle \
    vendor/st-ericsson/u8500/charge/pic_4.rle:/system/usr/share/charge/res/pic_4.rle \
    vendor/st-ericsson/u8500/charge/pic_5.rle:/system/usr/share/charge/res/pic_5.rle \
    vendor/st-ericsson/u8500/charge/snda.rle:/system/usr/share/charge/res/snda.rle

# Install script
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/install_bt_core.sh:system/etc/install_bt_core.sh \
    vendor/st-ericsson/u8500/install_wlan_core.sh:system/etc/install_wlan_core.sh \
    vendor/st-ericsson/u8500/install_script.sh:system/etc/install_script.sh

# Custom init / uevent
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/init.rc:root/init.rc \
    vendor/st-ericsson/u8500/init.st-ericsson.rc:root/init.st-ericsson.rc \
    vendor/st-ericsson/u8500/init.st-ericsson.usb.rc:root/init.st-ericsson.usb.rc \
    vendor/st-ericsson/u8500/ueventd.st-ericsson.rc:root/ueventd.st-ericsson.rc

# init.d support
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/prebuilt/common/etc/init.d/00banner:system/etc/init.d/00banner \
    vendor/st-ericsson/u8500/prebuilt/common/bin/sysinit:system/bin/sysinit

# Don't export PS1 in /system/etc/mkshrc.
PRODUCT_COPY_FILES += \
    vendor/st-ericsson/u8500/prebuilt/common/etc/mkshrc:system/etc/mkshrc

# Filesystem management tools
PRODUCT_PACKAGES += \
    make_ext4fs \
    setup_fs \
    e2fsck \
    libext2fs \
    libext2_blkid \
    libext2_uuid \
    libext2_profile \
    libext2_com_err \
    libext2_e2p

# Audio
PRODUCT_PACKAGES += \
    audio_policy.montblanc \
    audio.primary.montblanc \
    audio.usb.default \
    audio.a2dp.default \
    libasound \
    libtinyalsa \
    tinyplay \
    tinycap \
    tinymix \
#    mmprobed \
#    libasf \

# Audio adm
PRODUCT_PACKAGES += \
    admsrv \
    adm.sqlite-u8500_ab8500 \
    ste-adm-test \
    libste_adm \

# Audio configuration files
PRODUCT_PACKAGES += \
    adm-asound.conf \
    preload_adm.txt

# Network
PRODUCT_PACKAGES += \
    libnl

# WIFi crda
PRODUCT_PACKAGES += \
    crda \
    regdbdump \
    regulatory.bin \
#    85-regulatory.rules
#    intersect \

# Camera
PRODUCT_PACKAGES += \
    camera.montblanc \
    tuning_server \
    libZXImg
#    Camera

# Cspsa
PRODUCT_PACKAGES += \
    cspsa-server \
    libcspsa
#    cspsa-cmd \

# Cspsa configuration files
PRODUCT_PACKAGES += \
    cspsa.conf \

# Display
PRODUCT_PACKAGES += \
    copybit.montblanc \
    gralloc.montblanc \
    hwcomposer.montblanc \
    libblt_hw

# GPS
PRODUCT_PACKAGES += \
    gps.montblanc \
    libclientgps \
    liblbstestengine \
    lbsstelp \
    lbsd

# Lights
PRODUCT_PACKAGES += \
    lights.montblanc

# Media
PRODUCT_PACKAGES += \
    libstagefrighthw \
    libstagefright_soft_ste_aacdec \
    libstagefright_soft_ste_mp3dec \
    st-ericsson-multimedia-package

# RIL
PRODUCT_PACKAGES += \
    libu300-ril \
    libu300-parser

# RIL configuration files
PRODUCT_PACKAGES += \
    ril_config

# Sensors
PRODUCT_PACKAGES += \
    sensors.montblanc

# Bass app
PRODUCT_PACKAGES += \
    libbassapp \
    libtee

# Cops
PRODUCT_PACKAGES += \
    copsdaemon \
    cops_cmd \
    libcops \
    cops_ta

# Modem lib
PRODUCT_PACKAGES += \
    libmalcs \
    libmalgpds \
    libmalgss \
    libmalmce \
    libmalmis \
    libmalnet \
    libmalnvd \
    libmalpipe \
    libmalsms \
    libmaluicc \
    libmalutil \
    libmalrf \
    libmalftd \
    libmalmon \
    libmalmte \
    libisimessage \
    libphonet

# Modem
PRODUCT_PACKAGES +=  \
    msa \
    modem-supervisor \
    modem_log_relay \
    ste_mad

# Midem configuration files
PRODUCT_PACKAGES +=  \
    telephony_log_levels \
    trace_auto.conf

# AT-Core
PRODUCT_PACKAGES += \
    at_core

# AT-Core configuration files
PRODUCT_PACKAGES += \
    system_id.cfg \
    manuf_id.cfg \
    model_id.cfg

# Call-Network
PRODUCT_PACKAGES += \
    libcn \
    cn_server \

# Call-Network configuration files
PRODUCT_PACKAGES += \
    plmn.operator.list \
    plmn.latam.list

# SIM
PRODUCT_PACKAGES += \
    simd \
    simpbd

# SMS
PRODUCT_PACKAGES += \
    libsms_server \
    sms_server

# Psdata
PRODUCT_PACKAGES += \
    libmpl \
    libnlcom \
    libpscc \
    libsterc \
    libstecom
    ppp_sterc \
    psccd \
    stercd \
    stepscc_conf \
    sterc_script_connect \
    sterc_script_disconnect \
    sterc_conf \
    sterc_script_connect_alt \
    sterc_conf_alt \
    sterc_script_connect_dun \
    sterc_script_disconnect_dun

# CG2900 GPS/WIFI/FM UART
PRODUCT_PACKAGES += \
    ste-cg29xx_ctrl

# Battery
PRODUCT_PACKAGES += \
    chargemode \
    battery_params \
    startup

# External
PRODUCT_PACKAGES += \
    libarchive \
    libarchive_fe \

# Misc
PRODUCT_PACKAGES += \
    com.android.future.usb.accessory \
    Stk
    Superuser \
    su

# Torch
#PRODUCT_PACKAGES += \
#   Torch

# FM Radio library name is dependent on whether it is RX+TX/RX/TX
# set one of these to true to get RX or TX only
FMRADIO_CG2900_SET_TX_ONLY := false
FMRADIO_CG2900_SET_RX_ONLY := false

ifeq ($(FMRADIO_CG2900_SET_RX_ONLY), true)
    PRODUCT_PACKAGES += libfmradio.cg2900_rx
else
ifeq ($(FMRADIO_CG2900_SET_TX_ONLY), true)
    PRODUCT_PACKAGES += libfmradio.cg2900_tx
else
    PRODUCT_PACKAGES += libfmradio.cg2900
endif
endif

PRODUCT_PROPERTY_OVERRIDES := \
    ro.com.google.clientidbase=android-ste

# Enable AAC 5.1 channel output
PRODUCT_PROPERTY_OVERRIDES += \
    media.aac_51_output_enabled=1 \

# WI-FI interface
PRODUCT_PROPERTY_OVERRIDES += \
    wifi.interface=wlan0

# Set Language
PRODUCT_PROPERTY_OVERRIDES += \
    persist.sys.timezone=Asia/Shanghai \
    persist.sys.language=zh \
    persist.sys.country=CN

# Disable red border
PRODUCT_PROPERTY_OVERRIDES += \
   persist.sys.strictmode.disable=1 \
   persist.sys.strictmode.visual=0

# Enabled Mass Storage Mode
PRODUCT_PROPERTY_OVERRIDES += \
   persist.sys.usb.config=mass_storage,acm,adb

# Enable Debug mode
ADDITIONAL_DEFAULT_PROPERTIES += ro.debuggable=1
ADDITIONAL_DEFAULT_PROPERTIES += ro.secure=0
ADDITIONAL_DEFAULT_PROPERTIES += ro.adb.secure=0
ADDITIONAL_DEFAULT_PROPERTIES += persist.service.adb.enable=1

# This device is hdpi.  However the platform doesn't
# currently contain all of the bitmaps at hdpi density so
# we do this little trick to fall back to the hdpi version
# if the hdpi doesn't exist.
PRODUCT_AAPT_CONFIG := normal hdpi
PRODUCT_AAPT_PREF_CONFIG := hdpi

PRODUCT_PACKAGE_OVERLAYS := vendor/st-ericsson/u8500/overlay

# The gps config appropriate for this device
$(call inherit-product, device/common/gps/gps_eu_supl.mk)
