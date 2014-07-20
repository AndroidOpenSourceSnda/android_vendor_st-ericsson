/*****************************************************************************/
/**
*  © ST-Ericsson, 2011 - All rights reserved
*  Reproduction and Communication of this document is strictly prohibited
*  unless specifically authorized in writing by ST-Ericsson
*
* \brief   This module provides routines to manage audio dth functions
* \author  ST-Ericsson
*/
/*****************************************************************************/
#define TATL02_C
#include "tatlaudio.h"
#undef  TATL02_C

#include <sys/stat.h>

/* to resolve compatibility between hats_audio.h definition and TATLAUDIO definitions , generated by dthrad.pl */
#if defined HATS_AB_8500_HW
#define TATAUDIO_ENUM_SRC_MAX           TATAUDIO_SRC_MICRO_DI3+1
int     Dthaudio_codec_src_tab[TATAUDIO_ENUM_SRC_MAX]
= {
    CODEC_SRC_LINEIN     /* TATAUDIO_SRC_LINEIN */
    , CODEC_SRC_MICROPHONE_1A   /*TATAUDIO_SRC_MICRO_AN1A */
    , CODEC_SRC_MICROPHONE_1B /*TATAUDIO_SRC_MICRO_AN1B */
    , CODEC_SRC_MICROPHONE_2 /*TATAUDIO_SRC_MICRO_AN2 */
    , CODEC_SRC_D_MICROPHONE_12 /*TATAUDIO_SRC_MICRO_DI1 */
    , CODEC_SRC_D_MICROPHONE_34 /*TATAUDIO_SRC_MICRO_DI2 */
    , CODEC_SRC_D_MICROPHONE_56 /*TATAUDIO_SRC_MICRO_DI3 */
};
#else
#define TATAUDIO_ENUM_SRC_MAX           TATAUDIO_SRC_MICRO_USB+1
int     Dthaudio_codec_src_tab[TATAUDIO_ENUM_SRC_MAX]
= {
    CODEC_SRC_LINEIN     /* TATAUDIO_SRC_LINEIN */
    , CODEC_SRC_MICROPHONE_1A /*TATAUDIO_SRC_MICRO_AN1A */
    , CODEC_SRC_MICROPHONE_1B /*TATAUDIO_SRC_MICRO_AN1B */
    , CODEC_SRC_MICROPHONE_2 /*TATAUDIO_SRC_MICRO_AN2 */
    , CODEC_SRC_D_MICROPHONE_12 /*TATAUDIO_SRC_MICRO_DI1 */
    , CODEC_SRC_D_MICROPHONE_34 /*TATAUDIO_SRC_MICRO_DI2 */
    , CODEC_SRC_D_MICROPHONE_56 /*TATAUDIO_SRC_MICRO_DI3 */
    , CODEC_SRC_MICROPHONE_1B   /*TATAUDIO_SRC_MICRO_USB */
};
#endif

#if defined HATS_AB_8500_HW
#define TATAUDIO_ENUM_SINK_MAX          TATAUDIO_SINK_VIBRATOR2+1
int     Dthaudio_codec_sink_tab[TATAUDIO_ENUM_SINK_MAX]
= {
    CODEC_DEST_HEADSET  /*TATAUDIO_SINK_HEADSET */
    , CODEC_DEST_EARPIECE /*TATAUDIO_SINK_EARSET */
    , CODEC_DEST_HANDSFREE /*TATAUDIO_SINK_HANDSFREE */
    , CODEC_DEST_VIBRATOR1 /*TATAUDIO_SINK_VIBRATOR1 */
    , CODEC_DEST_VIBRATOR2 /*TATAUDIO_SINK_VIBRATOR2 */
};
#else
#define TATAUDIO_ENUM_SINK_MAX          TATAUDIO_SINK_USB_CARKIT+1
#ifndef CODEC_DEST_VIBRATOR2
#define CODEC_DEST_VIBRATOR2  -1
#endif

int     Dthaudio_codec_sink_tab[TATAUDIO_ENUM_SINK_MAX]
= {
    CODEC_DEST_HEADSET  /*TATAUDIO_SINK_HEADSET */
    , CODEC_DEST_EARPIECE /*TATAUDIO_SINK_EARSET */
    , CODEC_DEST_HANDSFREE /*TATAUDIO_SINK_HANDSFREE */
    , CODEC_DEST_VIBRATOR1 /*TATAUDIO_SINK_VIBRATOR1 */
    , CODEC_DEST_VIBRATOR2 /*TATAUDIO_SINK_VIBRATOR2 */
    , CODEC_DEST_LINE_OUT   /*TATAUDIO_SINK_LINE_OUT */
    , CODEC_DEST_PDM    /*TATAUDIO_SINK_PDM */
    , CODEC_DEST_USB_HS     /*TATAUDIO_SINK_USB_HEADSET */
    , CODEC_DEST_USB_CK     /*TATAUDIO_SINK_USB_CARKIT */
};
#endif

