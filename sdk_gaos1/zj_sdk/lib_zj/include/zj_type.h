#ifndef _ZJ_TYPE_H_
#define _ZJ_TYPE_H_
#include <time.h>
#ifdef __cplusplus
extern "C" {
#endif

#ifdef ZJ_EXPORTS
#define _ZJ_API  __declspec(dllexport)
#else
#define _ZJ_API
#endif

#define ZJ_HANDLE   void*


typedef enum enum_zj_os_type
{
    EN_ZJ_OS_TYPE_LINUX     = 1,
    EN_ZJ_OS_TYPE_IOS       = 2,
    EN_ZJ_OS_TYPE_ANDRIOD   = 3,
    EN_ZJ_OS_TYPE_ANDRIODTV = 4,
    EN_ZJ_OS_TYPE_WINDOWS   = 5,
    EN_ZJ_OS_TYPE_RTOS      = 6
}EN_ZJ_OS_TYPE;

/**
  * �豸��ʼ��״̬���ֱ�Ϊ����ʼ�������ü��ء������ʼ����ע�ᡢ��¼���󶨡����С�
**********************************************/
typedef enum enum_ZJ_SERVER_STATUS
{
    EN_ZJ_SERVER_STATUS_INIT     = 0,
    EN_ZJ_SERVER_STATUS_GETADDR,
    EN_ZJ_SERVER_STATUS_CONNECT,        //�����������
    EN_ZJ_SERVER_STATUS_REGIST,         //�豸ע��
    EN_ZJ_SERVER_STATUS_WAITBIND,       //�豸�ȴ���
    EN_ZJ_SERVER_STATUS_PROCESS,        //�豸�������
    EN_ZJ_SERVER_STATUS_EXITGROUP       //�豸�������
}EN_ZJ_SERVER_STATUS;

/*
 * �豸�ڴ渻�༶��
 */
typedef enum enum_ZJ_DEVICE_MEM_ABILITY
{
   EN_ZJ_DEVICE_MEM_ABILITY_RICH = 0, //�ڴ��������Դ洢3����������GOP
   EN_ZJ_DEVICE_MEM_ABILITY_MID  = 1, //�ڴ��������У����Դ洢1����������GOP
   EN_ZJ_DEVICE_MEM_ABILITY_POOR = 2  //�ڴ��������㣬ֻ���Դ���һ������֡
}EN_ZJ_DEVICE_MEM_ABILITY;

typedef enum enum_ZJ_CFG_ITEM
{
    EN_ZJ_CFG_ITEM_ALL            = 0X00,
    EN_ZJ_CFG_ITEM_DEVICE         = 0X01,
    EN_ZJ_CFG_ITEM_CAMERA         = 0X02,
    EN_ZJ_CFG_ITEM_PTZ            = 0X04,
    EN_ZJ_CFG_ITEM_INIOT          = 0X08,
    EN_ZJ_CFG_ITEM_IOTHUB         = 0X10,
    EN_ZJ_CFG_ITEM_TIMEPOLICY     = 0X20,
    EN_ZJ_CFG_ITEM_ALARMPOLICY    = 0X40,
    EN_ZJ_CFG_ITEM_SYSTEM         = 0X80,
    EN_ZJ_CFG_ITEM_SERVERSET      = 0X100,
    EN_ZJ_CFG_ITEM_SCENEPOLICY    = 0X200,

    EN_ZJ_CFG_ITEM_GROUPINF       = 0x10000
}EN_ZJ_CFG_ITEM;

/*
 * �豸����״̬��
 */
typedef enum enum_ZJ_DEVICE_UPDATE_STATUS
{
    EN_ZJ_DEVICE_UPDATE_STATUS_NOUPDATE     = 0, //����Ҫ����
    EN_ZJ_DEVICE_UPDATE_STATUS_NEEDUPDATE   = 1, //���°汾��Ҫ����
    EN_ZJ_DEVICE_UPDATE_STATUS_MUSTUPDATE   = 2  //ǿ��������ϵͳ�汾��������Ҫǿ������
}EN_ZJ_DEVICE_UPDATE_STATUS;

// ��������
typedef enum enum_ZJ_NETWORK_TYPE{
    EN_ZJ_NETWORK_TYPE_NONET                = 0x00,     // ������
    EN_ZJ_NETWORK_TYPE_WIRED                = 0x01,     // ��������
    EN_ZJ_NETWORK_TYPE_WIFI                 = 0x02,     // WIFI����
    EN_ZJ_NETWORK_TYPE_AP                   = 0x04,     // AP����
    EN_ZJ_NETWORK_TYPE_SIM                  = 0x08,     // �ƶ�����
}EN_ZJ_NETWORK_TYPE;

//����WIFI�б�Ԫ��
typedef struct stru_ZJ_WIFI_INFO{
    int     iSigStrength;       //�ź�ǿ��
    int     iConnectFlag;       //�Ƿ�ǰ���� 1.�ǣ�0.����
    char    acWifiSSID[32];     //�31�ֽ�WiFiSSID
    int     iSecurity;          //��ȫ�ԣ�0���ޣ�1.WEP��2.WPA-PSK��3.WPA-PSK/WPA2-PSK��4.WPA2-PSK��5.����
}ST_ZJ_WIFI_INFO;

// ���嵱ǰ��������ṹ
typedef struct stru_ZJ_NETWORK_INFO{
	int             iNetType;
    int             iSignalType;            // 2: 2G 3: 3G 4: 4G 
	int             iSigStrength;
    unsigned char   aucNetmask[64];        //��������				
    unsigned char   aucGateway[64];         //Ĭ������				
	unsigned char 	aucIPAddr[64];
	unsigned char 	aucMacAddr[64];
	unsigned char 	aucWIFISSID[32];
}ST_ZJ_NETWORK_INFO;

//WIFI����״̬
typedef enum enum_ZJ_NETWORK_ERR_STATUS{
	EN_ZJ_NETWORK_ERR_STATUS_PWDERR		= 0x01, //WIFI�������
 	EN_ZJ_NETWORK_ERR_STATUS_NOSIGNAL	= 0x02  //�ź��ж�
}EN_ZJ_NETWORK_ERR_STATUS;


//֧��OTA������ģʽ
typedef enum enum_ZJ_OTA_ABILITY{
    EN_ZJ_OTA_ABILITY_SDCARD                = 0x01,     // SD���������û���������������SD����Ȼ��SD�������豸���������
    EN_ZJ_OTA_ABILITY_LOCALUPDATE           = 0x02,     // �����������û����豸������ͬһ�������������������
    EN_ZJ_OTA_ABILITY_REMOTEUPDATE          = 0x04      // Զ���������û����豸����ͬһ��������������������豸��Ҫ����Ŀռ�����������
}EN_ZJ_OTA_ABILITY;

// ֧��WIFI����ģʽ
typedef enum enum_ZJ_SETWIFI_ABILITY{
    EN_ZJ_SETWIFI_ABILITY_AP                   = 0x01,  //֧��AP����
    EN_ZJ_SETWIFI_ABILITY_SOUND                = 0x02,  //֧����������
    EN_ZJ_SETWIFI_ABILITY_SMARTLINK            = 0x04,  //֧��SMARTLINK����
    EN_ZJ_SETWIFI_ABILITY_QRCODE               = 0x08,  //֧�ֶ�ά������
    EN_ZJ_SETWIFI_ABILITY_WIRED                = 0x10   //֧����������
}EN_ZJ_SETWIFI_ABILITY;

//�豸���߻�������
typedef enum enum_ZJ_AWAKE_ABILITY{
    EN_ZJ_AWAKE_ABILITY_NOTSUPPORT          = 0x00, //��֧������
    EN_ZJ_AWAKE_ABILITY_LOCALAWAKE          = 0x01, //֧�ֱ��ػ���
    EN_ZJ_AWAKE_ABILITY_REMOTEAWAKE         = 0x02  //֧��Զ�̻���
}EN_ZJ_AWAKE_ABILITY;

//�����Խ�֧������
typedef enum enum_ZJ_VOICEPLAY_ABILITY{
    EN_ZJ_VOICEPLAY_ABILITY_NOSUPPORT   = 0x00, //��֧�ֶԽ�
    EN_ZJ_VOICEPLAY_ABILITY_SIMPLEX     = 0x01, //����
    EN_ZJ_VOICEPLAY_ABILITY_DUPLEX      = 0x02 //˫��
}EN_ZJ_VOICEPLAY_ABILITY;

//�����PTZ֧������
typedef enum enum_ZJ_CAMERA_PTZ_ABILITY{
    EN_ZJ_CAMERA_PTZ_ABILITY_P          = 0x01,  //֧��P����
    EN_ZJ_CAMERA_PTZ_ABILITY_T          = 0x02,  //֧��T����
    EN_ZJ_CAMERA_PTZ_ABILITY_Z          = 0x04   //֧��Z����
}EN_ZJ_CAMERA_PTZ_ABILITY;

//�����PTZת��
typedef enum enum_ZJ_CAMERA_PTZ_CONTROL{
    EN_ZJ_CAMERA_PTZ_CONTROL_UP         = 1,
    EN_ZJ_CAMERA_PTZ_CONTROL_DOWN       = 2,
    EN_ZJ_CAMERA_PTZ_CONTROL_LEFT       = 3,
    EN_ZJ_CAMERA_PTZ_CONTROL_RIGHT      = 4,
}EN_ZJ_CAMERA_PTZ_CONTROL;

typedef struct str_ZJ_PRESET_POINT       		//PTZ ABS MOVE
{
	int    iX;			      	//Ԥ��λx������    ���ײ㣩
	int    iY;			      	//Ԥ��λy������    ���ײ㣩
}ST_ZJ_PRESET_POINT;

//Ѳ��Ԥ�õ㶨��
typedef struct stru_ZJ_CAMERA_CRUISE_PRESET{
    int         Idx;            //Ԥ�õ����
    int         iX;             //Ԥ�õ�λ��X
    int         iY;             //Ԥ�õ�λ��Y
    int         iDwellTime;     //ͣ��ʱ�� ��λ s
    int         iSpeed;         //��̨ת��
}ST_ZJ_CAMERA_CRUISE_PRESET;

//������ֱ���֧��������
typedef enum enum_ZJ_CAMERA_RESOLUTION_ABILITY{
    EN_ZJ_CARERA_RESOLUTION_ABILITY_360P        = 0x0001, //֧��640*360�ֱ���
    EN_ZJ_CARERA_RESOLUTION_ABILITY_480P        = 0x0002, //֧��640*480�ֱ���
    EN_ZJ_CARERA_RESOLUTION_ABILITY_720P        = 0x0004, //֧��1280*720�ֱ���
    EN_ZJ_CARERA_RESOLUTION_ABILITY_960P        = 0x0008, //֧��1280*960�ֱ���
    EN_ZJ_CARERA_RESOLUTION_ABILITY_1080P       = 0x0010, //֧��1920*1080�ֱ���
    EN_ZJ_CARERA_RESOLUTION_ABILITY_1200P       = 0x0020, //֧��1600*1200�ֱ���
    EN_ZJ_CARERA_RESOLUTION_ABILITY_300W        = 0x0040, //֧��2048*1536�ֱ���
    EN_ZJ_CARERA_RESOLUTION_ABILITY_400W        = 0x0080, //֧��2500*1600�ֱ���
    EN_ZJ_CARERA_RESOLUTION_ABILITY_500W        = 0x0100, //֧��2560*1920�ֱ���
    EN_ZJ_CARERA_RESOLUTION_ABILITY_4K          = 0x0200, //֧��3840*2160�ֱ��� 800W����
    EN_ZJ_CARERA_RESOLUTION_ABILITY_8K          = 0x0400, //֧��7680*4320�ֱ��� 3200W����
}EN_ZJ_CARERA_RESOLUTION_ABILITY;

//������������ʶ���
typedef enum enum_ZJ_CAMERA_BITRATE_TYPE{
    EN_ZJ_CAMERA_BITRATE_TYPE_96K       = 1,
    EN_ZJ_CAMERA_BITRATE_TYPE_128K      = 2,
    EN_ZJ_CAMERA_BITRATE_TYPE_196K      = 3,
    EN_ZJ_CAMERA_BITRATE_TYPE_256K      = 4,
    EN_ZJ_CAMERA_BITRATE_TYPE_384K      = 5,
    EN_ZJ_CAMERA_BITRATE_TYPE_512K      = 6,
    EN_ZJ_CAMERA_BITRATE_TYPE_768K      = 7,
    EN_ZJ_CAMERA_BITRATE_TYPE_1024K     = 8,
    EN_ZJ_CAMERA_BITRATE_TYPE_1536K     = 9,
    EN_ZJ_CAMERA_BITRATE_TYPE_2048K     = 10,
    EN_ZJ_CAMERA_BITRATE_TYPE_2560K     = 11,
    EN_ZJ_CAMERA_BITRATE_TYPE_3072K     = 12,
    EN_ZJ_CAMERA_BITRATE_TYPE_4096K     = 13
}EN_ZJ_CAMERA_BITRATE_TYPE;

//�����֧������
typedef enum enum_ZJ_CAMERA_IRLED_ABILITY{
    EN_ZJ_CAMERA_IRLED_ABILITY_NOSUPPORT        = 0x00, //��֧�ֺ����
    EN_ZJ_CAMERA_IRLED_ABILITY_NOCONTROL        = 0x01, //��֧�ֺ���ƿ��ؿ��ƣ�ֻ��ͨ���й����Զ����ؿ���
    EN_ZJ_CAMERA_IRCUR_ABILITY_CANCONTROL       = 0x02, //֧�ֺ��������ؿ���
}EN_ZJ_CAMERA_IRLED_ABILITY;

//�������Ƶ��������
typedef enum enum_ZJ_VIDEOENC_TYPE{
    EN_ZJ_VIDEOENC_TYPE_JPEG        = 0x01, //JPEGͼƬ����ģʽ
    EN_ZJ_VIDEOENC_TYPE_H264        = 0x02, //H264��������
    EN_ZJ_VIDEOENC_TYPE_H265        = 0x04  //H265��������
}EN_ZJ_VIDEOENC_TYPE;

//��Ƶ��������
typedef enum enum_ZJ_AUDIOENC_TYPE{
    EN_ZJ_AUDIOENC_TYPE_PCM16       = 0x01,
    EN_ZJ_AUDIOENC_TYPE_G711A       = 0x02,
    EN_ZJ_AUDIOENC_TYPE_G711U       = 0x04,
    EN_ZJ_AUDIOENC_TYPE_AAC         = 0x08,
    EN_ZJ_AUDIOENC_TYPE_MP3         = 0x10
}EN_ZJ_AUDIOENC_TYPE;

typedef enum enum_ZJ_MEDIA_TYPE{
    EN_ZJ_MEDIA_VIDEO   = 0X01,
    EN_ZJ_MEDIA_AUDIO   = 0X02,
    EN_ZJ_MEDIA_AV      = 0X03
}EN_ZJ_STREAMER_TYPE;


//��ͷ����
typedef enum enum_ZJ_CAMERA_LENS_TYPE{
    EN_ZJ_CAMERA_LENS_TYPE_NORMAL       = 0x00,
    EN_ZJ_CAMERA_LENS_TYPE_360          = 0x01,
    EN_ZJ_CAMERA_LENS_TYPE_720          = 0x02
}EN_ZJ_CAMERA_LENS_TYPE;

//��Ƶ�������
typedef struct stru_ZJ_VIDEO_PARAM{
    unsigned int uiResolution;    //�ֱ��ʣ����ֱ��ʶ���
    unsigned int uiWidth;         //�ֱ���  �ص����ÿ��Ժ���
    unsigned int uiHeight;        //�ֱ���  �ص����ÿ��Ժ���
    unsigned int uiEncodeType;    //�����ʽ
    unsigned int uiSmartEncFlag;  //0.��֧��Smart���룻1.֧��Smart����
    unsigned int uiQuality;       //��������
    unsigned int uiBitrate;       //���ʣ������ʶ���
    unsigned int uiFramerate;     //֡�� 
    unsigned int uiFrameInterval; //I֡��� 50֡��100֡��200֡
    unsigned int uiRateType;      // 0 CBR 1 VBR 
}ST_ZJ_VIDEO_PARAM;

// ��Ƶ��������
typedef struct stru_ZJ_AUDIO_PARAM{
    unsigned int uiEncodeType;    //�����ʽ
    unsigned int uiSampleRate;    //������
    unsigned int uiChannel;       //������
    unsigned int uiDepth;         //���
}ST_ZJ_AUDIO_PARAM;

//��Ǿ�ͷԲ�İ뾶��Ϣ����
typedef struct str_ZJ_VIDEO_CIRCLE
{
    unsigned int uiRadius;  //�뾶
    double doubleAngle;    //�Ƕ�
    unsigned int uiCc1x;    //Բ������X
    unsigned int uiCc1Y;    //Բ������Y
    unsigned int uiCc2x;   // 720��˫Ŀ
    unsigned int uiCc2Y;   // 720��˫Ŀ
}ST_ZJ_VIDEO_CIRCLE;

// Ť�������� 
typedef struct str_ZJ_VIDEO_DISTORTION
{
    double fx;    // ��ͷ������ͼ��Բ�ĵ�ˮƽƫ��
    double fy;    // ��ͷ������ͼ��Բ�ĵĴ�ֱƫ��
    double a;     // Ͱ�λ���У������
    double b;     // ���λ���У������
    double scale; // ͼ����������
}ST_ZJ_VIDEO_DISTORTION;

//��Ƶ����֡����
typedef enum enum_ZJ_VIDEO_FRAME_TYPE{
    EN_ZJ_VIDEO_FRAME_TYPE_UNKNOW       = 0, //δ֪֡���ͣ���Ҫȥ���
    EN_ZJ_VIDEO_FRAME_TYPE_I            = 1, //I֡
    EN_ZJ_VIDEO_FRAME_TYPE_P            = 2, //P֡
}EN_ZJ_VIDEO_FRAME_TYPE;


// ͼƬ���Ͷ��塣��ͨͼƬ���еȴ�СͼƬ��Сͼ��ICONͼƬ��
typedef enum enum_ZJ_PICTURE_TYPE{
    EN_ZJ_PICTURE_NORMAL                = 0X01,   //����ͬ�ȳߴ�
    EN_ZJ_PICTURE_MIDDLE                = 0X02,   //��������һ���ߴ�
    EN_ZJ_PICTURE_SMALL                 = 0X04,   //320*240�ߴ�
    EN_ZJ_PICTURE_ICON                  = 0X08    //64*48�ߴ�
}EN_ZJ_PICTURE_TYPE;


//  IRģʽ���Զ�ģʽ������ģʽ��ȫ��ģʽ��
typedef enum enum_ZJ_IRMODE{
    EN_ZJ_IRMODE_AUTO               = 0,  //�Զ�ģʽ
    EN_ZJ_IRMODE_IR                 = 1,  //����ģʽ
    EN_ZJ_IRMODE_FULLCOLOR          = 2   //ȫ��ģʽ
}EN_ZJ_IRMODE;

// �ؼ�֡������������
typedef enum enum_ZJ_KEYFRAME_QUALITY{
    EN_ZJ_KEYFRAME_QUALITY_NORMAL = 1, // ��׼����
    EN_ZJ_KEYFRAME_QUALITY_LOW    = 2, // ������
}EN_ZJ_KEYFRAME_QUALITY;

//����AIIoT���ͣ��������������źŲɼ����������������
typedef enum enum_ZJ_AIIOT_TYPE{
    EN_ZJ_AIIOT_TYPE_REMOTECTRLER               = 0,        //ң����
    EN_ZJ_AIIOT_TYPE_DOORSWITCH                 = 1,        //�Ŵ�
    EN_ZJ_AIIOT_TYPE_SMOKETRANSDUCER            = 2,        //��������
    EN_ZJ_AIIOT_TYPE_GASSENSOR                  = 3,        //ȼ�� ̽�� ������
    EN_ZJ_AIIOT_TYPE_LIGHTSWITCH                = 4,        //���
    EN_ZJ_AIIOT_TYPE_CURTAIN                    = 5,        //����
    EN_ZJ_AIIOT_TYPE_JACK                       = 6,        //����
    EN_ZJ_AIIOT_TYPE_PIR                        = 7,        //���� ���� 
    EN_ZJ_AIIOT_TYPE_WATER                      = 8,        //ˮ��
    EN_ZJ_AIIOT_TYPE_ERG                        = 9,        //����
    EN_ZJ_AIIOT_TYPE_ALARMBEER                  = 10,       //����
    
    EN_ZJ_AIIOT_TYPE_JCAKHVAC                   = 11,       //�յ�����
    EN_ZJ_AIIOT_TYPE_MULTISWITCH                = 12,       //��·����
    EN_ZJ_AIIOT_TYPE_SHUTTERMOTOR               = 13,       //���� �綯��
    EN_ZJ_AIIOT_TYPE_GLASSBROKENSENSOR          = 20,       //�������� ������
    EN_ZJ_AIIOT_TYPE_INFRAREDSENSOR             = 23,       //���� ���� 
    EN_ZJ_AIIOT_TYPE_BATTERYVALVE               = 24,       //��ŷ���
    EN_ZJ_AIIOT_TYPE_AIRFLOWSENSOR              = 25,       //����������
    EN_ZJ_AIIOT_TYPE_MULTICTR                   = 32,       //�๦�ܿ���
    EN_ZJ_AIIOT_TYPE_INTELLOCK                  = 33,       //������
    EN_ZJ_AIIOT_TYPE_DOORBELL                   = 34,       //����
	EN_ZJ_AIIOT_TYPE_COSENSOR                   = 40,       //һ����̼̽����
    
	EN_ZJ_AIIOT_TYPE_MOTION                     = 1000,      //�˶����
	EN_ZJ_AIIOT_TYPE_INNER_DOORBELL             = 1001,      //���� ����
    EN_ZJ_AIIOT_TYPE_RECORD                     = 1002,      //¼�� ����Ҫע��IOT
    EN_ZJ_AIIOT_TYPE_INNER_PIR                  = 1003,      //�����������̽����
    EN_ZJ_AIIOT_TYPE_VOICEALARMDETECT           = 1004,      //�����������
    EN_ZJ_AIIOT_TYPE_SNAPSHORT                  = 1005,      //SnapShot��ͼ  ����Ҫע��IOT
    EN_ZJ_AIIOT_TYPE_PTZ                        = 1006,      //PTZ ����Ҫ��ע��IOT
    EN_ZJ_AIIOT_TYPE_INNER_LAMP                 = 1007,      //���ð׹��
    EN_ZJ_AIIOT_TYPE_INNER_STATELAMP            = 1008,      //����״ָ̬ʾ��
    EN_ZJ_AIIOT_TYPE_BUZZER                     = 1009,      //���÷�����
    EN_ZJ_AIIOT_TYPE_CLOUDRECORD                = 1010,      // �ƶ�¼��
    EN_ZJ_AIIOT_TYPE_CLOUDSNAP                  = 1011,      // �ƶ˽�ͼ
    EN_ZJ_AIIOT_TYPE_CAMERA                     = 1012,      // �����
    EN_ZJ_AIIOT_TYPE_EVENT                      = 1013,      // �¼���¼
    EN_ZJ_AIIOT_TYPE_DNSET                      = 1014,      // ǿ�ư�������,���Զ�
    EN_ZJ_AIIOT_TYPE_FORCEREMOVE                = 1015,       // ǿ��
    EN_ZJ_AIIOT_TYPE_STAY                       = 1016        // ����
}EN_ZJ_AIIOT_TYPE;

//����MOTION�в�ͬ�ļ������
typedef enum enum_zj_motion_event_type
{
    EN_ZJ_MOTION_EVENT_MOTION = 0X00,         //�ƶ�����¼�����
    EN_ZJ_MOTION_EVENT_HUMAN  = 0X01,         //��������¼�����
    EN_ZJ_MOTION_EVENT_FACE   = 0X02          //��������¼�����
}EN_ZJ_MOTION_EVENT_TYPE;

typedef enum enum_ZJ_ROTATE_TYPE {
    EN_ZJ_ROTATE_TYPE_VERTICAL_UP      = 0x01,  //��ת180��
    EN_ZJ_ROTATE_TYPE_VERTICAL_DOWN    = 0x02,  //������ת180��
    EN_ZJ_ROTATE_TYPE_MIRROR_ENABLE    = 0x04,  //����ת
    EN_ZJ_ROTATE_TYPE_MIRROR_DISABLE   = 0x08,  //ȡ������ת
}EN_ZJ_ROTATE_TYPE;

typedef enum enum_ZJ_CTRLDEVICEID_TYPE{

    EN_ZJ_CTRLDID_NODE       = 0,
    EN_ZJ_CTRLDID_CLEAR      = 1,
    EN_ZJ_CTRLDID_QUERY      = 2,
    EN_ZJ_CTRLDID_EXITGROUP  = 3
}EN_ZJ_CTRLDEVICEID_TYPE;

//�����豸����?1.�������2.�������壻3.�������壻4.NVR
typedef enum enum_ZJ_DEV_TYPE
{
    EN_ZJ_DEV_TYPE_CAMERA                   = 0X01,     //�����
    EN_ZJ_DEV_TYPE_DOORBELL_SPLIT           = 0X02,     //��������
    EN_ZJ_DEV_TYPE_DOORBELL_SINGLE          = 0X03,     //��������
    EN_ZJ_DEV_TYPE_NVR                      = 0X04      //NVR
}EN_ZJ_DEV_TYPE;

typedef struct stru_ZJ_TRIGGER_INFO{
    unsigned int uiIotType;
    unsigned long long lluIotId;
    unsigned int uiEventId;
    unsigned int uiDuration;
    time_t       tCreateTime;
    void        *pstHandler;  // ����
}ST_ZJ_TRIGGER_INFO;


// ������� �� ���� ��ͼ
typedef struct stru_ZJ_HUMANFACE_INFO
{
    unsigned  char *pjpgBuff;
    unsigned int uiJpgLen;
    double dPointX;  //  0 - 1  ���Ͻ� �� 00 ���½� ��11
    double dPointY;
    double dWidth;
    double dHeight;
    struct stru_ZJ_HUMANFACE_INFO *pstNext;
}ST_ZJ_HUMANFACE_INFO;

typedef int (*ZJ_PFUN_COLLECTLOGFILES)(unsigned char *pucPeerId,unsigned int iSessionId,unsigned char *pcDesInfo);


// �豸״̬�ص��ӿڣ� �����豸��ǰ״̬��
typedef int (*ZJ_PFUN_DEVICE_STATUS)(EN_ZJ_SERVER_STATUS enDeviceStatus, int iErrCode);

// ����������ص��ӿڣ� �����豸��Ҫ��������
typedef int (*ZJ_PFUN_DEV_REBOOT)();

// ����ʱ��ʱ���ص��ӿڣ� �����豸����������ʱ��ʱ����
typedef int (*ZJ_PFUN_DEVICE_SETTIMEZONE)(int iSyncFlag, int iZone, char* pcDatetime,char *pucDst);

// ʱ��ʱ����Ϣ��ȡ�ص��ӿڣ����豸ʱ��ʱ����Ϣͨ���ýӿڲ���������ȥ��
typedef int (*ZJ_PFUN_DEVICE_GETTIMEANDZONE)(int *piZone,unsigned char *pucTime,int *piSyncFlag);

// �豸�ָ��������ûص��ӿڣ������豸��Ҫ���������ûָ���������״̬
typedef int (*ZJ_PFUN_DEVICE_RESTOREFACTORYSETTING)();

// ����WIFI�ص��ӿڣ������豸��ǰ���õ�WIFIģʽ��WIFI�Ĳ�����SSID, ���룬�������ͣ���
typedef int (*ZJ_PFUN_DEVICE_SETWIFI)(EN_ZJ_NETWORK_TYPE enWifiType, char* pcSSID, char* pcPwd, int iEncrytType);
// ��ȡWIFI�б�ص��ӿڣ���ȡ�ź���ǿ�ģ����16��WIFI�б�
typedef int (*ZJ_PFUN_DEVICE_GETWIFI)(ST_ZJ_WIFI_INFO stWifiInfo[16], unsigned int *puiWifiCount);
// ��ȡ��ǰ��������
typedef int (*ZJ_PFUN_DEVICE_GETNETINFO)(ST_ZJ_NETWORK_INFO* pstNetInfo);

typedef int (*ZJ_PFUN_DEVICE_RECVCUSTOMDATA)(const unsigned char* pucPeerID, unsigned char* pucData, int iLen);

// �豸�������߻ص��ӿڣ� �豸�ڸýӿ�,�յ��ȴ������󣬽�������״̬��-1.Ϊ�����Խ������ߣ� 0.���̽������ߣ� > 0Ϊ�ȴ���Ӧ��������������ߣ�
typedef int (*ZJ_PFUN_STARTSLEEP)(int iWaitSecond);

// ��Ƶ���뿪�ػص��� ��Ƶ��ʼ����/�رձ��� 0. ������ 1.��ʼ
typedef int (*ZJ_PFUN_AUDIO_SWITCH)(int iState); 

// ��Ƶ���뿪�ػص��� ��·��Ƶ��ʼ����/�������� 0. ������ 1.��ʼ
typedef int (*ZJ_PFUN_VIDEO_SWITCH)(int iStreamID, int iState);

//��ý����Ҫһ��I֡�ص��ӿڣ���֪�豸��ǰ����Ҫһ���ؼ�֡�� EN_ZJ_KEYFRAME_QUALITY
typedef int (*ZJ_PFUN_VIDEO_NEEDIFRAME)(int iStreamID,unsigned int uiKeyQuality);

//����ƿ��ػص��ӿڣ������豸������л�ģʽ ����EN_ZJ_IRMODE
typedef int (*ZJ_PFUN_IRLED_SWITCH)(int iState);

//���û��淭ת�ص��ӿڣ� �����豸������з�ת��ȡֵ�ο���EN_ZJ_ROTATE_TYPE
typedef int (*ZJ_PFUN_IMAGEINVERSION)(int iState);

//����������򿪹رջص��ӿڣ������豸�ر���Ƶ����Ƶ�� 0. �رգ� 1.��
typedef int (*ZJ_PFUN_CAMERA_SWITCH)(int iState);

//����ץȡͼƬ�ص��ӿڣ������豸ץȡһ��ʵʱ�����ͼƬ, ��ȡ��Ӧ�ߴ��ͼƬ�������뵽����Ŀռ��С� If success, the return value is the jpeg buf length.
typedef int (*ZJ_PFUN_VIDEO_GETJPEG)(EN_ZJ_PICTURE_TYPE enPicType, unsigned char** ppucJpegBuf);

//����ͷPTZ�ص��ӿڣ������豸����PTZ����;PTZ�����������ٶȣ�1~7��1��ͣ�7��죻PTZStep���ƶ�������һ������Ϊ1�ȡ�360��ʾһֱ�ƶ���ͷһȦ
typedef int (*ZJ_PFUN_CAMERA_ONPTZ)(EN_ZJ_CAMERA_PTZ_CONTROL enPTZControl, int iSpeed, int iPTZStep);
//����ͷ��ǰλ�û�ȡ����ȡX,Y��ֵ��
typedef int (*ZJ_PFUN_CAMERA_PTZ_GETPOINT)(int* piX, int* piY);
//������ƶ���Ԥ�õ�λ��
typedef int (*ZJ_PFUN_CAMERA_PTZ_GOTOPOINT)(int iX, int iY);
//������Զ���⣬��Ԥ�õ�λ������Ϊת��������´���ʱ����Ҫ�������ã�����ǰ��Ҫ���Լ��ó�ʼλ�ã�
typedef int (*ZJ_PFUN_CAMERA_PTZ_AUTOCHECK)();

//�����Ѳ����ʼ�ص��ӿڣ������豸�������Ԥ�õ�Ѳ����
typedef int (*ZJ_PFUN_CAMERA_CRUISE_START)(int iPresetPointNum, ST_ZJ_CAMERA_CRUISE_PRESET* pstPresets);
//�����ֹͣѲ��
typedef int (*ZJ_PFUN_CAMERA_PTZ_STOP)();

//��Ƶ�������ڻص��ӿڣ������豸Ҫ��������С; 0~100�� 0Ϊ������10Ϊ�������
typedef int (*ZJ_PFUN_AUDIO_VOLUMN_ADJUST)(int iSpeakerId,int iVolumn);

//����¼��״̬�ص��ӿڣ������豸����¼���Ƿ���С� 0.δ¼��1.¼��
typedef int (*ZJ_PFUN_CAMERA_RECORD_STATUS)(int iStatus);

/* ����ͷOSDˮӡ��ӻص��ӿڣ������豸�Ե�ǰ��������ˮӡ iPosition:1.���ϣ�2.���£�3.���ϣ�4.���£�0.Ĭ��
�� openfalg �� 0 ��ʱ�� , ���� iPosition �� pcOSDName ��������
*/
typedef int (*ZJ_PFUN_CAMERA_OSDSETTING)(int iPosition, char* pcOSDName);
// osd ˮӡ�� ������ʾ
typedef int (*ZJ_PFUN_CAMERA_CTRLOSDSHOWFLAG)(int iOpenFlag);


// ����ͷ������������ص��ӿڣ������豸������ý�������룻 1. Start; 0. Stop; iStreamType:EN_ZJ_STREAMER_TYPE
typedef int (*ZJ_PFUN_CAMERA_MEDIA_TOPLAY)(const char* pcPeerID, ZJ_HANDLE hPlayHandle, int iStreamType, int iStatus);

//SD����ʽ���ص��ӿڣ�ͨ���ýӿ�֪ͨ�豸�ع�
typedef int (*ZJ_PFUN_CAMERA_FORMATSDCARD)();

//��ȡSD�������ص��ӿڣ�ͨ���ýӿڻ�ȡSD��������Ϣ ��λ M
typedef int (*ZJ_PFUN_CAMERA_GETSDCARDSIZE)(unsigned int* piTotalSize, unsigned int* piFreeSize);

//SD���Լ��ص��ӿڣ�ͨ���ýӿ���SD�����м���޸������ش�����Ϣ�� 0 Ϊ�޴���
typedef int (*ZJ_PFUN_CAMERA_CHECKSDCARD)(int* piErrCode);

//AIiOT �豸��ʼ�����ص��ӿڣ� ͨ���ýӿ�����AIIOT�豸�źŲɼ���
typedef int (*ZJ_PFUN_AIIOT_START)(unsigned int uiAIIoTType, unsigned long long uiAIIoTID);

//AIiOT �豸ֹͣ�����ص��ӿڣ� ͨ���ýӿ�֪ͨ�豸ֹͣ�źŲɼ���
typedef int (*ZJ_PFUN_AIIOT_STOP)(unsigned int uiAIIoTType, unsigned long long lluAIIoTID);

/*************************************************************************************
��ѯAIiOT �豸��ǰ�¼����ź����ص��ӿڣ� ͨ���ýӿڷ����豸��ǰ���ź������¼�, 
���������ź����ͺͶ�Ӧ���ź�Json�ִ��������������ֵ�ڲ����䣬 sdk ֻʹ�ã� ���ͷ�
*************************************************************************************/
typedef int (*ZJ_PFUN_AIIOT_GETINPUT)(unsigned int uiAIIoTType, unsigned long long uiAIIoTID,unsigned char** ppSignalValue);

//��AIiOT �豸����źŻص��ӿڣ�ͨ���ýӿڣ�������ź����ͺͶ�Ӧ��JSON�����ַ��������AIiOT�豸��CONTRL ����
typedef int (*ZJ_PFUN_AIIOT_OUTPUT)(unsigned int uiAIIoTType, unsigned long long uiAIIoTID, unsigned char* pSignalValue,ST_ZJ_TRIGGER_INFO* pstTriggerInf);

//��AIIoT�豸�������Իص��ӿڣ�ͨ���ýӿڣ����µ�����ֵ���ø�AIIoT�豸�����豸�����õ�����ֵ���й�����������һ��JSON�ַ������ݣ�
typedef int (*ZJ_PFUN_AIIOT_SETPROP)(unsigned int uiAIIoTType, unsigned long long uiAIIoTID, unsigned char* pstProp); //yinkai changed type

//��⵱ǰ�����źŶ�Ӧ���¼����ͻص��ӿڣ�ͨ���ýӿڣ��ж���ǰ�����źŵ��¼����ͣ��Է���ֵ���أ�
typedef int (*ZJ_PFUN_AIIOT_CHECKEVENT)(unsigned int uiAIIoTType, unsigned long long uiAIIoTID, unsigned char* pSignalValue);

//�����豸����
typedef int (*ZJ_PFUN_SET_DEVICE_NAME)(unsigned char *pucDeviceName);

//ǿ���豸������������
typedef int (*ZJ_PFUN_SET_DISMANTABLE_ALARM)(unsigned int uiOpenFlag);

//������������
typedef int (*ZJ_PFUN_SET_STAY_ALARM)(unsigned int uiOpenFlag);

//�����������̬����
typedef int (*ZJ_PFUN_SET_WIDE_DYNAMIC_CAM)(unsigned int uiOpenFlag);

//���ñ仯 ֪ͨ 
typedef int (*ZJ_PFUN_CFGITEM_CHANGE)(unsigned int uiCfgItem);


// ��Ƶ�ɼ��������õĻص��ӿ�,�������÷���pstAudioParm��ߣ�
typedef int (*ZJ_PFUN_SET_AUDIO_PARM)(ST_ZJ_AUDIO_PARAM *pstAudioParm);

//����������Ƶ�ɼ������Ļص�����
typedef int (*ZJ_PFUN_SET_VIDEO_PARM)(int iStreamID,ST_ZJ_VIDEO_PARAM *pstVideoParm);

//��������PTZ �����Ļص��ӿ�
typedef int (*ZJ_PFUN_SET_PTZ_PARM)(int iOpenFlag);

/****************************************************************
�����ص�����
***************************************************************/
// �豸�汾״̬�ص��ӿڣ������豸��ǰ�汾����״̬
typedef int (*ZJ_PFUN_NEWVERSON_NOTICE)(unsigned char *pucNewVersion,unsigned int uiFileSize);

// �豸�汾״̬�ص��ӿڣ������豸��ǰ�汾����״̬
typedef int (*ZJ_PFUN_NEWVERSON_DATADOWN)(unsigned char *pucPackage,unsigned int uiPacklen,unsigned int uiEndFlag);

// ֹͣ�����ļ�
typedef int (*ZJ_PFUN_STOPUPGRADE)();

// 1 ��ǩ�ɹ���֪ͨ�̼����Ǿ��� 0 ��ǩ���ɹ���������
typedef int (*ZJ_PFUN_COVERIMAGE_NOTICE)(unsigned int uiCoverFlag);

/****************************************************************
***************************************************************/
//�л�����ͷ
typedef int (*ZJ_PFUN_SWITCH_LEN)(int iLenId);

/***************************************************************
�Զ��屨������
***************************************************************/
//ɾ�������ļ�
typedef int (*ZJ_PFUN_DELSOUNDFILE)(unsigned char *pucSoundName);
//��ȡ�����ļ��б�
typedef int (*ZJ_PFUN_GETSOUNDFILES)( unsigned int *piTotalSize, unsigned int *piFreeSize, unsigned char aucSoundList[32][64], unsigned int *uiSoundListCnt,unsigned int uiRingType);

/***************************************************************
������ص���Ϣ
***************************************************************/
typedef struct ZJ_HUMANFACE_NODE
{
    unsigned char aucFaceId[64];        //����id
    unsigned char aucFaceLabelId[64];   //������ǩid
    struct ZJ_HUMANFACE_NODE *pstNextNode;
}ZJ_HUMANFACE_NODE;

typedef struct ZJ_HUMANFACE_LABLE_NODE
{
    unsigned int  uiMaxFaceCnt;         //�������
    unsigned int  *pucFaceDes;          //������ǩ��ע��Ϣ
    unsigned char aucFaceLabeName[64];  //��������
    unsigned char aucFaceLabelId[64];   //������ǩid
    struct ZJ_HUMANFACE_LABLE_NODE *pstNextNode;
}ZJ_HUMANFACE_LABLE_NODE;

//��ȡ�������б�
typedef int (*ZJ_PFUN_GET_FACELABLELIST)(ZJ_HUMANFACE_LABLE_NODE **pstFaceLableHead);
// ��ȡ�����б�
typedef int (*ZJ_PFUN_GET_FACELIST)(ZJ_HUMANFACE_NODE **pstFaceHead);
// �޸���������Ϣ
typedef int (*ZJ_PFUN_MODIFY_FACELABLEINF)(ZJ_HUMANFACE_LABLE_NODE *pstFaceLableInf);
// ��������������������
typedef int (*ZJ_PFUN_MODIFY_FACEINF)(ZJ_HUMANFACE_NODE *pstFaceHead);
// ����������
typedef int (*ZJ_PFUN_CREAT_FACELABLE)(unsigned char *pucInLableName,unsigned char *pucOutLableId);
// �� ���������������
typedef int (*ZJ_PFUN_ADDFACETOLABLE)(unsigned char *pucLableId,unsigned char *pucFileName);

// ��������ͼƬ����·��
_ZJ_API int ZJ_SetFaceFileCachePath(unsigned char *pucFaceCachePath);



#ifdef __cplusplus
}
#endif


#endif
