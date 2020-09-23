#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "device_log.h"
#include "zj_type.h"
#include "zj_log.h"


#include "dev_zj_funReg.h"
#include "forZb_comCfg.h"
#include "forZb_camera.h"
#include "forZbSeg_camera.h" 

#include "sdk_commonstruct.h"
#include "sdkout_impl.h" 
#include "CommonUtils.h"



static char *PcSnapPic = NULL;
static ST_H_VOICEPLAY st_H_audio = {0};


ST_H_VOICEPLAY *stH_glget_audio(){
    return  &st_H_audio;
}



#define VIDEOMIRROR_NONE       0
#define VIDEOMIRROR_HORIZONTAL 1
#define VIDEOMIRROR_VERTICAL   2
#define VIDEOMIRROR_H_V        3

static int getMap_videoMir(int state){
	if(state == 1)
		return VIDEOMIRROR_NONE;
	if(state == 2)
		return VIDEOMIRROR_H_V;
	return -1;
}
int fzb_ImageInversion(int iState){
	DPRI_INFO("ImageInversion exe,istate:%d\n",iState);
	int para_mirror;

	para_mirror = getMap_videoMir(iState);
	if(para_mirror == -1)
		return -1;
	
	if (0 != SDK_Cmd_Impl(SDKCMD_SET_VIDEO_ENCODE_MIRROR,(void *)&para_mirror))	{
	   DPRI_INFO("callSDKCMD_SET_SNAPSHOT_PATH fail .\n");           
	   return -1;
	} 	

	DPRI_INFO("para_mirror:%d",para_mirror); 
	return 0;
}

int fzb_VideoNeedIFrame(int iStreamID,unsigned int uiKeyQuality){
	return 0;
}

int fzb_VideoSwitch(int iStreamID, int iState){
	DPRI_INFO("VideoSwitch iStreamID[%d],iState[%d]\n",iStreamID,iState);
	
	if(SegCam_setVideoArrSw(iStreamID,iState) != 0)
		return -1;
	
	return 0;
}

static int SDK_SnapShot()
{
	T_SDK_PIC_PATH un_snap_path;
	memset(&un_snap_path, 0, sizeof(un_snap_path));
	strcpy((un_snap_path.pic_path), "/mnt/app/1.jpg"); //the folder must exist and can be write.
	DPRI_INFO("SDK_SnapShot pic_path >>>>>>>>>>%s",un_snap_path.pic_path);
	if (0 != SDK_Cmd_Impl(SDKCMD_SET_SNAPSHOT_PATH,(void *)&un_snap_path))
	{
	   DPRI_INFO("callSDKCMD_SET_SNAPSHOT_PATH fail .\n");           
	   return -1;
	} 	
	return 0;
}

int fzb_VideoGetJpeg(EN_ZJ_PICTURE_TYPE enPicType, unsigned char **ppucJpegBuf){

	FILE *fjge  = NULL;
	char *filepath = NULL;
	unsigned int filesize = 0;
	char *tmpmallocp = NULL;

	DPRI_INFO("GetJpeg callback exe !enPicType:%d\n",enPicType);
	if( SDK_SnapShot() != 0){
		DPRI_INFO("SDK_SnapShot err!\n");
		return -1;
	}

	filepath = "/mnt/app/1.jpg";
	fjge  = fopen(filepath,"rb"); 
	if(NULL==fjge){
		DPRI_INFO("fopen PATH error!\n");
		return -1;
	}   
	fseek(fjge,0, SEEK_END);
	filesize = ftell(fjge);//读取图片的大小长度
	fseek(fjge, 0, SEEK_SET);
	DPRI_INFO("ftell filesize:%d\n",filesize);
	if(0 == filesize)
		return -1;
	tmpmallocp = (char *)realloc(PcSnapPic, filesize);
	if(tmpmallocp == NULL){
		DPRI_INFO("device video snap realloc buff failed\n");
		return -1;
	}
	PcSnapPic = tmpmallocp;
	if(0 == fread(PcSnapPic, 1, filesize, fjge)){
		fclose(fjge);
		DPRI_INFO("fread err\n");
		return -1;
	}
	*ppucJpegBuf = (unsigned char *)PcSnapPic;
	DPRI_INFO("*ppucJpegBuf :%p\n",*ppucJpegBuf);
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
	DPRI_INFO("AudioSwitch iState[%d]\n",iState);
	SegCam_setAudioSw(iState);
	return 0;
}

