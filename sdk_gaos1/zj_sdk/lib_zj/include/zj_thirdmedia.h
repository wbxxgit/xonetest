#ifndef _ZJ_THIRDMEDIA_H_
#define _ZJ_THIRDMEDIA_H_
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

/*******************************************************************
����Ǩ��
*******************************************************************/
typedef ZJ_HANDLE (*ZJ_PFUN_OPENFILE)(unsigned char *pucFilePath,unsigned int *puiMaxFrameSize);

typedef int (*ZJ_PFUN_CLOSEFILE)(ZJ_HANDLE hHandle);

typedef int (*ZJ_PFUN_THIRDREADFRAME)(ZJ_HANDLE hHandle, unsigned char *pucFrame,unsigned int *puiFrameLen, unsigned char *pucAVFlag, int *pIFrame, unsigned int *puiTimeStamp);

typedef int (*ZJ_PFUN_SEEKBYTIMESTAMP)(ZJ_HANDLE hHandle, unsigned int uiSeekTime, unsigned int *puiSeekTimeStamp);

typedef int (*ZJ_PFUN_READFILEDES)(ZJ_HANDLE hHandle,ST_ZJ_VIDEO_PARAM *pstVideoParm,ST_ZJ_VIDEO_CIRCLE *pstCircle,ST_ZJ_AUDIO_PARAM *pstAudioParm);

//���������̴�¼���ļ�
_ZJ_API int ZJ_ThirdOpenFile(ZJ_PFUN_OPENFILE pfunOpenFile);

//���������̹ر�¼���ļ�
_ZJ_API int ZJ_ThirdCloseFile(ZJ_PFUN_CLOSEFILE pfunCloseFile);

//��ȡ����������¼��һ֡����
_ZJ_API int ZJ_ThirdReadData(ZJ_PFUN_THIRDREADFRAME pfunReadFrame);

//��ת������¼��ʱ��
_ZJ_API int ZJ_ThirdSeekTime(ZJ_PFUN_SEEKBYTIMESTAMP pfunSeekTime);

//��ȡ������¼������Ƶ����
_ZJ_API int ZJ_ThirdGetFileDes(ZJ_PFUN_READFILEDES pfunGetFileDes);

//�������������¼������
_ZJ_API int ZJ_RdAddCompatibleDate(unsigned char *pucDate,int iCamId);

//�������������¼���ļ�
_ZJ_API int ZJ_RdAddCompatibleFile(unsigned char *pucDate,int iCamId,unsigned char *pucFilePath,unsigned int uiStartUnixTime,unsigned int uiEndUnixTime,unsigned int uiStartMsTime,unsigned int uiEndMsTime);

//��������������¼�����
_ZJ_API int ZJ_EventAddCompatibleDate(unsigned char *pucDate);

//��������������¼�
_ZJ_API int ZJ_EventAddCompatibleFile(unsigned char *pucDate,time_t cEventTime,unsigned int uiDuration,unsigned int uiIotType,unsigned int uiEventId);


#ifdef __cplusplus
}
#endif


#endif
