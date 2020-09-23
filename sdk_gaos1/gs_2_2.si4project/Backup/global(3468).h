/**************************************************************************
 * 	FileName:	global.h
 *	Description:	ϵͳ�����ݽṹ��꿪�صĶ��壬��ȫ���̰���
 *	Copyright(C):	2014-2020 Gos Inc.
 *	History:		����֮ǰHi3518ϵ���ļ��޸��˽ṹ�����������
 *	Author:		johnny
 *	Created:		2015-12-11
 *	Updated:		
 *					
 **************************************************************************/
#ifndef __GLOBAL_H__
#define __GLOBAL_H__

//#include "GVAP_deviceDiscover.h"
#include "adi_gpio.h"

#define     HI3516_ARCH             1
//
/*----------------------------------------------*
  �Զ�������������Ͷ���
 *----------------------------------------------*/
typedef unsigned long long      UInt64;
typedef long long      			Int64;
typedef unsigned char           UInt8;
typedef unsigned short          UInt16;
typedef unsigned int            UInt32;
typedef char                    Int8;
typedef short                   Int16;
typedef int                     Int32;
;
//�������õ�ͷ�ļ� ͳһ��������
#define PACKED		__attribute__((packed, aligned(1)))
#define PACKED4		__attribute__((packed, aligned(4)))

//==========�汾����==========
#define GOS_SDK_VERSION				1  //Ĭ��һ������


//��������ʾ���滹�����������
#define GOS_gk7102_T5886GAA_VERSION		0  //100W ҡͷ�� gc1024	��������ѡ��������¶�
#define GOS_gk7102_T5820GBA_VERSION		0  //130W ��Ƭ�� sc1035		
#define GOS_gk7102_T5881GBA_VERSION		0  //130W ҡͷ�� sc1035
#define GOS_gk7102_T2858GBA_VERSION		0  //130W ҡͷ�� sc1035 ͷ��
#define GOS_gk7101_T2858GCA_VERSION		0  //200W ҡͷ�� ov2710 ͷ��
#define GOS_gk7101_T5820GCA_VERSION		0  //200W ��Ƭ�� ov2710
#define GOS_gk7101_T5886GCA_VERSION		0  //200w ҡͷ�� ov2710 
#define GOS_gk7101_T5881GCA_VERSION		0  //200w ҡͷ�� ov2710
#define GOS_gk7101_T5925GCA_VERSION		0  //200w ����� ov2710
#define GOS_gk7102_T5703GAA_VERSION		0  //100w ��Ƭ�� gc1034 �����ɱ���������
#define GOS_gk7102_T5703GAB_VERSION		0  //100w ��Ƭ�� h62   
#define GOS_gk7102s_T5830GAA_VERSION	0  //100w ҡͷ�� h62 GOS_PHOTOSENSITIVE=5
#define GOS_gk7102s_T5708GAA_VERSION	0  //100w ��Ƭ�� h62 GOS_PHOTOSENSITIVE=3
#define GOS_gk7102s_T5825GAB_VERSION	0  //100w ��Ƭ�� h62
#define GOS_gk7102s_T5821GAA_VERSION	0  //100w ��Ƭ�� h62
#define GOS_gk7102s_T5826GAA_VERSION	0  //100w ��Ƭ�� h62
#define GOS_gk7102s_T5703GCA_VERSION	0  //200w ��Ƭ�� f23
#define GOS_gk7102s_T5830GCA_VERSION	0  //200w ��̨�� f23
#define GOS_gk7102s_T5830GCB_VERSION	0  //200w ��̨�� f23 GOS_gk7102s_T5830GCA_VERSION ����
#define GOS_gk7102c_C5833GCA_VERSION	0  //200w ��̨�� f23 GOKE_CHIP_7102C_A
#define GOS_gk7102c_C5925GCA_VERSION	0  //200w ����� f23 GOKE_CHIP_7102C_A
#define GOS_gk7102c_C5929GCA_VERSION	0  //200w ����� f23 GOKE_CHIP_7102C_A

#define GOS_gk7102c_C5931GCA_VERSION	0  //200w ����� f23 GOKE_CHIP_7102C_A
#define GOS_gk7102c_C5931GCB_VERSION	0  //200w ����� f23 GOKE_CHIP_7102C_A GOS_gk7102c_C5931GCA_VERSION
#define GOS_gk7102c_C5931GCC_VERSION	0  //200w ����� f23 GOKE_CHIP_7102C_A GOS_gk7102c_C5931GCA_VERSION
#define GOS_gk7102c_C5931GCD_VERSION	0  //200w ����� f23 GOKE_CHIP_7102C_A GOS_gk7102c_C5931GCA_VERSION
#define GOS_gk7102c_C5931GCE_VERSION	0  //200w ����� f23 GOKE_CHIP_7102C_A GOS_gk7102c_C5931GCA_VERSION

