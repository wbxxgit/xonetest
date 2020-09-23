/*
Description: 
              ...            
*/

#ifndef _SDK_COMMONSTRUCT_H
#define _SDK_COMMONSTRUCT_H

#if defined (__cplusplus)
extern "C" {
#endif
#include "cqueue.h"


//********************************************************************
//********Moudle type: System (a1)*******************************
//********************************************************************
typedef struct
{    
	char a_name[64];
	char a_type[64];
	char a_software_version[64];
	char a_hardware_version[64];
	char a_id[128];
	char a_wifi_mac[64];
	char a_line_mac[64];
}T_SDK_DEVICE_INFO;

typedef struct
{
	unsigned int un_year;	//value range  (1970~2055)
	unsigned int un_month;	//value range (1~12)
	unsigned int un_day;	//value range (1~31)
	unsigned int un_hour;	//value range(0~23)
	unsigned int un_minute;	//value range (0~59)
	unsigned int un_second;	//value range (0~59)
}T_SDK_DEVICE_TIME;

typedef struct
{
	unsigned int un_auto;	    //value range (0:off 1:on)
	unsigned int un_day_night;	//value range(0:day 1:night)
}T_SDK_NIGHT_VISION;


typedef struct
{
	char u8DevCTEI[128];
	char u8DevSN[128];	
	char u8DevKey[128];
}T_SDK_THREE_DevCfg;


typedef struct
{
	unsigned int un_gpio_0;	   
	unsigned int un_gpio_1;		
	unsigned int un_value;	
}T_SDK_LED;

// for amba 
typedef struct
{
	unsigned int un_battery_level;
	unsigned int un_charge_state;	//0:off 1:on
	unsigned int un_battery_state;  //0:full 1:middle 2:low 3.deep low
}T_SDK_BATTERY_INFO;

//�������������ṹ��
typedef struct 
{	
	unsigned char alarm_switch[4];			//�����澯���Ϳ���,(0:�ر����ͣ�1:��������) alarm_type[0]:������Ϣ�����ܿ���, alarm_type[1]:����, alarm_type[2]:�͵磬alarm_type[3]:��������
	unsigned char reserved[16];			
}T_SDK_BATTERY_ALARM_PARAM;


//IPC ����TUTKƽ̨ ��Ȩ��Ϣ�ṹ��
typedef struct
{
	int  index;					//�������0 ,1 ,2
	char user_name[64];	   
	char passwd[64];
	char reserved[4];
}T_SDK_DEVICE_AUTHENTICATION_INFO;


//IPC �������ṹ�壬��Ҫ���ڸ�APP���ṩ���ػ���ʾ��ؼ�UI ������ 
typedef struct
{
	unsigned int  encrypted_ic_flag;	//�Ƿ��м���IC 
	unsigned int  pir_flag; 			//�Ƿ���PIR��������0:�ޣ�1:�У���ͬ
	unsigned int  ptz_flag; 			//�Ƿ�����̨
	unsigned int  mic_flag; 			//�Ƿ�����ͷ				
	unsigned int  speaker_flag; 		//�Ƿ�������
	unsigned int  sd_flag;				//�Ƿ���SD��
	unsigned int  temperature_flag; 	//�Ƿ����¸�̽ͷ	
	unsigned int  timezone_flag;		//�Ƿ�֧��ͬ��ʱ��
	unsigned int  night_vison_flag;		//�Ƿ�֧��ҹ��
	unsigned int  resolution_0_flag;	//�������ֱ��ʴ�С Width:��16λ Height:��16λ  Ming@2016.06.14
	unsigned int  resolution_1_flag;	//�������ֱ��ʴ�С Width:��16λ Height:��16λ  Ming@2016.06.14
	unsigned int  reserver[8];			
}T_SDK_DEVICE_ABILITY_INFO;

//IPC �������ṹ�壬��Ҫ���ڸ�APP���ṩ���ػ���ʾ��ؼ�UI ������ 
typedef struct 
{
	unsigned int   c_device_type; //�豸����   900���԰�     101����     100����	    901������
	unsigned int   un_resolution_0_flag;	//�������ֱ��ʴ�С Width:��16λ Height:��16λ  Ming@2016.06.14
	unsigned int   un_resolution_1_flag;	//������	
	unsigned int   un_resolution_2_flag;	//��3·����
	unsigned char  c_encrypted_ic_flag;	//�Ƿ��м���IC 
	unsigned char  c_pir_flag; 			//�Ƿ���PIR��������0:�ޣ�1:�У���ͬ
	unsigned char  c_ptz_flag; 			//�Ƿ�����̨
	unsigned char  c_mic_flag; 			//�Ƿ�����ͷ				
	unsigned char  c_speaker_flag; 		//�Ƿ�������
	unsigned char  c_sd_flag;			//�Ƿ���SD��
	unsigned char  c_temperature_flag; 	//�Ƿ����¸�̽ͷ	
	unsigned char  c_timezone_flag;		//�Ƿ�֧��ͬ��ʱ��
	unsigned char  c_night_vison_flag;	//�Ƿ�֧��ҹ��
	unsigned char  ethernet_flag;	//�Ƿ������0:wifi 1����2wifi������
	unsigned char  c_smart_connect_flag;	//�Ƿ�֧��smartɨ��	0����֧�֣�1����7601smart  2����8188smart	
	unsigned char  c_motion_detection_flag; //�Ƿ�֧���ƶ����	
	unsigned char  c_record_duration_flag;
}T_SDK_DEVICE_ABILITY_INFO1;	

//IPC �������ṹ�壬��Ҫ���ڸ�APP���ṩ���ػ���ʾ��ؼ�UI ������ 
typedef struct 
{
	unsigned int   c_device_type; //�豸����   900���԰�     101����     100����	    901������
	unsigned int   un_resolution_0_flag;	//�������ֱ��ʴ�С Width:��16λ Height:��16λ  Ming@2016.06.14
	unsigned int   un_resolution_1_flag;	//������	
	unsigned int   un_resolution_2_flag;	//��3·����
	unsigned char  c_encrypted_ic_flag;	//�Ƿ��м���IC 
	unsigned char  c_pir_flag; 			//�Ƿ���PIR��������0:�ޣ�1:�У���ͬ
	unsigned char  c_ptz_flag; 			//�Ƿ�����̨
	unsigned char  c_mic_flag; 			//�Ƿ�����ͷ	
	
	unsigned char  c_speaker_flag; 		//�Ƿ�������
	unsigned char  c_sd_flag;			//�Ƿ���SD��
	unsigned char  c_temperature_flag; 	//�Ƿ����¸�̽ͷ	
	unsigned char  c_timezone_flag;		//�Ƿ�֧��ͬ��ʱ��
	
	unsigned char  c_night_vison_flag;	//�Ƿ�֧��ҹ��	
	unsigned char  ethernet_flag;	//�Ƿ������0:wifi 1����2wifi������
	unsigned char  c_smart_connect_flag;	/* �Ƿ�֧��smartɨ��	
												0	����֧�֣�
												1	����7601smart  
												2	����8188smart	
												3	����ap6212 
												9	��֧�ֶ�ά��ɨ��
												10	ֻ֧�ֶ�ά��ɨ��
												11�����ά��ɨ��+7601smart
												12�����ά��ɨ��+8188smart
												13�����ά��ɨ��+ap6212smart
										*/
	unsigned char  c_motion_detection_flag; //�Ƿ�֧���ƶ����
	
	unsigned char  c_record_duration_flag; // �Ƿ�������¼��¼��ʱ��
	unsigned char  c_light_flag; // �Ƿ������������ƿ���
	unsigned char  c_audio_alarm_detection_flag; //�Ƿ�֧��������ⱨ��
	unsigned char  align1;	 // �Ƿ�֧��ҡ����
	/*
	reserver_default_off[0]	 // �Ƿ����� 0. �� ��1. ��
	reserver_default_off[1]	 // �Ƿ�֧��WIFIԶ�̻��� 0.��֧�֣� 1֧��
	reserver_default_off[2]  // �Ƿ�֧��״̬�ƿ��� 0.��֧�֣� 1֧��
	
	reserver_default_off[3]  // �Ƿ�֧������ͷ���� 0.��֧�֣� 1֧��
	reserver_default_off[4]  // �Ƿ�֧������ͷ��˷翪�� 0.��֧�֣� 1֧��
	reserver_default_off[5]  // �Ƿ�֧���ƴ洢 0.��֧�֣� 1֧��
	reserver_default_off[6]	 // �Ƿ�֧�ִ�����Ȩ

	reserver_default_off[7]	 // �Ƿ�֧��Alexa_Voice_Service
	reserver_default_off[8]	 // �Ƿ�֧��Alexa_Skills_Kit
	*/
	unsigned char  reserver_default_off[32]; // Ԥ��������Ĭ�Ϲر�
	unsigned char  reserver_default_on[32]; // Ԥ��������Ĭ�Ͽ���
}T_SDK_DEVICE_ABILITY_INFO2;	


typedef struct
{
	unsigned char  c_record_duration_flag;  //�Ƿ�֧��¼��ʱ���趨,
	unsigned char  c_alarm_audio_play_set_flag;   //�Ƿ�֧�ֱ�����������,  
	
	unsigned char  c_audio_alarm_detection_flag;	//�Ƿ�֧���������������������Ӥ���ޣ�
	unsigned char  c_temperature_detection_flag;	//�Ƿ�֧�ֲ��±���,
	unsigned char  c_loop_record_flag;	//�Ƿ�֧��ѭ��¼�񿪹�,
	unsigned char  c_manual_record_flag;	//�Ƿ�֧���ֶ�¼��, 
	unsigned char  c_ptz_auto_cruise_flag;	//�Ƿ�֧����̨�Զ�ѭ��·�߿���
	unsigned char  c_ptz_preset_flag;	//�Ƿ�֧����̨Ԥ�õ�����
	unsigned char  c_humidity_detection_flag;	//�Ƿ�֧��ʪ�ȴ�����
	unsigned char  c_time_correct_flag;	//�Ƿ�֧��ʱ��У׼,
	unsigned char  c_WDR_flag;	//�Ƿ�֧�ֿ�̬,
	unsigned char  c_key_for_all_alarm_flag;	//�Ƿ�֧��һ������,
	unsigned char  c_share2friends_flag;	//�Ƿ�֧�ֺ��ѷ���,
	unsigned char  c_bitrat_auto_correct_flag;	//�Ƿ�֧����������Ӧ
	unsigned char  c_wifi_channel_flag;	//�Ƿ���Ը�wifi�ŵ�
	unsigned char  c_OSD_switch_flag;	//�Ƿ�֧��osd����
	unsigned char  c_OSD_string_add_flag;	//�Ƿ�֧��osd�ַ������
	unsigned char  c_bitrate_change_flag;	//�Ƿ�֧�������л�
	unsigned char  c_wire_flag;	//�Ƿ�֧������
	unsigned char  c_wireless_flag;	//�Ƿ�֧������
	unsigned char  c_normal_battery_flag;	//�Ƿ����أ�������ʾ
	unsigned char  c_solar_battery_flag;	//�Ƿ��̫���ܵ�أ���ʾ���ŵ�״̬
	unsigned char  c_3D_denoise_flag;	//�Ƿ�֧��3D����
	unsigned char  c_hue_adjust_flag;	//�Ƿ�֧��ɫ������


	unsigned char  c_saturation_debuggable_flag;	//�Ƿ�֧�ֱ��Ͷȵ���
	unsigned char  c_brightness_debuggable_flag;	//�Ƿ�֧�����ȵ���
	unsigned char  c_acutance_debuggable_flag;	//�Ƿ�֧����ȵ���
	unsigned char  c_have_anti_shaking_flag;	//�Ƿ�֧�ַ�������(Anti-Shaking/STABILIZER MODE)
	unsigned char  c_have_intelligent_tracking_flag;	//�Ƿ�֧�����ܸ���
	unsigned char  c_have_ota_upgrade_flag;	//�Ƿ�֧�������Զ�����(Over-the-Air)
	unsigned char  c_audio_encoder_selectable_flag;	//�Ƿ�֧����Ƶ�����ʽ�л�
	unsigned char  c_have_h265_flag;	//�Ƿ�֧��H265
	unsigned char  c_have_cloud_storage_flag;	//�Ƿ�֧���ƴ洢
	unsigned char  c_auto_zoom_flag;	//�Ƿ�֧���Զ��佹
	unsigned char  c_auto_diaphragm_flag;	//�Ƿ�֧���Զ���Ȧ
	unsigned char  c_motion_detection_alarm_zone_flag;	//�Ƿ�֧���ƶ���ⱨ����������
	unsigned char  c_planning_recording_flag;	//�Ƿ�֧�ּƻ�¼��
	unsigned char  c_privacy_masking_flag;	//�Ƿ�֧����˽�ڵ�
	unsigned char  c_cross_the_line_alarm_flag;	//�Ƿ�֧��Խ�߱���
	unsigned char  c_smoking_detection_flag;	//�Ƿ�֧���̸�
	unsigned char  c_door_contact_flag;	//�Ƿ�֧���Ŵ�
	unsigned char  c_license_plate_recognition_flag;	//�Ƿ�֧�ֳ���ʶ��
	unsigned char  c_digital_ptz_flag;	//�Ƿ�֧��������̨
	unsigned char  c_cross_line_alram_flag;	//�Ƿ�֧��Խ�߱���
	unsigned char  c_have_display_screen_flag;	//�Ƿ����
	unsigned char  c_wet_alarm_flag;	//�Ƿ�֧�ֽ�ʪ����
	unsigned char  c_have_bluetooth_flag;	//�Ƿ�֧������
	unsigned char  c_intelligent_light_flag;	//�Ƿ�֧�����ܵƿ���
	unsigned char  c_door_curtain_flag;	//�Ƿ�֧����������


	unsigned char  c_air_cond_ctrl_flag;	//�Ƿ�֧�ֿյ�����
	unsigned char  c_washing_ctrl_flag;	//�Ƿ�֧��ϴ�»�����
	unsigned char  c_refrigerator_ctrl_flag;	//�Ƿ�֧�ֱ������
	unsigned char  c_tv_ctrl_flag;	//�Ƿ�֧�ֵ��ӻ�����
	unsigned char  c_rice_cooker_ctrl_flag;	//�Ƿ�֧�ֵ緹�ҿ���
	unsigned char  c_smart_plug_ctrl_flag;	//�Ƿ�֧�����ܲ�������
	unsigned char  c_pm25_induction_flag;	//�Ƿ�֧��pm2.5��Ӧ
	unsigned char  c_heartbeat_detection_flag;	//�Ƿ�֧���������
	unsigned char  c_breathe_detection_flag;	//�Ƿ�֧�ֺ������
	unsigned char  c_bp_detection_flag;	//�Ƿ�֧��Ѫѹ���
	unsigned char  c_Blood_sugar_detection_flag;	//�Ƿ�֧��Ѫ�����
	unsigned char  c_4g_flag;	//�Ƿ�֧��4G
	unsigned char  c_3g_flag;	//�Ƿ�֧��3G
	unsigned char  c_GPS_locating_flag;	//�Ƿ�֧��GPS��λ
	unsigned char  c_wechart_pre_flag;	//�Ƿ�֧��΢�Ų鿴
	unsigned char  c_qq_pre_flag;	//�Ƿ�֧��qq�鿴
	unsigned char  c_web_pre_flag;	//�Ƿ�֧��web�鿴������
	unsigned char  c_thief_alarm_flag;	//�Ƿ�֧�ַ�������
	unsigned char  c_intelligent_learn_flag;	//�Ƿ�֧������ѧϰ
	unsigned char  c_face_regi_flag;	//�Ƿ�֧������ʶ��
	unsigned char  c_sub_regi_flag;	//�Ƿ�֧����������ʶ�𣬱���Ұ��
	unsigned char  c_ap_model_flag;	//�Ƿ�֧��apģʽ
	unsigned char  c_money_check_flag;	//�Ƿ�֧������ҷ�α���
	unsigned char  c_people_count_flag;	//�Ƿ�֧������ͳ��
	unsigned char  c_demisting_func_flag;;	//�Ƿ�֧��ȥ����


	unsigned char  c_gesture_recognition_flag;	//�Ƿ�֧������ʶ��
	unsigned char  c_speech_recognition_flag;	//�Ƿ�֧����������ʶ��
	unsigned char  c_wind_speed_flag;	//�Ƿ�֧�ַ��ٲ���
	unsigned char  c_air_pressure_display_flag;	//�Ƿ�֧����ѹ��ʾ
	unsigned char  c_seismic_survey_flag;	//�Ƿ�֧�ֵ��𿱲�
	unsigned char  c_seafloor_depth_shows_flag;	//�Ƿ�֧�ֺ��������ʾ
	unsigned char  c_gas_content_test_flag;	//�Ƿ�֧����˹��������
	unsigned char  c_Intensity_of_ultraviolet_detectiont_flag;	//�Ƿ�֧��������ǿ�����
	unsigned char  c_gyroscope_flag;	//�Ƿ�֧��������
	unsigned char  c_data_encryption_flag;	//�Ƿ�֧�����ݴ������
	unsigned char  c_remote_control_flag;	//�Ƿ��ң����
	unsigned char  c_wheel_mobile_capabilities_flag;	//�Ƿ�֧�������ƶ�����
	unsigned char  c_flight_flag ;	//�Ƿ�֧�ַ��й���
	unsigned char  c_Laser_tease_cats_tease_dogs_flag;	//�Ƿ�֧�ּ��ⶺè����
	unsigned char  c_video_conference_flag;	//�Ƿ�֧����Ƶ����
	unsigned char  c_projection_flag;	//�Ƿ�֧��ͶӰ����
	unsigned char  c_external_speaker_flag;	//�Ƿ�֧���������
	unsigned char  c_character_recognition_flag;	//�Ƿ�֧������ʶ��
	unsigned char  c_open_parking_brake_machine_flag;	//�Ƿ�֧��ͣ����բ����������
	unsigned char  c_probe_rotation_flag;	//�Ƿ�֧��̽ͷת��
	unsigned char  c_dual_cameras_flag;	//�Ƿ�֧��˫����ͷ
	unsigned char  c_electronic_payment_flag;	//�Ƿ�֧�ֵ���֧��
	unsigned char  c_fingerprint_identification_flag;	//�Ƿ�֧��ָ��ʶ��
	unsigned char  c_Iris_recognition_flag;	//�Ƿ�֧�ֺ�Ĥʶ��
	unsigned char  c_serial_snapshot_flag;	//�Ƿ�֧����������һ�������������ͼƬ�����ɶ����Ĺ���
	unsigned char  c_perspective_flag ;	//�Ƿ�֧��͸�ӹ���
}T_SDK_DEVICE_ABILITY_INFO100;


typedef struct 
{
    unsigned int	un_trigger_time;	//��������ʱ�� pir / motion
    unsigned int	un_manual_time;	//�ֶ���������ʱ��
	int	n_reserve;
}T_SDK_DEVICE_LIGHT_DURATION;

typedef struct 
{
    unsigned int	un_on_hour;	
    unsigned int	un_on_min;	
    unsigned int	un_off_hour;	
    unsigned int	un_off_min;	
	unsigned int 	un_wday_switch;	//�� 0~6λ��ʾ����0λ��ʾ�����죬��1λ��ʾ����һ 0->�ر� 1->��
	int	n_reserve;
}T_SDK_DEVICE_LIGHT_TIMING;//��ʱ����ʱ��㣬����

//********************************************************************
//******** module tpye: video (a2)*******************************
//********************************************************************
typedef enum  _E_VIDEO_ENCODER_TYPE
{
	E_VENC_NONE	= 0x00,
	E_VENC_H264	= 0x01,
	E_VENC_MPEG4	= 0x02,
	E_VENC_MJPEG	= 0x03,
	E_VENC_JPEG	= 0x04,
}E_SDK_VIDEO_ENCODER_TYPE;

typedef struct 
{
    unsigned int	un_encode_channel_id;
    unsigned char*	uncp_data;
    unsigned int	un_data_len;
	unsigned int	un_frame_type;	//value range (1:I frame 0:P frame)
	unsigned int	un_steam_type;	//1:means video,2:means audio
	unsigned int	un_timestamp;
    unsigned int 	un_sec;        /*usecond of frame*/
	unsigned int	un_sequence;
	int	n_reserve;
}T_SDK_STREAM_CALLBACK_PARAM;

typedef int (*F_SDK_Stream_Callback)(T_SDK_STREAM_CALLBACK_PARAM *pt_encode_data);

typedef struct 
{
	F_SDK_Stream_Callback	fp_callback;
	unsigned int un_video_switch;
	unsigned int un_audio_switch;
	unsigned int un_video_channel;
	unsigned int un_audio_channel;	
	int	n_reserve;	
}T_CALLBACK_INFO;

typedef struct 
{
	T_CALLBACK_INFO	ta_callback_info[4];		
	int	n_reserve;	
}T_SDK_STREAM_REGISTER_CALLBACK;

typedef struct 
{
	unsigned int	un_encode_channel_id;
	unsigned int	un_force_num;	
}T_SDK_FORCE_I_FARME;

typedef struct 
{
    unsigned int	un_encode_channel_id;     
    unsigned int	un_switch;	//value range (0:off 1:on)
}T_SDK_VIDEO_ENCODE_SWITCH;

typedef struct 
{
    unsigned int	un_encode_channel_id;  
    E_SDK_VIDEO_ENCODER_TYPE	e_type;		
}T_SDK_VIDEO_ENCODE_TYPE;

typedef struct 
{
	unsigned int	un_encode_channel_id;        
	unsigned int	un_width;				    
	unsigned int	un_height;					
}T_SDK_VIDEO_ENCODE_RESOLUTION;

typedef struct 
{
    unsigned int	un_encode_channel_id;              
    unsigned int	un_interval;			
}T_SDK_VIDEO_ENCODE_I_FRAME_INTERVAL;

typedef struct 
{
	unsigned int	un_encode_channel_id; 
	unsigned int	un_bitrate_type;	//value range (0: CBR; 1: VBR; 2: CBR keep quality; 3: VBR keep quality)
	unsigned int	un_average_bitrate;
	unsigned int	un_max_bitrate;
	unsigned int	un_min_bitrate;	
}T_SDK_VIDEO_ENCODE_BITRATE;

typedef struct 
{
	unsigned int	un_encode_channel_id;
	unsigned int	un_switch;	//value range (0:off 1:on)
}T_SDK_LOWER_BITRATE_CONTORL;	//only for  Ambarella

typedef struct 
{
	unsigned int	un_encode_channel_id;  
	unsigned int	un_framerate;	     
}T_SDK_VIDEO_ENCODE_FRAMERATE;

typedef struct 
{
	unsigned int	un_encode_channel_id; 
	unsigned int	un_quality;	//value range(0-5)
}T_SDK_VIDEO_ENCODE_QUALITY;

typedef struct 
{
	unsigned int	un_encode_channel_id;	
	unsigned int	un_profile;	//value range of Encode level ( 0: baseline; 1:MP; 2:HP)   HiSilicon not permitted set it
}T_SDK_VIDEO_ENCODE_LEVEL;

typedef struct 
{
	unsigned int	un_encode_channel_id;  				
	unsigned int	un_I_frame_max_Qp;                   
	unsigned int	un_I_frame_min_Qp;                   
	unsigned int	un_P_frame_max_Qp;                   
	unsigned int	un_P_frame_min_Qp;
	unsigned int	un_I_frame_Weight_Qp; //goke
	unsigned int	un_P_frame_Weight_Qp; //goke
}T_SDK_VIDEO_ENCODE_QP;

typedef struct 
{
	unsigned int	un_encode_channel_id;	//(input Param)
	unsigned int	un_encode_switch;	//value range(0:off 1:on)
	E_SDK_VIDEO_ENCODER_TYPE	e_encode_type;			  
	unsigned int	un_width;					
	unsigned int	un_height;					
	unsigned int	un_I_frame_interval;			  
	T_SDK_VIDEO_ENCODE_BITRATE	t_bitrate;					   
	unsigned int	un_framerate;					
	T_SDK_LOWER_BITRATE_CONTORL	t_lower_bitrate_control;	//only for  Ambarella
	unsigned int	un_quality;	//value range(0-5)
	unsigned int	un_profile;	//value range of Encode level ( 0: baseline; 1:MP; 2:HP)   HiSilicon not permitted set it
	T_SDK_VIDEO_ENCODE_QP t_QP;              
	unsigned int	un_mirro_type;	//value range 0:none,1:horizontal,2:vertical,3:horizonta+vertical
} T_SDK_VIDEO_ENCODE_PARAM;



//********************************************************************
//******** module tpye: Audio (a3)*******************************
//********************************************************************
typedef enum  _E_AUDIO_ENCODE_TYPE
{
	E_AENC_NONE	= 0x0,
	E_AENC_G726	= 0x01,
	E_AENC_G722	= 0x02,
	E_AENC_G711A	= 0x03,
	E_AENC_ADPCM	= 0x04,
	E_AENC_MP3	= 0x05,
	E_AENC_PCM	= 0x06,
	E_AENC_G711U	= 0x07,
	E_AENC_AACLC	= 0x08,
	E_AENC_AMRNB	= 0x09,
	E_AENC_PTAAC 	= 0x25,
}E_SDK_AUDIO_ENCODE_TYPE;

typedef struct 
{
	unsigned int	un_encode_switch;                     
	unsigned int	un_sound_mode;	//value range of soud_mode(0:single 1:stereo)
	unsigned int	un_mic_line_input;	//value range(0: mic input 1:line input)	
	E_SDK_AUDIO_ENCODE_TYPE	e_encode_type;					     
	unsigned int	un_audio_echo_canell_switch;	//(1:on 0:off)	
	unsigned int	un_bitrate;			            
	unsigned int	un_sample_rate;	                
	unsigned int	un_input_volume;	                     
	unsigned int	un_output_volume;                     
} T_SDK_AUDIO_ENCODE_PARAM;

typedef struct 
{
	unsigned char*	cp_data;			
	unsigned int	un_data_len;  
} T_SDK_INTERCOM_DATA;



//********************************************************************
//****** module tpye: sensor (a4)******************************
//********************************************************************	
typedef struct 
{
	unsigned int	un_brightness;
	unsigned int	un_contrast; 
	unsigned int	un_hue; 
	unsigned int	un_saturation; 
	unsigned int	una_sharp[4];	//sharp[0] for Ambarella
}T_SDK_SENSOR_PARAM;

typedef struct 
{
	unsigned int	una_sharp[4];	 //value range(0-100)
}T_SDK_SENSOR_SHARP;

#if 0
typedef struct
{
    unsigned int	un_encode_AE_mode;
    unsigned int	un_ExpTimeMax;
    unsigned int	un_ExpTimeMin;
    unsigned int	un_DGainMax;
    unsigned int	un_DGainMin;
    unsigned int	un_AGainMax;
    unsigned int	un_AGainMin;
    unsigned int	un_ISPDGainMax;
	unsigned int	un_SystemGainMax;
	unsigned int	un_GainThreshold;
	unsigned char	uc_ExpStep;
	short	s_ExpTolerance;
	unsigned char	uc_ExpCompensation;
	unsigned short	us_EVBias;
	unsigned int	un_AEStrategyMode;
	unsigned char	uc_MaxHistOffset;
	unsigned short	us_HistRatioSlope;
	unsigned int	un_FrameEndUpdateMode;
	unsigned int	un_ByPassAE;
}T_SDK_SENSOR_AUTO_EXPOSURE;
#else
typedef struct {
    unsigned int        speed;
    unsigned int        shutterTimeMin;
    unsigned int        shutterTimeMax;
    unsigned int        gainMax;
    unsigned int        gainMin;
    unsigned int        tagetRatio;
} T_SDK_SENSOR_AUTO_EXPOSURE;
#endif

typedef struct
{
    unsigned int	un_dain;
    unsigned int	un_value;
}T_SDK_SENSOR_2D;

typedef struct
{
    unsigned int	un_space_denoise;
    unsigned int	un_time_denoise;
    unsigned int	un_chroma_range;
}T_SDK_SENSOR_3D;




//********************************************************************
//********** module tpye: alarm (a5)******************************
//********************************************************************
typedef enum 
{
	E_UNKNOWN ,
	E_VIDEO_MOTION,
	E_PIR_MOTION,	//Passive Infrared Radiation  motion alarm
	E_PIR_VIDEO_MOTION, 
	E_AUDIO_MOTION, 
	E_IO_ALARM,
	E_LOW_TEMP_ALARM, //6
	E_HIGH_TEMP_ALARM,
	E_LOW_HUM_ALARM,
	E_HIGH_HUM_ALARM,
	E_LOW_WBGT_ALARM,
	E_HIGH_WBGT_ALARM, // 11
	E_CALLING,
	E_KEY_LONG_PRESS,
	E_KEY_SHORT_PRESS,
	E_KEY_ORDINARY_PRESS,
	E_WIFI_CONNECTED,
	E_WIFI_DISCONNECTED,
	E_SCAN_SUCCEED,
	E_RECORD_FINISHED,
	E_BODY_DETECT,
	E_QRCode_String,
	E_LINE_CONNECTION_MODE,
	E_WIFI_CONNECTION_MODE
}E_SDK_ALARM_TYPE;

typedef struct 
{
    E_SDK_ALARM_TYPE	e_alarm_type;
	char alarm_pic_url[256];
	char alarm_record_path[256];
	char QrString[128];
}T_SDK_ALARM_CALLBACK_PARAM;

typedef int	(*F_SDK_Alarm_Callback)(T_SDK_ALARM_CALLBACK_PARAM *pt_alarm);

typedef struct 
{
	F_SDK_Alarm_Callback	fp_callbak;	
	int	n_reserve;	
}T_SDK_ALARM_REGISTER_CALLBACK;

//********************************************************************
//********** module tpye: motion detection **************************
//********************************************************************

typedef struct {
   unsigned int	un_start_x;
   unsigned int	un_start_y;
   unsigned int	un_width;
   unsigned int	un_height;
   unsigned int	c_switch;
   unsigned int	c_sensitivity;		 //value range(1 ~100)���ƶ����ȼ���ֵ,ֵԽС,������Խ�ߡ�1(max) ~ 100(min):  (��: 100,  ��: 90  ��: 60  ��: 30)
   short	s_threshold;	 //when below threshold, not considered as motion; else, trigger motion   
}T_SDK_VIDEO_MOTION_SINGEL;

typedef enum {
  AM_MD_ALGO_MSE	= (0x01 << 0),
  AM_MD_ALGO_MOG2	= (0x01 << 1),
  AM_MD_ALGO_HYBRID	= AM_MD_ALGO_MSE | AM_MD_ALGO_MOG2,
  AM_MD_ALGO_NUM	= 2,
} E_SDK_VIDEO_MOTION_ALGO;

typedef struct 
{
	E_SDK_VIDEO_MOTION_ALGO e_algo_type;	//AM_MD_ALGO_MSE or AM_MD_ALGO_MOG2
	T_SDK_VIDEO_MOTION_SINGEL t_video_motion_rect; //�ֶ�����ʱֻ����һ����������
	unsigned int un_mode;	// �ֶ���������0 or �Զ����������1
	unsigned int un_submode; //�������1x1=0, 2x2=1, 3x3=2, 4x4=3
	unsigned int un_enable;//���ݶ����ģʽ��ѡ�������Ƿ�ʹ�����4x4=16;
}T_SDK_VIDEO_MOTION_ALARM;	 

//********************************************************************
typedef struct 
{
	unsigned int	un_switch;
	unsigned int	un_sensitivity;  //PIR���ȼ�(1-10)��ֵԽС��������Խ��  (��: 8, ��: 5, ��: 2)
}T_SDK_PIR_ALARM;         //(only for HiSilicon)

typedef struct 
{
	unsigned int	un_switch;
	unsigned int	un_sensitivity;
}T_SDK_DOORBELL_ALARM;    //(only for HiSilicon)

typedef struct 
{
	unsigned int	un_switch;
	unsigned int	un_sensitivity;
}T_SDK_AUDIO_ALARM;     

typedef struct 
{
	unsigned int	un_switch;
	unsigned int	un_sensitivity;
}T_SDK_SHELTER_ALARM;	//(not support yet)

typedef struct 
{
	unsigned int	un_switch;
	unsigned int	un_sensitivity;
}T_SDK_IO_ALARM;


//IPCһ���������ýṹ�壬��ʱ����
typedef struct 
{
	unsigned int	un_switch;
	unsigned int	reserved[3];
}T_SDK_ONEKEY_ALARM_CONTROL;


typedef struct 
{
	T_SDK_VIDEO_MOTION_ALARM	t_motion;
	T_SDK_PIR_ALARM	t_PRI;	//(only for HiSilicon)
    T_SDK_DOORBELL_ALARM	t_doorbell;	//(only for HiSilicon)
	T_SDK_AUDIO_ALARM	t_audio;
	T_SDK_SHELTER_ALARM	t_shelter;	//(not support yet)
    T_SDK_IO_ALARM	t_IO;
}T_SDK_ALARM_PARAM;


//IPC�����������ýṹ�壬��ʱ����
typedef struct 
{
	unsigned int	alarm_ring_no;
	unsigned int	reserved[3];
}T_SDK_ALARM_RING_PARAM;


//�¶ȱ��������ṹ��
typedef struct 
{	
	unsigned int alarm_enale;			//�������¶ȱ������أ� 0:������ȫ���رգ� 1:���޿��������޹رգ�2:���޹رգ����޿�����3:������ȫ������
	unsigned int temperature_type;		//�¶ȱ�ʾ���ͣ� 0:��ʾ�����¶�.C�� 1����ʾ�����¶�.F
	double curr_temperature_value;		//��ǰ�¶�
	double max_alarm_value;				//���ޱ����¶�
	double min_alarm_value;				//���ޱ����¶�
	unsigned char reserved[16];			//
}T_SDK_TEMPERATURE_ALARM_PARAM;


//********************************************************************
//********** module tpye: OSD on-screen display (a6)********************************
//********************************************************************
typedef struct 
{
	unsigned int	un_show;	//value range(1:display 0:close)
	unsigned int	un_color;	//value range(1:Black 2:Yelloow 3:Red 4:Blue 5:White Other default red)
	unsigned int	un_x_coordinate;					
	unsigned int	un_y_coordinate;
}T_SDK_SINGLE_OSD_PARAM;

typedef struct 
{
	unsigned int	un_encode_channel_id;	//(Input Param)
	char	a_title1[64];          
	char	a_title2[64];           
	T_SDK_SINGLE_OSD_PARAM	t_time;
	T_SDK_SINGLE_OSD_PARAM	t_title1;
	T_SDK_SINGLE_OSD_PARAM	t_title2;
}T_SDK_ALL_OSD_PARAM;

typedef struct 
{
	unsigned int	un_encode_channel_id;    
	unsigned int	un_show_Time;	//value range(1:display 0:close)
	unsigned int	un_show_Date;	//value range(1:display 0:close)
	unsigned int	un_show_Title1;	//value range(1:display 0:close)
	unsigned int	un_show_Title2;	//value range(1:display 0:close)
}T_SDK_OSD_SWITCH;

typedef struct 
{
	unsigned int	un_encode_channel_id;      
	unsigned int	un_color;	//goke :value range(// 0:Black, 1:Red, 2:Blue, 3:Green, 4:Yellow, 5:Magenta, 6:Cyan, 7:White)
}T_SDK_OSD_COLOR;

typedef struct 
{
	unsigned int	un_encode_channel_id; 
	unsigned int	un_x_time;   
	unsigned int	un_y_time;
	unsigned int	un_x_title1;   
	unsigned int	un_y_title1;
    unsigned int	un_x_title2;   
	unsigned int	un_y_title2;
}T_SDK_OSD_POS;

typedef struct 
{
	unsigned int	un_encode_channel_id;  
	char	a_title1[64];  
	char	a_title2[64]; 
}T_SDK_OSD_TITLE;



//********************************************************************
//********** module tpye: Record (a7)******************************
//********************************************************************
typedef cqueue P_QUEUE;	
typedef enum 
{
    SDK_UNKNOWN_RECORD = 0,
    SDK_EVENT_RECORD,
    SDK_MANUAL_RECORD,
}E_SDK_RECORD_TYPE;

typedef struct 
{
	unsigned int	un_switch;
	unsigned int	un_audio_switch;
	unsigned int 	un_manual_record_switch;	//�ֶ�¼�񿪹�
	unsigned int	un_encode_channel_id;   
	unsigned int	un_file_duration; 
	unsigned int	un_loop;	//value range of auto circulate record(0:on 1:off)
	unsigned int	un_file_type;	//record file type value range (0:ts 1:mp4 2:flv)
}T_SDK_RECORD_PARAM;

typedef struct 
{
	unsigned int	un_lock;
	char	a_file_name[64]; 
}T_SDK_RECORD_LOCK_FILE;

typedef struct 
{
	char	a_month[16];	//example:"201401"  (input Param. 2014 means year,01 means month)
	char*	cp_list;	//example:"201401013|201401021|201401122|" (Output Param. 2014 means year , in 201401013 01 means month ,3 meas how many files exist) 
	unsigned int	un_list_len;	
}T_SDK_RECORD_MONTH_LIST;

typedef struct 
{
	char	a_day[16];				//example:"20140112"(input Param. 2014 means year,01 means month,12 mens the day)
	unsigned int  file_type;		//�����ļ����� (��Ƶ: 0 , ͼƬ: 1)
	unsigned int  file_counts;		//�ļ���
									/*example:"201401121132231bc0120.mp4|201401121133231bc0120.mp4|"
									(Output Param. in 201401121132231bc0120z.ts 2014 means year,01 means month ,
									12 meas the day,11 means hour, 32 means minute, 23 means second, 
									1 means the file can not remove when auto circulate record is open,
									b means record type (value frome enum RECORD_TYPE + 'a')
									c means alarm type (value frome enum E_SDK_ALARM_TYPE + 'a')) 
									012 means record time 
									.mp4 meas record file type*/
	char*	cp_list;						   
	unsigned int	un_list_len;	
}T_SDK_RECORD_DAY_LIST;

typedef struct 
{
	char	filename[32];			//example:"201401121132231bc0120.mp4"
	unsigned int  direction;		//���ҷ���,0:����(����); 1:����(����);
	unsigned int  file_counts;		//��Ҫ���ҵ��ļ���
	unsigned int  Counts;			//ʵ���ļ���
									/*example:"201401121132231bc0120.mp4|201401121133231bc0120.mp4|"
									(Output Param. in 201401121132231bc0120z.ts 2014 means year,01 means month ,
									12 meas the day,11 means hour, 32 means minute, 23 means second, 
									1 means the file can not remove when auto circulate record is open,
									b means record type (value frome enum RECORD_TYPE + 'a')
									c means alarm type (value frome enum E_SDK_ALARM_TYPE + 'a')) 
									012 means record time 
									.mp4 meas record file type*/
	char*	cp_list;						   
	unsigned int	un_list_len;	
}T_SDK_RECORD_ASSIGNTIME_DAY_LIST;

typedef struct 
{
	char	a_file_name[32]; 		 //example:"201401121132231bc0120.mp4"(input param)
    char	a_path[128];  //example:"/sdcard/ipc/201401/12/201401121132231bc0120.mp4"
}T_SDK_RECORD_FILE_PATH;
typedef struct
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
}T_SDK_REC_DAY_NODE;