/* selected audio loop interface */
int dthaudio_digital_loop_in_ab_action = TATAUDIO_STOP;
int dthaudio_digital_loop_in_ap_action = TATAUDIO_STOP;
int dthaudio_analog_loop_action = TATAUDIO_STOP;
#if defined HATS_AB_8520_HW
int dthaudio_digital_loop_in_modem_action = TATAUDIO_MOD_STOP;
int dthaudio_loop_interface = TATAUDIO_MODEM_LOOP1;
uint32_t dthaudio_micswitch = TATAUDIO_JACKMIC;
uint32_t dthaudio_headsetswitch = TATAUDIO_OMTP_HEADSET;
#endif

int dthaudio_playback_action = TATAUDIO_STOP;
int dthaudio_playback_device = TATAUDIO_MAIN_DEVICE;
int dthaudio_record_action = TATAUDIO_STOP;

u32 dthaudio_activity = TATAUDIO_READY; /* same options as TATAUDIO_AUDIT_ACTIVITY */

uint32_t dthaudio_source = TATAUDIO_SRC_LINEIN;
uint32_t dthaudio_sink = TATAUDIO_SINK_HEADSET;
uint32_t dthaudio_avconnector = TATAUDIO_AVCONN_AUDIO;


int DthAudio_stopAudioLoop(e_HatsAudioCodecType_t codec);
int DthAudio_startAnalogAudioLoop(void);
int DthAudio_startABDigitalAudioLoop(void);
int DthAudio_startAPDigitalAudioLoop(void);
int DthAudio_startModemAudioLoop(void);
int DthAudio_stopModemAudioLoop(void);
int DthAudio_setModemAudioLoop(void);

int DthAudio_startAudioPlayback(e_HatsAudioDevice_t, const char *, const char *);
int DthAudio_stopAudioPlayback(e_HatsAudioDevice_t);
int DthAudio_changeVolume(e_HatsAudioDevice_t, e_HatsAudioCodecType_t, uint32_t);

int DthAudio_01SimpleGet(struct dth_element *elem, void *value)
{
    DECLARE_ERR();
    uint32_t *pl_value = STATIC_CAST(value, uint32_t *);
    SYSLOG(LOG_DEBUG, "DTH Get with  elem->user_data=%u", elem->user_data);

    switch (elem->user_data) {
#if defined HATS_AB_8520_HW
    case TATAUDIO_MODEM_LOOP:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        TAT_IF_OK(*pl_value = dthaudio_loop_interface);
        break;
#endif
    case TATAUDIO_AUDIT_ACTIVITY:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        TAT_IF_OK(*pl_value = dthaudio_activity);
        break;

    case TATAUDIO_DEVICE:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        TAT_IF_OK(*pl_value = dthaudio_playback_device);
        break;

    case TATAUDIO_SRC:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        TAT_IF_OK(*pl_value = dthaudio_source);
        break;

    case TATAUDIO_SINK:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        TAT_IF_OK(*pl_value = dthaudio_sink);
        break;

    case TATAUDIO_AVCONNECTOR:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        TAT_IF_OK(*pl_value = dthaudio_avconnector);
        break;

#if defined HATS_AB_8520_HW
    case TATAUDIO_JACK_USB_MIC_SWITCH:
        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        TAT_IF_OK(*pl_value = dthaudio_micswitch);
        break;

    case TATAUDIO_HEADSET_SWITCH:
        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        TAT_IF_OK(*pl_value = dthaudio_headsetswitch);
        break;
#endif

    default:
        TAT_SET_LAST_ERR(TAT_BAD_REQ);
    }

    RETURN_ERR();
}

