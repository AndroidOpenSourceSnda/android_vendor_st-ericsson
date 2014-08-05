# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# call dalvik heap config
$(call inherit-product, frameworks/native/build/phone-xhdpi-1024-dalvik-heap.mk)

# Firmware
$(call inherit-product-if-exists, vendor/st-ericsson/kernel-firmware/copy_files.mk)

# Copy files for modules
$(call inherit-product-if-exists, vendor/st-ericsson/processing/security_framework/bass_app/libbassapp/ta/copy_files.mk)

# Inherit from u8500 device
$(call inherit-product, vendor/st-ericsson/products/u8500.mk)

# Overrides
PRODUCT_BRAND := Bambookphone
PRODUCT_NAME := s1w_u8500
PRODUCT_DEVICE := u8500
PRODUCT_MANUFACTURER := Bambookphone
PRODUCT_MODEL := Bambook S1

PRODUCT_LOCALES := en_US zh_CN zh_TW
