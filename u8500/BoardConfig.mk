ENABLE_ST_ERICSSON_BUILD := true

# Include path
TARGET_SPECIFIC_HEADER_PATH := vendor/st-ericsson/include

# Assert
TARGET_OTA_ASSERT_DEVICE := u8500,s1w_u8500
TARGET_RELEASETOOL_OTA_FROM_TARGET_SCRIPT := vendor/st-ericsson/u8500/releasetools/snda_ota_from_target_files

# Bootloader
TARGET_BOOTLOADER_BOARD_NAME := montblanc
TARGET_NO_BOOTLOADER := true
TARGET_NO_RADIOIMAGE := true

# Platform
TARGET_BOARD_PLATFORM := montblanc

# Architecture
TARGET_ARCH := arm
TARGET_ARCH_VARIANT := armv7-a-neon
TARGET_CPU_ABI := armeabi-v7a
TARGET_CPU_ABI2 := armeabi
TARGET_CPU_SMP := true
TARGET_CPU_VARIANT := cortex-a9
ARCH_ARM_HAVE_TLS_REGISTER := true

# Kernel information
BOARD_KERNEL_BASE := 0x00000000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_KERNEL_CMDLINE := androidboot.hardware=st-ericsson
BOARD_FORCE_RAMDISK_ADDRESS := 0x02000000
TARGET_KERNEL_SOURCE := kernel/snda/u8500
TARGET_KERNEL_CONFIG := cm_u8500_defconfig
#TARGET_USE_ST_ERICSSON_KERNEL := true

# ST-Ericsson Hardware
BOARD_USES_STE_HARDWARE := true
COMMON_GLOBAL_CFLAGS += -DSTE_HARDWARE

# Audio
BOARD_USES_ALSA_AUDIO := true
BUILD_WITH_ALSA_UTILS := true
BOARD_USES_LD_ANM := true
BOARD_USES_C_AUDIO_HAL := true
A2DP_USES_STANDARD_ANDROID_PATH := true
COMMON_GLOBAL_CFLAGS += -DSTE_AUDIO

# Bluetooth
BOARD_HAVE_BLUETOOTH := true
#BOARD_HAVE_STE_BLUETOOTH := true

# Camera
USE_CAMERA_STUB := false
STE_CAMERA_ENABLE_FEATURE_PLATFORM := u8500
CAMERA_SET_PRIMARY_SENSOR ?= MT9P111
CAMERA_SET_SECONDARY_SENSOR ?= MT9V113
CAMERA_PRIMARY_TYPE = YUV
CAMERA_SECONDARY_TYPE = YUV

# FM
BOARD_USES_STE_FM := true
COMMON_GLOBAL_CFLAGS += -DSTE_FM

# Graphics
USE_OPENGL_RENDERER := true
# Build OpenGLES emulation guest and host libraries
#BUILD_EMULATOR_OPENGL := true

# Lights
LIBLIGHTS_SET_PLATFORM := u8500

# Media
TARGET_USE_ST_ERICSSON_MULTIMEDIA := true

# Sensors
LIBSENSORS_SET_PLATFORM := u8500

# GPS
BOARD_GPS_LIBRARIES := libgps

# Enable STE WiFi Tethering/SoftAPController
WLAN_ENABLE_STE_WIFI_TETHERING := true

# WiFi Configuration
WPA_SUPPLICANT_VERSION := VER_0_8_X
BOARD_WPA_SUPPLICANT_DRIVER := NL80211

# Wifi Mac Fixed from cspsa
WIFI_MAC_ADDR_CSPSA := true

# Wifi drivers
WIFI_DRIVER_MODULE_NAME := cw1200_wlan
WIFI_DRIVER_MODULE_PATH := /system/lib/modules/cw1200_wlan.ko
WIFI_DRIVER_LOADER_DELAY := 1000000

#WLAN_ENABLE_OPEN_MAC_SOLUTION := true
#STE_WLAN_DRIVER := true
#WLAN_ENABLE_WAPI := true
WLAN_SET_PLATFORM := u8500
#WLAN_SET_DRIVER_MODULE_CORE_NAME := cw1200_core
#WIFI_TEST_INTERFACE := wlan0
#WLAN_ENABLE_FEATURE_CSPSA := true
#WLAN_SET_DUALBAND := false

