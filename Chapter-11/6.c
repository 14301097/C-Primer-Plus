#include <stdio.h>
#include <string.h>
#define QUIT "quit"
#define SIZE 80
//�����ַ����ַ������״γ��ֵ�λ��
int is_within(char * str, char c);		
int main(void)
{
	char str[SIZE];
	char ch;

	printf("Input a string (type quit to quit):\n");
	while (strcmp(gets(str), QUIT))
	{
		printf("Input a character: ");
		scanf("%c", &ch);
		while (getchar() != '\n')		//����ʣ�����벿��
			continue;
		if (is_within(str, ch))
			printf("Find!\n");
		else
			printf("Can't find!\n");
		printf("Input a string (type quit to quit):\n");
	}
	printf("Bye.\n");
		
	return 0;
}



int is_within(char * str, char c)
{
	int flag = 0;
	size_t count = 0;
	
	while (count++ < strlen(str))
		if (*str++ == c)
		{
			flag = 1;
			break;
		}

	return flag;
}