#define GOS_gk7202_C5931GCF_VERSION		0  //200w ����� f23 GOKE_CHIP_7202
#define GOS_gk7202_C5933GCA_VERSION		1  //200w ����� f23 GOKE_CHIP_7202

#define GOS_gk7202_C5939GEA_VERSION		0  //400w ����� 

#define GOKE_CHIP_7102C_A				0
#define GOKE_CHIP_7202					1
#define GOKE_CHIP_7205S					0

#define GOS_H265                  		1  // 0:H264 1:H265
#define GOS_VIDEO_2304_1296             1  // ��ֵ300��

#define Make_SDK						1


/* �豸�����,�������������Ƿ�������,7101,7102,7102s��Ӧ����˵�Ƿ�������,sensor�����ֻ���������� */
/*============ sensor =============*/
#if (GOS_gk7102_T5703GAB_VERSION || GOS_gk7102s_T5830GAA_VERSION || GOS_gk7102s_T5708GAA_VERSION || GOS_gk7102s_T5825GAB_VERSION || GOS_gk7102s_T5821GAA_VERSION || GOS_gk7102s_T5826GAA_VERSION)
#define SENSOR_SOIH62           1
#elif (GOS_gk7102s_T5703GCA_VERSION || GOS_gk7102s_T5830GCA_VERSION ||GOS_gk7102c_C5929GCA_VERSION || GOS_gk7102c_C5833GCA_VERSION || GOS_gk7102c_C5925GCA_VERSION || GOS_gk7102c_C5931GCA_VERSION || GOS_gk7202_C5933GCA_VERSION || GOS_gk7202_C5931GCF_VERSION)
#define SENSOR_JXF23            1
#endif

//============configuration===========
#define DOMESTIC_SERVER			1		// 0 ����     1���ڣ�ֻ���ulifeƽ̨)
#define VOIC_LANGUAGE			1		// 0 ����ʾ 1����  2Ӣ��
#if DOMESTIC_SERVER
#define Amazon_AVS				0       // Amazon Alexa Voice Service
#define Amazon_ASK				0       // Amazon Alexa Skills Kit
#else
#define Amazon_AVS				0       // Amazon Alexa Voice Service
#define Amazon_ASK				3       // Amazon Alexa Skills Kit  0:none 1:Alexa 2:Google 3:Alexa&Google
#endif
#define SOUND_PLAY				1		//������������ 0 off 1 on
#define GOS_21CN				0       //�� GOS_21CN_V2������ �ر�GOS_21CN_V2
#define GOS_21CN_V2             1       //�°�SDK �� GOS_21CN������ �ر�GOS_21CN

#define GOS_21CN_TEST_ENV       0       //0:formal environment 1:test environment
#define GOS_21CN_MUSIC          1

#if GOS_gk7202_C5939GEA_VERSION || GOS_gk7202_C5933GCA_VERSION
#define GOS_21CN_QLINK          0		//21cn�޸���������
#else
#define GOS_21CN_QLINK          1		//21cn�޸���������
#endif
#define GOS_PERSON_BODY_DETECT  1       //������⹦��
#define MOTION_TRACKING     	1		//�ƶ�׷��



#define AEC_OPEN				0       // ���������ĺ�
#define VOICE_MODE_SWITCH		0       // APP�Ƿ�֧��ȫ˫���Ͱ�˫���л� ����AEC_OPEN

#define SELECT_RECORD_LIB		4       //ѡ��¼��⣬1:Ԥ����洢�⣻2:����tutk������¼��ʽ��3:��Ԥ����
#if (SELECT_RECORD_LIB == 1)
#define DISK_MANAGER              
#elif(SELECT_RECORD_LIB == 2)
#define PUBLIC_TUTK_PALYBACK_SUPPORT
#elif(SELECT_RECORD_LIB == 3)
#define RECORD_LJJ 				1
#endif

#if (GOS_gk7202_C5931GCF_VERSION || GOS_gk7202_C5933GCA_VERSION || GOS_gk7202_C5939GEA_VERSION)
#define GOS_Full_Color_Night_Vision		1
#endif

#if GOS_gk7102c_C5931GCA_VERSION
#define IRCUT_5931
#endif