# Filesystem
TARGET_USERIMAGES_USE_EXT4 := true
TARGET_PARTITIONS_USE_TOC := true
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_FLASH_BLOCK_SIZE := 4096

# Flash Partition sizes
BOARD_RAMDISKIMAGE_PARTITION_SIZE := 10485760
BOARD_BOOTIMAGE_PARTITION_SIZE := 8388608
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 340787200
BOARD_USERDATAIMAGE_PARTITION_SIZE := 1170210816
BOARD_CACHEIMAGE_PARTITION_SIZE := 134217728
BOARD_MODEMIMAGE_PARTITION_SIZE := 8388608
BOARD_MISCIMAGE_PARTITION_SIZE := 4096

# RIL
TARGET_USE_VENDOR_RIL := true

# Init
TARGET_PROVIDES_INIT_RC := true

# Vold
BOARD_VOLD_MAX_PARTITIONS := 8

# Recovery information
TARGET_PROVIDES_RECOVERY_INIT_RC := true

TARGET_USE_CUSTOM_LUN_FILE_PATH := "/sys/devices/soc0/musb-ux500.0/musb-hdrc/gadget/lun%d/file"

MM_PACKAGE ?= $(ANDROID_BUILD_TOP)/vendor/st-ericsson/u8500/restricted

#TARGET_SHELL := ash

ifeq ($(HOST_OS),linux)
WITH_DEXPREOPT := false
endif

# Set to true for platforms with 32 byte L2 cache line.
# Set to false for platforms with 64 byte L2 cache line.
ARCH_ARM_HAVE_32_BYTE_CACHE_LINES := true

# Set to true for CPUs with the Control Register (c1) A-bit set to zero
# allowing unaligned access for NEON memory instructions.
ARCH_ARM_NEON_SUPPORTS_UNALIGNED_ACCESS := true

# Sets the upper size limit for NEON unaligned memory access in memcpy.
# For sizes smaller than this, no pre-alignment is made before the main loop.
# This has no effect unless ARCH_ARM_NEON_UNALIGNED_ACCESS is also set to true.
BIONIC_MEMCPY_ALIGNMENT_DIVIDER := 224

# Sets the lower size limit for ARM implementation of memcpy.
# For sizes larger than this, the ARM version of memcpy is
# used when source and destination are aligned.
BIONIC_MEMCPY_ARM_DIVIDER := 128

# Sets the upper size limit for NEON implementation of memset.
# For sizes larger than this, the ARM version of memset is used.
BIONIC_MEMSET_NEON_DIVIDER := 132

# Sets the upper size limit for NEON implementation of memset32.
# For sizes larger than this, the ARM version of memset32 is used.
LIBCUTILS_MEMSET32_NEON_DIVIDER := 158

CROSS_COMPILE := arm-eabi-

#####################################################################
# STELP paths

ACCESS_SERVICES_PATH := $(TOP)/vendor/st-ericsson/access_services
CONNECTIVITY_PATH := $(TOP)/vendor/st-ericsson/connectivity
MULTIMEDIA_PATH := $(TOPDIR)vendor/st-ericsson/multimedia
PROCESSING_PATH := $(TOP)/vendor/st-ericsson/processing
STORAGE_PATH := $(TOP)/vendor/st-ericsson/storage
#BOOT_PATH := $(TOP)/vendor/st-ericsson/boot
BASE_UTILITIES_PATH := $(TOP)/vendor/st-ericsson/base_utilities
TOOLS_PATH := $(TOP)/vendor/st-ericsson/tools
BUILD_PATH := $(TOP)/vendor/st-ericsson/build
APPS_PATH := $(TOP)/vendor/st-ericsson/apps
HARDWARE_PATH := $(TOP)/vendor/st-ericsson/hardware
EXTERNAL_PATH := $(TOP)/vendor/st-ericsson/external
MODEM_PATH :=$(TOP)/modem/u8500
GRALLOC_PATH := $(HARDWARE_PATH)/libgralloc

