T=$(gettop)
if [ -e $T/vendor/st-ericsson/u8500/BoardConfig.mk ]; then
  add_lunch_combo s1w_u8500-userdebug
  add_lunch_combo s1w_u8500-user
fi

if [ -e $T/vendor/st-ericsson/multimedia/linux/build/mmbuild.sh ]; then
  echo "including vendor/st-ericsson/multimedia/linux/build/mmbuild.sh"
  source $T/vendor/st-ericsson/multimedia/linux/build/mmbuild.sh
fi
