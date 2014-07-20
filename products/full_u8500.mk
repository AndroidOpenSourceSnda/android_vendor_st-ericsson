# Inherit from u8500 device
$(call inherit-product, vendor/st-ericsson/products/u8500.mk)

# Overrides
PRODUCT_BRAND := Bambookphone
PRODUCT_NAME := full_u8500
PRODUCT_DEVICE := u8500
PRODUCT_MANUFACTURER := Bambookphone
PRODUCT_MODEL := Bambook S1

PRODUCT_LOCALES := en_US zh_CN zh_TW
