#ifndef STREAM_DEFINE_H
#define STREAM_DEFINE_H

#define VIDEO_MAIN						"VIDEO_MAIN"
#define VIDEO_SUB						"VIDEO_SUB"
#define VIDEO_EX1						"VIDEO_EX1"
#define VIDEO_EX2						"VIDEO_EX2"
#define AUDIO_MAIN						"AUDIO_MAIN"
#define AUDIO_ADEC						"AUDIO_ADEC"

#define	STREAM_MAX_USER					(20)
#define STREAM_MEDIA_MAX_FRAMES			(90)
#define STREAM_MAIN_VIDEO_MAX_FRAMES	(50)
#define STREAM_SUB_VIDEO_MAX_FRAMES		(65)
#define STREAM_AUDIO_MAX_FRAMES			(45)
#define STREAM_MAIN_VIDEO_MAX_SIZE		(1024*1024*1)
#define STREAM_SUB_VIDEO_MAX_SIZE		(1024*512)
#define STREAM_AUDIO_MAX_SIZE			(50*1024)


#define	STREAM_REC_MAX_USER				(5)
#define STREAM_REC_VIDEO_MAX_FRAMES	    (50)
#define STREAM_REC_VIDEO_MAX_SIZE		(1024*1024)

#define STREAM_ADEC_MAX_FRAMES			(1000)
#define STREAM_ADEC_MAX_SIZE			(1024*320)


#define STREAM_MAIN_VIDEO_LOSE_FRAMES	(30)
#endif