# Dumpstate
BOARD_LIB_DUMPSTATE=libdumpstate

################################################################################
## PV/MediaPlayer related settings
BUILD_PV_VIDEO_ENCODERS:=1
BUILD_PV_2WAY:=1
BUILD_PV_TEST_APPS:=1
BUILD_WITHOUT_PV:=false

################################################################################
## ENABLE STAGEFRIGHT and STE CODECS IN STAGEFRIGHT
BUILD_WITH_FULL_STAGEFRIGHT:=true
STE_CODECS_IN_STAGEFRIGHT:=true

################################################################################

# To enable AT parser plugin
AT_PLUGIN_ON := false

# Kernel firmware settings
KERNEL_FIRMWARE_ENABLE_FEATURE_BT := true
KERNEL_FIRMWARE_ENABLE_FEATURE_FM := true
KERNEL_FIRMWARE_ENABLE_FEATURE_WLAN := true
KERNEL_FIRMWARE_ENABLE_FEATURE_HDMI := true

ifeq ($(TARGET_USE_ST_ERICSSON_MULTIMEDIA),true)

  # Set Multimdia platform
  MULTIMEDIA_SET_PLATFORM := u8500

  # Get some useful variables to build
  include $(MULTIMEDIA_PATH)/linux/build/Defs.mk

endif

# RIL configuration
RIL_ENABLE_FEATURE_RIL := true
RIL_ENABLE_FEATURE_CAIF := false
RIL_ENABLE_FEATURE_DUAL_CHANNELS := true
RIL_ENABLE_FEATURE_GPRS_AUTO_ATTACH := true
RIL_ENABLE_FEATURE_SMS_PHASE_2_PLUS := true
RIL_ENABLE_FEATURE_FDN_SERVICE_AVAILABILITY := false
# FIXME: remove when RIL is merged
RIL_ENABLE_FEATURE_U8500 := true

# AT-Core configuration
ATC_ENABLE_FEATURE_ATC := true
ATC_ENABLE_FEATURE_CN := true
ATC_ENABLE_FEATURE_AUDIO := true
ATC_ENABLE_FEATURE_COPS := true
ATC_ENABLE_FEATURE_PSCC := true
ATC_ENABLE_FEATURE_SIM := true
ATC_ENABLE_FEATURE_SMS := true
ATC_ENABLE_FEATURE_CSPSA := true
ATC_ENABLE_FEATURE_ATC_CUSTOMER_EXTENSIONS := false
ATC_ENABLE_FEATURE_FTD := true
ATC_ENABLE_FEATURE_SIMPB := false
ATC_ENABLE_FEATURE_AUDIO_LEGACY := false

# Call-network configuration
CN_ENABLE_FEATURE_CN := true
CN_SET_FEATURE_BACKEND := MAL
CN_ENABLE_FEATURE_FTD := true
CN_DISABLE_BLACKLIST_IN_MODEM := true
CN_REMOVE_PLUS_IN_DIAL_STRING := false

# PSDATA configuration
PSDATA_STEPSCC_SET_MODEM_BEARER := MAL
PSDATA_ENABLE_FEATURE_PSCC_CONF := true
PSDATA_ENABLE_FEATURE_STERC_CONF := true

# Modem Access Daemon configuration
CN_ENABLE_FEATURE_MAD := true

## Add modem specific file system contents into root file system image for
## U8500 to satisfy expectations from NWM.
NWM_ENABLE_FEATURE_MODEMFS := true

# Path to modemfs, used when creating modemfs.img and cspsa image
NWM_MODEMFS_PATH := $(MODEM_PATH)/modemfs

## Enable Modem Storage Agent so that it can serve file system requests
## from the NWM modem.
MSA_ENABLE_FEATURE_MSA := true

