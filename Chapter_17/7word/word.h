#ifndef WORD_H_
#define WORD_H_

#define LEN 40
#define MAX 100

typedef struct item {
	char word[LEN];
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
int InTree(const Tree * ptree, const Item * pi);

//�����
int AddItem(Tree * ptree, const Item * pi);

//ɾ����
int DelItem(Tree * ptree, const Item * pi);

//������
void Traverse(const Tree * ptree, void (*pfun)(Item item));

//�����
void DeleteAll(Tree * ptree);

//��ĳһ�����
int ItemCount(const Tree * ptree, const Item * item);

#endif