int DthAudio_02SimpleSet(struct dth_element *elem, void *value)
{
    DECLARE_ERR();
    uint32_t vl_value = DEREF_PTR(value, uint32_t);
    hats_audio_err_t vl_audioerr;

    SYSLOG(LOG_DEBUG, "DTH set with elem->user_data= %u", elem->user_data);

    switch (elem->user_data) {
    case TATAUDIO_DIGITAL_LOOP_IN_AB:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        VERIFY_ENUM(vl_value, TATAUDIO_STOP);
        if (TAT_LAST_OK()) {
            dthaudio_digital_loop_in_ab_action = vl_value;
            SYSLOG(LOG_INFO, "Digital AB Audio loop operation set to %u.", dthaudio_digital_loop_in_ab_action);
        }
        break;

    case TATAUDIO_DIGITAL_LOOP_IN_AP:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        VERIFY_ENUM(vl_value, TATAUDIO_STOP);
        if (TAT_LAST_OK()) {
            dthaudio_digital_loop_in_ap_action = vl_value;
            SYSLOG(LOG_INFO, "Digital AP Audio loop operation set to %u.", dthaudio_digital_loop_in_ap_action);
        }
        break;

    case TATAUDIO_ANALOG_LOOP:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        VERIFY_ENUM(vl_value, TATAUDIO_STOP);
        if (TAT_LAST_OK()) {
            dthaudio_analog_loop_action = vl_value;
            SYSLOG(LOG_INFO, "ANALOG Audio loop operation set to %u.", dthaudio_analog_loop_action);
        }
        break;

#if defined HATS_AB_8520_HW
    case TATAUDIO_DIGITAL_LOOP_IN_MODEM:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        VERIFY_ENUM(vl_value, TATAUDIO_MOD_STOP);
        if (TAT_LAST_OK()) {
            dthaudio_digital_loop_in_modem_action = vl_value;
            SYSLOG(LOG_INFO, "Modem Audio loop operation set to %u.", dthaudio_digital_loop_in_modem_action);
        }
        break;

    case TATAUDIO_MODEM_LOOP:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        VERIFY_ENUM(vl_value, TATAUDIO_MODEM_LOOP2);
        if (TAT_LAST_OK()) {
            dthaudio_loop_interface = vl_value;
            SYSLOG(LOG_INFO, "Modem Audio loop interface set to %u.", dthaudio_loop_interface);
        }
        break;
#endif
    case TATAUDIO_PLAYBACK:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        VERIFY_ENUM(vl_value, TATAUDIO_STOP);
        if (TAT_LAST_OK()) {
            dthaudio_playback_action = vl_value;
            SYSLOG(LOG_INFO, "Audio playback operation set to %u.", dthaudio_playback_action);
        }
        break;

    case TATAUDIO_RECORD:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        VERIFY_ENUM(vl_value, TATAUDIO_STOP);
        if (TAT_LAST_OK()) {
            dthaudio_record_action = vl_value;
            SYSLOG(LOG_INFO, "Audio record operation set to %u.", dthaudio_record_action);
        }
        break;

    case TATAUDIO_DEVICE:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        VERIFY_ENUM(vl_value, TATAUDIO_HDMI_DEVICE);
        if (TAT_LAST_OK()) {
            dthaudio_playback_device = vl_value;
            SYSLOG(LOG_INFO, "Playback device %u (0=MAIN, 1=HDMI) selected.", dthaudio_playback_device);
        }
        break;

    case TATAUDIO_SRC:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        VERIFY_ENUM(vl_value, TATAUDIO_ENUM_SRC_MAX);

        if (TAT_LAST_OK()) {
            vl_audioerr = SetSrc(AUDIO_DEVICE_0, (e_HatsAudioInput_t) Dthaudio_codec_src_tab[vl_value]);
            if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
                dthaudio_source = vl_value;
                SYSLOG(LOG_INFO, "Audio source changed to %u", dthaudio_source);

            } else {
                TAT_SET_LAST_ERR(hats_audio_err_to_dth(vl_audioerr));
                SYSLOG(LOG_ERR, "Failed to set audio source");
            }
        }

        if (TAT_LAST_OK()) {
            if (TATAUDIO_SRC_MICRO_AN1B == vl_value) {
#if defined HATS_AB_8520_HW
                dthaudio_micswitch = TATAUDIO_JACKMIC;
                DthAudio_GpioConfig(TATAUDIO_GPIO_MICCTRL_DIR, TATAUDIO_GPIO_MICCTRL_OUT, TATAUDIO_GPIO_MICCTRL_PUD,
                                    TATAUDIO_GPIO_MICCTRL_OFFSET_IN_REGISTER, 1, 1, 0);
                TAT_TRY(libtatasync_msg_send(VALUE_CHANGED, "/DTH/AUDIO/Tests/Setup/GPIO_MIC_CTRL"));
#endif

                dthaudio_avconnector = TATAUDIO_AVCONN_AUDIO;
                DthAudio_GpioConfig(TATAUDIO_GPIO_VIDEOCTRL_DIR, TATAUDIO_GPIO_VIDEOCTRL_OUT, TATAUDIO_GPIO_VIDEOCTRL_PUD,
                                    TATAUDIO_GPIO_VIDEOCTRL_OFFSET_IN_REGISTER, 1, 1, 0);;
                TAT_TRY(libtatasync_msg_send(VALUE_CHANGED, "/DTH/AUDIO/Tests/Setup/GPIO_MICVIDEO_CTRL"));
            }
#if defined HATS_AB_8520_HW
			 else if (TATAUDIO_SRC_MICRO_USB == vl_value) {
                dthaudio_micswitch = TATAUDIO_USBMIC;
                DthAudio_GpioConfig(TATAUDIO_GPIO_MICCTRL_DIR, TATAUDIO_GPIO_MICCTRL_OUT, TATAUDIO_GPIO_MICCTRL_PUD,
                                    TATAUDIO_GPIO_MICCTRL_OFFSET_IN_REGISTER, 1, 0, 0);
                TAT_TRY(libtatasync_msg_send(VALUE_CHANGED, "/DTH/AUDIO/Tests/Setup/GPIO_MIC_CTRL"));

                dthaudio_avconnector = TATAUDIO_AVCONN_AUDIO;
                DthAudio_GpioConfig(TATAUDIO_GPIO_VIDEOCTRL_DIR, TATAUDIO_GPIO_VIDEOCTRL_OUT, TATAUDIO_GPIO_VIDEOCTRL_PUD,
                                    TATAUDIO_GPIO_VIDEOCTRL_OFFSET_IN_REGISTER, 1, 1, 0);;
                TAT_TRY(libtatasync_msg_send(VALUE_CHANGED, "/DTH/AUDIO/Tests/Setup/GPIO_MICVIDEO_CTRL"));
            }
#endif
        }
        break;


    case TATAUDIO_SINK:

        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);

        VERIFY_ENUM(vl_value, TATAUDIO_ENUM_SINK_MAX);

        if (TAT_LAST_OK()) {
            vl_audioerr = SetSink(AUDIO_DEVICE_0, (e_HatsAudioOutput_t) Dthaudio_codec_sink_tab[vl_value]);
            if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
                dthaudio_sink = vl_value;
                SYSLOG(LOG_INFO, "Audio sink set to %u", dthaudio_sink);

            } else {
                TAT_SET_LAST_ERR(hats_audio_err_to_dth(vl_audioerr));
                SYSLOG(LOG_ERR, "Failed to set audio sink");
            }
        }
        break;



    case TATAUDIO_AVCONNECTOR:
        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        VERIFY_ENUM(vl_value, TATAUDIO_AVCONN_VIDEO);

        if (TAT_LAST_OK()) {
            if (TATAUDIO_AVCONN_VIDEO == vl_value) {
                DthAudio_GpioConfig(TATAUDIO_GPIO_VIDEOCTRL_DIR, TATAUDIO_GPIO_VIDEOCTRL_OUT, TATAUDIO_GPIO_VIDEOCTRL_PUD,
                                    TATAUDIO_GPIO_VIDEOCTRL_OFFSET_IN_REGISTER, 1, 0, 0);

                SYSLOG(LOG_INFO, "AV connector set to VIDEO_SOURCE");
            } else if (TATAUDIO_AVCONN_AUDIO == vl_value) {
                DthAudio_GpioConfig(TATAUDIO_GPIO_VIDEOCTRL_DIR, TATAUDIO_GPIO_VIDEOCTRL_OUT, TATAUDIO_GPIO_VIDEOCTRL_PUD,
                                    TATAUDIO_GPIO_VIDEOCTRL_OFFSET_IN_REGISTER, 1, 1, 0);;

                SYSLOG(LOG_INFO, "AV connector set to AUDIO_SOURCE");
            }
            if (TAT_LAST_OK()) {
                dthaudio_avconnector = vl_value;
            } else {
                SYSLOG(LOG_ERR, "Failed to set AV connector");
            }
        }
        break;