typedef struct
{
	unsigned int 	count;
	P_QUEUE 	 	info;
}T_SDK_REC_DAY_LIST;


typedef struct
{
	unsigned int start;
	unsigned int type;
	unsigned int duration;
}T_SDK_REC_EVENT_NODE;

typedef struct
{
	char					root[128];
	int						count;
	T_SDK_REC_EVENT_NODE*	info;
}T_SDK_REC_EVENT_LIST;

typedef struct
{
	unsigned int			time;
	T_SDK_REC_EVENT_LIST	list;
}T_SDK_REC_DAY_EVENT;

typedef struct
{
	unsigned int start;
	char		 name[256];
}T_SDK_REC_SPLIT_INFO;

typedef struct
{
	unsigned int			time;
	T_SDK_REC_SPLIT_INFO	info;
}T_SDK_REC_SPLIT;

typedef struct
{
	char	name[32];
}T_SDK_REC_SUB_NODE;

typedef struct
{
	char				root[128];
	int					count;
	T_SDK_REC_SUB_NODE*	info;
}T_SDK_REC_SUB_LIST;

typedef enum
{
	E_REC_SPLIT_FIND_TYPE_EXACT,
	E_REC_SPLIT_FIND_TYPE_NEXT,
	E_REC_SPLIT_FIND_TYPE_FFLUSH_NEXT,
}E_REC_SPLIT_FIND_TYPE;

