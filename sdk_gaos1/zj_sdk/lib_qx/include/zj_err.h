#ifndef _ZJ_ERR_H_
#define _ZJ_ERR_H_

#ifdef __cplusplus
extern "C" {
#endif
 
/*
**�����������sdk֮��ͨ�ŵĴ�����
*/
typedef enum enum_ZJ_ERR_TYPE{
	EN_ZJ_ERR             								= -1,	/*common err*/
	EN_ZJ_ERR_PARAM       								= -2,	/*param err*/
	EN_ZJ_ERR_NOMEM       								= -3,	/*no memory*/
	EN_ZJ_ERR_NOINIT      								= -4,	/*parameter not init*/
	EN_ZJ_ERR_NORES       								= -5, 	 /*no mutex, no thread, no file,inc*/
	EN_ZJ_ERR_OVERFLOW    								= -6, 	/*stack overflow*/
	EN_ZJ_ERR_MAGIC_N     								= -7, 	/*the heap PTR of struct is modified err */
	EN_ZJ_ERR_KEY_UNEXIST 								= -8, 	/*key not exist */
	EN_ZJ_ERR_FILE_EXIST  								= -9, 	/*key is exist */
	EN_ZJ_ERR_AUTHORITY   								= -10,	 /*No authority  */
	EN_ZJ_ERR_CLOSE       								= -11,	 /*Fun Not open  */
	EN_ZJ_ERR_SUPPORT     								= -12,	 /*Fun Not support  */
	EN_ZJ_ERR_NOADDR      								= -13,	/*addr path is err*/
	EN_ZJ_ERR_FREQUENTLY  								= -14,	/*request too many times*/
	EN_ZJ_ERR_TRYAGAIN    								= -15,	/*please try again*/
	EN_ZJ_ERR_FULL        								= -16,	/*dev list full*/
	EN_ZJ_ERR_NET         								= -80,	/*connect net err*/
	EN_ZJ_ERR_TIMEOUT     								= -83,	/*wait time out*/
	EN_ZJ_DES_CHANGE      								= -100,	/*des changed*/
	EN_ZJ_ERR_FILEEND     								= -101,	/*at the end of file*/
	EN_ZJ_ERR_FILEWAIT    								= -102, 
	EN_ZJ_ERR_EXIST       								= -110,	/*dev exist*/

    EN_ZJ_ERR_OK                                  		= 0,       //����ɹ�
    EN_ZJ_ERR_SDK_CHARACTER                             = 1001,    //����WIFIʱ������SSID����Ч�ַ�
    EN_ZJ_ERR_SDK_NO_WIFI_MODULE                        = 1002,    //��ѯWIFI�б��豸û��WIFIģ��
    EN_ZJ_ERR_SDK_WIFI_ISCLOSE                          = 1003,    //��ѯWIFI�б�WIFIģ��ر�
    EN_ZJ_ERR_SVR_SIGN_NO_SVR_DISTRI                    = 1101,    //SIGN�������ʱ��û�пɷ���ķ���
    EN_ZJ_ERR_SVR_FREQUENT_OPERATION            		= 1103,    //����Ƶ��
    EN_ZJ_ERR_SVR_COMPANYID_INVALID             		= 1111,    //��Ȩ����ҵID������
    EN_ZJ_ERR_SVR_COMPANY_NO_PRIVILEGE          		= 1112,    //��Ȩ����ҵID��Ӧ����ҵ��ƽ̨����
    EN_ZJ_ERR_SVR_APPID_INVALID                 		= 1113,    //��Ȩ�����AppID����ҵ�²�����
    EN_ZJ_ERR_SVR_APPID_NO_PRIVILEGE            		= 1114,    //��Ȩ�����AppID����ҵ/ƽ̨����
    EN_ZJ_ERR_SVR_LICENSENOTEXIST               		= 1115,    //������Ȩ��CTEI��û���ҵ�
    EN_ZJ_ERR_SVR_LICENSEEXPIRE                 		= 1116,    //��Ȩ�õ�CTEI���Ѿ�����
    EN_ZJ_ERR_SVR_LICENSEDISABLE                		= 1117,    //��Ȩ�õ�CTEI�뱻ƽ̨����
    EN_ZJ_ERR_SVR_APPHAVENOLICENSECOUNT         		= 1118,    //������Ȩ��AppID���޿��õ���Ȩ����
    EN_ZJ_ERR_SVR_DEVICENOTHERE                 		= 1121,    //�豸��½������豸ID��Ч���豸�յ��ô����룬����ע���µ�ID
    EN_ZJ_ERR_SVR_DEVICEDISABLE                 		= 1122,    //���豸��ƽ̨���ã��豸�޷�����
    EN_ZJ_ERR_SVR_DEVICE_VERSION_DISABLE        		= 1123,    //�豸�汾̫�ɣ�ϵͳ���ټ��ݡ��豸��ʱ��Ҫ��������
    EN_ZJ_ERR_SVR_DEVICESVR_CALL_FAILED         		= 1131,    //�豸���ù���ϵͳ���ʱ���
    EN_ZJ_ERR_SDK_DEVICE_NO_BUSI_CONFIG             	= 1141,    //�豸��δ�ϴ�ҵ������
    EN_ZJ_ERR_SDK_RESOLUTION_ABILITY_NOT_SUPPORT    	= 1142,    //���õ��豸�ֱ��ʣ���ǰ�豸��֧��
    EN_ZJ_ERR_SDK_RESOLUTION_BUSI_NOT_SUPPORT 			= 1143,    //���õ��豸�ֱ��ʣ�������ҵ�����Ʋ�֧�֣���Ȩ���ƣ�
    EN_ZJ_ERR_SDK_PTZ_ISMAX   							= 1144,    //�豸ִ��PTZ�Ѿ�ת�����ֵ
    EN_ZJ_ERR_SDK_EXITGROUP_ERR   						= 1146,    //�豸Ҫ�����飬�����豸��ǰ���飬����ʧ��
    EN_ZJ_ERR_SDK_SDCARD_FORMATTING_ERR   				= 1148,    //�豸��ʽ��SDʧ��
    EN_ZJ_ERR_SDK_SDCARD_NOT_EXIST    					= 1149,    //��ʽ��SD��ʱ��SD��������
    EN_ZJ_ERR_SDK_SDCARD_WR_ERR   						= 1150,    //��дSD��ʱ������ʧ��
    EN_ZJ_ERR_SDK_ADD_CHILD_DEVICE_TIMEOUT    			= 1151,    //���HUB���豸ʱ��ͨ�ų�ʱ��ʧ��
    EN_ZJ_ERR_SDK_CHILD_DEVICE_EXIST  					= 1152,    //���HUB���豸ʱ���豸ID�ظ�
    EN_ZJ_ERR_SDK_HUB_OPT_ERR 							= 1153,    //HUB�����쳣������ʧ��
    EN_ZJ_ERR_SDK_QUERY_RECORD_NO_PRIVILEGE  			= 1154,    //��ǰ��ѯ��¼û�в���Ȩ��
    EN_ZJ_ERR_SVR_CLOUDSVR_CALL_FAILED    				= 1155,    //�޷����ʵ�ǰ�ƴ��¼����
    EN_ZJ_ERR_SDK_LOCAL_RECORD_NOT_EXIST  				= 1156,    //��ǰ��ѯ����ı��ؼ�¼�ļ��ѱ�����
    EN_ZJ_ERR_SDK_CLOUD_FILE_EXPIRE   					= 1157,    //��ǰ��ѯ���Ƽ�¼�ļ��Ѿ�����
    EN_ZJ_ERR_SVR_ACCOUNT_ISEXIST 						= 2001,    //�˺��Ѵ���
    EN_ZJ_ERR_SVR_VERIFICATION_CODE_NOTEXIST  			= 2207,    //��֤�벻����
    EN_ZJ_ERR_SVR_REG_OTHER_ERR   						= 2003,    //����ע��ʧ��ԭ��
    EN_ZJ_ERR_SVR_ACCOUNT_NOTEIXST    					= 2004,    //�˺Ų�����
    EN_ZJ_ERR_SVR_USER_ACCOUNT_PWD_ERR    				= 2005,    //User��¼�˺��������
    EN_ZJ_ERR_SVR_VERIFY_OPENID_ERR   					= 2006,    //��������½ʱ��������У��ʧ��
    EN_ZJ_ERR_SVR_ACCOUNT_FORBIDDEN   					= 2007,    //��½ʱ�������˻��Ѿ�������
    EN_ZJ_ERR_SVR_UTOKEN_NOTEXIST 						= 2008,    //UTOKEN������
    EN_ZJ_ERR_SVR_SMSCODE_FREQUENT    					= 2009,    //���λ�ȡ������֤��ʱ����̣�����ʧ��
    EN_ZJ_ERR_SVR_USER_REJECT_INVITE  					= 2010,    //���û����ͷ������룬�������߾ܾ�
    EN_ZJ_ERR_SVR_GTOKENNOTMATCH  						= 2011,    //ͨ��Gtoken���飬GtokenʧЧ
    EN_ZJ_ERR_SVR_DEVICEISINGROUP 						= 2012,    //����豸����ʱʧ�ܣ��豸�Ѿ���������һ����
    EN_ZJ_ERR_SVR_USERNOPRIVILEGE 						= 2013,    //�û��޲���Ȩ��
	EN_ZJ_ERR_SVR_ACCOUNT_TYPE_NOT_SUPPORT				= 2014,    //��ȡ������֤��ʱ����֧���ֻ���������ķ�ʽ��ȡ
	EN_ZJ_ERR_SVR_ACCOUNT_FORMAT_ERR					= 2015,    //�˺Ÿ�ʽ����
	EN_ZJ_ERR_SVR_ACCOUNT_ALREADY_BIND					= 2016,    //�˺��ѱ���
	EN_ZJ_ERR_SVR_ACCOUNT_BIND_ERR						= 2017,    //���˺Ŵ���
	EN_ZJ_ERR_SVR_FILEID_NOT_EXIST						= 2018,	   //�ƴ洢�ļ�ID������
	EN_ZJ_ERR_SVR_APPID_NOTFOUND_TEMPLATE            	= 2027,    //APPIDδ�ҵ���Ӧ�Ķ���/emsģ��
    EN_ZJ_ERR_SVR_DEVICE_P2P_NOT_SUPPORT  				= 3001,    //���û����豸����P2Pʱ���豸���ز�֧��P2P
    EN_ZJ_ERR_SVR_CONN_NOT_MATCH  						= 3002,    //�û����豸��P2P����У�鲻ƥ��
    EN_ZJ_ERR_SVR_MEDIA_MATCH_TIMEOUT 					= 3003,    //�û����豸��MEDIA����Գ�ʱ
    EN_ZJ_ERR_SVR_MEDIA_CHANNEL_NOTEXIST 				= 3004,    //ý�����ʱ����Ӧ��ChannelID������
    EN_ZJ_ERR_SVR_MEDIA_PLAY_UPPER_LIMIT				= 3005,    //�㲥��ý��ʱ������������
    EN_ZJ_ERR_SVR_MEDIA_INVALID   						= 3006,    //��ý�����ʱ����Դ���ڻ���Ч
	EN_ZJ_ERR_SVR_MALLOC_ERR		     				= 4001,		//���������ڴ�������
	EN_ZJ_ERR_SVR_JSON_DECODE_ERR	     				= 4002,		//�������JSONЭ�����
	EN_ZJ_ERR_SVR_JSON_ENCODE_ERR	     				= 4003,		//������JSON�ַ�������
	EN_ZJ_ERR_SVR_API_PARAM_ERR		     				= 4004,		//API���ò�������
	EN_ZJ_ERR_SVR_METHOD_ERR		     				= 4005,		//API����NIL
	EN_ZJ_ERR_SVR_ENCRYPT_ERR		     				= 4006,		//Э����ܴ���
	EN_ZJ_ERR_SVR_DECRYPT_ERR		     				= 4007,		//Э����ܴ���
	EN_ZJ_ERR_SVR_BUFREAD_ERR		     				= 4008,		//���Ӷ�ȡBUFFER����
	EN_ZJ_ERR_SVR_TLS_PEMKEY_ERR	     				= 4009,		//TLS�����Ҳ���PEM KEY�ļ�����
	EN_ZJ_ERR_SVR_AUTHATOKEN_ERR	     				= 4010,		//������֮����ʵ��� ATOKEN����
	EN_ZJ_ERR_SVR_REDIS_PUB_ERR		     				= 4011,		//Redis������ʴ���
	EN_ZJ_ERR_SVR_DB_CONNECT_ERR	     				= 4012,		//���ݿ�����ʧ��
	EN_ZJ_ERR_SVR_DB_INSERT_ERR		     				= 4013,		//���ݿ����ݲ���ʧ��
	EN_ZJ_ERR_SVR_DB_SELECT_ERR		     				= 4014,		//���ݿ����ݲ�ѯʧ��
	EN_ZJ_ERR_SVR_DB_UPDATE_ERR		     				= 4015,		//���ݿ����ݸ���ʧ��
	EN_ZJ_ERR_SVR_DB_DELETE_ERR		     				= 4016,		//���ݿ�����ɾ��ʧ��
	EN_ZJ_ERR_SVR_DB_NORECORD_ERR	     				= 4017,		//û���ҵ���ؼ�¼
	EN_ZJ_ERR_SVR_DB_DUPLICATE_KEY	     				= 4018,		//�����ظ�
	EN_ZJ_ERR_SVR_NET_LISTEN_ERR	     				= 4019,		//����˿���������
	EN_ZJ_ERR_SVR_CLOSED			     				= 4020,		//����رմ���
	EN_ZJ_ERR_SVR_IDSVR_NOT_FOUND	     				= 4021,		//IDSVR�����Ҳ���
	EN_ZJ_ERR_SVR_IDSTUNSVR_NOT_FOUND	    			= 4022,		//IDSTUN�����Ҳ���
	EN_ZJ_ERR_SVR_BUSISVR_NOT_FOUND						= 4023,		//BUSICENTRE�����Ҳ���
	EN_ZJ_ERR_SVR_MEDIASVR_NOT_FOUND					= 4024,		//ý������Ҳ���
	EN_ZJ_ERR_SVR_LINKSVR_NOT_FOUND						= 4025,		//LINK�����Ҳ���
	EN_ZJ_ERR_SVR_USERSVR_CALL_FAILED					= 4026,		//�û�ϵͳ�ӿڵ���ʧ��
	EN_ZJ_ERR_SVR_IDSVR_CALL_FAILED						= 4027,		//IDSVRϵͳ�ӿڵ���ʧ��
	EN_ZJ_ERR_SVR_IDSTUN_CALL_FAILED					= 4028,		//IDSTUNϵͳ�ӿڵ���ʧ��
	EN_ZJ_ERR_SVR_PUSHSVR_NOT_FOUND						= 4029,		//���ͷ����Ҳ���
	EN_ZJ_ERR_SVR_GATEWAYSVR_CALL_FAILED				= 4030,		//���ط������ʧ��
	EN_ZJ_ERR_SVR_COMPMNGSVR_CALL_FAILED				= 4031,		//��ҵ��̨�������ʧ��
	EN_ZJ_ERR_SVR_PUBSUBSVR_NOT_FOUND					= 4032,		//���ķ��������Ҳ���
	EN_ZJ_ERR_SVR_SYSNOTICESVR_NOT_FOUND				= 4033,		//sysnotice�Ҳ���
	EN_ZJ_ERR_SVR_GATEWAYSVR_NOT_FOUND					= 4034,		//���ط����Ҳ���
	EN_ZJ_ERR_SVR_HTTPSVR_NOT_FOUND						= 4035,		//http�����Ҳ���
	EN_ZJ_ERR_SVR_HTTPSVR_CALL_FAILED					= 4036,		//http�������ʧ��
	EN_ZJ_ERR_SVR_BUSISVR_CALL_FAILED					= 4037,		//busicentre����ʧ��
	EN_ZJ_ERR_SVR_ID_CALL_FAILED						= 4038,		//IDSVR����ʧ��
	EN_ZJ_ERR_SVR_SIGN_CALL_FAILED						= 4039,		//SIGN�������ʧ��
	EN_ZJ_ERR_SVR_LINK_CALL_FAILED						= 4040,		//Link�������ʧ��
	EN_ZJ_ERR_SVR_LOGSVR_CALL_FAILED					= 4041,		//LOGϵͳ����ʧ��
	EN_ZJ_ERR_SVR_USERSVR_NOT_FOUND						= 4042,		//�û�ϵͳ�Ҳ���
	EN_ZJ_ERR_SVR_SYSNOTICESVR_CALL_FAILED				= 4043,		//sysnotice�Ҳ�������ʧ��
	EN_ZJ_ERR_SVR_PUBSUBSVR_CALL_FAILED					= 4044,		//���ķ����������ʧ��
	EN_ZJ_ERR_SVR_DYNAMICMETHOD_CALL_FAILED				= 4045,		//notice��̬������������ʧ��
	EN_ZJ_ERR_SVR_PLAYLOAD_IS_FULL						= 4046,		//����Ϊ��
	EN_ZJ_ERR_SVR_GRPCSVR_CALL_FAILED					= 4047,		//GRPC����ʧ��
	EN_ZJ_ERR_SVR_DEVICESVR_NOT_FOUND					= 4048,		//�豸ϵͳλ�Ҳ���
	EN_ZJ_ERR_SVR_EVENTSVR_NOT_FOUND					= 4049,		//�¼�ϵͳ�Ҳ���	
	EN_ZJ_ERR_SVR_ZONE_NOT_FOUND						= 4050,		//ZONE�����Ҳ���
	EN_ZJ_ERR_SVR_NET_WRITE_BLOCK						= 4051,		//����ͨ��д���ʧ��
	EN_ZJ_ERR_SVR_SOCKET_CLOSED							= 4052,		//SOCKET�����ѹر�
	EN_ZJ_ERR_SVR_SOCKET_READERR						= 4053,		//SOCKET���Ӷ�ȡ��ʧ��
	EN_ZJ_ERR_SVR_ID_PARSEERR							= 4054,		//ID��������ʧ��(��ʽ����ȡ)
	EN_ZJ_ERR_SVR_NET_DNSPARSE_ERR						= 4055,		//
	EN_ZJ_ERR_SVR_NET_REQ_TIMEOUT						= 4056,		//��������ʱ
	EN_ZJ_ERR_SVR_SUBPUB_TOKEN_NOTEXIST					= 4057,		
	EN_ZJ_ERR_SVR_SOCKET_ACCEPT_ERROR					= 4058,		
	EN_ZJ_ERR_SVR_OPERATION_TOO_FREQUENT				= 4059,		
	EN_ZJ_ERR_SVR_PARSE_IP_ERR							= 4060,		
	EN_ZJ_ERR_SVR_GETSVRPUBKEY_ERR						= 4061,		//��ȡpubkey
	EN_ZJ_ERR_SVR_LINKNOTICESVR_NOT_FOUND				= 4062,		//LINKNOTICE�Ҳ���
	EN_ZJ_ERR_SVR_ENCRYPTTYPE_ERROR						= 4064,		//�������ʹ���
	EN_ZJ_ERR_SVR_VIDEOSVR_NOT_FOUND					= 4065,		//��Ƶ�洢�����Ҳ���
	EN_ZJ_ERR_SVR_EXCEPTIONSVR_NOT_FOUND				= 4066,		//EXCEPTION�����Ҳ���
	EN_ZJ_ERR_SVR_LOGSVR_NOT_FOUND						= 4067,		//LOGSVR�Ҳ���
	EN_ZJ_ERR_SVR_OPRECORDSVR_NOT_FOUND					= 4068,		//OPRECORD�����Ҳ���
	EN_ZJ_ERR_SVR_NATSTUNSVR_NOT_FOUND					= 4069,		//NATSTUN�����Ҳ���
	EN_ZJ_ERR_SVR_COMBO_CALL_FAILED						= 4070,		//�ײͷ������ʧ��
	EN_ZJ_ERR_SVR_COMBO_NOT_FOUND						= 4071,		//�ײͷ����Ҳ���
	EN_ZJ_ERR_SVR_BINDSVR_NOT_FOUND						= 4073,		//�󶨷����Ҳ���
	EN_ZJ_ERR_SVR_PICTURESVR_NOT_FOUND					= 4074,		//ͼƬϵͳ�Ҳ���
	EN_ZJ_ERR_SVR_GROUPNOTHERE							= 4407,		//�鲻����
	EN_ZJ_ERR_SVR_DEVICENOTINGROUP						= 4409,		//Device��������
	EN_ZJ_ERR_SVR_WAKEUP_DEVICEERR						= 4422,		//���ѳ���
	EN_ZJ_ERR_SVR_DEVICEOFFLINE							= 4602,		//Device������
	EN_ZJ_ERR_SVR_DEVICE_ISSLEEP						= 4610,		//�豸������
	EN_ZJ_ERR_SVR_HAVENOGROUPS							= 4612,		//û�����б�
	EN_ZJ_ERR_SVR_REG_AUTH_ERR							= 5001,		//SIGN����ע�� SVRID&SVRPWDУ�����
	EN_ZJ_ERR_SVR_SIGN_ATOKEN_NOT_EXIST					= 5002,		//SIGN����ͨ��SVR ATOKEN�Ҳ�������
	EN_ZJ_ERR_SVR_SIGN_MANAGE_NOMETHOD					= 5004,		//SIGN��Manage�ӿ�method��֧��
	EN_ZJ_ERR_SVR_GENERALUTOKEN_ERR						= 5005,		//BUSI����UTOKEN����
	EN_ZJ_ERR_SVR_UTOKEN_NOTAUTHED						= 5006,	
	EN_ZJ_ERR_SVR_USERNOTHERE							= 5007,	
	EN_ZJ_ERR_SVR_USERISINGROUP							= 5011,	
	EN_ZJ_ERR_SVR_ROLENOTEXIST							= 5013,	
	EN_ZJ_ERR_SVR_CHILDGROUPNOTEXIST					= 5014,	
	EN_ZJ_ERR_SVR_ROLEISINUSE							= 5015,	
	EN_ZJ_ERR_SVR_GROUPISINGROUP						= 5016,	
	EN_ZJ_ERR_SVR_USERNOTINGROUP						= 5017,	
	EN_ZJ_ERR_SVR_GROUPNOTINGROUP						= 5019,	
	EN_ZJ_ERR_SVR_DEVICEISSLEEP							= 5021,	
	EN_ZJ_ERR_SVR_ID_MAXIDINDEX_GETERR					= 5024,	
	EN_ZJ_ERR_SVR_APPNOTEXIST							= 5026,	
	EN_ZJ_ERR_SVR_APPDISABLE							= 5027,	
	EN_ZJ_ERR_SVR_APPAUTHTYPE_ERR						= 5031,	
	EN_ZJ_ERR_SVR_APPISEXIST							= 5032,	
	EN_ZJ_ERR_SVR_ACCOUNTTYPENOTBIND					= 5034,	
	EN_ZJ_ERR_SVR_APPAUTHTYPENOTSUPPORT					= 5036,	
	EN_ZJ_ERR_SVR_DEVICE_NOT_AUTH						= 5038,	
	EN_ZJ_ERR_SVR_UTOKEN_NOT_AUTH						= 5039,	
	EN_ZJ_ERR_SVR_DEVICE_FORBIDDEN						= 5040,	
	EN_ZJ_ERR_SVR_UTOKEN_FORBIDDEN						= 5041,	
	EN_ZJ_ERR_SVR_UTOKEN_CHECKERR						= 5042,	
	EN_ZJ_ERR_SVR_SYSCOMMAND_FAIL						= 5043,	
	EN_ZJ_ERR_SVR_PUSHTEMPLATENOTEXIST					= 5044,	
	EN_ZJ_ERR_SVR_DEVICE_LIMIT_AUTH						= 5045,	
	EN_ZJ_ERR_SVR_SIGN_SVRKEY_NOTEXIST					= 5046,	
	EN_ZJ_ERR_SVR_SVRPUBKEY_NOTEXIST					= 5047,	
	EN_ZJ_ERR_SVR_FILETYPE_NOTEXIST						= 5048,	
	EN_ZJ_ERR_SVR_SUBPUB_SUBJ_NOT_EXIST					= 8000,	
	EN_ZJ_ERR_SVR_SUBPUB_ID_TYPE_NOT_SUPPORT    		= 8001,	
	EN_ZJ_ERR_SVR_NOTICE_QUEUE_WRITE_ERR				= 8002,		//NOTICE����д�����ʧ��
	EN_ZJ_ERR_SVR_NOTICE_PROTO_NOT_SUPPORT				= 8003,		//NOTICE֪ͨЭ�鲻֧��
	EN_ZJ_ERR_SVR_LANGUAGE_NOT_EXIST					= 8004,		//���Բ�����
	EN_ZJ_ERR_SVR_SUBPUB_PUBLISH_MSG_ERR				= 8005,		//���ķ�������Publishʧ��
	EN_ZJ_ERR_SVR_NOTICE_JUMP_NOTIE_SUPPORT				= 8006,		//NOTICE��������ò�֧��
    EN_ZJ_ERR_SVR_SIGNAL_NOT_SUPPORT					= 9001,    //�����͵�ָ��Է���֧�ָ�ָ������汾/�ͺŴ����£�
    EN_ZJ_ERR_SVR_SERVICE_TIMEOUT						= 9002,    //ָ��ͺ󣬳�����ʱʱ����û�л�Ӧ��
    EN_ZJ_SVR_SIGNAL_ALREADY_CACHE					    = 9003,    //ͨ�������ת������豸֧������棬�豸���ߣ����Ӧ��
    EN_ZJ_ERR_SVR_SIGNAL_DISCARD						= 9004,    //ͨ�������ת�������֧������棬�豸�����ߣ����Ӧ��
    EN_ZJ_ERR_SVR_CMD_NOT_SUPPORT						= 9010,    //�汾�Ͼɣ����豸���Ͳ����ϲ�֧�ֵ�ǰָ�
    EN_ZJ_ERR_SVR_DEVICE_REG_FORBIDDEN					= 9030,    //�豸ע����Ȩ�ޣ���������ƣ��豸��������
    EN_ZJ_ERR_SVR_DEVICE_LOGIN_FORBIDDEN				= 9031,    //�豸��½�����ã��豸��������


}EN_ZJ_ERR_TYPE;


#ifdef __cplusplus
}
#endif


#endif



