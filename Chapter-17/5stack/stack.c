#include <stdio.h>
#include "stack.h"

//��ʼ��ջ
void InitializeStack(Stack * ps)
{
	ps->items = 0;
}	

//ȷ��ջΪ��
int StackIsEmpty(const Stack * ps)
{
	return (ps->items == 0) ? 1 : 0;
}

//ȷ��ջΪ��
int StackIsFull(const Stack * ps)
{
	return (ps->items == SMAX) ? 1 : 0;
}

//ͳ��ջ������
int StackItemCount(const Stack * ps)
{
	return ps->items;
}

//��ջ��ѹ����
int AddItem(Stack * ps, Item item)
{
	if (StackIsFull(ps))
		return 0;
	else
	{
		ps->item[ps->items] = item;
		ps->items++;
		return 1;
	}
}

//��ջ��������
int DelItem(Stack * ps, Item * pitem)
{
	if (StackIsEmpty(ps))
		return 0;
	else
	{
		* pitem = ps->item[ps->items - 1];
		ps->item[ps->items - 1] = '\0';
		ps->items--;
		return 1;
	}
}
