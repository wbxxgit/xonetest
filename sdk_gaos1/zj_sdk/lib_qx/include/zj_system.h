#ifndef _ZJ_SYSTEM_H_
#define _ZJ_SYSTEM_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * �豸��ʼ���ӿڣ�����һ�����ô洢·����һ��ϵͳ·����ϵͳ·�������� ��ʱ�� ���ļ����ᱻɾ��
 ��Ҫȷ��·���ɷ��ʣ��粻�ɷ�����᷵�ض�Ӧ�Ĵ���״̬��Ϣ��
 */
_ZJ_API int ZJ_Init(char *pucSystemPath, char* pcConfPath);

// �Զ���ƽ̨�� ������ַ xxx:port port ���� Ĭ�� 443
_ZJ_API int ZJ_SetPlatSignAddr(unsigned char *pucSignAddr);

// ��ҵ����Ϣ, û�п��Բ���
_ZJ_API int ZJ_SetCompanyInfo(unsigned char *pucCompanyId,unsigned char* pucAppId);

// �����豸CTEI ID
_ZJ_API int ZJ_SetCTEIID(unsigned char* pucCTEI);

// �����豸��DeviceUID��
_ZJ_API int ZJ_SetDeviceUID(unsigned char *pucDevSn, unsigned char *pucDevKey);

//�����豸�ͺ� EF-FH8632-0530-00  ��һλ sdk ������ , �ڶ�λ����оƬ�ź� ���� ��Ʒ�ͺ� ���� ʡ��
_ZJ_API int ZJ_SetDeviceModel(unsigned char *pucDevModel);

//EN_ZJ_OS_TYPE
_ZJ_API int ZJ_SetDevOsType(unsigned int uiOsType);

//�����豸����?1.�������2.�������壻3.�������壻4.NVR
_ZJ_API int ZJ_SetDevType(unsigned int uiDevType);

// ���ù̼��汾�ţ��汾�Ŷ�����ѭ�汾�Ŷ������
_ZJ_API int ZJ_SetAppVersion(const char* pcVersion);

// �豸״̬�ص��������ã� �ӳ�ʼ������&�豸����&�豸��Ӱ󶨣�һ��Ϊ��Ҫ�ϲ��������ʾ�Ĳ�Ʒ���øûص�����
_ZJ_API int ZJ_Set_SystemStatusCB(ZJ_PFUN_DEVICE_STATUS pFunSelfStatusCb);

// �豸�����ص��������ã��豸�ϲ��ڸú����а�ȫ�ر��豸��ִ�г���Ȼ���豸��������
_ZJ_API int ZJ_SetDeviceRebootCbFunc(ZJ_PFUN_DEV_REBOOT pfunDevRebootCb);

//����ϵͳʱ���ȡ�����ûص�����
_ZJ_API int ZJ_SetZoneAndTimeCB(ZJ_PFUN_DEVICE_SETTIMEZONE pfunSetTimeZone, ZJ_PFUN_DEVICE_GETTIMEANDZONE pfunGetTimeZone);

//����ϵͳMemory����ֵ,������Ĭ��ΪMIDֵ
_ZJ_API void ZJ_SetSysMemLevel(EN_ZJ_DEVICE_MEM_ABILITY enZJDevAblity);

//�����豸�ָ��������ûص�����
_ZJ_API int ZJ_SetRestoreFactorySettingCB(ZJ_PFUN_DEVICE_RESTOREFACTORYSETTING pfunRestoreFactorySetting);

//������������ƵĻص���֪ͨui�㣬�豸��dev��������仯
_ZJ_API int ZJ_SetNoticeCfgChangeCbFun(ZJ_PFUN_CFGITEM_CHANGE pfunCfgItemChangeCb);

//�����豸���������� ��λ�� EN_ZJ_ENCRYPT_ABILITY
_ZJ_API int ZJ_SetEncryptAbility(int iEncAbility);

// ��ȡ�豸��did, ��ID �� ������ ����
_ZJ_API unsigned char* ZJ_GetDeviceId();

// EN_ZJ_CTRLDEVICEID_TYPE
_ZJ_API int ZJ_CtrlDeviceId(unsigned int uiCtrlType);

// ��ȡ �� ���� �豸����
_ZJ_API unsigned char *ZJ_GetDeviceName();

_ZJ_API int ZJ_SetDeviceName(unsigned char *pucDevName);

// ��ȡ��ǰ��Ч���ײ�
_ZJ_API int ZJ_GetCurChargePackage(ST_ZJ_CURCHARGEPACKAGE *pstChargePackage);

// 1 �������� 0 ����
_ZJ_API int ZJ_BoolDeviceJoinGroup();

// ��ȡ �豸 �� �û� ��Ϣ
_ZJ_API int ZJ_GetDeviceOwnerPubInf(unsigned char aucName[64],unsigned char aucCcount[64],unsigned char aucMobile[32]);

// �����豸��4G����
_ZJ_API int ZJ_SetSIMCardInfo(unsigned char aucSIMCard[64]);

// ����4G��������
_ZJ_API int ZJ_Set4GAbility(int i4GAbility);


_ZJ_API int ZJ_Start();

_ZJ_API int ZJ_Stop();

//SDKʵ�����ٽӿڣ�
_ZJ_API int ZJ_Destroy();


#ifdef __cplusplus
}
#endif

#endif