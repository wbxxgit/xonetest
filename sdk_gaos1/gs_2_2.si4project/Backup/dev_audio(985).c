#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "devCfg.h"
#include "device_log.h"
#include "zj_type.h"
#include "zj_log.h"
#include "zj_camera.h"  

#include "dev_zj_funReg.h"

#include "forZb_camera.h"  

#include "IPC_MediaBuff.h"
#include "sdk_commonstruct.h"
#include "sdkout_impl.h" 


static pthread_t tid_dev_audio = 0;

static void *dev_audio_loop(){
    int iDataLen;
    unsigned char *ucAudioData;
    unsigned int uiTimestamp;
//	unsigned char s_talk_data[2048] = {0};	
	DPRI_INFO("enter loop_dev_audio");
	while(1){		
		if(dj_audio_GtFTbl()->f_GtMediaAudioData == NULL){
			DPRI_INFO("f_GtMediaAudioData no register");
			usleep(500*000);
			continue;
		}
		
		if(stH_glget_audio()->iRun == 1){		
			DPRI_INFO("audio iRun openflag:%d ",stH_glget_audio()->openflag);
			if(stH_glget_audio()->openflag !=1){
				stH_glget_audio()->openflag = 1;			
			//	if(SDK_Cmd_Impl(SDKCMD_INTERCOM_START, NULL)){
			//		DPRI_INFO("SDKCMD_INTERCOM_START fail");					
			//		continue;
			//	}		
			
			} 				
	        dj_audio_GtFTbl()->f_GtMediaAudioData(stH_glget_audio()->hPlayHandle, &ucAudioData, &iDataLen, &uiTimestamp);
	        if(iDataLen > 0){	
				T_SDK_INTERCOM_DATA t_inercom_data;	
				t_inercom_data.cp_data = ucAudioData;
				t_inercom_data.un_data_len = iDataLen;
	            DPRI_INFO("audio recv voice data, size [%d] uiTimestamp[%u]", iDataLen, uiTimestamp);	
				if(SDK_Cmd_Impl(SDKCMD_SEND_INTERCOM_DATA, &t_inercom_data) != 0)			
					DPRI_INFO("SDKCMD_SEND_INTERCOM_DATA faile\n");				
	        }else{
	        	DPRI_INFO("f_GtMediaAudioData iDataLen:%d,usleep(5000)",iDataLen);
				usleep(5000);
			}			
			
						
		}else{	
			
			if(stH_glget_audio()->openflag !=0){				
				stH_glget_audio()->openflag = 0;
			//	if(SDK_Cmd_Impl(SDKCMD_INTERCOM_STOP, NULL))
			//		DPRI_INFO("SDKCMD_INTERCOM_START fail\n");					
				DPRI_INFO("intercom play over.openflag[%d]",stH_glget_audio()->openflag);							
			} 	 
			usleep(200*000);
		}	
	}
	return 0;
}

int dev_audio_init(void){
	DPRI_INFO("dev_audio_init exe");

	if(SDK_Cmd_Impl(SDKCMD_INTERCOM_START, NULL)){
		DPRI_INFO("SDKCMD_INTERCOM_START fail");					
		return -1;
	}

	return 0;	
} 

int dev_audio_start(void){
	DPRI_INFO("dev_audio_start exe");
	if(-1 == pthread_create(&tid_dev_audio, NULL, dev_audio_loop, NULL)){
		DPRI_INFO("create error!\n");
		return -1;
	}	
	return 0;
} 
int dev_audio_destory(void){
	void *ret;
	pthread_t tid_tmp = tid_dev_audio;
	DPRI_INFO("dev_audio_destory exe\n");	
	
	pthread_cancel(tid_tmp);	
	pthread_join(tid_tmp,&ret);//等待线程2的返回状况，获取返回值
	if(ret==PTHREAD_CANCELED)
		return 0;			
	else{
		DPRI_INFO("thread return,id is:%ld,return code:NULL\n",tid_tmp);	
		return -1;
	}	
} 







