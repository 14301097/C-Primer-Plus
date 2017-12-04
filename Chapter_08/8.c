#include <stdio.h>
float get_float(void);
char get_choice(void);
char get_first(void);
int main(void)
{
	char choice;
	float num1, num2;
	
	while ((choice = get_choice()) != 'q')
	{
		printf("Enter first number: ");
		num1 = get_float();
		printf("Enter second number: ");
		num2 = get_float();
		
		switch (choice)
		{
			case 'a': printf("%.2f + %.2f = %.2f\n",
						num1, num2, num1 + num2);
					  break;
			case 's': printf(".2%f - %.2f = %.2f\n",
						num1, num2, num1 - num2);
				      break;
			case 'm': printf("%.2f * %.2f = %.2f\n",
						num1, num2, num1 * num2);
					  break;				
			case 'd': 
				      if (!num2)
					  {
						  printf("Enter a number other than 0: ");
						  num2 = get_float();
					  }
					  printf("%.2f / %.2f = %.2f\n",
					  num1, num2, num1 / num2);
					  break;	
			default:  printf("Program error!\n");
				      break;
		}
	}
	printf("Bye.\n");

	return 0;
}

//��ӡ��������û�ѡ��ĺ���
char get_choice(void)
{
	char ch;
	printf("Enter the operation of your choice:\n");
	printf("%-36s%s\n", "a. add", "s. subtract");
	printf("%-36s%s\n", "m. multiply", "d. divide");
	printf("q. quit\n");
	ch = get_first();
	while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd'
		    && ch != 'q')
	{
		printf("Please enter a, s, m, d or q.\n");
		ch = get_first();
	}

	return ch;
}

//�������ֵ�������������ĺ���
float get_float(void)
{
	float input;
	char ch;
	
	while (scanf("%f", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an number.\n");
		printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
	}
	while (getchar() != '\n')
		continue;

	return input;
}

//��ȡ�����еĵ�һ���ַ�
char get_first(void)
{
	char ch;

	ch = getchar();
	while (getchar() != '\n')
		continue;

	return ch;
}

