#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
#define MAXTITL 40
#define MAXAUTH 40
#define MAXBKS 10

int count = 0;							//�ⲿ�����������Ŀ

struct book {
	char title[MAXTITL];
	char author[MAXAUTH];
	float value;
};

char * s_gets(char * st, int n);		//�����ַ����ĺ���
char get_choice(void);					//��ȡ�û�ѡ��
void add(struct book *);				//������ɱ���
void change(struct book *);				//�滻һ����
void del(struct book *);				//ɾ��һ����
void print(struct book *);				//��ӡ�鵥
void write_file(struct book *, char *);	//������д���ļ�

int main(void)
{
	char name[LEN];
	struct book library[MAXBKS];
	char ch;
	FILE * fp;

	//���ļ�����ȡ�������ݵ��ṹ��
	printf("Please input the file name: ");
	s_gets(name, LEN);
	if ((fp = fopen(name, "a+b")) == NULL)
	{
		fprintf(stderr, "Can't open %s", name);
		exit(EXIT_FAILURE);
	}
	rewind(fp);
	while (count < MAXBKS && fread(&library[count], 
		sizeof(struct book), 1, fp) == 1)
	{
		count++;						//��ǰ�ļ���
	}
	fclose(fp);
	
	//��ӡ�ļ�����������
	printf("There are %d books:\n", count);
	print(library);

	//���û�����ѡ��
	while ((ch = get_choice()) != 'q')
	{
		switch (ch)
		{
			case 'a': add(library);
					  break;
			case 'c': change(library);
					  break;
			case 'd': del(library);
					  break;
			case 'p': print(library);
					  break;
			default: printf("Program error.\n");
					break;
		}
	}
	//������������ļ���
	write_file(library, name);
	
	return 0;
}

char get_choice(void)
{
	char ch;
	
	printf("Please input your choice:\n");
	printf("a. add some books        c. change a book\n");
	printf("d. delete a book         p. print all books\n");
	printf("q. quit.\n");
	while ((ch = getchar()) != 'a' && ch != 'c' && ch != 'd' &&
		ch != 'p' && ch != 'q')
	{
		while (getchar() != '\n')
			continue;
		printf("Please input the right character.\n");
	}
	while (getchar() != '\n')
			continue;

	return ch;
}

void add(struct book * ps)
{
	if (count == MAXBKS)
		printf("Sorry, the list is full.\n");
	else
	{
		printf("Please input the title (empty line to quit):\n");
		while (count < MAXBKS && s_gets(ps[count].title, MAXTITL) != NULL
			&& ps[count].title[0] != '\0')
		{
			printf("Input the author:\n");
			s_gets(ps[count].author, MAXAUTH);
			printf("Input the value:\n");
			scanf("%f", &ps[count].value);
			getchar();
			printf("Now, next title (empty line to quit):\n");
			count++;
		}
	}
}

void change(struct book * ps)
{
	int i;
	char name[MAXTITL];

	if (count == 0)
		printf("Sorry, the list is empty.\n");
	else
	{
		printf("Please input the title of book you want to change:\n");
		s_gets(name, MAXTITL);
		for (i = 0; i < count; i++) 
		{
			if (!strcmp(name, ps[i].title))
			{	
				printf("Please input the title of new book:\n");
				s_gets(ps[i].title, MAXTITL);
				printf("Input the author:\n");
				s_gets(ps[i].author, MAXAUTH);
				printf("Input the value:\n");
				scanf("%f", &ps[i].value);
				getchar();
				break;
			}
		}
		if (i == count)
			printf("Sorry, we can't find the book you input.\n");
	}
	
}

void del(struct book * ps)
{
	char name[MAXTITL];
	int i, j;

	if (count == 0)
		printf("Sorry, the list is empty.\n");
	printf("Please input the title of book you want to delete:\n");
	s_gets(name, MAXTITL);
	for (i = 0; i < count; i++) 
	{
		if (!strcmp(name, ps[i].title))
		{	
			for (j = i + 1; j < count; j++)
				ps[j - 1] = ps[j];
			count--;
			strcpy(ps[count].title, "");
			strcpy(ps[count].author, "");
			ps[count].value = 0;
			break;	
		}
	}
	if (i == count)
		printf("Sorry, we can't find the book you input.\n");
}

void print(struct book * ps)
{
	int i;

	for (i = 0; i < count; i++)
	{
		printf("%s by %s: $%g\n", ps[i].title, ps[i].author,
			ps[i].value);
	}
}

void write_file(struct book * ps, char * st)
{
	FILE * fp;

	fp = fopen(st, "w+b");
	fwrite(ps, sizeof(struct book), count, fp);
	fclose(fp);
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
