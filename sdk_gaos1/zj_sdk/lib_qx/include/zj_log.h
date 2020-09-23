#ifndef _ZJ_LOG_H_
#define _ZJ_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#define _ZJ_FUNC     __FUNCTION__ 
#else
#define _ZJ_FUNC     __func__

#endif

typedef enum enum_ZJ_LOG_LVL{
   EN_ZJ_LOG_LVL_NONE  = 0x0000,
   EN_ZJ_LOG_LVL_ERR   = 0x0001,
   EN_ZJ_LOG_LVL_WARN  = 0x0002,
   EN_ZJ_LOG_LVL_INFO  = 0x0004,
   EN_ZJ_LOG_LVL_DBG   = 0x0008,
   EN_ZJ_LOG_LVL_ALL   = 0x00FF, 
}EN_ZJ_LOG_LVL;

//���õ���ģʽ�� 0.�ر�print 1.��print
_ZJ_API int ZJ_SetDebugMode(int iDebugMode);

// ��־�򿪱�־
_ZJ_API int Zj_SetLogOpenFlag(int iOpenFlag);

 //������־ˮƽ ����EN_ZJ_LOG_LVL����
 _ZJ_API int ZJ_SetDebugLevel(EN_ZJ_LOG_LVL iLevel);

///��־��¼�� ֻ��ӡ��־ˮƽ��������־ˮƽ������
_ZJ_API int ZJ_LogPrintf(unsigned char* pucFunName, unsigned int uiLine, unsigned char* pucPid,unsigned int uiLeval, unsigned char* pucFormat, ...);

// ֪ͨ�豸��ʼ�ռ���־
_ZJ_API int ZJ_SetDevCollectLogFilesFunc(ZJ_PFUN_COLLECTLOGFILES pFunCollectLogFiles);

#ifdef XW_PLUGIN
struct XWLog {
    char *request_id;
    char *url;
    int error_code;
    char *msg;
    int http_status;
    int tt; // ????????ms
    int level; //????????  1 ????, 2 ?????? , 3 ???? ??????????
    char *extern_json;
};

char *generateUUID32Byte(char *uuid);
typedef int(*LogReportCallback)(char* logMsg, int msgSize);
_ZJ_API int initLogReporter();
_ZJ_API int setLogReportCallback(LogReportCallback cb, int msg_max_len);
_ZJ_API int logReport(const struct XWLog *log);
#endif

/**********************************************
iStatus�Ѽ�״̬ 0: �ռ����; <0:��ʾ�ռ�����  
pucFileName: ��־�ռ�ȫ·��
************************************************/
_ZJ_API int ZJ_SetCollectLogFilesStatus(unsigned char* pucPeerID, unsigned int uiSessionID,int iStatus, unsigned char* pucDesInfo, unsigned char* pucFileName);

#define ZJ_LOG_ERR(_pucFormat, ...) ZJ_LogPrintf((unsigned char*)_ZJ_FUNC,__LINE__,(unsigned char*)"APP", EN_ZJ_LOG_LVL_ERR,(unsigned char*)_pucFormat, ##__VA_ARGS__)

#define ZJ_LOG_INF(_pucFormat, ...) ZJ_LogPrintf((unsigned char*)_ZJ_FUNC,__LINE__,(unsigned char*)"APP", EN_ZJ_LOG_LVL_INFO,(unsigned char*)_pucFormat, ##__VA_ARGS__)


#ifdef __cplusplus
}
#endif

#endif