int fzb_MediaToPlay(const char* pcPeerID, ZJ_HANDLE hPlayHandle, int iStreamType, int iStatus){

	ST_ZJ_AUDIO_PARAM stAudioParam = {0};
	stH_glget_audio()->pcPeerID = pcPeerID;
	stH_glget_audio()->hPlayHandle  =  hPlayHandle;
	stH_glget_audio()->iRun = iStatus;
	DPRI_INFO("audio start voice to play , iStreamType [%d], iStatus [%d]", iStreamType,iStatus);

	if( NULL == dj_audio_GtFTbl()->f_GetMediaAudioParam){
		DPRI_INFO("f_GetMediaAudioParam no register!\n");
		return -1;			
	}	
	dj_audio_GtFTbl()->f_GetMediaAudioParam(stH_glget_audio()->hPlayHandle , &stAudioParam);
	DPRI_INFO("device audio encode param:");
	DPRI_INFO(" 			uiEncodeType: %u", stAudioParam.uiEncodeType);
	DPRI_INFO(" 			uiSampleRate: %u", stAudioParam.uiSampleRate);
	DPRI_INFO(" 			   uiChannel: %u", stAudioParam.uiChannel);
	DPRI_INFO(" 				 uiDepth: %u", stAudioParam.uiDepth);
	return 0;
}

//sd
int fzb_FormatSDCard(){
    DPRI_INFO("FormatSDCard exe...\n");
	int retcode = SDK_Cmd_Impl(SDKCMD_FORMAT_STORAGE_REQ, NULL);
	if(retcode < 0)
	{
		DPRI_INFO("SDKCMD_FORMAT_STORAGE_REQ fail\n");
		return -1;
	}
	DPRI_INFO("SDKCMD_FORMAT_STORAGE_REQ succeed\n");
    return 0;
}

int fzb_GetSDCardInfo(unsigned int *piTotalSize, unsigned int *piFreeSize){  

	tf_info info2;
	memset(&info2,0,sizeof(tf_info));
	int retcode = SDK_Cmd_Impl(SDKCMD_GET_SD_CARD_INFO,(void*)(&info2));
	if(retcode != 0)
	{
		return -1;
	}
	DPRI_INFO("ret1 ,total:%lld,free:%lld,USED:%lld",info2.a_total_size,info2.a_free_size,info2.a_used_size);
	*piTotalSize = info2.a_total_size/1024;
	*piFreeSize = info2.a_free_size/1024;
//	DPRI_INFO("retsdd ,total:%lld,free:%lld",*piTotalSize,*piFreeSize);
	DPRI_INFO("retsdd ,total:%d,free:%d",*piTotalSize,*piFreeSize);
	return 0;
#if 0	
	FILE *fstream = NULL;
	char buff[1024];	
	memset(buff,0,sizeof(buff));	
	if(NULL == ( fstream = popen("df -m","r"))){	
			fprintf(stderr,"execute command failed:%s",strerror(errno));
			pclose(fstream);
			return -1;
	}	
	while( NULL != fgets(buff,sizeof(buff),fstream))	
			DPRI_INFO("%s",buff);	
	pclose(fstream);

	memset(buff,0,sizeof(buff));
	if(NULL == ( fstream = popen("df -m|grep sd|awk '{print $2}'","r"))){	
			fprintf(stderr,"execute command failed:%s",strerror(errno));
			pclose(fstream);
			return -1;
	}		
	while( NULL != fgets(buff,sizeof(buff),fstream)){
		DPRI_INFO("$2:%s",buff);
		if( buff[0]=='\r' ||buff[0]=='\n')
			continue;
		else
			break;				
	}	
	pclose(fstream);
	*piTotalSize = atoi(buff);
	
	memset(buff,0,sizeof(buff));
	if(NULL == ( fstream = popen("df -m|grep sd|awk '{print $4}'","r"))){	
			fprintf(stderr,"execute command failed:%s",strerror(errno));
			pclose(fstream);
			return -1;
	}	
	while( NULL != fgets(buff,sizeof(buff),fstream)){
		DPRI_INFO("$4:%s",buff);
		if( buff[0]=='\r' ||buff[0]=='\n')
			continue;
		else
			break;	
	}	

	pclose(fstream);
	*piFreeSize = atoi(buff);
	DPRI_INFO("GetSDCardInfo piTotalSize:%d,piFreeSize_1118:%d",*piTotalSize,*piFreeSize);		
	return 0;
#endif	
}

int fzb_CheckSDCard(int *piErrCode){
    DPRI_INFO("CheckSDCard normal,return 0");
	*piErrCode = 0;
	return 0;
}

//extend

int fzb_IRLedSwitch(int iState){
	return 0;
}
int fzb_CameraSwitch(int iState){
	DPRI_INFO("fzb_CameraSwitch iState:%d",iState);	
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
int fzb_AudioVolumnAdjust_PZJ(int iSpeakerId,int iVolumn){
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

int fzb_GetSoudFiles_PZJ( unsigned int *piTotalSize, unsigned int *piFreeSize, 
		unsigned char aucSoundList[32][64], unsigned int *uiSoundListCnt,unsigned int uiRingType){
	return 0;
}

int fzb_SetRelayDevAwakeStatus(unsigned int iAwakeStatus){
	return 0;
}
