# SIM configuration
SIM_ENABLE_FEATURE_SIM := true
SIM_SET_FEATURE_BACKEND := MAL
## If SIM_ENABLE_SAT_BIP_SUPPORT is true it means that the terminal profile will be
## override and set Byte:Bit 6:3,4; 12:1,2,3,4,5; 13:6,7,8; 17:1,2,3,4,5;
SIM_ENABLE_SAT_BIP_SUPPORT := false
SIM_SET_POLL_INTERVALL := 300
## If SIM_ENABLE_SAT_PLI_LANGUAGE_SUPPORT is true it meant that terminal profile will be
## override and set Byte:Bit 9:4.
SIM_ENABLE_SAT_PLI_LANGUAGE_SUPPORT := false
## If SIM_ENABLE_SAT_EVENT_LANGUAGE_SUPPORT is true it meant that terminal profile will be
## override and set Byte:Bit 6:1.
SIM_ENABLE_SAT_EVENT_LANGUAGE_SUPPORT := false
SIM_ENABLE_MNC_LENGTH_CHECK_SUPPORT := false
SIM_ENABLE_PIN_CACHE_FOR_MSR := true
SIM_ENABLE_FEATURE_SIMPB := true

## Path to SIM detect file that will be written to when a SIM is either inserted or removed.
## 1 for removed and 0 for inserted.
SIM_DETECT_PATH := ""
## The whole terminal profile as a byte array, Starts with first byte (FF, all bits in that byte
## are set and ends with Thirtieth byte (00). ref; 3GPP ETSI TS 102223, chapter 5.2 Structure and
## coding of TERMINAL PROFILE when coming to change it. Note! It's the same terminal profile for
## both 2G and 3G cards.
SIM_SET_TERMINAL_PROFILE := "FFFFFFFF1F9000DfB703FE00021FFFE680EB0F000002400000000000000000"

## The default Adapt terminal support table file.
SIM_SET_ADAPT_TERMINAL_SUPPORT_TABLE := "FFFFFFFFFF000000"

## EVENT DOWNLOAD Envelope is not sent to CARD between a Proactive Command and its TR.
## This ensures that an ENVELOPE (EVENT DOWNLOAD in this case and can be generalized for
## all Envelopes) is not sent to CARD between a Proactive Command and its Terminal Response.
## This is required for specific SIM (e.g.Oberthur SIM) otherwise SIM stops to respond further.
SIM_ENABLE_SAT_ENV_NO_INTERLEAVING_SUPPORT := false

# Use the default value of dirty Ratio which is set by kernel
USB_USE_DEFAULT_DIRTY_RATIO := true

# SMS configuration
SMS_ENABLE_FEATURE_SMS := true
SMS_SET_FEATURE_BACKEND := MAL
SMS_ENABLE_FEATURE_MO_ROUTE := CS_PS

# MAL configuration
MAL_NET_OPERATOR_CODE_ECC_NUMBER_CHECK := false

## Select what ADM-version to build when building for U8500
ADM_VERSION := u8500

## Set true to exclude ADM cscall functionality
## Set false to include ADM cscall functionality
ADM_DISABLE_FEATURE_CSCALL := false

# Set u8500 as platform type in COPS
COPS_PLATFORM_TYPE := 8500

# Set u8500 signing in Bass App
BASS_APP_SET_SIGNING := 8500

## Add Core Platform Security functionalities
COPS_SET_SECURE_WORLD := secure
COPS_SET_STORAGE := cspsa
COPS_ENABLE_SILENT_REBOOT_SUPPORT := true

## Set true to enable arb update in cops when not using LK as bootloader
## Set false to disable arb update in cops when using LK as bootloader
COPS_ENABLE_ARB_UPDATE := true

## Add Basic Security Services(BASS) functionalities
BASS_APP_ENABLE_FEATURE_BASS_APP := true

# Select for STE OMX JPEG decoder in SKIA and MediaServer
STE_JPEGDEC_ENABLE_FEATURE_STE_JPEGDEC := true

# Set Modem adaptation configuration for LBS module.
LBS_SET_MODEMCLIENT := MAL

# Select for cell information source : Modem or Application framework
LBS_SET_MODEM_CELLINFO_SUPPORT := true

