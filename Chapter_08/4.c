#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;
	int inword = 0;			//�ڵ�����Ϊ1����Ϊ0
	int words = 0;			//������
	int chars = 0;			//�ַ���

	printf("Please enter some words:\n");
	while ((ch = getchar()) != EOF)
	{
		if (!isspace(ch) && !ispunct(ch))
			chars++;		
	//��ʼһ���µĵ���
		if (!isspace(ch) && !ispunct(ch) && !inword)
		{
			inword = 1;
			words++;
		}
	//����ĩβ
		if (isspace(ch) || ispunct(ch) && inword)
			inword = 0;
	}
		printf("There are %d words and %d letters\n",
				words, chars);
		printf("The average number of letters of ");
		printf("each word is %.2f.\n", 
				((double)chars / (double)words));

		return 0;
	}