#if defined HATS_AB_8520_HW
    case TATAUDIO_JACK_USB_MIC_SWITCH:
        VERIFY_DTH_TYPE(elem, DTH_TYPE_U32);
        VERIFY_ENUM(vl_value, TATAUDIO_USBMIC);
        if (TAT_LAST_OK()) {
            if (TATAUDIO_JACKMIC == vl_value) {
                DthAudio_GpioConfig(TATAUDIO_GPIO_MICCTRL_DIR, TATAUDIO_GPIO_MICCTRL_OUT, TATAUDIO_GPIO_MICCTRL_PUD,
                                    TATAUDIO_GPIO_MICCTRL_OFFSET_IN_REGISTER, 1, 1, 0);

                SYSLOG(LOG_INFO, "Mic switch set to JACK");
            } else if (TATAUDIO_USBMIC == vl_value) {
                DthAudio_GpioConfig(TATAUDIO_GPIO_MICCTRL_DIR, TATAUDIO_GPIO_MICCTRL_OUT, TATAUDIO_GPIO_MICCTRL_PUD,
                                    TATAUDIO_GPIO_MICCTRL_OFFSET_IN_REGISTER, 1, 0, 0);;

                SYSLOG(LOG_INFO, "Mic switch set to USB");
            }
            if (TAT_LAST_OK()) {
                dthaudio_micswitch = vl_value;
            } else {
                SYSLOG(LOG_ERR, "Failed to set Mic switch");
            }
        }
        break;

#endif

    default:
        TAT_SET_LAST_ERR(TAT_BAD_REQ);
    }

    RETURN_ERR();
}

