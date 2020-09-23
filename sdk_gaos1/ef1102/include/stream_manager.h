#ifndef STREAM_MANAGER_H
#define STREAM_MANAGER_H

#include "lock_utils.h"

typedef struct
{
	char 	name[64];
	void* 	addr;
	int 	size;
	int		ref_count;
}shmmap_node;

typedef enum{
	SHM_STREAM_READ = 1,
	SHM_STREAM_WRITE,
	SHM_STREAM_WRITE_BLOCK,
}SHM_STREAM_MODE_E;

typedef enum{
	SHM_STREAM_MMAP = 1,
	SHM_STREAM_MALLOC,
}SHM_STREAM_TYPE_E;

typedef struct
{
	int type;
	int key;
	int seq;
	unsigned int 		length;
	unsigned long long 	pts;
	unsigned int		t_time;
	unsigned int		framerate;	// or samplerate
	unsigned int		width;
	unsigned int		height;
	char reserved[12];
}frame_info;

typedef int (*shm_stream_info_callback)(frame_info info, unsigned char* data, unsigned int length);

typedef struct 
{
	char			id[32];	//	�û���ʶ
	unsigned int	index;	//	��ǰ��дinfo_array�±�
	unsigned int	offset;	//	��ǰ���ݴ洢ƫ�� ֻ����дģʽ
	unsigned int	users;	//	���û���
	shm_stream_info_callback	callback;
}shm_user_t;

typedef struct 
{
	unsigned int	offset;		//	���ݴ洢ƫ��
	unsigned int	lenght;		//	���ݳ���
	frame_info		info;		//	����info
}shm_info_t;

typedef struct 
{
//private
	char*	user_array;			//	�û������ʼ��ַ
	char*	info_array;			//	��Ϣ�����ʼ��ַ
	char*	base_addr;			//	���ݳ�ʼ��ַ
	CMtx	mtx;
	char	name[20];			//	�����Ĺ����ļ���
	unsigned int index;			//	�û���userArray�е��±�
	unsigned int max_frames;	//	����֡����������Ҫ��frameArray����Ԫ�ظ���
	unsigned int max_users;
	unsigned int size;
	SHM_STREAM_MODE_E mode;
	SHM_STREAM_TYPE_E type;
	
}shm_stream_t;


//public
shm_stream_t* shm_stream_create(char* id, char* name, int users, int infos, int size, SHM_STREAM_MODE_E mode, SHM_STREAM_TYPE_E type);
void shm_stream_destory(shm_stream_t* handle);

int shm_stream_put(shm_stream_t* handle, frame_info info, unsigned char* data, unsigned int length);
int shm_stream_get(shm_stream_t* handle, frame_info* info, unsigned char** data, unsigned int* length);
int shm_stream_front(shm_stream_t* handle, frame_info* info, unsigned char** data, unsigned int* length);
int shm_stream_post(shm_stream_t* handle);
int shm_stream_sync(shm_stream_t* handle);
int shm_stream_remains(shm_stream_t* handle);
int shm_stream_readers(shm_stream_t* handle);
int shm_stream_info_callback_register(shm_stream_t* handle, shm_stream_info_callback callback);
int shm_stream_info_callback_unregister(shm_stream_t* handle);

//private
void* shm_stream_malloc(shm_stream_t* handle, char* name, unsigned int size);
int   shm_stream_malloc_fix(shm_stream_t* handle, char* id, char* name, int users, void* addr);
void  shm_stream_unmalloc(shm_stream_t* handle);
void* shm_stream_mmap(shm_stream_t* handle, char* name, unsigned int size);
void  shm_stream_unmap(shm_stream_t* handle);

#endif
