/******************************************************************************

                  ��Ȩ���� (C), 2012-2022, Goscam

 ******************************************************************************
  �� �� ��   : upgrade.h
  �� �� ��   : ����
  ��    ��   : mr.iubing
  ��������   : 2014��4��9��
  ����޸�   :
  ��������   : upgrade.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2014��4��9��
    ��    ��   : mr.iubing
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef __UPGRADE_H__
#define __UPGRADE_H__

#include "sdk_commonstruct.h"
#include "api_Remote_Upgrade.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

//return : -1 -> invalid params;		-2 -> local upgrade package path is not exist; 0 -> success
int GOS_SDK_Upgrade_Bylocal(T_SDK_UPGRADE_BYLOCAL_PARAMS *param);

//reutnr : 0 -> success;
int GOS_SDK_Upgrade_Start(T_SDK_UPGRADE_BYSELF_PARAMS *param);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __UPGRADE_H__ */
