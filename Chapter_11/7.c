#include <stdio.h>
#include <string.h>
#define QUIT "quit"
#define SIZE 40
char * mystrncpy(char * p1, char * p2, int n);
int main(void)
{
	char s1[SIZE];
	char s2[SIZE];
	int num;
	
	printf("Input the first string (type quit to quit):\n");
	while (strcmp(gets(s1), QUIT))		//����quit����
	{
		printf("Input the second string:\n");
		gets(s2);
		printf("Input the number of char copied from s2: ");
		scanf("%d", &num);
		getchar();						//�����س�
		//��s2�ĳ��ȴ��ڻ����Ҫ�������ַ���ʱ��Ҫ��s1ĩβ����'\0',
		//����ע��Ҫ�ڵ��ú���֮ǰ����Ȼstrlen(s1)�ᷢ���ı�
		if (strlen(s2) >= num)
			s1[strlen(s1) + num] = '\0';
		puts(mystrncpy(s1, s2, num));	//�����������ַ���s1
		printf("Input the first string (type quit to quit):\n");
	}
	
	printf("Bye.\n");
}

char * mystrncpy(char * p1, char * p2, int n)
{
	int i = 1;
	char * p = p1;

	while (*p1++)		
		continue;
	//p1ָ��ָ��λ���Ѿ��������ַ�
	*--p1 = *p2;		
	while (i < n && *p2)
	{
		*++p1 = *++p2;
		i++;
	}

	return p;
}