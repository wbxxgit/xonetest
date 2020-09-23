#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef struct
{
	unsigned long long a_total_size;	//������
	unsigned long long a_used_size;	    //��������
	unsigned long long a_free_size;	    //δ������
}tf_info;

//ִ�п���ָ̨��
int exec_cmd(const char *cmd);		
//��ȡϵͳʣ���ڴ�
unsigned long get_system_mem_freeKb();		
//��ȡĿ¼ʣ��洢�ռ�
unsigned long long get_system_tf_freeKb(char* dir);
//��ȡϵͳ������ʱ�䵽���ڵ�tick��
int64_t get_tick_count();
//��ȫ·���ļ����л�ȡ�ļ���
void  get_file_pure_name(char* full_name,char * dest);

int get_system_tf_info(char* dir,tf_info *info);

#ifdef __cplusplus
}
#endif

#endif