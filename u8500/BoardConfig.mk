ENABLE_ST_ERICSSON_BUILD := true

# Include path
TARGET_SPECIFIC_HEADER_PATH := vendor/st-ericsson/include

# Path
ACCESS_SERVICES_PATH := $(TOP)/vendor/st-ericsson/access_services
CONNECTIVITY_PATH := $(TOP)/vendor/st-ericsson/connectivity
MULTIMEDIA_PATH := $(TOPDIR)vendor/st-ericsson/multimedia
PROCESSING_PATH := $(TOP)/vendor/st-ericsson/processing
STORAGE_PATH := $(TOP)/vendor/st-ericsson/storage
BASE_UTILITIES_PATH := $(TOP)/vendor/st-ericsson/base_utilities
TOOLS_PATH := $(TOP)/vendor/st-ericsson/tools
APPS_PATH := $(TOP)/vendor/st-ericsson/apps
HARDWARE_PATH := $(TOP)/vendor/st-ericsson/hardware
EXTERNAL_PATH := $(TOP)/vendor/st-ericsson/external
MODEM_PATH :=$(TOP)/modem/u8500
GRALLOC_PATH := $(HARDWARE_PATH)/libgralloc

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

# ST-Ericsson Hardware
BOARD_USES_STE_HARDWARE := true
COMMON_GLOBAL_CFLAGS += -DSTE_HARDWARE

# Audio
BOARD_USES_ALSA_AUDIO := true
BUILD_WITH_ALSA_UTILS := true
BOARD_USES_LD_ANM := true
COMMON_GLOBAL_CFLAGS += -DSTE_AUDIO

# Bluetooth
BOARD_HAVE_BLUETOOTH := true

# Camera
USE_CAMERA_STUB := false
STE_CAMERA_ENABLE_FEATURE_PLATFORM := u8500
CAMERA_SET_PRIMARY_SENSOR ?= MT9P111
CAMERA_SET_SECONDARY_SENSOR ?= MT9V113
CAMERA_PRIMARY_TYPE = YUV
CAMERA_SECONDARY_TYPE = YUV

# Dumpstate
BOARD_LIB_DUMPSTATE := libdumpstate.montblanc

# FM
BOARD_USES_STE_FM := true
COMMON_GLOBAL_CFLAGS += -DSTE_FM

# Graphics
USE_OPENGL_RENDERER := true

# Lights
TARGET_PROVIDES_LIBLIGHT := true

# Media
TARGET_USE_ST_ERICSSON_MULTIMEDIA := true
MULTIMEDIA_SET_PLATFORM := u8500
include vendor/st-ericsson/multimedia/linux/build/Defs.mk

# GPS
#BOARD_GPS_LIBRARIES := libgps

# WiFi Tethering
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

# Wifi Pcsc
WLAN_SET_PLATFORM := u8500

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

#MM_PACKAGE ?= $(ANDROID_BUILD_TOP)/vendor/st-ericsson/u8500/restricted

#ifeq ($(HOST_OS),linux)
#WITH_DEXPREOPT := false
#endif

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

## PV/MediaPlayer related settings
BUILD_PV_VIDEO_ENCODERS:=1
BUILD_PV_2WAY:=1
BUILD_PV_TEST_APPS:=1
BUILD_WITHOUT_PV:=false

## ENABLE STAGEFRIGHT and STE CODECS IN STAGEFRIGHT
BUILD_WITH_FULL_STAGEFRIGHT:=true
STE_CODECS_IN_STAGEFRIGHT:=true

# To enable AT parser plugin
AT_PLUGIN_ON := false

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
ADM_DISABLE_FEATURE_CSCALL := true

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
MMPROBE_ENABLE_FEATURE_MMPROBE := false
CSCALL_ENABLE_SILENT_REBOOT_SUPPORT := true

# SurfaceFlinger configuration
# Enable dim with texture
SF_ENABLE_FEATURE_DIM_WITH_TEXTURE := true
# Enable frame buffer rotation
SF_ENABLE_FEATURE_FB_ROTATION := true

# Enable tripple buffered main display frame buffer
BOARD_NUM_FRAME_BUFFERS := 3

# Enable build of fm radio vendor library
FMRADIO_CG2900_ENABLE_FEATURE_VENDOR_DRIVE := true

# CG29XX Configuration
STE_CG29XX_CTRL_ENABLE_FEATURE_STE_CG29XX_CTRL := true