typedef struct
{
	unsigned int			start;
	char 					file_name[128];
}T_SDK_REC_SPLIT_INFO_EX;

typedef struct
{		
	unsigned int		 	time;
	E_REC_SPLIT_FIND_TYPE 	type;
	
	T_SDK_REC_EVENT_LIST	event;
	T_SDK_REC_SUB_LIST		split;
	T_SDK_REC_SPLIT_INFO_EX split_info;		//������Ƭ����Ϣ
	int 					event_index; 
	int 					splite_index;
}T_SDK_REC_SPLIT_BUFFERRING;

typedef struct
{
	unsigned int a_total_size;	//������
	unsigned int a_used_size;	//��������
	unsigned int a_free_size;	//δ������
	unsigned int a_reserve[2];	//����
}T_SDK_STORAGE_INFO;

typedef struct 
{
 	unsigned int StartTimeStamp;	//��ʼʱ�� 
	unsigned int EndTimeStamp;		//����ʱ��
	unsigned int AlarmType;			//�澯����
}T_SDK_RECORD_LIST;

typedef struct 
{
	char* lastFd;						//��һ�ε��������ļ�������
	unsigned int start_time;
	unsigned int end_time;			//jie
	T_SDK_RECORD_LIST record_list;
}T_SDK_GET_RECORD_LIST;