int DthAudio_03SimpleExec(struct dth_element *elem)
{
    DECLARE_ERR();

    SYSLOG(LOG_DEBUG, "DTH Exec with elem->user_data=%u", elem->user_data);

    switch (elem->user_data) {

    case TATAUDIO_DIGITAL_LOOP_IN_AB:
        if (TATAUDIO_START == dthaudio_digital_loop_in_ab_action) {
            TAT_TRY(DthAudio_startABDigitalAudioLoop());
        } else
            TAT_TRY(DthAudio_stopAudioLoop(CODEC_PLAYBACK));

        break;

    case TATAUDIO_DIGITAL_LOOP_IN_AP:
        if (TATAUDIO_START == dthaudio_digital_loop_in_ap_action) {
            TAT_TRY(DthAudio_startAPDigitalAudioLoop());
        } else
            TAT_TRY(DthAudio_stopAudioLoop(CODEC_PLAYBACK));

        break;

    case TATAUDIO_ANALOG_LOOP:
        if (TATAUDIO_START == dthaudio_analog_loop_action) {
            TAT_TRY(DthAudio_startAnalogAudioLoop());
        } else
            TAT_TRY(DthAudio_stopAudioLoop(CODEC_CAPTURE));

        break;
#if 0
    case TATAUDIO_DIGITAL_LOOP_IN_MODEM:
        if (TATAUDIO_MOD_START == dthaudio_digital_loop_in_modem_action) {
            TAT_TRY(DthAudio_startModemAudioLoop());
        } else if (TATAUDIO_MOD_STOP == dthaudio_digital_loop_in_modem_action) {
            TAT_TRY(DthAudio_stopModemAudioLoop());
        } else if (TATAUDIO_SET_MODEM_MODE == dthaudio_digital_loop_in_modem_action) {
            TAT_TRY(DthAudio_setModemAudioLoop());
        }

        break;
#endif
    case TATAUDIO_PLAYBACK:
        if (TATAUDIO_START == dthaudio_playback_action) {
            if (TATAUDIO_HDMI_DEVICE == dthaudio_playback_device) {
                TAT_TRY(DthAudio_startAudioPlayback(AUDIO_DEVICE_HDMI, PLAYBACK_UPLOAD_FILE, PLAYBACK_FINAL_FILE));
            } else {
                TAT_TRY(DthAudio_startAudioPlayback(AUDIO_DEVICE_0, PLAYBACK_UPLOAD_FILE, PLAYBACK_FINAL_FILE));
            }
        } else if (TATAUDIO_STOP == dthaudio_playback_action) {
            if (TATAUDIO_HDMI_DEVICE == dthaudio_playback_device) {
                TAT_TRY(DthAudio_stopAudioPlayback(AUDIO_DEVICE_HDMI));
            } else {
                TAT_TRY(DthAudio_stopAudioPlayback(AUDIO_DEVICE_0));
            }
        }

        break;

    case TATAUDIO_RECORD:
        if (TATAUDIO_START == dthaudio_record_action) {
            if (TATAUDIO_HDMI_DEVICE == dthaudio_playback_device) {
                TAT_TRY(StartPCMTransfer(AUDIO_DEVICE_HDMI, CODEC_CAPTURE, NORMAL_CAPTURE_MODE, RECORD_FILE));
            } else {
                TAT_TRY(StartPCMTransfer(AUDIO_DEVICE_0, CODEC_CAPTURE, NORMAL_CAPTURE_MODE, RECORD_FILE));
            }
        } else if (TATAUDIO_STOP == dthaudio_record_action) {
            if (TATAUDIO_HDMI_DEVICE == dthaudio_playback_device) {
                TAT_TRY(StopPCMTransfer(AUDIO_DEVICE_HDMI, CODEC_CAPTURE));
            } else {
                TAT_TRY(StopPCMTransfer(AUDIO_DEVICE_0, CODEC_CAPTURE));
            }
        }

        break;

    default:
        TAT_SET_LAST_ERR(TAT_BAD_REQ);
    }

    /* sends asychronous events in order to indicate a value change in the parameters values*/
    SYSLOG(LOG_INFO, "DthAudio_SendAsyncEventParameters VALUE_CHANGED ...");
    //printf("\nDthAudio_SendAsyncEventParameters VALUE_CHANGED for full list....\n");
    DthAudio_SendAsyncEventParameters(a_dthaudio_fulllistpath, VALUE_CHANGED, (mode_t)0);
    libtatasync_msg_send(VALUE_CHANGED, "/DTH/AUDIO/Tests/Activity");

    RETURN_ERR();
}

int DthAudio_stopAudioLoop(e_HatsAudioCodecType_t codec)
{
    DECLARE_ERR();

    SYSLOG(LOG_DEBUG, "Stopping audio loop device=%d, codec=%d...", AUDIO_DEVICE_0, codec);
    hats_audio_err_t vl_audioerr = StopPCMTransfer(AUDIO_DEVICE_0, codec);
    if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
        SYSLOG(LOG_INFO, "Audio loop stopped");
        dthaudio_activity = TATAUDIO_READY;
    } else {
        TAT_SET_LAST_ERR(hats_audio_err_to_dth(vl_audioerr));
        SYSLOG(LOG_ERR, "Failed to stop audio loop");
    }

    RETURN_ERR();
}

