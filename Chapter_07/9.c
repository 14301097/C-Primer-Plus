#include <stdio.h>
int main(void)
{
	int div, prime; 
	int num, count;
	int flag;

	printf("Input a positive integer: ");
	scanf("%d", &num);
	printf("The prime numbers in range:\n");
	for (prime = 2; prime <= num; prime++)	//���ѭ����ʾ��������
	{	
		flag = 1;
		for (div = 2; (div * div) <= prime; div++) 
		{
			if (prime % div == 0)
				flag = 0;
		}									//�ڲ�ѭ�������Ƿ�Ϊ����
		if (flag)							//���ñ��flag�ж�
			printf("%d ",prime);			
	}
	printf("\n");
	
	return 0;
}