#define CLOUD_STORAGE			1		//�������ƴ洢����:0. ��֧���ƴ洢; 1. ֧���ƴ洢; 2. ��֧���ƴ洢, ����������SD���ط�; 3. ֧���ƴ洢, ������������SD���ط�;
#define P2P_PLATFORM			5       // 1. TUTK   2. 4.0_P2P   3. 4.0_TCP   4. 4.0_TCP&4.0_P2P
#define ULIFE_PUSH				1       // 0. tutk���ͷ���; 1. ulife���ͷ���
#define SDK_USE_TLIB			0		//Ulife1.0ƽ̨��غ꿪��
#define TUTK_PLATFORM_FLAG		1		//TUTKƽ̨��غ꿪��
#define TUTK_SDK				0		//��SDKʱ�򿪣�Ĭ�Ϲر�
#define GK_MEDIA_BUF_RECORD		1		//ʹ�ù���media buf¼��
#define TUTK_PLATFORM_WITH_40TCP 0      // TUTK�Ƿ����TCPת��
//#define WIFI_AP_MODE_21CN		1 		//21CN APģʽ

#define FFMPEG_MP4				0
#define MY_MP4					0		//200W
#define MP4_V2					0		//130W, 100W
#define GOS_VENC_CALCBITRATE	0		//֡�ʡ�����ͳ��
#define GOS_TEMP_HUM			0		//5886gר�� ��������ʪ�ȿ���
#if (GOS_gk7102s_T5830GAA_VERSION || GOS_gk7102s_T5830GCA_VERSION || GOS_gk7102c_C5833GCA_VERSION)        //FOR ircut
#define  GOS_PHOTOSENSITIVE		5       // CONS:5  
#else
#define  GOS_PHOTOSENSITIVE		3	    // PROS:3
#endif
#define HARD_UNBIND			 	1       // �Ƿ�֧��Ӳ���
#define AP_HARD_UNBIND			0       // APģʽ�����Ƿ�֧��Ӳ���
#define _RECORD_TYPE_ALIYUN		1       //�����ƴ洢���ܿ���
#define AUDIO_ALL_IN_G711A		1

//============δ���Թ��Ĺ���ģ��,��û���ù�==========
#define GOS_MODULE_RTSP         0
#define GOS_MODULE_ONVIF        0

//============usual function module==========
#if GOS_gk7102_T5886GAA_VERSION
#define GOS_MODULE_LOG		    	1
#define GOS_MODULE_RECORD	    	1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        	1 
#define GOS_MODULE_UPGRADE			1
#define GOS_MODULE_MOTOR	        1
#define GOS_MODULE_ONVIF	        0
#define GOS_MODULE_VIDEO		    0	//��ʱ�����0
#define GOS_MODULE_AUDIO	        1
#define GOS_MODULE_WIFI	        	1
#define GOS_MODULE_OSD	        	1
#define GOS_MODULE_ALARM	        1
#define GOS_MODULE_TEMP_HUM	    	0
#define GOS_MODULE_NIGHT_VISUAL		1
#define GOS_MODULE_LED	        	1
#define GOS_MODULE_SNAP	        	1
#define GOS_MODULE_MOTION	    	1
#define GOS_MODULE_WATCH_DOG     	1
#define GOS_SEGMENT_FAULT 			1
#define GOS_LINE				    0
#define GOS_WIFI 					1

#elif (GOS_gk7102s_T5830GCB_VERSION)
#define GOS_MODULE_LOG		    	1
#define GOS_MODULE_RECORD	    	1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        	1
#define GOS_MODULE_UPGRADE			0
#define GOS_MODULE_MOTOR	        1
#define GOS_MODULE_ONVIF	        0
#define GOS_MODULE_VIDEO		    0	//��ʱ�����0
#define GOS_MODULE_AUDIO	        1
#define GOS_MODULE_WIFI	        	1
#define GOS_MODULE_OSD	        	1
#define GOS_MODULE_ALARM	        1
#define GOS_MODULE_TEMP_HUM	    	0
#define GOS_MODULE_NIGHT_VISUAL		1
#define GOS_MODULE_LED	        	1
#define GOS_MODULE_SNAP	        	1
#define GOS_MODULE_MOTION	    	1
#define GOS_MODULE_WATCH_DOG    	1
#define GOS_SEGMENT_FAULT 			1
#define GOS_LINE					1
#define GOS_WIFI 					1