int DthAudio_startAudioLoop(void)
{
    DECLARE_ERR();


    RETURN_ERR();
}

int DthAudio_startAnalogAudioLoop(void)
{
    DECLARE_ERR();
    hats_audio_err_t vl_audioerr;

    SYSLOG(LOG_INFO, "Starting audio loop AB ANALOG...");

    vl_audioerr = StartPCMTransfer(AUDIO_DEVICE_0, CODEC_CAPTURE, ANALOG_LOOPBACK_MODE, NULL);

    if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
        SYSLOG(LOG_INFO, "Done.");
        dthaudio_activity = TATAUDIO_AUDIO_LOOP_ON;
    } else {
        TAT_SET_LAST_ERR(hats_audio_err_to_dth(vl_audioerr));
        SYSLOG(LOG_ERR, "Failed to start AB analog audio loop");
    }

    RETURN_ERR();
}

int DthAudio_startABDigitalAudioLoop(void)
{
    DECLARE_ERR();
    hats_audio_err_t vl_audioerr;

    SYSLOG(LOG_INFO, "Starting audio loop AB DIGITAL...");
    vl_audioerr = StartPCMTransfer(AUDIO_DEVICE_0, CODEC_PLAYBACK, AB_DIGITAL_LOOPBACK_MODE, NULL);


    if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
        SYSLOG(LOG_INFO, "Done.");
        dthaudio_activity = TATAUDIO_AUDIO_LOOP_ON;

    } else {
        TAT_SET_LAST_ERR(hats_audio_err_to_dth(vl_audioerr));
        SYSLOG(LOG_ERR, "Failed to start AB digital audio loop");
    }

    RETURN_ERR();
}

int DthAudio_startAPDigitalAudioLoop(void)
{
    DECLARE_ERR();
    hats_audio_err_t vl_audioerr;

    SYSLOG(LOG_INFO, "Starting audio loop AP DIGITAL...");
    vl_audioerr = StartPCMTransfer(AUDIO_DEVICE_0, CODEC_PLAYBACK, DIGITAL_LOOPBACK_MODE, NULL);

#if defined HATS_AB_8520_HW
    /* ++ tmp*/
    if (dthaudio_source == TATAUDIO_SRC_MICRO_USB) {
        DthAudio_GpioConfig(TATAUDIO_GPIO_MICCTRL_DIR, TATAUDIO_GPIO_MICCTRL_OUT, TATAUDIO_GPIO_MICCTRL_PUD,
                            TATAUDIO_GPIO_MICCTRL_OFFSET_IN_REGISTER, 1, 0, 0);
/*        system("sk-ab w 0x382 0x03");*/
        system("sk-ab w 0xBA2 0x0C");
    } else {
        DthAudio_GpioConfig(TATAUDIO_GPIO_MICCTRL_DIR, TATAUDIO_GPIO_MICCTRL_OUT, TATAUDIO_GPIO_MICCTRL_PUD,
                            TATAUDIO_GPIO_MICCTRL_OFFSET_IN_REGISTER, 1, 1, 0);
/*        system("sk-ab w 0x382 0x01");*/
        system("sk-ab w 0xBA2 0x00");
    }
    /* -- tmp*/
#else
        DthAudio_GpioConfig(TATAUDIO_GPIO_MICCTRL_DIR, TATAUDIO_GPIO_MICCTRL_OUT, TATAUDIO_GPIO_MICCTRL_PUD,
                            TATAUDIO_GPIO_MICCTRL_OFFSET_IN_REGISTER, 1, 0, 0);

#endif

    if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
        SYSLOG(LOG_INFO, "Done.");
        dthaudio_activity = TATAUDIO_AUDIO_LOOP_ON;

    } else {
        TAT_SET_LAST_ERR(hats_audio_err_to_dth(vl_audioerr));
        SYSLOG(LOG_ERR, "Failed to start AP digital audio loop");
    }

    RETURN_ERR();
}

