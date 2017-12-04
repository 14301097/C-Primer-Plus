#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
char * s_gets(char * st, int n);

int main(void)
{
	FILE * fs, * fa;		//fsָ��Դ�ļ�,faָ��Ŀ���ļ�
	char ch;
	char name_source[SIZE];
	char name_dest[SIZE];
	int count = 0;

	//����Դ�ļ���Ŀ���ļ���
	fprintf(stdout, "Please enter the source file name:\n");
	s_gets(name_source, SIZE);
	fprintf(stdout, "Please enter the destination file name:\n");
	s_gets(name_dest, SIZE);
	
	//��Դ�ļ���Ŀ���ļ�
	if ((fs = fopen(name_source, "r")) == NULL)
	{
		fprintf(stderr, "Could not open the %s\n", name_source);
		exit(EXIT_FAILURE);
	}
	if ((fa = fopen(name_dest, "w")) == NULL)
	{
		fprintf(stderr, "Could not open the %s\n", name_dest);
		exit(EXIT_FAILURE);
	}

	//��Դ�ļ�ÿ3���ַ��ĵ�1���ַ������Ŀ���ļ�
	while ((ch = getc(fs)) != EOF)
	{
		if (count++ %3 == 0)
			putc(ch, fa);		
	}

	//��β����
	if (fclose(fs) != 0 || fclose(fa) != 0)
		fprintf(stderr, "Error in closing files\n");

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
		find = strchr(st, '\n');	 		//���һ��з�
		if (find)
			*find = '\0';			//�滻Ϊ���ַ�
		else
			while (getchar() != '\n')
				continue;		//�����������
	}

	return ret_val;
}

