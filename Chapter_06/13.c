#include <stdio.h>
#define SIZE 8
int main(void)
{
	int index, count, num[SIZE];
	 
	for (index = 0, count = 1; index < SIZE; index++)
	{
		count *= 2;
		num[index] = count; 
	}											//forѭ��������Ԫ����Ϊ2��ǰ8����
	
	index=0;									//��ʼ��index��ֵ
	do
	printf("%d ", num[index++]);
	while (index < SIZE);						//do whileѭ����ʾ����Ԫ�ص�ֵ
	printf("\n");

	return 0;
}