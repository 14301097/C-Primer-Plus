#include <stdio.h>
#include <string.h>
#define SIZE 40
#define QUIT "quit"
char * s_gets(char * st, int n);
void reverse(char * st);
int main(void)
{
	char str[SIZE];
	while (strcmp(s_gets(str, SIZE), QUIT))		//����quit����
	{	
		reverse(str);
		puts(str);
	}
	
	return 0;
}


//�Զ�����ַ������뺯��
char * s_gets(char * st, int n)
{
	int i = 0;
	
	printf("Input the first string (type quit to quit):\n");
	if (fgets(st, n, stdin))	//������ֵst������NULL
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else 
			while (getchar() != '\n')
				continue;
	}

	return st;
}

//ʹ�ַ�������ĺ���
void reverse(char * st)
{
	unsigned int i;
	char temp;

	size_t length = strlen(st);
	for (i = 0; i < length / 2; i++)
	{
		temp = st[length - i -1];
		st[length - i - 1] = st[i];
		st[i] = temp;
	}
	st[length] = '\0';
}





	

