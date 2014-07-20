LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include -I$(LK_TOP_DIR)/platform/msm_shared

PLATFORM := apq8064

MEMBASE := 0x88F00000 # SDRAM
MEMSIZE := 0x00100000 # 1MB

SCRATCH_ADDR := 0x90000000
SCRATCH_SIZE := 128 #size in MB

KEYS_USE_GPIO_KEYPAD := 1

MODULES += \
	dev/keys \
	dev/ssbi \
	dev/pmic/pm8921 \
	lib/ptable

DEFINES += \
	MEMSIZE=$(MEMSIZE) \
	MEMBASE=$(MEMBASE) \
	SCRATCH_ADDR=$(SCRATCH_ADDR) \
	SCRATCH_SIZE=$(SCRATCH_SIZE)

OBJS += \
	$(LOCAL_DIR)/init.o \
	$(LOCAL_DIR)/atags.o \
	$(LOCAL_DIR)/keypad.o
