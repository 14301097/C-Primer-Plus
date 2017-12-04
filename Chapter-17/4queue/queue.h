#ifndef QUEUE_H_
#define QUEUE_H_

#define MAXSIZE 10

typedef struct item {
	long arrive;
	int processtime;
} Item;

typedef struct node {
	Item item;
	struct node * next;
} Node;

typedef struct queue {
	Node * head;
	Node * end;
	int items;
} Queue;

//��ʼ������
void InitializeQueue(Queue * pq);

//ȷ������Ϊ��
int QueueIsEmpty(const Queue * pq);

//ȷ������Ϊ��
int QueueIsFull(const Queue * pq);

//ȷ����������
unsigned int QueueItemCount(const Queue * pq);

//������ĩβ�����
int EnQueue(Queue * pq, Item item);

//�Ӷ��п�ͷɾ����
int DeQueue(Queue * pq, Item * pitem);

//��ն���
void DeleteAll(Queue * pq);

#endif