#elif (GOS_gk7102s_T5830GCA_VERSION)
#define GOS_MODULE_LOG		    	1
#define GOS_MODULE_RECORD	    	1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        	1
#define GOS_MODULE_UPGRADE			0
#define GOS_MODULE_MOTOR	        1
#define GOS_MODULE_ONVIF	        0
#define GOS_MODULE_VIDEO		    0	//��ʱ�����0
#define GOS_MODULE_AUDIO	        1
#define GOS_MODULE_WIFI	        	1
#define GOS_MODULE_OSD	        	1
#define GOS_MODULE_ALARM	        1
#define GOS_MODULE_TEMP_HUM	    	0
#define GOS_MODULE_NIGHT_VISUAL		1
#define GOS_MODULE_LED	        	1
#define GOS_MODULE_SNAP	        	1
#define GOS_MODULE_MOTION	    	1
#define GOS_MODULE_WATCH_DOG    	1
#define GOS_SEGMENT_FAULT 			1
#define GOS_LINE					0
#define GOS_WIFI 					1

#elif (GOS_gk7102c_C5833GCA_VERSION)
#define GOS_MODULE_LOG		    		1
#define GOS_MODULE_RECORD	    		1
#define GOS_MODULE_SCHEDULES_RECORD		0
#define GOS_MODULE_COMM	        		1	//////////////////////////////////////////////////////////
#define GOS_MODULE_UPGRADE				0
#define GOS_MODULE_MOTOR	        	1	//////////////////////////////////////////////////////////
#define GOS_MODULE_ONVIF	        	0
#define GOS_MODULE_VIDEO		    	0	//��ʱ�����0
#define GOS_MODULE_AUDIO	        	1
#define GOS_MODULE_WIFI	        		1
#define GOS_MODULE_OSD	        		1
#define GOS_MODULE_ALARM	        	1
#define GOS_MODULE_TEMP_HUM	    		0
#define GOS_MODULE_NIGHT_VISUAL			1
#define GOS_MODULE_LED	        		1
#define GOS_MODULE_SNAP	        		1
#define GOS_MODULE_MOTION	    		1
#define GOS_MODULE_WATCH_DOG     		1
#define GOS_SEGMENT_FAULT 				0
#define GOS_LINE				    	0
#define GOS_WIFI 						1

#elif (GOS_gk7102c_C5929GCA_VERSION || GOS_gk7102c_C5925GCA_VERSION || GOS_gk7102c_C5931GCA_VERSION || GOS_gk7202_C5933GCA_VERSION || GOS_gk7202_C5931GCF_VERSION || GOS_gk7202_C5939GEA_VERSION)
#define GOS_MODULE_LOG		    		1
#define GOS_MODULE_RECORD	    		0
#define GOS_MODULE_SCHEDULES_RECORD		0
#define GOS_MODULE_COMM	        		0
#define GOS_MODULE_UPGRADE				0
#define GOS_MODULE_MOTOR	        	0
#define GOS_MODULE_ONVIF	        	0
#define GOS_MODULE_VIDEO		    	0	//��ʱ�����0
#define GOS_MODULE_AUDIO	        	1
#define GOS_MODULE_WIFI	        		1
#define GOS_MODULE_OSD	        		1
#define GOS_MODULE_ALARM	        	1
#define GOS_MODULE_TEMP_HUM	    		0
#define GOS_MODULE_NIGHT_VISUAL			1
#define GOS_MODULE_LED	        		1
#define GOS_MODULE_SNAP	        		1
#define GOS_MODULE_MOTION	    		1
#define GOS_MODULE_WATCH_DOG     		1
#define GOS_SEGMENT_FAULT 				1
#define GOS_LINE				   		1
#if GOS_gk7202_C5939GEA_VERSION || GOS_gk7202_C5933GCA_VERSION
#define GOS_WIFI 						0
#else
#define GOS_WIFI 						1
#endif

#elif (GOS_gk7102s_T5703GCA_VERSION)
#define GOS_MODULE_LOG		    	1
#define GOS_MODULE_RECORD	    	1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        	0
#define GOS_MODULE_UPGRADE			0
#define GOS_MODULE_MOTOR	        0
#define GOS_MODULE_ONVIF	        0
#define GOS_MODULE_VIDEO		    0	//��ʱ�����0
#define GOS_MODULE_AUDIO	        1
#define GOS_MODULE_WIFI	        	1
#define GOS_MODULE_OSD	        	1
#define GOS_MODULE_ALARM	        1
#define GOS_MODULE_TEMP_HUM	    	0
#define GOS_MODULE_NIGHT_VISUAL		1
#define GOS_MODULE_LED	        	1
#define GOS_MODULE_SNAP	        	1
#define GOS_MODULE_MOTION	    	1
#define GOS_MODULE_WATCH_DOG     	1
#define GOS_SEGMENT_FAULT 			0
#define GOS_LINE				    0
#define GOS_WIFI 					1

