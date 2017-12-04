#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 40
char * s_gets(char * st, int n);
int main(void)
{
	char name[SIZE];
	char ch;
	unsigned long count = 0;
	FILE * fp;
	
	printf("Enter the file name: ");
	s_gets(name, SIZE);
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("Can't open %s\n", name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", name, count);

	return 0;
}

//�Զ����ȡ�ļ����ĺ���
char * s_gets(char * st, int n)
{
	char * find;
	char * ret_val;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');	//���һ��з�
		if (find)
			*find = '\0';			//�滻Ϊ���ַ�
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