typedef struct 
{
	unsigned int reference_time;	//�������ˢ��ʱ��
	char* lastFd;
	T_SDK_RECORD_LIST record_list;	//
}T_SDK_REFRESH_RECORD_LIST;

typedef struct 
{
	unsigned int oldest_time;	//��ȡ���������ʱ��
}T_SDK_GET_RECORD_LIST_OLDEST_TIME;



//********************************************************************
//********** module tpye: snapshot (a8)****************************
//********************************************************************
typedef struct 
{
	unsigned int	un_switch;			
	char	a_save_file_path[128];		
}T_SDK_SNAPSHOT_PARAM;
typedef struct
{    
	char pic_path[128];
}T_SDK_PIC_PATH;
typedef struct
{    
	unsigned int	un_switch;			
}T_SDK_PIC_SWITCH;
//********************************************************************
//********** module tpye: upgrade (a9)****************************
//********************************************************************
typedef struct
{
    unsigned int	un_mode;     		//value range(0:Download but no upgrade 1:upgrade but no upgrade 2:Dowload and upgrade)
    char	a_package_name[128]; 
    char	a_server_path[128]; 	
}T_SDK_UPGRADE_PARAMS;

typedef struct
{
	char	a_ipaddr[128];	//ip address
	unsigned int	un_port;	//ip port
	unsigned int result;	//0 -> create upgrade thread success; 1->malloc failed;  2 -> create thread failed; 3 -> is upgrading
	unsigned int remoteFlag;	//�Ƿ���Զ������	 0:����������;	1:����������;
	unsigned int cancelFlag;	//ȡ��������־Ĭ��Ϊ0��ȡ��1ʱȡ������
}T_SDK_UPGRADE_BYSELF_PARAMS;

