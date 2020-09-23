#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#include <string.h>


#include "zj_type.h"
#include "zj_log.h"

#include "forZb_comCfg.h"
#include "forZb_camera.h"

#include "dev_zj_funReg.h"

#include "sdk_commonstruct.h"
#include "sdkout_impl.h" 



static char *PcSnapPic = NULL;

ST_H_VOICEPLAY st_H_audio = {0};




ST_H_VOICEPLAY *stH_glget_audio(){
    return  &st_H_audio;
}


int fzb_ImageInversion(int iState){
	return 0;
}

int fzb_VideoNeedIFrame(int iStreamID,unsigned int uiKeyQuality){
	return 0;
}

int fzb_VideoSwitch(int iStreamID, int iState){
	printf("VideoSwitch iStreamID[%d],iState[%d]",iStreamID,iState);

	
	
	return 0;
}

static int SDK_SnapShot()
{
	T_SDK_PIC_PATH un_snap_path;
	memset(&un_snap_path, 0, sizeof(un_snap_path));
	strcpy((un_snap_path.pic_path), "/mnt/app/1.jpg"); //the folder must exist and can be write.
	printf("SDK_SnapShot pic_path >>>>>>>>>>%s\n",un_snap_path.pic_path);
	if (0 != SDK_Cmd_Impl(SDKCMD_SET_SNAPSHOT_PATH,(void *)&un_snap_path))
	{
	   printf("callSDKCMD_SET_SNAPSHOT_PATH fail .\n");           
	   return -1;
	} 	
	return 0;
}

int fzb_VideoGetJpeg(EN_ZJ_PICTURE_TYPE enPicType, unsigned char **ppucJpegBuf){

	FILE *fjge  = NULL;
	char *filepath = NULL;
	unsigned int filesize = 0;
	char *tmpmallocp = NULL;

	printf("GetJpeg callback enPicType:%d,ppucJpegBuf:%p\n",enPicType,*ppucJpegBuf);
	if( SDK_SnapShot() != 0){
		printf("SDK_SnapShot err!\n");
		return -1;
	}

	filepath = "/mnt/app/1.jpg";
	fjge  = fopen(filepath,"rb"); 
	if(NULL==fjge){
		ZJ_LOG_INF("fopen PATH error!\n");
		return -1;
	}   
	fseek(fjge,0, SEEK_END);
	filesize = ftell(fjge);//读取图片的大小长度
	fseek(fjge, 0, SEEK_SET);
	ZJ_LOG_INF("ftell filesize:%d",filesize);
	if(0 == filesize)
		return -1;
	tmpmallocp = (char *)realloc(PcSnapPic, filesize);
	if(tmpmallocp == NULL){
		ZJ_LOG_INF("device video snap realloc buff failed\n");
		return -1;
	}
	PcSnapPic = tmpmallocp;
	if(0 == fread(PcSnapPic, 1, filesize, fjge)){
		fclose(fjge);
		ZJ_LOG_INF("fread err\n");
		return -1;
	}
	*ppucJpegBuf = (unsigned char *)PcSnapPic;
	ZJ_LOG_INF("*ppucJpegBuf :%p\n",*ppucJpegBuf);
	fclose(fjge);	
    return filesize;  
}

int fzb_VideoGetJpeg_destorySP(){
	free(PcSnapPic);
	PcSnapPic = NULL;	
	return 0;
}


//audio
int fzb_AudioSwitch(int iState){
	printf("AudioSwitch iState[%d]",iState);
	return 0;
}

int fzb_MediaToPlay(const char* pcPeerID, ZJ_HANDLE hPlayHandle, int iStreamType, int iStatus){

	ST_ZJ_AUDIO_PARAM stAudioParam = {0};
	stH_glget_audio()->pcPeerID = pcPeerID;
	stH_glget_audio()->hPlayHandle  =  hPlayHandle;
	stH_glget_audio()->iRun = iStatus;
	printf("device audio start voice to play , iStreamType [%d], iStatus [%d] \n", iStreamType,iStatus);

	if( NULL == dj_audio_GtFTbl()->f_GetMediaAudioParam){
		printf("f_GetMediaAudioParam no register!\n");
		return -1;			
	}	
	dj_audio_GtFTbl()->f_GetMediaAudioParam(stH_glget_audio()->hPlayHandle , &stAudioParam);
	printf("device audio encode param:\n");
	printf(" 			uiEncodeType: %u\n", stAudioParam.uiEncodeType);
	printf(" 			uiSampleRate: %u\n", stAudioParam.uiSampleRate);
	printf(" 			   uiChannel: %u\n", stAudioParam.uiChannel);
	printf(" 				 uiDepth: %u\n", stAudioParam.uiDepth);
	return 0;
}

//sd
int fzb_FormatSDCard(){
    ZJ_LOG_INF("FormatSDCard exe...\n");
    return 0;

}

int fzb_GetSDCardInfo(unsigned int *piTotalSize, unsigned int *piFreeSize){    
	*piTotalSize = 100;
	*piFreeSize = 48;
	ZJ_LOG_INF("GetSDCardInfo piTotalSize:%d,piFreeSize:%d\n",*piTotalSize,*piFreeSize);
	return 0;
}

int fzb_CheckSDCard(int *piErrCode){
    ZJ_LOG_INF("CheckSDCard normal,return 0");
	*piErrCode = 0;
	return 0;
}


//extend

int fzb_IRLedSwitch(int iState){
	return 0;
}
int fzb_CameraSwitch(int iState){
	return 0;
}
int fzb_OnPTZ(EN_ZJ_CAMERA_PTZ_CONTROL enPTZControl, int iSpeed, int iPTZStep){
	return 0;
}
int fzb_PTZGetPoint(int* piX, int* piY){
	return 0;
}

int fzb_PTZGotoPoint(int iX, int iY){
	return 0;
}
int fzb_PTZAutoCheck(){
	return 0;
}
int fzb_CruiseStart(int iPresetPointNum, ST_ZJ_CAMERA_CRUISE_PRESET* pstPresets){
	return 0;
}
int fzb_PtzStop(){
	return 0;
}


//13
int fzb_RecordStatus(int iStatus){
	return 0;
}
int fzb_ScanFrequery(unsigned int uiScanFrequery){
	return 0;
}
int fzb_OSDSetting(int iPosition, char* pcOSDName){
	return 0;
}
int fzb_CtrlTimeOSD(int iOpenFlag){
	return 0;
}
int fzb_CtrlCustomOsd(int iOpenFlag){
	return 0;
}
int fzb_AudioVolumnAdjust(int iVolumn){
	return 0;
}
int fzb_SetVideoParm(int iStreamID,ST_ZJ_VIDEO_PARAM *pstVideoParm){
	return 0;
}
int fzb_VideoAdjust(int iStreamID, int iAdjust){
	return 0;
}
int fzb_SwitchLen(int iLenId){
	return 0;
}
int fzb_SetWideDynamicCam(unsigned int uiOpenFlag){
	return 0;
}
int fzb_DelSoundFile(unsigned char *pucSoundName){
	return 0;
}
int fzb_GetSoudFiles(unsigned int *piTotalSize, unsigned int *piFreeSize, unsigned char aucSoundList[32][64], unsigned int *uiSoundListCnt){
	return 0;
}
int fzb_SetRelayDevAwakeStatus(unsigned int iAwakeStatus){
	return 0;
}
