# Set GNSS CHIP in use for LBS module.Default value: CG2900, Need to make it CG2910 if that is the chip supported
LBS_SET_GNSSCHIP_VER := CG2900

# Enable speech and audio probes
# WARNING: This feature should be disabled (set to false) in production software
MMPROBE_ENABLE_FEATURE_MMPROBE := true
CSCALL_ENABLE_SILENT_REBOOT_SUPPORT := true

# SurfaceFlinger configuration
# Enable dim with texture
SF_ENABLE_FEATURE_DIM_WITH_TEXTURE := true
# Enable frame buffer rotation
SF_ENABLE_FEATURE_FB_ROTATION := true

# Enable tripple buffered main display frame buffer
BOARD_NUM_FRAME_BUFFERS := 3

# Set hwconfig to use in flashkit
#FLASHKIT_SET_HWCONFIG := u8500

# set TARGET_HW to use in sign_tool_cli
#TARGET_HW:=hrefp_v22_v1x_db8500b0_secst_1ghz_glacier_hz3

# Enable build of fm radio vendor library
FMRADIO_CG2900_ENABLE_FEATURE_VENDOR_DRIVE := true



# ISSW Configuration
#ISSW_ENABLE_FEATURE_SIGN_IMAGES ?= false

# XLOADER settings
#XLOADER_SET_PLATFORM := u8500

# SOC-SETTINGS settings
#SOC_SETTINGS_SET_PLATFORM := u8500

# Documentation settings
#REFMAN_ENABLE_FEATURE_REFMAN_GEN := true
#REFMAN_SET_UML_EXPORT_XML := $(abspath $(TOP)/vendor/st-ericsson/u8500/uml-export/ste-uml-export.xml)

# CG29XX Configuration
STE_CG29XX_CTRL_ENABLE_FEATURE_STE_CG29XX_CTRL := true

# Windows USB Host Drivers
#USB_PC_DRIVERS_SET_DRIVERS := STE-Linux-platform-usb-drivers-windows.zip

# CSPSA settings
CSPSA_SET_DEFAULT_CSPSA_IMAGES := u8500_default_cspsa.bin u8500_default_cspsa.gdf
CSPSA_IMAGE_ENABLE_MODEM_PARAMETERS ?= true

# Pickup the right bluetooth's Sim Access Profile backend driver
# Available values: MAL, CAIF
BLUETOOTH_ENABLE_FEATURE_SAP_BACKEND := MAL

#####################################################################
# Add/remove/etc. files just prior to generating Android's file system images

#PATCHTOP := $(BUILD_PATH)/ste_image/fs_patches
#APPLY_FS_PATCHES := $(BUILD_PATH)/ste_image/apply_fs_patches.sh

#PATCH_VARS += TOPLEVEL=$(realpath $(TOP)) KERNELDIR=kernel INSTALL_MOD_PATH=$(PRODUCT_OUT)/system KERNEL_OUTPUT=$(KERNEL_OUTPUT)

#patch-systemimage:
#	$(hide) $(APPLY_FS_PATCHES) PATCHDIR=$(PATCHTOP)/system VOLUMEDIR=$(PRODUCT_OUT)/system $(PATCH_VARS)

#patch-userdataimage:
#	$(hide) $(APPLY_FS_PATCHES) PATCHDIR=$(PATCHTOP)/userdata VOLUMEDIR=$(PRODUCT_OUT)/userdata $(PATCH_VARS)

#patch-ramdiskimage:
#	$(hide) $(APPLY_FS_PATCHES) PATCHDIR=$(PATCHTOP)/ramdisk VOLUMEDIR=$(PRODUCT_OUT)/ramdisk $(PATCH_VARS)
#
#patch-cacheimage:
#	$(hide) $(APPLY_FS_PATCHES) PATCHDIR=$(PATCHTOP)/cache VOLUMEDIR=$(PRODUCT_OUT)/cache $(PATCH_VARS)

#####################################################################

# Create cache.img and misc.img
#droidcore: cacheimage miscimage

# Create misc.img
#.PHONY: miscimage
#miscimage: $(PRODUCT_OUT)/misc.img

