#ifndef _ZJ_CAMERA_H_
#define _ZJ_CAMERA_H_

#ifdef __cplusplus
extern "C" {
#endif

_ZJ_API int ZJ_SetLensMaxCount(int iLensCount);

_ZJ_API int ZJ_SetLensInf(int iLenId,char *pucLenName,EN_ZJ_CAMERA_LENS_TYPE enLensType,double focalLenth);

_ZJ_API int ZJ_GetCurLenId(int *piOutCurLenId);

/***
 *** ����Ϊ����ͷ���������ú����� ������Ĭ��Ϊ��֧�֣�
 ****/
// ������������ ��Ϊ0���ʾû������ͷ��Ĭ��Ϊ0
_ZJ_API int ZJ_SetStreamCount(int iStreamCount);

//���������Խ����� 0.��֧�֣�1.֧�ֵ�����2.֧��˫��
_ZJ_API int ZJ_SetVoicePlayAbility(int iVoicePlayAbility);

//OSD��������֧��  0.��֧�֣� 1.֧�֣�
_ZJ_API int ZJ_SetOSDSetAbility(int iOSDSetAbility);

//Ԥ�õ���������֧��  0.��֧�֣� 1.֧�֣�
_ZJ_API int ZJ_SetPresetPointAbility(int iPresetAbility);

//���÷ֱ�����������֧�ֶ��ְ�λ�� EN_ZJ_CARERA_RESOLUTION_ABILITY ��������
_ZJ_API int ZJ_SetResolutionAbility(int iStreamid,int iResolutionAbility);

//���ñ���������֧�ֶ��ְ�λ�� ����EN_ZJ_VIDEOENC_TYPE ��������
_ZJ_API int ZJ_SetVideoEncodeAbility(int istreamid,int iEncAbility);

//������˷��Ƿ�֧�� 0.��֧�֣� 1.֧�֣�
_ZJ_API int ZJ_SetMicroPhoneAbility(int iMicroPhoneAbility);

//����IRLed����ƿ���ģʽ  EN_ZJ_IRMODE
_ZJ_API int ZJ_SetIRLedAbility(int iIRLedAbility);
// �ο�����EN_ZJ_IRMODE��
_ZJ_API int ZJ_SetCamerCurIRWorkMode(int iCurWorkMode);

//����ͼ��ת����֧������  0.��֧�֣� 1.֧�֣�
_ZJ_API int ZJ_SetImageInversionAbility(int iInversionAbility);

//����SD��֧������   0.��֧�֣� 1.֧�֣�
_ZJ_API int ZJ_SetSDCardAbility(int iSDCardAbility);

// ����PTZ֧������
//����PTZ���� 0.��֧�֣�0x01: ֧��P��0x02: ֧��T��0x04: ֧��Z����λ��
_ZJ_API int ZJ_SetPTZAbility(int iPTZAbility);

//����PTZ��̨�ٶ����ñ�־ 0.��֧�֣� 1.֧�֣�
_ZJ_API int ZJ_SetPTZSpeedAbility(int iPTZSpeedSetAbility);

//���������̨PTZ������
_ZJ_API int ZJ_SetAttachPTZAbility(int iAttachPTZAbility);

//���û��淭ת�ص��ӿڣ� ͨ���ûص��ӿ�֪ͨ�ϲ������淭ת
_ZJ_API int ZJ_SetImageInversionCB(ZJ_PFUN_IMAGEINVERSION pfunImageInversion);

//���ú���ƿ��ؿ��ƻص��ӿڣ� ͨ���ûص��ӿ�֪ͨ�ϲ�������ƿ��ؿ���
_ZJ_API int ZJ_SetIRLedSwitchCB(ZJ_PFUN_IRLED_SWITCH pfunIRLedSwitch);

//��������ͷ��/�رջص��ӿڣ� ͨ���ûص��ӿ�֪ͨ�ϲ�ر���Ƶ�ɼ���ֹͣ��⡢ֹͣ���롢ֹͣ�ɼ���ֹͣ�ɼ���Ƶ��ֹͣ������⣻
_ZJ_API int ZJ_SetCameraSwitchCB(ZJ_PFUN_CAMERA_SWITCH pfunCameraSwitch);

//��������ͷPTZ�ص��ӿڣ�ͨ���ûص��ӿ�֪ͨ�ϲ���ɶ�ӦPTZ����
_ZJ_API int ZJ_SetCameraPTZCB(ZJ_PFUN_CAMERA_ONPTZ pfunOnPTZ, ZJ_PFUN_CAMERA_PTZ_GETPOINT pfunPTZGetPoint,
                ZJ_PFUN_CAMERA_PTZ_GOTOPOINT pfunPTZGotoPoint, ZJ_PFUN_CAMERA_PTZ_AUTOCHECK pfunPTZAutoCheck,
                ZJ_PFUN_CAMERA_CRUISE_START pfunCruiseStart,ZJ_PFUN_CAMERA_PTZ_STOP pfunPtzStop);

//����¼��״̬�ص��ӿ� ͨ���ýӿڿ������ϲ�����Ӧ����ʾ
_ZJ_API int ZJ_SetRecordStatusCB(ZJ_PFUN_CAMERA_RECORD_STATUS pfunRecordStatus);

//������Ƶ����ɨ��Ƶ�ʽӿ� 

//�����������ǰ״̬�� 1.��/0.�رգ� ����������ϲ��������ذ�ť������������رա���״̬��
_ZJ_API int ZJ_SetCameraStatus(int iStatus);

//��ʼ�����¼�� �豸�д�����ʼ¼���ֹͣ¼��Ľӿڣ�������ʼ¼�ƣ�����¼��������ţ��������0Ϊ��������1Ϊ�������������ִ���¼��ʱ����������¼�����ȣ�
_ZJ_API int ZJ_StartRecord(int iStreamID);

//ֹͣ��ǰ¼���豸�ϲ�ر�¼��SDK�յ�����Ϣ�ر�����¼��
_ZJ_API int ZJ_StopRecord();

//���������ˮӡ���ûص��ӿڣ�
_ZJ_API int ZJ_SetOSDSettingCB(ZJ_PFUN_CAMERA_OSDSETTING pfunOSDSetting);

//�����Ƿ���ʾTimeosd
_ZJ_API int ZJ_SetShowTimeOSDCB(ZJ_PFUN_CAMERA_CTRLOSDSHOWFLAG pfunCtrlTimeOSD,ZJ_PFUN_CAMERA_CTRLOSDSHOWFLAG pFunCtrlCustomOsd);


//����Cache�洢·���ӿڣ�pcStoragePath���洢·����·���󲻴�'/'��'\'���ţ�Ϊȫ·����������·��Ϊ�ձ�ʾû��SD����
_ZJ_API int ZJ_SetStoragePath(char* pcStoragePath);

//���������ļ�·�� 
_ZJ_API int ZJ_SetDevSoudFilePath(char* pcStoragePath);

//����SD�������ص��ӿڣ�
_ZJ_API int ZJ_SetSDCardCB(ZJ_PFUN_CAMERA_FORMATSDCARD pfunFormatSDCard, ZJ_PFUN_CAMERA_GETSDCARDSIZE pfunGetSDCardInfo, ZJ_PFUN_CAMERA_CHECKSDCARD pfunCheckSDCard);

/***
 *** ����Ϊ˫��������غ���
 ****/
//�����Խ����ջص��ӿڣ������豸��һ��ý��������,�����ǰ����û���ڲ����򷵻ؿɲ��ţ��豸ͨ���ӿڻ�ȡ���ݲ��š�
_ZJ_API int ZJ_SetMediaToPlayCB(ZJ_PFUN_CAMERA_MEDIA_TOPLAY pfunMediaToPlay);

//ͨ�������ȡ��Ƶ����
_ZJ_API int ZJ_GetMediaAudioParam(ZJ_HANDLE hHandle, ST_ZJ_AUDIO_PARAM* pstAudioParam);

//ͨ���������ȡ��Ƶ����,��������BUFFER�����ݳ��ȣ�ʱ���
_ZJ_API int ZJ_GtMediaAudioData(ZJ_HANDLE hHandle, unsigned char** ppucDataBuf, int* iDataLen, unsigned int* puiTimestamp);
/***
 *** ����Ϊ��Ƶ�ɼ�������غ���
 ****/
//������Ƶ�������
_ZJ_API int ZJ_SetAudioEncParm(ST_ZJ_AUDIO_PARAM* pstAudioParam);


//д��Ƶ����
_ZJ_API int ZJ_Audio_WriteFrame(unsigned char* pucFrame, int iLen, unsigned int uiTimestamp);

//����������Ƶ�������
_ZJ_API int ZJ_Audio_ResetParam(ST_ZJ_AUDIO_PARAM* pstAudioParam);

//������Ƶ���뿪�ػص��ӿ�  ͨ���ýӿڿ�����Ƶ�Ƿ����
_ZJ_API int ZJ_SetAudioEncSwitchCB(ZJ_PFUN_AUDIO_SWITCH pfunAudioSwitch);

//������Ƶ�ɼ�/�����������ڽӿ� ͨ���ýӿڵ�������
_ZJ_API int ZJ_SetAudioVolumnCB(ZJ_PFUN_AUDIO_VOLUMN_ADJUST pfunAudioVolumnAdjust);

//���������������������ǰֵ
_ZJ_API int ZJ_SetAudioVolumn(int iVolumn);
// ��ȡ��������������
_ZJ_API int ZJ_SetCamerMicOpenFlag(int iOpenFlag);

_ZJ_API int ZJ_GetCameraMicOpenFlag();

//��������������������
/*****************************************************************
����Ϊ��Ƶ�ɼ�������غ���
 ****************************************************************/
//�������� ��Ǿ�ͷУ������������ͷΪ��Ǿ�ͷʱ��
_ZJ_API int ZJ_SetStreamWideAngleLensInfo(int iStreamID, ST_ZJ_VIDEO_CIRCLE* pstCircleInfo);
_ZJ_API int ZJ_SetStreamWideAngleLensDistortion(int iStreamID, ST_ZJ_VIDEO_DISTORTION* pstDistortionInfo);

//�������� ��Ƶ���������
_ZJ_API int ZJ_SetVideoEncParam(int iStreamID, ST_ZJ_VIDEO_PARAM* pstVideoParam);

//����д��ӿڣ���Frameһ֡һ֡������д
_ZJ_API int ZJ_Video_WriteFrame(int iStreamID, unsigned char* pucFrame, int iLen, unsigned int uiTimestamp, unsigned int uiFrameType);

//����д��ӿڣ���NAL��ʽ����������д
_ZJ_API int ZJ_Video_WriteNalFrame(int iSteramID, unsigned char* ptNal[], int iNalLen[], int iNalNum, unsigned int uiTimestamp, unsigned int iFrameType);

//���ñ��������һ���Ǹı��˲ɼ��ֱ��ʺͱ��뷽��
_ZJ_API int ZJ_Video_ResetParam(int iStreamID, ST_ZJ_VIDEO_PARAM* pstVideoParam);

//������Ƶ���뿪�ػص��ӿ� ͨ���ýӿڿ�����Ƶ�Ƿ����
_ZJ_API int ZJ_SetVideoEncSwitchCB(ZJ_PFUN_VIDEO_SWITCH pfunVideoSwitch);

//������Ƶ�������
_ZJ_API int ZJ_SetVideoEncParamCB(ZJ_PFUN_SET_VIDEO_PARM pfunSetVideoParm);

//������Ҫһ���༭һ��I֡�ص��ӿ� ͨ���ýӿ�֪ͨ��������һ��I֡д����
_ZJ_API int ZJ_SetVideoNeedIFrameCB(ZJ_PFUN_VIDEO_NEEDIFRAME pfunVideoNeedIFrame);
//������Ƶ�������ʵ��ڽӿ� ͨ���ýӿ�֪ͨ���������ڱ�����������ֵ����/��������

//���û�ȡͼƬ�ص��ӿ�
_ZJ_API int ZJ_Video_SetGetJpegCB(ZJ_PFUN_VIDEO_GETJPEG pfunVideoGetJpeg);

/*****************************************************************
******************************************************************/
//�л�ǰ������ͷ
_ZJ_API int ZJ_SetSwitchLenCB(ZJ_PFUN_SWITCH_LEN pfunSwitchLen);

//�������̬����
_ZJ_API int ZJ_SetCamWdrOpenFlagCB(ZJ_PFUN_SET_WIDE_DYNAMIC_CAM pfunSetWideDynamicCam);

/****************************************************************************************
�Զ�����������
*****************************************************************************************/
_ZJ_API int ZJ_SetCamAlarmSoundFileCB(ZJ_PFUN_DELSOUNDFILE  pFunDelSoundFile,ZJ_PFUN_GETSOUNDFILES  pFunGetSoudFiles);

/***************************************************************
�м��豸
***************************************************************/

// ��ȡ��ǰ����ʵʱ��Ƶ�Ự��TTL ʱ��

#ifdef __cplusplus
}
#endif

#endif
