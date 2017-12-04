#ifndef WORD_H_
#define WORD_H_

#define MAX 10
#define LEN 40
#define SIZE 100

typedef struct item {
	char name[LEN];
	char kind[MAX][LEN];
	int num;
} Item;

typedef struct trnode {
	Item item;
	struct trnode * left;
	struct trnode * right;
} Trnode;

typedef struct tree {
	Trnode * root;
	int size;
} Tree;

//��ʼ����
void InitializeTree(Tree * ptree);

//ȷ����Ϊ��
int TreeIsFull(const Tree * ptree);

//ȷ����Ϊ��
int TreeIsEmpty(const Tree * ptree);

//ͳ������
int TreeItemCount(const Tree * ptree);

//������
void FindItem(const Tree * ptree, const Item * item);

//�����
int AddItem(Tree * ptree, const Item * pi);

//ɾ����
int DelItem(Tree * ptree, const Item * pi);

//������
void Traverse(const Tree * ptree, void (*pfun)(Item item));

//�����
void DeleteAll(Tree * ptree);

#endif