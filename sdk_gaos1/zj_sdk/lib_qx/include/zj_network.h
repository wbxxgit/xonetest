#ifndef _ZJ_NETWORK_H_
#define _ZJ_NETWORK_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * �����豸����״̬��Ϣ����������SDK������仯����Ӧ������Ӧ���Ӽ�ʱ��
 *************************************************************************/
_ZJ_API int ZJ_SetNetWorkType(EN_ZJ_NETWORK_TYPE enNetType);

// ���û�ȡWIFI�б������WIFI�Ļص�������
_ZJ_API int ZJ_SetWifiCB(ZJ_PFUN_DEVICE_SETWIFI pfuncSetWifi, ZJ_PFUN_DEVICE_GETWIFI pfuncGetWifi, ZJ_PFUN_DEVICE_GETNETINFO pfunGetNetInfo);
// �����������״̬�������緢������ʱ��֪ͨ��������
_ZJ_API int ZJ_SetNetErrStatus(EN_ZJ_NETWORK_ERR_STATUS enNetWorkErrStatus);

// WiFi�����������ã�����EN_ZJ_SETWIFI_ABILITY��λ���ʾ֧�ֶ�������ģʽ
_ZJ_API int ZJ_SetWifiSetAbility(unsigned int uiSetWifiAbility); 

/**********************************************************************************
��ά�� �������� �ϲ�ʶ�𵽶�ά�룬����Ӧ���ַ�����������
***********************************************************************************/
_ZJ_API int ZJ_SetQRCodeString(unsigned char *pstrQRCode);

//���������� ���ϲ�����ʶ����ַ�����������
_ZJ_API int ZJ_SetVoiceString(unsigned char* pstrVoiceString);


#ifdef __cplusplus
}
#endif

#endif