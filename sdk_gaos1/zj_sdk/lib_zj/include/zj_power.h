#ifndef _ZJ_POWER_H_
#define _ZJ_POWER_H_

#ifdef __cplusplus
extern "C" {
#endif

// �����豸��Դ���ͣ��Ƿ����ء� 0.������أ�1.�����
_ZJ_API int ZJ_SetEnergySavingType(unsigned int iEngeryType);

// ���û��������� ����EN_ZJ_AWAKE_ABILITY
_ZJ_API int ZJ_SetAwakeAbility(unsigned int uiAwakeAbility);

// �����豸��ǰ�Ƿ��磻�����Ե�����豸��
_ZJ_API int ZJ_SetPowerSupply(unsigned int uiSupplyFlag);

// ���ý������߻ص�����
_ZJ_API int ZJ_SetStartSleepCb(ZJ_PFUN_STARTSLEEP pfuncStartSleep);

// �����豸��ǰ���������
_ZJ_API int ZJ_SetPowerLevel(unsigned int uiPowerLevel);


#ifdef __cplusplus
}
#endif

#endif