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


//���õ���ģʽ�� 0.�ر�print 1.��print
_ZJ_API int ZJ_SetDebugMode(int iDebugMode);

///��־��¼�� ֻ��ӡ��־ˮƽ��������־ˮƽ������
_ZJ_API int ZJ_LogPrintf(unsigned char* pucFunName, unsigned int uiLine, unsigned char* pucPid,unsigned int uiLeval, unsigned char* pucFormat, ...);

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
#endif



#define ZJ_LOG_ERR(_pucFormat, ...) ZJ_LogPrintf((unsigned char*)_ZJ_FUNC,__LINE__,(unsigned char*)"APP", EN_ZJ_LOG_LVL_ERR,(unsigned char*)_pucFormat, ##__VA_ARGS__)

#define ZJ_LOG_INF(_pucFormat, ...) ZJ_LogPrintf((unsigned char*)_ZJ_FUNC,__LINE__,(unsigned char*)"APP", EN_ZJ_LOG_LVL_INFO,(unsigned char*)_pucFormat, ##__VA_ARGS__)


#ifdef __cplusplus
}
#endif

#endif