#elif (GOS_gk7102_T5703GAA_VERSION || GOS_gk7102s_T5830GAA_VERSION )
#define GOS_MODULE_LOG		    	1
#define GOS_MODULE_RECORD	    	1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        	1
#define GOS_MODULE_UPGRADE			0
#define GOS_MODULE_MOTOR	        1
#define GOS_MODULE_ONVIF	        0
#define GOS_MODULE_VIDEO		    0	//��ʱ�����0
#define GOS_MODULE_AUDIO	        1
#define GOS_MODULE_WIFI	        	1
#define GOS_MODULE_OSD	        	1
#define GOS_MODULE_ALARM	        1
#define GOS_MODULE_TEMP_HUM	    	0
#define GOS_MODULE_NIGHT_VISUAL		1
#define GOS_MODULE_LED	        	1
#define GOS_MODULE_SNAP	        	1
#define GOS_MODULE_MOTION	    	1
#define GOS_MODULE_WATCH_DOG     	1
#define GOS_SEGMENT_FAULT 			0
#define GOS_LINE				    0
#define GOS_WIFI 					1

#elif (GOS_gk7102s_T5708GAA_VERSION || GOS_gk7102_T5703GAB_VERSION || GOS_gk7102s_T5825GAB_VERSION || GOS_gk7102s_T5821GAA_VERSION || GOS_gk7102s_T5826GAA_VERSION)
#define GOS_MODULE_LOG		    	1
#define GOS_MODULE_RECORD	    	1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        	0
#define GOS_MODULE_UPGRADE			0
#define GOS_MODULE_MOTOR	        0
#define GOS_MODULE_ONVIF	        0
#define GOS_MODULE_VIDEO		    0	//��ʱ�����0
#define GOS_MODULE_AUDIO	        1
#define GOS_MODULE_WIFI	        	1
#define GOS_MODULE_OSD	        	1
#define GOS_MODULE_ALARM	        1
#define GOS_MODULE_TEMP_HUM	    	0
#define GOS_MODULE_NIGHT_VISUAL		1
#define GOS_MODULE_LED	        	1
#define GOS_MODULE_SNAP	        	1
#define GOS_MODULE_MOTION	    	1
#define GOS_MODULE_WATCH_DOG     	1
#define GOS_SEGMENT_FAULT 			0
#define GOS_LINE				    0
#define GOS_WIFI 					1

#elif GOS_gk7102_T5820GBA_VERSION
#define GOS_MODULE_LOG		    	1
#define GOS_MODULE_RECORD	    	1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        	0 
#define GOS_MODULE_MOTOR	        0
#define GOS_MODULE_ONVIF	        0
#define GOS_MODULE_VIDEO		    0		//��ʱ�����0
#define GOS_MODULE_AUDIO	        1
#define GOS_MODULE_WIFI	        	1
#define GOS_MODULE_OSD	        	1
#define GOS_MODULE_ALARM	        1
#define GOS_MODULE_TEMP_HUM	    	0
#define GOS_MODULE_NIGHT_VISUAL		1
#define GOS_MODULE_LED	        	1
#define GOS_MODULE_SNAP	        	1
#define GOS_MODULE_MOTION	    	1
#define GOS_MODULE_WATCH_DOG     	1
#define GOS_SEGMENT_FAULT 			0
#define GOS_LINE				    0
#define GOS_WIFI 					1

#elif GOS_gk7101_T5886GCA_VERSION
#define GOS_MODULE_LOG		    	1
#define GOS_MODULE_RECORD	    	1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        	1 
#define GOS_MODULE_MOTOR	        1
#define GOS_MODULE_ONVIF	        0
#define GOS_MODULE_VIDEO		    0
#define GOS_MODULE_AUDIO	        1
#define GOS_MODULE_WIFI	        	1
#define GOS_MODULE_OSD	        	1
#define GOS_MODULE_ALARM	        1
#define GOS_MODULE_TEMP_HUM	    	1
#define GOS_MODULE_NIGHT_VISUAL		1
#define GOS_MODULE_LED	        	1
#define GOS_MODULE_SNAP	        	1
#define GOS_MODULE_MOTION	    	1
#define GOS_MODULE_WATCH_DOG     	1
#define GOS_SEGMENT_FAULT 			1
#define GOS_LINE				    0
#define GOS_WIFI 					1