typedef struct
{
	unsigned int un_mode;				//0 -> app;	1 -> fw;	2 -> kernel;	3 -> uboot
	char a_current_ver[32];				//current version
	char a_local_path[256];				//upgrade package path
	long un_FileSize;
}T_SDK_UPGRADE_BYLOCAL_PARAMS;



//********************************************************************
//********** module tpye: network (aa)****************************
//********************************************************************
typedef enum _E_SDK_WIFI_MODE
{
	E_SDK_WIFI_AP_MODE = 0x00,
	E_SDK_WIFI_CLIENT_MODE,
	E_SDK_WIFI_AP_CLIENT_MODE,
	E_SDK_WIFI_WPS_MODE,
	E_SDK_WIFI_MODE_NUM
}E_SDK_WIFI_MODE;

typedef enum _E_SDK_NET_STATUS
{
	E_SDK_DISCONNECT,  
	E_SDK_CONNECT,  
	E_SDK_SETTING,  
	E_SDK_CONNECTING, 
}E_SDK_NET_STATUS;


typedef struct
{
	char	a_SSID[64];
	unsigned int  un_signal_level;
	unsigned int  un_ssid_flag;
}T_SDK_SEARCH_SSID_INFO;

typedef struct
{
	unsigned int	un_ssid_num;
	T_SDK_SEARCH_SSID_INFO	t_info[30];
}T_SDK_SEARCH_SSID_NEARBY;