#$(PRODUCT_OUT)/misc.img:
#	dd if=/dev/zero of=$(PRODUCT_OUT)/misc.img bs=$(BOARD_MISCIMAGE_PARTITION_SIZE) count=1

# setup flash configuration files
#CREATE_FILELISTS := $(FLASHKIT_CONFIG_PATH)/createfilelists.sh
#CREATE_FILELISTS_FLASHER := $(FLASHKIT_CONFIG_PATH)/createfilelists-flasher.sh

#.PHONY: setup-flashconfig
#setup-flashconfig:
#	cp -f $(FLASHKIT_CONFIG_PATH)/config.list $(FLASHKIT_INSTALL_BASE)/
#	cp -f $(FLASHKIT_CONFIG_PATH)/flasharchive.xml $(FLASHKIT_INSTALL_BASE)/
#	cp -f $(FLASHKIT_CONFIG_PATH)/flashlayout.txt $(FLASHKIT_INSTALL_BASE)/
#Create paths for flashkit, first for old flashkit scripts solution and then for new "flasher" script.
#The paths only differ in that the old scripts needs "../../" first
#	$(CREATE_FILELISTS) -d $(FLASHKIT_INSTALL_BASE) -p ../../$(FLASHKIT_RELATIVE_SPLASHPATH) -n $(FLASHKIT_ENABLE_MODEMINFILELIST) -a ../../$(filter %.bin,$(CSPSA_SET_DEFAULT_CSPSA_IMAGES))
#	$(CREATE_FILELISTS_FLASHER) -d $(FLASHKIT_INSTALL_BASE) -p ./$(FLASHKIT_RELATIVE_SPLASHPATH) -n $(FLASHKIT_ENABLE_MODEMINFILELIST) -a $(filter %.bin,$(CSPSA_SET_DEFAULT_CSPSA_IMAGES))

#st-ericsson-flashkit: setup-flashconfig

#ifeq ($(FLASHKIT_ENABLE_ST_ERICSSON_FLASHKIT), true)
#systemimage: st-ericsson-flashkit
#endif

#$(PRODUCT_OUT)/kernel: $(PRODUCT_OUT)/uImage
#	ln -sf zImage $@

# Collect loadmodules and flashkit and place them nicely in a common directory

#systemimage: collect-loadmodules

#files: init-symlinks
#init-symlinks:
#	@echo "Symlink: $(TARGET_ROOT_OUT)/ueventd.st-ericssonmop500platform.rc -> ./ueventd.st-ericsson.rc"
#	@mkdir -p $(TARGET_ROOT_OUT)
#	$(hide) ln -sf ./ueventd.st-ericsson.rc $(TARGET_ROOT_OUT)/ueventd.st-ericssonmop500platform.rc
#	@echo "Symlink: $(TARGET_ROOT_OUT)/ueventd.st-ericssonu8500platformhrefv60.rc -> ./ueventd.st-ericsson.rc"
#	$(hide) ln -sf ./ueventd.st-ericsson.rc $(TARGET_ROOT_OUT)/ueventd.st-ericssonu8500platformhrefv60.rc
#	@echo "Symlink: $(TARGET_ROOT_OUT)/ueventd.st-ericssona9500platform.rc -> ./ueventd.st-ericsson.rc"
#	$(hide) ln -sf ./ueventd.st-ericsson.rc $(TARGET_ROOT_OUT)/ueventd.st-ericssona9500platform.rc
#	@echo "Symlink: $(TARGET_ROOT_OUT)/init.st-ericssonmop500platform.rc -> ./init.st-ericsson.rc"
#	$(hide) ln -sf ./init.st-ericsson.rc $(TARGET_ROOT_OUT)/init.st-ericssonmop500platform.rc
#	@echo "Symlink: $(TARGET_ROOT_OUT)/init.st-ericssonu8500platformhrefv60.rc -> ./init.st-ericsson.rc"
#	$(hide) ln -sf ./init.st-ericsson.rc $(TARGET_ROOT_OUT)/init.st-ericssonu8500platformhrefv60.rc
#	@echo "Symlink: $(TARGET_ROOT_OUT)/init.st-ericssona9500platform.rc -> ./init.st-ericsson.rc"
#	$(hide) ln -sf ./init.st-ericsson.rc $(TARGET_ROOT_OUT)/init.st-ericssona9500platform.rc
#	@echo "Symlink: $(TARGET_ROOT_OUT)/init.st-ericssonmop500platform.usb.rc -> ./init.st-ericsson.usb.rc"
#	$(hide) ln -sf ./init.st-ericsson.usb.rc $(TARGET_ROOT_OUT)/init.st-ericssonmop500platform.usb.rc
#	@echo "Symlink: $(TARGET_ROOT_OUT)/init.st-ericssonu8500platformhrefv60.usb.rc -> ./init.st-ericsson.usb.rc"
#	$(hide) ln -sf ./init.st-ericsson.usb.rc $(TARGET_ROOT_OUT)/init.st-ericssonu8500platformhrefv60.usb.rc
#	@echo "Symlink: $(TARGET_ROOT_OUT)/init.st-ericssona9500platform.usb.rc -> ./init.st-ericsson.usb.rc"
#	$(hide) ln -sf ./init.st-ericsson.usb.rc $(TARGET_ROOT_OUT)/init.st-ericssona9500platform.usb.rc



