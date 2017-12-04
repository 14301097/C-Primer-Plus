#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 40
char * s_gets(char * st, int n);

int main(void)
{
	FILE * fs;			//ԭʼ�ļ�ָ��
	FILE * ft;			//Ŀ���ļ�ָ��
	char name_s[SIZE];
	char name_t[SIZE];
	char ch;
	
	//����ԭʼ�ļ���Ŀ���ļ���
	fprintf(stdout, "Please enter the source file name:\n");
	s_gets(name_s, SIZE);
	fprintf(stdout, "Please enter the target file name:\n");
	s_gets(name_t, SIZE);
	
	//��ԭʼ�ļ���Ŀ���ļ�
	if ((fs = fopen(name_s, "r")) == NULL)
		fprintf(stderr, "Could not open the %s\n", name_s);
	if ((ft = fopen(name_t, "w")) == NULL)
		fprintf(stderr, "Could not open the %s\n", name_t);
	
	//��������
	while ((ch = getc(fs)) != EOF)
		putc(toupper(ch), ft);
	
	fclose(fs);
	fclose(ft);

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
				continue;			//�����������
	}

	return ret_val;
}