/*
typedef struct
{
	E_SDK_WIFI_MODE	e_wifi_mode;
	E_SDK_NET_STATUS	e_wifi_connect_status;	
	char	a_SSID[64];
	char	a_passwd[64];
	unsigned int	un_encrypt;
}T_SDK_WIRELESS_PARAMS;
*/
typedef struct
{
	E_SDK_WIFI_MODE e_wifi_mode;
	E_SDK_NET_STATUS	e_wifi_connect_status;	
	char	a_SSID[64];
	char	a_passwd[64];
	unsigned int	un_encrypt;
	int     qlink_start;      //1�޸�������ʼ��2�޸�����ʧ�ܣ�0Ĭ��ֵ
}T_SDK_WIRELESS_PARAMS;



typedef struct
{
    char	a_IP[64];
}T_SDK_IPADDR;

typedef struct
{
    unsigned int	ddns_swicth;    //value range(1:enable 0:disable)
	char	a_username[50];  
	char	a_password[50];  
	char	a_server[128];   
	char	a_domain[128];  
	unsigned int	un_protocol_type;      //value range(:0: Oray  protocol 1:DYNDNS protocol)
}T_SDK_DDNS;


typedef struct
{
	char	a_DNS[2][64]; 
}T_SDK_DNS;


typedef struct _T_NTP_CONFIG_S
{
	unsigned int	un_switch;		//value range(0:close 1:open)
	unsigned int	un_cycle;          //value range(1~7*24 hour)
	unsigned int	un_timezone;	//value range(0-12: The west 12 zone - 0 zone ;13-24:East 1 zone - East 12 zone)
	char	a_host[128];	
	unsigned int	un_daylight;     
}T_SDK_NTP;