#COLLECT_LOADMODULES := $(BUILD_PATH)/ste_image/collect-loadmodules.sh
#COLLECT_LOADMODULES_DELIMITER := :

#.PHONY: collect-loadmodules
#collect-loadmodules: $(PRODUCT_OUT)/system.img $(PRODUCT_OUT)/boot.img $(PRODUCT_OUT)/recovery.img $(PRODUCT_OUT)/misc.img
#	$(hide) $(COLLECT_LOADMODULES) PRODUCT_OUT=$(PRODUCT_OUT) TOP=$(TOP) \
#	 KERNEL_OUTPUT=$(KERNEL_OUTPUT_RELATIVE) \
#	 UBOOT_OUTPUT=$(UBOOT_OUTPUT) \
#	 LK_OUTPUT=$(LK_OUTPUT) \
#	 KERNEL_DEFCONFIG=$(KERNEL_DEFCONFIG) \
#	 FLASHKIT_INSTALL_PATH=$(FLASHKIT_INSTALL_PATH) \
#	 SPLASH_IMAGE_PATH=${UBOOT_SPLASH_IMAGE_OUTPUT} \
#	 USB_PC_DRIVERS_SET_DRIVERS=$(USB_PC_DRIVERS_SET_DRIVERS) \
#	 DEFAULT_CSPSA_IMAGES=$(subst $(COLLECT_LOADMODULES_DELIMITER) ,$(COLLECT_LOADMODULES_DELIMITER),$(addsuffix $(COLLECT_LOADMODULES_DELIMITER),$(CSPSA_SET_DEFAULT_CSPSA_IMAGES))) \
#	 DELIMITER=$(COLLECT_LOADMODULES_DELIMITER)

#.PHONY: collect-loadmodules-nodeps
#collect-loadmodules-nodeps: systemimage-nodeps
#	$(hide) $(COLLECT_LOADMODULES) PRODUCT_OUT=$(PRODUCT_OUT) TOP=$(TOP) \
#	 KERNEL_OUTPUT=$(KERNEL_OUTPUT_RELATIVE) \
#	 UBOOT_OUTPUT=$(UBOOT_OUTPUT) \
#	 LK_OUTPUT=$(LK_OUTPUT) \
#	 KERNEL_DEFCONFIG=$(KERNEL_DEFCONFIG) \
#	 FLASHKIT_INSTALL_PATH=$(FLASHKIT_INSTALL_PATH) \
#	 SPLASH_IMAGE_PATH=${UBOOT_SPLASH_IMAGE_OUTPUT} \
#	 USB_PC_DRIVERS_SET_DRIVERS=$(USB_PC_DRIVERS_SET_DRIVERS) \
#	 DEFAULT_CSPSA_IMAGES=$(subst $(COLLECT_LOADMODULES_DELIMITER) ,$(COLLECT_LOADMODULES_DELIMITER),$(addsuffix $(COLLECT_LOADMODULES_DELIMITER),$(CSPSA_SET_DEFAULT_CSPSA_IMAGES))) \
#	 DELIMITER=$(COLLECT_LOADMODULES_DELIMITER)

