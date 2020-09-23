#ifndef _ZJ_CAMERAIOT_H_
#define _ZJ_CAMERAIOT_H_
/**
 ** ���������ͷ�豸��ص�IoT�¼��������磺ͼ����ⱨ���������������豸ָʾ�ƿ��ơ����������ơ�����¼��
 **/

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************************
1 ���һ��IoT�豸��һ�����õ��Ǹ��豸�Ĺ�����ʼ/��������/��ȡ�����ź�/����źŵĻص�������
2 ����ǿ����� �� ��������� �� ����Ҫע�� start �� stop ����,Ĭ�Ͽ�������
3 ����Ǳ�����: ����motion: ��Ҫע�� start stop  pfunAIIoTSetProp , Ȼ����Ե��� ZJ_IoTEventInPut ����ź�
*******************************************************************************************/
/********************************************************************************
1 �ƶ����: 
prop: json ��: {"Motion":{"Sensitive":"","Status":"","Trace":"","Interval","ActiveTime":"����ʱ��"},
                "Human":{"Sensitive":"","Status":"","Trace":"","Interval","MaxCount","ActiveTime":"����ʱ��"},
                "Face":{"Sensitive":"","Status":"","Trace":"","Interval","MaxCount","ActiveTime":"����ʱ��"}};
*********************************************************************************/

/********************************************************************************
2 ��������
prop: json ��: {"Sensitive":""},
*********************************************************************************/

/*********************************************************************************
3 ����pir 
prop: {"Sensitive":""}
**********************************************************************************/

/*********************************************************************************
3 ������
"output": {"CtrlType":"","AlarmType":"","SoundName":"","LoopCnt"}
"prop": ��
**********************************************************************************/

/*******************************************************************************
4 �ƹ�
"prop":{"Flicker":""}
"Output":{"CtrlType":"","Flicker":"","Duration":""} // ���û�� flicker ���� ��output Ҳû�� 
********************************************************************************/

/*******************************************************************************
5 ¼��
"prop":{"RecordLoop":"", "RecordFull" : "","StreamID",""}
********************************************************************************/

/*******************************************************************************
6 ����ץͼ
"prop":{"LoopFlag":"", "Interval" : "","PicType","", "FullFlag":""}
********************************************************************************/

/*******************************************************************************
7 ǿ�ư�������
"prop":{"IrcutType":""}
"Output":{"CtrlType":""} //EN_ZJ_IRMODE
********************************************************************************/
_ZJ_API int ZJ_AddIoTDevice(unsigned int uiAIIoTType, unsigned long long lluAIIoTID,
                            ZJ_PFUN_AIIOT_START pfunAIIoTStart, ZJ_PFUN_AIIOT_STOP pfunAIIoTStop, 
                            ZJ_PFUN_AIIOT_GETINPUT pfunAIIoTGetInput, ZJ_PFUN_AIIOT_OUTPUT pfunAIIoTOutPut,
                            ZJ_PFUN_AIIOT_SETPROP pfunAIIoTSetProp, ZJ_PFUN_AIIOT_CHECKEVENT pfunAIIotCheckEvent);

//����IoT�豸��Ĭ�����ԣ�IoT�豸������һ��JSON�ַ�������
_ZJ_API int ZJ_SetIoTDefaultProp(unsigned int uiAIIoTType, unsigned long long lluAIIoTID, char* pcProp);

//IoT�豸�����źŽӿ�, �����ź����ͺͶ�Ӧ��Json�ַ�����Ϊ�ź�����
_ZJ_API int ZJ_IoTInPut(unsigned int uiAIIoTType, unsigned long long lluAIIoTID, char* pcInPut);

//IoT�豸�¼�����ӿڣ�IoT�豸Ϊ�¼���һ�豸������ʱֱ�Ӹ�����������¼���
_ZJ_API int ZJ_IoTEventInPut(unsigned int uiAIIoTType, unsigned long long lluAIIoTID, int iEvent);

// ����Ĭ��¼������� ���� ���� ZJ_SetIoTDefaultProp ����
_ZJ_API int ZJ_SetDefaultRecordProp(unsigned int uiLoopFlag,unsigned int  uiFullFlag,unsigned int uiStreamId);

// ���ñ���ץͼ�� Ĭ������
_ZJ_API int ZJ_SetDefaultSnapProp(unsigned int uiLoopFlag,unsigned int uiFullFlag,unsigned int uiInterval,unsigned int uiPicType);

// ��⵽�����б� �������,  ���õ��� ZJ_IoTEventInPut
_ZJ_API void ZJ_SetHumanFaceEvent(unsigned int uiAIIoTType, unsigned long long lluAIIoTID,ST_ZJ_HUMANFACE_INFO *pstHumanIfoList);

//����Ĭ�ϵ�iot����
_ZJ_API int ZJ_SetIotDefaultPolicy(unsigned int uiIotType, unsigned int uiOpenFlag, unsigned int uiEventId, unsigned int uiTraceFlag, unsigned int uiBuzzerFlag,
    unsigned int uiSenstive, unsigned int uiRecordFlag, unsigned int uiSnapFlag, unsigned int uiEventFlag, unsigned int uiDuration,unsigned int uiActiveTime);

#ifdef __cplusplus
}
#endif

#endif