typedef struct
{
    char	a_gateway[64];
}T_SDK_GATEWAY;

typedef struct
{
    char	a_mask[64];
}T_SDK_NET_MASK;

typedef struct
{
	char	a_wire_MAC[19];
	char	a_wireless_MAC[19];	
}T_SDK_NET_MAC;  // not support

typedef struct
{
    char	a_hostname[64];
}T_SDK_HOSTNAME;

typedef struct
{
	unsigned int un_protocals_type;
	T_SDK_WIRELESS_PARAMS	t_wireless_param;
	unsigned int	un_dhcp_switch; 			//0:static 1:dhcp
	char	a_hostname[64];
	char	a_IP[64];
	char	a_DNS[2][64]; 
	T_SDK_NTP	t_NTP;
	char	a_gateway[64];
	char	a_mask[64];
	char	a_wire_MAC[19];
	char	a_wireless_MAC[19];	
	T_SDK_DDNS	t_DDNS_info;
}T_SDK_NETWORK_PARAMS;


//ntp �����ṹ����
typedef struct
{
	unsigned int	un_NtpOpen;						//ntpУʱ���� (1:������ 0:�ر�)
	unsigned int	un_EuroTime;					//����ʱ����  (1:����,  0:�ر�)
	unsigned int	un_NtpRefTime;					//ntpУʱ��� (��λ��)
	int				un_TimeZone;					//ʱ�� (-12~11)
	char     		a_NtpServer[64];		        //ntpУʱ��������ַ
	unsigned int	un_ntp_port; 					//ntpУʱ�������˿�
	unsigned int	un_Res[2];
}T_SDK_NTP_CFG_PARAMS;


//********************************************************************
//********** module tpye: SDK DEBUG (ff)**************************
//********************************************************************
typedef enum 
{
	FATAL, 	
	ERROR, 		
	WARING,		
	NOTE, 
	None,
}E_SDK_DEBUG_LEVEL;

/*
int yhp2p_data_build(T_SDK_STREAM_CALLBACK_PARAM *encodeData);
*/


typedef struct _PTZ_POSI_
{
	int s32X;
	int s32Y;
}PTZ_POSI_ST;

#if defined (__cplusplus)
}
#endif

#endif