int DthAudio_startModemAudioLoop(void)
{
    DECLARE_ERR();
#if 0
    int vl_status = 0;

    VERIFY_ENUM(dthaudio_loop_interface, TATAUDIO_MODEM_LOOP2);
    if (TAT_LAST_OK()) {
        switch (dthaudio_loop_interface) {
        case TATAUDIO_MODEM_LOOP1:

            SYSLOG(LOG_INFO, "Starting modem audio loop 1 ...");
            if (modemMngt_getModemConfig() == 1) {
                printf("Modem Loopback is not supported in this config\n");
                TAT_SET_LAST_ERR(TAT_BAD_REQ);
            } else {
                //printf("Modem Loopback will be supported in this config\n");
                /* check modem mode */
                if (modemMngt_getModemMode() != 0 /*normal*/) {
                    /* change to normal mode and indicate to reboot...*/
                    modemMngt_setModemMode(NORMAL_MODE);
                    printf("/!\\ NEED TO REBOOT TO BE IN NORMAL MODEM MODE!\n");
                    modemMngt_setModemState(2);
                    ///system("reboot"); /* normal modem mode is off after reboot */
                    system("poweroff");
                    printf("Reboot has been launched, if it has no effect, please poweroff then poweron manually..\n");
                } else {
                    char Cmd[1000] = "";
                    vl_status = modemLstr_rcvResponse(0, (char**)&Cmd, 1000);
                    /* send atcommand for modem loopback*/
                    //printf("prepare to send a modem command...\n");
                    memset(Cmd, 0, 1000);
                    strncpy(Cmd, "AT*EAUR=3,1,3\r\n", strlen("AT*EAUR=3,1,3\r\n"));
                    vl_status = modemLstr_sendCmd(0, Cmd, 1000);
                    printf("AT*EAUR=3,1,3 has been send.\n");
                    /* check response */
                    memset(Cmd, 0, 1000);
                    vl_status = modemLstr_rcvResponse(0, (char**)&Cmd, 1000);
                    printf("Modem Response is: ");
                    printf(Cmd);
                    printf("\n");

                    /*cscall mpc*/
                    if (dthaudio_sink == TATAUDIO_SINK_HEADSET)
                        system("/usr/local/bin/audio/AudioCallmpc_Headset.sh 1");
                    else if (dthaudio_sink == TATAUDIO_SINK_HANDSFREE)
                        system("/usr/local/bin/audio/AudioCallmpc_Handsfree.sh 1");
                    else if (dthaudio_sink == TATAUDIO_SINK_EARSET)
                        system("/usr/local/bin/audio/AudioCallmpc_Earpiece.sh 1");

                    printf("cscallmpc on going...\n");

                }
            }

            break;

        case TATAUDIO_MODEM_LOOP2:

            SYSLOG(LOG_INFO, "Starting modem audio loop 2 ...");
            /* */

            break;
        default:
            TAT_SET_LAST_ERR(TAT_BAD_REQ);
        }
    }
#endif

    RETURN_ERR();
}

int DthAudio_stopModemAudioLoop(void)
{
    DECLARE_ERR();
#if 0
    int vl_status = 0;

    VERIFY_ENUM(dthaudio_loop_interface, TATAUDIO_MODEM_LOOP2);
    if (TAT_LAST_OK()) {
        switch (dthaudio_loop_interface) {

        case TATAUDIO_MODEM_LOOP1:

            SYSLOG(LOG_INFO, "Stopping modem audio loop 1 ...");
            if (modemMngt_getModemConfig() == 1) {
                printf("Modem Loopback is not supported in this config\n");
                TAT_SET_LAST_ERR(TAT_BAD_REQ);
            } else {
                //printf("Modem Loopback will be supported in this config\n");
                /* check modem mode */
                if (modemMngt_getModemMode() != 0 /*normal*/) {
                    /* change to normal mode and indicate to reboot...*/
                    modemMngt_setModemMode(NORMAL_MODE);
                    printf("/!\\ NEED TO REBOOT TO BE IN NORMAL MODEM MODE!\n");
                    modemMngt_setModemState(2);
                    ///system("reboot"); /* normal modem mode is off after reboot */
                    system("poweroff");
                    printf("Reboot has been launched, if it has no effect, please poweroff then poweron manually..\n");
                } else {
                    char Cmd[1000] = "";
                    vl_status = modemLstr_rcvResponse(0, (char**) &Cmd, 1000);
                    /* send atcommand for modem loopback*/
                    //printf("prepare to send a modem command...\n");
                    memset(Cmd, 0, 1000);
                    strncpy(Cmd, "AT*EAUR=3,0,3\r\n", strlen("AT*EAUR=3,0,3\r\n"));
                    vl_status = modemLstr_sendCmd(0, Cmd, 1000);
                    printf("AT*EAUR=3,0,3 has been send.\n");
                    /* check response */
                    memset(Cmd, 0, 1000);
                    vl_status = modemLstr_rcvResponse(0, (char**) &Cmd, 1000);
                    printf("Modem Response is: ");
                    printf(Cmd);
                    printf("\n");

                    system("/usr/local/bin/audio/AudioCallmpc_Headset.sh 0");
                }
            }

            break;

        case TATAUDIO_MODEM_LOOP2:

            SYSLOG(LOG_INFO, "Stopping modem audio loop 2 ...");
            /* */

            break;

        default:
            TAT_SET_LAST_ERR(TAT_BAD_REQ);
        }
    }
#endif
    RETURN_ERR();
}

