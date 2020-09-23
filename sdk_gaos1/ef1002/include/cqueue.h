#ifndef C_QUEUE_H
#define C_QUEUE_H
#include "lock_utils.h"

typedef struct cqueuenode_s{
	void* data;
	struct cqueuenode_s *next;
}cqueuenode;
typedef struct
{
	cqueuenode *front;
	cqueuenode *rear;
	int size;
	CMtx lock;
}cqueue;

#ifdef __cplusplus
extern "C"{
#endif

void cqueue_init(cqueue *p);
//���ͷŽڵ������ڴ�
void cqueue_clear(cqueue *q);
//���ͷŽڵ������ڴ�
int cqueue_destory(cqueue *q);
int cqueue_is_empty(cqueue *q);
//�ⲿmallco�ڵ�ṹ
int cqueue_enqueue(cqueue *q, void* e);
//��Ҫ�ֶ�ɾ���ڵ�
void* cqueue_dequeue(cqueue *q);
void* cqueue_gethead(cqueue *q);
int cqueue_size(cqueue *q);


typedef struct
{
	char*	base;
	int		max;			// �����Ԫ�ظ���
	int		node_size;		// ÿ��Ԫ�صĴ�С

	int		front;
	int 	tail;
	CMtx 	lock;
}array_queue;

array_queue* array_queue_create(int max, int node_size);
void array_queue_clear(array_queue *q);
void array_queue_destory(array_queue *q);
int array_queue_is_empty(array_queue *q);
int array_queue_is_full(array_queue *q);
int array_queue_push(array_queue *q, void* e);
int array_queue_pop(array_queue *q, void* e);
int array_queue_front(array_queue *q, void* e);
int array_queue_post(array_queue *q);
int array_queue_get(array_queue *q, int i, void* e);
int array_queue_remaid(array_queue *q);

#ifdef __cplusplus
}
#endif

#endif
