#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
#define SLEN 81
char * s_gets(char * st, int n);

int main(void)
{
	FILE * f1, * f2;	
	char st[SLEN];
	char name_f1[SIZE];
	char name_f2[SIZE];
	char * ret_val1;
	char * ret_val2;
	int count = 0;

	//�������������ļ����ļ���
	fprintf(stdout, "Please enter the first file name:\n");
	s_gets(name_f1, SIZE);
	fprintf(stdout, "Please enter the second file name:\n");
	s_gets(name_f2, SIZE);
	
	//�������������ļ�
	if ((f1 = fopen(name_f1, "r")) == NULL)
	{
		fprintf(stderr, "Could not open the %s\n", name_f1);
		exit(EXIT_FAILURE);
	}
	if ((f2 = fopen(name_f2, "r")) == NULL)
	{
		fprintf(stderr, "Could not open the %s\n", name_f2);
		exit(EXIT_FAILURE);
	}
	
	do
	{
		if ((ret_val1 = fgets(st, SLEN, f1)) != NULL)
		{
			fputs(st, stdout);

		}
		if ((ret_val2 = fgets(st, SLEN, f2)) != NULL)
		{
			fputs(st, stdout);
		}
	}
	while (ret_val1 != NULL || ret_val2 != NULL);

	fclose(f1);
	fclose(f2);

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
