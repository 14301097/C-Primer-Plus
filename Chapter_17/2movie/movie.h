#ifndef MOVIE_H_
#define MOVIE_H_

#define TSIZE 45

typedef struct film {
	char titile[TSIZE];
	int rating;
} Item;

typedef struct node {
	Item item;
	struct node * next;
} Node;

typedef struct list {
	Node * head;
	Node * end;
} List;

//��ʼ������Ϊ��
void InitializeList(List * plist);

//����Ϊ��,����1
int ListIsEmpty(const List * plist);

//����Ϊ��������1
int ListIsFull(const List * plist);

//Ϊ���������ɹ�����1
int AddItem(List * plist, Item item);

//ȷ�����������
unsigned int ListItemCount(List * plist);

//��������
void Traverse(const List * plist, void (*pfun)(Item item));

//�������
void DeleteAll(List * plist);

#endif