#ifndef _ZJ_OTA_H_
#define _ZJ_OTA_H_

#ifdef __cplusplus
extern "C" {
#endif

// �����豸����״̬�ص�������ͨ���ص���������״̬���豸�ϲ��յ������������������������̼���
_ZJ_API int ZJ_SetOtaCBFuncs(ZJ_PFUN_NEWVERSON_NOTICE pFunNewVersionCb,
    ZJ_PFUN_NEWVERSON_DATADOWN pFunVersonDataDownCb, ZJ_PFUN_STOPUPGRADE pFunStopUpgrade,ZJ_PFUN_COVERIMAGE_NOTICE pFunCoverImageNotice);

// �豸��ʼ����״̬���豸�ϱ�ƽ̨����������״̬�� �����ؽ���������״̬�������������̣���ʼ������
_ZJ_API int ZJ_StartUpdate();

// �汾���ظ��º�, �㱨��¼ ����
_ZJ_API int ZJ_SetBurnningProgress(unsigned int uiPercentage);

//����OTA�����������߱�����������λ��
_ZJ_API int ZJ_SetOTAAbility(unsigned int uiOTAAbility);

#ifdef __cplusplus
}
#endif

#endif