#!/system/bin/sh
# give system access to ril_config
cp -f /system/etc/ril_config /data/misc/ril_config
chmod 0660 /data/misc/ril_config
chown root:radio /data/misc/ril_config

# give system access to sterc_script when enabling usb nap
cp -f /system/etc/psdata/sterc_conf /data/misc/psdata/sterc_conf
cp -f /system/etc/psdata/sterc_script_connect /data/misc/psdata/sterc_script_connect
cp -f /system/etc/psdata/sterc_script_disconnect /data/misc/psdata/sterc_script_disconnect
cp -f /system/etc/psdata/sterc_conf_alt /data/misc/psdata/sterc_conf_alt
cp -f /system/etc/psdata/sterc_script_connect_alt /data/misc/psdata/sterc_script_connect_alt
cp -f /system/etc/psdata/sterc_script_connect_dun /data/misc/psdata/sterc_script_connect_dun
cp -f /system/etc/psdata/sterc_script_disconnect_dun /data/misc/psdata/sterc_script_disconnect_dun
chmod 0660 /data/misc/psdata/sterc_conf
chmod 0500 /data/misc/psdata/sterc_script_connect
chmod 0500 /data/misc/psdata/sterc_script_disconnect
chmod 0660 /data/misc/psdata/sterc_conf_alt
chmod 0500 /data/misc/psdata/sterc_script_connect_alt
chmod 0500 /data/misc/psdata/sterc_script_connect_dun
chmod 0500 /data/misc/psdata/sterc_script_disconnect_dun
chown root:radio /data/misc/psdata/sterc_conf
chown root:radio /data/misc/psdata/sterc_conf_alt

# give system access to stepscc_conf
cp -f /system/etc/psdata/stepscc_conf /data/misc/psdata/stepscc_conf
chmod 0660 /data/misc/psdata/stepscc_conf
chown root:radio /data/misc/psdata/stepscc_conf

# Change permissions for modem_log_relay config file
cp -f /system/etc/trace_auto.conf /data/misc/trace_auto.conf
chmod 666 /data/misc/trace_auto.conf

# Modem config file
cp -f /system/etc/telephony_log_levels /data/misc/telephony_log_levels
chmod 0660 /data/misc/telephony_log_levels
chown root:radio /data/misc/telephony_log_levels