#elif GOS_gk7101_T5881GCA_VERSION
#define GOS_MODULE_LOG		    	1
#define GOS_MODULE_RECORD	    	1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        	1 
#define GOS_MODULE_MOTOR	        1
#define GOS_MODULE_ONVIF	        0
#define GOS_MODULE_VIDEO		    0
#define GOS_MODULE_AUDIO	        1
#define GOS_MODULE_WIFI	        	1
#define GOS_MODULE_OSD	        	1
#define GOS_MODULE_ALARM	        1
#define GOS_MODULE_TEMP_HUM	    	0
#define GOS_MODULE_NIGHT_VISUAL		1
#define GOS_MODULE_LED	        	1
#define GOS_MODULE_SNAP	        	1
#define GOS_MODULE_MOTION	    	1
#define GOS_MODULE_WATCH_DOG     	0
#define GOS_SEGMENT_FAULT 			0
#define GOS_LINE				    0
#define GOS_WIFI 					1

#elif GOS_gk7101_T5820GCA_VERSION
#define GOS_MODULE_LOG		    	1
#define GOS_MODULE_RECORD	    	1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        	0 
#define GOS_MODULE_MOTOR	        0
#define GOS_MODULE_ONVIF	        0
#define GOS_MODULE_VIDEO		    0
#define GOS_MODULE_AUDIO	        1
#define GOS_MODULE_WIFI	        	1
#define GOS_MODULE_OSD	        	1
#define GOS_MODULE_ALARM	        1
#define GOS_MODULE_TEMP_HUM	    	0
#define GOS_MODULE_NIGHT_VISUAL		1
#define GOS_MODULE_LED	        	1
#define GOS_MODULE_SNAP	        	1
#define GOS_MODULE_MOTION	    	1
#define GOS_MODULE_WATCH_DOG     	0
#define GOS_SEGMENT_FAULT 			0
#define GOS_LINE				    0
#define GOS_WIFI 					1

#elif GOS_gk7102_T5881GBA_VERSION
#define GOS_MODULE_LOG		    	1
#define GOS_MODULE_RECORD	    	1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        	1 
#define GOS_MODULE_MOTOR	        1
#define GOS_MODULE_ONVIF	        0
#define GOS_MODULE_VIDEO		    0
#define GOS_MODULE_AUDIO	        1
#define GOS_MODULE_WIFI	        	1
#define GOS_MODULE_OSD	        	1
#define GOS_MODULE_ALARM	        1
#define GOS_MODULE_TEMP_HUM	    	0
#define GOS_MODULE_NIGHT_VISUAL		1
#define GOS_MODULE_LED	        	1
#define GOS_MODULE_SNAP	        	1
#define GOS_MODULE_MOTION	    	1
#define GOS_MODULE_WATCH_DOG     	0
#define GOS_SEGMENT_FAULT 			0
#define GOS_LINE				    0
#define GOS_WIFI 					1

#elif GOS_gk7101_T2858GCA_VERSION
#define GOS_MODULE_LOG		    1
#define GOS_MODULE_RECORD	    1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        1 
#define GOS_MODULE_MOTOR	    1
#define GOS_MODULE_ONVIF	    0
#define GOS_MODULE_VIDEO		0
#define GOS_MODULE_AUDIO	    1
#define GOS_MODULE_WIFI	        1
#define GOS_MODULE_OSD	        1
#define GOS_MODULE_ALARM	    1
#define GOS_MODULE_TEMP_HUM	    0
#define GOS_MODULE_NIGHT_VISUAL	1
#define GOS_MODULE_LED	        1
#define GOS_MODULE_SNAP	        1
#define GOS_MODULE_MOTION	    1
#define GOS_MODULE_WATCH_DOG    0
#define GOS_SEGMENT_FAULT 		0
#define GOS_LINE				1
#define GOS_WIFI 				1

#elif GOS_gk7102_T2858GBA_VERSION
#define GOS_MODULE_LOG		    1
#define GOS_MODULE_RECORD	    1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        0 
#define GOS_MODULE_MOTOR	    0
#define GOS_MODULE_ONVIF	    0
#define GOS_MODULE_VIDEO		0
#define GOS_MODULE_AUDIO	    1
#define GOS_MODULE_WIFI	        1
#define GOS_MODULE_OSD	        1
#define GOS_MODULE_ALARM	    1
#define GOS_MODULE_TEMP_HUM	    0
#define GOS_MODULE_NIGHT_VISUAL	1
#define GOS_MODULE_LED	        1
#define GOS_MODULE_SNAP	        1
#define GOS_MODULE_MOTION	    1
#define GOS_MODULE_WATCH_DOG    0
#define GOS_SEGMENT_FAULT 		0
#define GOS_LINE				1
#define GOS_WIFI 				1

