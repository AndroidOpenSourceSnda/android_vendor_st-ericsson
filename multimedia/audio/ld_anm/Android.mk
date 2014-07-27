LOCAL_PATH := $(call my-dir)

ifeq ($(strip $(BOARD_USES_LD_ANM)),true)

include $(CLEAR_VARS)
LOCAL_MODULE := audio_policy.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES := \
	libste_adm \
	libcutils \
	libstelpcutils \
	libutils \
	libmedia \
	libdl \
	libc

LOCAL_SRC_FILES := \
	src/policy/ste_anm_ap.c \
	src/policy/ste_anm_ext_hal.c \
	src/policy/ste_hal_a2dp.c \
	src/policy/ste_hal_usb.c \
	src/ste_anm_dbg.c \
	src/ste_anm_util.c

LOCAL_CFLAGS := \
	-DLOG_WARNINGS \
	-DLOG_ERRORS \
        -DSTE_VIDEO_CALL \
	-D_POSIX_SOURCE \
	-DUSE_CACHE_MECHANISM \
	-DALLOW_DUPLICATION \
	-DSTD_A2DP_MNGT \
	-DWITH_BLUETOOTH \
	-DWITH_A2DP

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/include \
	$(MULTIMEDIA_PATH)/audio/adm/include \
	$(MULTIMEDIA_PATH)/shared/utils/include \
	hardware/libhardware/include \
	$(call include-path-for, audio-effects)

LOCAL_STATIC_LIBRARIES := \
	libmedia_helper

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := audio.primary.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES := \
	libste_adm \
	libcutils \
	libstelpcutils \
	libutils \
	libmedia \
	libhardware \
	liblog \
	libasound \
	libdl

LOCAL_SRC_FILES := \
	src/ahi/ste_anm_ahi.c \
	src/ahi/ste_anm_ahi_admbase.c \
	src/ahi/ste_anm_ahi_input.c \
	src/ahi/ste_anm_ahi_output.c \
	src/ste_anm_dbg.c \
	src/ste_anm_util.c

LOCAL_CFLAGS := \
	-DLOG_WARNINGS \
	-DLOG_ERRORS \
        -DSTE_VIDEO_CALL \
	-D_POSIX_SOURCE \
	-DUSE_CACHE_MECHANISM \
	-DALLOW_DUPLICATION \
	-DSTD_A2DP_MNGT

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/include \
	$(MULTIMEDIA_PATH)/audio/adm/include \
	$(MULTIMEDIA_PATH)/shared/utils/include \
	hardware/libhardware/include \
	$(call include-path-for, audio-effects)

LOCAL_STATIC_LIBRARIES := \
	libmedia_helper

include $(BUILD_SHARED_LIBRARY)

endif #if BOARD_USES_LD_ANM = TRUE
