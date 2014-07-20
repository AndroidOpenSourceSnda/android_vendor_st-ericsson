/*******************************************************************************
*                                                                              *
*       File Name:      taos_common.h                                          *
*       Description:    Common file for ioctl and configuration definitions.   *
*       		Used by kernel driver and driver access applications.  *
*       		Please include this file, and <sys/ioctl.h> in your    *
*                       driver access application program source.	       *
*       Author:         John Koshi                                             *
*       History:        09/16/2009 - Initial creation                          *
*       		02/07/2010 - Add proximity			       *
*                                                                              *
*******************************************************************************/
// ioctl numbers
#define TAOS_IOCTL_MAGIC        	0XCF
#define TAOS_IOCTL_ALS_ON       	_IO(TAOS_IOCTL_MAGIC, 1)
#define TAOS_IOCTL_ALS_OFF      	_IO(TAOS_IOCTL_MAGIC, 2)
#define TAOS_IOCTL_ALS_DATA     	_IOR(TAOS_IOCTL_MAGIC, 3, short)
#define TAOS_IOCTL_ALS_CALIBRATE	_IO(TAOS_IOCTL_MAGIC, 4)
#define TAOS_IOCTL_CONFIG_GET   	_IOR(TAOS_IOCTL_MAGIC, 5, struct taos_cfg)
#define TAOS_IOCTL_CONFIG_SET		_IOW(TAOS_IOCTL_MAGIC, 6, struct taos_cfg)
#define TAOS_IOCTL_PROX_ON			_IO(TAOS_IOCTL_MAGIC, 7)
#define TAOS_IOCTL_PROX_OFF			_IO(TAOS_IOCTL_MAGIC, 8)
#define TAOS_IOCTL_PROX_DATA		_IOR(TAOS_IOCTL_MAGIC, 9, struct taos_prox_info)
#define TAOS_IOCTL_PROX_EVENT       _IO(TAOS_IOCTL_MAGIC, 10)
#define TAOS_IOCTL_PROX_CALIBRATE	_IO(TAOS_IOCTL_MAGIC, 11)

#define TAOS_IOCTL_SENSOR_ON		_IO(TAOS_IOCTL_MAGIC, 12)
#define TAOS_IOCTL_SENSOR_OFF		_IO(TAOS_IOCTL_MAGIC, 13)
#define TAOS_IOCTL_SENSOR_CONFIG	_IOW(TAOS_IOCTL_MAGIC, 14, struct taos_cfg)
#define TAOS_IOCTL_SENSOR_CHECK		_IO(TAOS_IOCTL_MAGIC, 15)
#define TAOS_IOCTL_SENSOR_test		_IO(TAOS_IOCTL_MAGIC, 16)

// device configuration
struct taos_cfg {
	__u32   calibrate_target;
	__u16   als_time;
	__u16   scale_factor;
	__u16   gain_trim;
	__u8    filter_history;
	__u8    filter_count;
	__u8    gain;
	__u16	prox_threshold_hi;
	__u16   prox_threshold_lo;
	__u16	als_threshold_hi;
	__u16   als_threshold_lo;
	__u8	prox_int_time;
	__u8	prox_adc_time;
	__u8	prox_wait_time;
	__u8	prox_intr_filter;
	__u8	prox_config;
	__u8	prox_pulse_cnt;
	__u8	prox_gain;
};
// proximity data
struct taos_prox_info {
	__u16   prox_clear;
	__u16   prox_data;
	int	prox_event;
};