int DthAudio_setModemAudioLoop(void)
{
    DECLARE_ERR();

    if (TAT_LAST_OK()) {
#if 0
        SYSLOG(LOG_INFO, "Set modem mode to normal mode ...");
        if (modemMngt_getModemConfig() == 1) {
            printf("Modem Loopback is not supported in this config\n");
            TAT_SET_LAST_ERR(TAT_BAD_REQ);
        } else {
            /* check modem mode */
            if (modemMngt_getModemMode() != 0 /*normal*/) {
                /* change to normal mode and indicate to reboot...*/
                modemMngt_setModemMode(NORMAL_MODE);
                printf("/!\\ NEED TO REBOOT TO BE IN NORMAL MODEM MODE!\n");
                modemMngt_setModemState(2);
                ///system("reboot"); /* normal modem mode is off after reboot */
                system("poweroff");
                printf("Reboot has been launched, if it has no effect, please poweroff then poweron manually..\n");
            } else {
                printf("nothing to do, modem already in normal mode!\n");
            }
        }
#endif

    }
    RETURN_ERR();
}


int DthAudio_startAudioPlayback(e_HatsAudioDevice_t dev, const char *file, const char *filef)
{
    DECLARE_ERR();
    hats_audio_err_t vl_audioerr = HATS_AUDIO_NO_ERROR;
    struct stat stat_src, stat_final;
    int res_stat_src, res_stat_final;

    res_stat_final = stat(filef, &stat_final);
    SYSLOG(LOG_DEBUG, "Audio file %s %s.", filef, (0 == res_stat_final) ? "exists" : "does NOT exist");

    res_stat_src = stat(file, &stat_src);
    SYSLOG(LOG_DEBUG, "Uploaded file %s %s.", file, (0 == res_stat_src) ? "exists" : "does NOT exist");

    /* error case: no audio file available */
    if ((-1 == res_stat_final) && (-1 == res_stat_src)) {
        SYSLOG(LOG_ERR, "No audio file available for playback.\nPlease upload one and try again.");
        TAT_SET_LAST_ERR(TAT_ERROR_FILE_OPEN);
    } else {
        /* need to generate the converted file if it is older than the uploaded one or if it does not exist */
        if ((-1 == res_stat_final) || (stat_final.st_mtime < stat_src.st_mtime)) {
            SYSLOG(LOG_NOTICE, "Converting %s to %s via device %u...", file, filef, dev);
            vl_audioerr = ConvWaveFile(dev, file, filef);

            if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
                /* conversion succeeded */
                SYSLOG(LOG_NOTICE, "File successfully converted.");
            } else {
                /* error on conversion*/
                SYSLOG(LOG_ERR, "Conversion failed");
            }
        }

        /* if the conversion succeed , try to play the file */
        if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
            vl_audioerr = StartPCMTransfer(dev, CODEC_PLAYBACK, NORMAL_PLAYBACK_MODE, (char *) filef);
            if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
                /* play on going */
                SYSLOG(LOG_NOTICE, "File is playing...");
                dthaudio_activity = TATAUDIO_PLAYBACK_ON;

            } else {
                /* error when playing the converted file */
                SYSLOG(LOG_ERR, "Fail to play the converted file");
                /* Try to play the non converted file*/
                vl_audioerr = StartPCMTransfer(dev, CODEC_PLAYBACK, NORMAL_PLAYBACK_MODE, (char *) file);
                if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
                    /* play on going */
                    SYSLOG(LOG_NOTICE, "Non-converted File is playing...");
                    dthaudio_activity = TATAUDIO_PLAYBACK_ON;
                } else {
                    /* error: what? */
                    TAT_SET_LAST_ERR(hats_audio_err_to_dth(vl_audioerr));
                    SYSLOG(LOG_ERR, "Fail to play the Non-converted file");
                    SYSLOG(LOG_ERR, "Unkown error...\n");

                }
            }
        } else {
            /*conversion has failed, file should be directly played*/
            vl_audioerr = StartPCMTransfer(dev, CODEC_PLAYBACK, NORMAL_PLAYBACK_MODE, (char *) file);
            if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
                /* play on going */
                SYSLOG(LOG_NOTICE, "Non-converted File is playing...");
                dthaudio_activity = TATAUDIO_PLAYBACK_ON;
            } else {
                TAT_SET_LAST_ERR(hats_audio_err_to_dth(vl_audioerr));
                SYSLOG(LOG_ERR, "Fail to play the Non-converted file");
                printf("Unkown error...\n");
            }
        }
    }

    RETURN_ERR();
}

int DthAudio_stopAudioPlayback(e_HatsAudioDevice_t device)
{
    DECLARE_ERR();

    SYSLOG(LOG_DEBUG, "Stopping audio Playback device=%d ", device);
    hats_audio_err_t vl_audioerr = StopPCMTransfer(device, CODEC_PLAYBACK);
    if (HATS_AUDIO_NO_ERROR == vl_audioerr) {
        SYSLOG(LOG_INFO, "Audio playback stopped");
        dthaudio_activity = TATAUDIO_READY;
    } else {
        TAT_SET_LAST_ERR(hats_audio_err_to_dth(vl_audioerr));
        SYSLOG(LOG_ERR, "Failed to stop audio playback");
    }

    RETURN_ERR();
}