#elif GOS_gk7101_T5925GCA_VERSION
#define GOS_MODULE_LOG		    1
#define GOS_MODULE_RECORD	    1
#define GOS_MODULE_SCHEDULES_RECORD	0
#define GOS_MODULE_COMM	        0 
#define GOS_MODULE_MOTOR	    0
#define GOS_MODULE_ONVIF	    0
#define GOS_MODULE_VIDEO		0
#define GOS_MODULE_AUDIO	    1
#define GOS_MODULE_WIFI	        1
#define GOS_MODULE_OSD	        1
#define GOS_MODULE_ALARM	    1
#define GOS_MODULE_TEMP_HUM	    0
#define GOS_MODULE_NIGHT_VISUAL	1
#define GOS_MODULE_LED	        1
#define GOS_MODULE_SNAP	        1
#define GOS_MODULE_MOTION	    1
#define GOS_MODULE_WATCH_DOG    0
#define GOS_SEGMENT_FAULT 		0
#define GOS_LINE				1
#define GOS_WIFI 				1

#endif
//=========== ��ֹ��δ����ı��뱨�� ==========//
#ifndef SENSOR_SOIH62
#define SENSOR_SOIH62           0
#endif
#ifndef SENSOR_JXF23
#define SENSOR_JXF23           0
#endif

//===========wifi module config==========
#if (GOS_gk7102_T5703GAA_VERSION || GOS_gk7102_T5703GAB_VERSION|| GOS_gk7102s_T5830GAA_VERSION ||GOS_gk7102s_T5708GAA_VERSION || GOS_gk7102s_T5825GAB_VERSION || GOS_gk7102s_T5821GAA_VERSION || GOS_gk7102s_T5826GAA_VERSION || GOS_gk7102s_T5703GCA_VERSION  || GOS_gk7102s_T5830GCA_VERSION || GOS_gk7102_T5886GAA_VERSION || GOS_gk7102c_C5929GCA_VERSION || GOS_gk7102c_C5833GCA_VERSION || GOS_gk7102c_C5925GCA_VERSION || GOS_gk7102c_C5931GCA_VERSION || GOS_gk7202_C5931GCF_VERSION)
#define GOS_WIFI7601			 0
#define GOS_WIFI8188			 1
#elif GOS_gk7202_C5939GEA_VERSION || GOS_gk7202_C5933GCA_VERSION
#define GOS_WIFI7601			 0
#define GOS_WIFI8188			 0
#else
#define GOS_WIFI7601			 1
#define GOS_WIFI8188			 0
#endif

#if GOS_WIFI
#define WIFI_AP_MODE_21CN		1 		//21CN APģʽ
#else
#define WIFI_AP_MODE_21CN		0 		//21CN APģʽ
#endif

#if (GOS_WIFI8188 && GOS_gk7102_T5886GAA_VERSION)
#define GOS_WIFI8188EUS	     1
#else
#define GOS_WIFI8188FTV	     1
#endif
//===========sensor��֧�ַ�ת:sc1035,h62,��Ҫ�ñ��뷭ת;gc1024 & ov2710֧��vi��ת==========//
#if (GOS_gk7102_T5820GBA_VERSION || GOS_gk7102_T5881GBA_VERSION || GOS_gk7102_T2858GBA_VERSION || SENSOR_SOIH62)
#define IMAGE_ENCODE_FLIP       1
#else
#define IMAGE_ENCODE_FLIP       0
#endif

//===========�Ѿ�ͣ��,����ȫ�����Ĺ���ģ��==========//
#define REBOOT_IN_AM2OCLOCK		0
//==================================================//
enum ALARM_TYPE
{
    UNKNOWN = 0,
    VIDEO_MOTION,
    PIR_MOTION,
    PIR_VIDEO_MOTION, 
    AUDIO_MOTION, 
    IO_ALARM,
    LOW_TEMP_ALARM,
    HIGH_TEMP_ALARM,
    LOW_HUM_ALARM,
    HIGH_HUM_ALARM,
    LOW_WBGT_ALARM,
    HIGH_WBGT_ALARM,
    CALLING,
    BODY_DETECT_ALARM
};

