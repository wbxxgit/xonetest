#ifndef _ZJ_IOTHUB_H_
#define _ZJ_IOTHUB_H_

#ifdef __cplusplus
extern "C" {
#endif

/***
 * ����IOT HUB��չ����������HUB��ͨ�š�Э��ת���ȣ��漰����չ������Э�齻����
 */
//�����豸֧��iOTHub��չ����. 0. ��֧�֣�û����չ�ۣ��� 1.֧�֣�����չ�ۣ���
_ZJ_API int ZJ_SetIoTHubAbility(int iSupport);

//�����豸iOTHub����״̬�� 0.û�в���HUB�� 1.�Ѿ�����HUB��
_ZJ_API int ZJ_SetIoTHubStatus(int iStatus);

//������Ҫͨ��RFHub���ط������ݵĻص��ӿڣ� ͨ���ýӿڽ�����ת��ΪRF�źŹ㲥��ȥ��
_ZJ_API int ZJ_SetIoTHubRecvFunc(ZJ_PFUN_IOTHUB_DATARECV pfunIoTHubDataRecv);

//RFHub���ؽ��յ�����豸��RF�źţ���������ת����д��SDKģ����д���
_ZJ_API int ZJ_IoTHubWriteData(unsigned char* pucData, int iLen);


#ifdef __cplusplus
}
#endif

#endif