# Select u-boot configuration
#ENABLE_BUILD_UBOOT := false

#ifeq ($(ENABLE_FEATURE_BUILD_HBTS),true)
#UBOOT_DEFCONFIG := u8500_hbts_config
#else
#UBOOT_DEFCONFIG ?= u8500_def_config
#endif
#UBOOT_SET_SPLASH_IMAGE := $(BOOT_PATH)/u-boot/tools/logos/stericsson.bmp
# Set input and output variables for u-boot environment parameter image
#BUILD_UBOOT_ENV_IMG_INPUT := $(TOP)/vendor/st-ericsson/u8500/uboot_envparameters_android.cfg
#BUILD_UBOOT_ENV_IMG_OUTPUT := $(UBOOT_OUTPUT)/u-boot-env.bin

# Set input and output variables for lk environment parameter image
#BUILD_LK_ENV_IMG_INPUT := $(TOP)/vendor/st-ericsson/u8500/lk_envparameters_android.cfg
#BUILD_LK_ENV_IMG_OUTPUT := $(LK_OUTPUT)/lk_env.bin
#BUILD_LK_TARGET := href500
####################################################################

####################################################################
# KERNEL, WLAN, UBOOT & LK OUTPUT dirs

#KERNEL_OUTPUT_RELATIVE := $(TARGET_OUT_INTERMEDIATES)/kernel
#KERNEL_OUTPUT := $(abspath $(KERNEL_OUTPUT_RELATIVE))
#UBOOT_OUTPUT := $(TARGET_OUT_INTERMEDIATES)/uboot
#LK_OUTPUT := $(TARGET_OUT_INTERMEDIATES)/lk
# If the UBOOT_SPLASH_IMAGE_OUTPUT variable is changed the copy
# in ste_uxx00.mk (vendor/st-ericsson/products) also needs to be updated
#UBOOT_SPLASH_IMAGE_OUTPUT := splash.bin
#WLAN_OUTPUT = $(abspath $(TARGET_OUT_INTERMEDIATES)/wlan)
####################################################################

###############################################################################
## FLASHKIT SETTINGS
#FLASHKIT_ENABLE_ST_ERICSSON_FLASHKIT := true
#FLASHKIT_INSTALL_PATH := $(PRODUCT_OUT)
#FLASHKIT_INSTALL_BASE := $(abspath $(FLASHKIT_INSTALL_PATH))
#FLASHKIT_RELATIVE_SPLASHPATH := $(UBOOT_SPLASH_IMAGE_OUTPUT)
#FLASHKIT_RELATIVE_MODEMDIRPATH := ../../modem_images/
#FLASHKIT_ENABLE_MODEMINFILELIST := true
#FLASHKIT_CONFIG_PATH ?= $(TOP)/vendor/st-ericsson/u8500/flashconfig
#ANT_HOME=$(abspath $(TOOLS_PATH)/community/apache_ant)
#ANT4ECLIPSE_HOME=$(abspath $(TOOLS_PATH)/community/ant4eclipse)
################################################################################

################################################################################



# For boot.img:
# Kernel will be loaded to this address + 0x00008000
# Ramdisk will be loaded to this address + 0x02000000
#BOARD_KERNEL_BASE := 0



###############################################################################

## Module configuration flags ##

#<MODULE_NAME>_ENABLE_FEATURE_<FEATURE_NAME_u8500> := true

# Enable signature verification features necessary for production fused hw
#ifeq (true,$(ENABLE_FEATURE_SIGNATURE_VERIFICATION))
#Add signature verification related module flags
#ISSW_ENABLE_FEATURE_SIGN_IMAGES := true
#UBOOT_ENABLE_FEATURE_SECBOOT := true
#endif

# Kernel configuration
#KERNEL_DEFCONFIG ?= ux500_ux540_defconfig