//ϵͳ����
typedef struct gsSYS_MAIN_S
{
    int                     day_night_switch;   		//1���� 0����
    int                     net_line_or_wifi;   		//0 line 1 wifi
    int                     search_resart;   			//bordcast discover rebuilt 0:off 1:on
    int                     platform_enable;			//0:close 1:open local and close platform 2:open all    
    int                     set_vi_flag_day;    		//�л�ҹ�ӵĿ���
    int                     set_vi_flag_night;  		//�л�ҹ�ӵĿ���
    int						Full_Color_Night_Vision;	//ȫ��ҹ�ӿ���
    int						Full_Color_State;			//ȫ��ҹ��״̬
    int						Body_Detect_State;			//����ʶ��״̬
    int						Body_Track_State;			//����׷��״̬
    int						Alarm_Interval;				//�澯���
    int                     onvif_compressing;  		//onvif�Ƿ��ѹ��ȫ
    int                     venc_max_farme;     		//vi�������֡��
    int                     audio_decode_control;		//������������
    int                     audio_yelp;         		//�������ֱ�ʾ
    int                     alarm_control;      		//һ�����ſ��� 
    int 					alarm_msg_push;				//������Ϣ���Ϳ���
	int                     LowLightNoiseLvl;   		//���նȵȼ�
    int                     alarm_flag_all;     		//���б�����־  
    int                     alarm_pir;          		//pir��������
    int                     alarm_pir_check_sec;		//pir�ж�ʱ��
    int                     alarm_pir_flag;
    int                     alarm_calling;      		//�����屨������
    int                     alarm_io;           		//io��������
    int                     record_state;       		//¼��״̬  
    int						snap_quality;	    		//ץ������ 0������ 1������
    int						tutk;						//0��֧�ֹ���app  1֧��
    int                     led_ir;
    int                     led_state;          		//��״̬
    int                     light_state;
    int                     Power;              		//p n
    int                     log_level;          		//��־�ȼ�
    int                     reboot_flag;        		//�Ƿ�Ҫ����
    int                     DevDhcpOpen;        		//0�� 1�� 
    int                     Aac_Enc_s32Handle;  		//��Ƶ���
    int                     Aaclc_Enc_s32Handle;		//��Ƶ���
    int                     Aac_Dec_s32Handle;  		//��Ƶ���
    int                     Aaclc_Dec_s32Handle;		//��Ƶ���
    int						app_get_stream_flag;		//0:�ͻ���û����  1:�ͻ���������,ȡ����
    //������
    int                     upgrade_flag;
    unsigned int            upgrade_count;
    char *                  upgrade_buf;    
	int						device_switch;				//����ͷ����
	int						device_mic_switch;			//��˷翪��
	int						device_led_switch;			//״̬�ƿ���
	int 					ulife_tool_switch;			//���⹤�߿���
    char                    bind_usrname[32];   		//���û���   
    char                    qrcode_sum[32];     		//��ά��ɨ��У����  
    char                    TimerISRFlag[1][3];			//�붨ʱ�жϱ�ʶ(���ڱ�����ˢ��ʱ��OSD)
} PACKED SYS_MAIN_S;
							
extern SYS_MAIN_S g_sysMainInfo;//johnny.liu: defined in main.c

//=========gpio handle define========	//define in main.c
extern GADI_SYS_HandleT gpioHandle_ircut_l;
extern GADI_SYS_HandleT gpioHandle_ircut_r;
extern GADI_SYS_HandleT gpioHandle_speaker;
extern GADI_SYS_HandleT gpioHandle_key;
extern GADI_SYS_HandleT gpioHandle_led_red;
extern GADI_SYS_HandleT gpioHandle_led_green;
extern GADI_SYS_HandleT gpioHandle_m2b_n;
extern GADI_SYS_HandleT gpioHandle_m2b_p;
extern GADI_SYS_HandleT gpioHandle_m2a_n;
extern GADI_SYS_HandleT gpioHandle_m2a_p;
extern GADI_SYS_HandleT gpioHandle_m1b_n;
extern GADI_SYS_HandleT gpioHandle_m1b_p;
extern GADI_SYS_HandleT gpioHandle_m1a_n;
extern GADI_SYS_HandleT gpioHandle_m1a_p;
extern GADI_SYS_HandleT gpioHandle_ptz_power;
extern GADI_SYS_HandleT gpioHandle_white_led_power;
extern GADI_SYS_HandleT gpioHandle_ircut_led_power;


#define SAMPLE_PRT(fmt...)   \
    do {\
        printf("[%s]-%d: ", __FUNCTION__, __LINE__);\
        printf(fmt);\
       }while(0)
       
#define DEFAULT_AUDIO_FRAME_RATE_BPS 8000

#endif

