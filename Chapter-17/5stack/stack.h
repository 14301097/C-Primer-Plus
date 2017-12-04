#ifndef STACK_H_
#define STACK_H_

#define SMAX 100

typedef char Item;
typedef struct stack {
	Item item[SMAX];
	int items;
} Stack;

//��ʼ��ջ
void InitializeStack(Stack * ps);

//ȷ��ջΪ��
int StackIsEmpty(const Stack * ps);

//ȷ��ջΪ��
int StackIsFull(const Stack * ps);

//ͳ��ջ������
int StackItemCount(const Stack * ps);

//��ջ��ѹ����
int AddItem(Stack * ps, Item item);

//��ջ��������
int DelItem(Stack * ps, Item * pitem);

//�����
void EmptyItem(Stack * ps);

#endif