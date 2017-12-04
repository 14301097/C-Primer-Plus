#include <stdio.h>
#define BASE1 8.75		
#define BASE2 9.33
#define BASE3 10.00
#define BASE4 11.20
//���ֵȼ��Ļ�������
#define TIME 40			//����40hΪ�Ӱ�
#define	MUL	1.5			//�Ӱ�ʱ������ƽʱ��1.5��
#define	RATE1 0.15		//ǰ300��Ԫ��˰��
#define RATE2 0.2		//300-450��Ԫ��˰��
#define RATE3 0.25		//����450��Ԫ��˰��
#define BREAK1 300		//˰�ʵĵ�һ���ֽ��
#define BREAK2 450		//˰�ʵĵڶ����ֽ��
int main(void)
{
	double base, hour, tax, gross;
	int count, num;
	const int LENGTH = 65;	//*�ĳ���
	
	printpart: for (count = 0; count < LENGTH; count++)
					printf("*");
	printf("\nEnter the number corresponding to the desired pay rate or action:\n");
	printf("%-36s%s","1) $8.75/hr", "2) $9.33/hr\n");
	printf("%-36s%s","3) $10.00/hr", "4) $11.20/hr\n");
	printf("%s\n", "5) quit");
	for (count = 0; count < LENGTH; count++)
		printf("*");
	printf("\n");			
	//��ӡ���
	while (scanf("%d", &num) == 1) {
	switch (num)
	{
		case 1:	base = BASE1;
				break;
		case 2: base = BASE2;
				break;
		case 3: base = BASE3;
				break;
		case 4: base = BASE4;
				break;
		case 5: printf("quit.\n");
				return 0;
		default: printf("Please input the right option.\n");
				goto printpart;
	}	//ѡ��������ʵȼ�

	printf("Input your work hours in a week: ");
	scanf("%lf", &hour);
	if (hour <= TIME)
		gross = hour * base;
	else
		gross = TIME * base + (hour - TIME) * MUL * base;
	//����������
	if (gross <= BREAK1)
		tax = gross * RATE1;
	else if (gross <= BREAK2)
		tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
	else
		tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2 
			+ (gross - BREAK2) * RATE3;
	//����˰��
	printf("Your gross income is $%.2lf\nYour tax is $%.2lf\n" 
			"Your net income is $%.2lf\n",
			gross, tax, (gross - tax));
	printf("\nYour next choice:\n");
	}
	return 0;
}
