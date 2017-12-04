#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
#define LEN 20
#define MAX 12

struct seat {
	int num;
	int isassign;
	char fname[LEN];
	char lname[LEN];
};

void read_file(struct seat * ps);		//���ļ���ȡ
void initialize(struct seat * ps);		//��ʼ���ṹ
char get_choice(void);					//�û�����ѡ��
void show_number(struct seat * ps);		//��λ�õĸ���
void show_empty(struct seat * ps);		//��ӡ���п�λ��
void show_list(struct seat * ps);		//��ӡ����λ����Ϣ
void assign_seat(struct seat * ps);		//Ԥ��һ��λ��
void delete_seat(struct seat * ps);		//ɾ��һ��λ��
void write_file(struct seat * ps);		//����д���ļ�
char * s_gets(char * st, int n);		//�����ַ���

int main(void)
{
	char ch;
	struct seat customer[MAX];
	
	initialize(customer);
	read_file(customer);
	
	//�û�����ѡ��
	while ((ch = get_choice()) != 'f')
	{
		switch (ch)
		{
			case 'a': show_number(customer);
					  break;
			case 'b': show_empty(customer);
					  break;
			case 'c': show_list(customer);
					  break;
			case 'd': assign_seat(customer);
					  break;
			case 'e': delete_seat(customer);
					  break;			
			default: printf("Program error.\n");
					break;
		}
	}
	//������������ļ���
	write_file(customer);

}
	
void initialize(struct seat * ps)
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		ps[i].num = i + 1;
		ps[i].isassign = 0;
		strcpy(ps[i].fname, "");
		strcpy(ps[i].lname, "");
	}
}

void read_file(struct seat * ps)
{
	FILE * fp;
	
	
	if((fp = fopen("seat.txt", "a+b")) == NULL)
	{
		fprintf(stderr, "Can't open seat.txt.\n");
		exit(EXIT_FAILURE);
	} 
	fread(ps, sizeof(struct seat), MAX, fp);
}

char get_choice(void)
{
	char ch;
	
	printf("To choose a function, enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n");

	while ((ch = getchar()) < 'a' || ch > 'f')
	{
		while (getchar() != '\n')
			continue;
		printf("Please input the right letter.\n");
	}
	while (getchar() != '\n')
			continue;

	return ch;
}

void show_number(struct seat * ps)
{
	int i;
	int count = 0;

	for(i = 0; i < MAX; i++)
	{
		if (ps[i].isassign == 0)
			count++;
	}
	printf("The number of empty seats is %d\n", count);
}

void show_empty(struct seat * ps)
{
	int i;

	printf("The list of empty seats:\n");
	for (i = 0; i <	MAX; i++)
	{
		if (!ps[i].isassign)
			printf("%d ", ps[i].num);
	}
	printf("\n");
}

void show_list(struct seat * ps)
{
	int i;

	printf("The list of seats:\n");
	for (i = 0; i <	MAX; i++)
	{
		printf("%d %s %s\n", ps[i].num, ps[i].fname, ps[i].lname);
	}
}

void assign_seat(struct seat * ps)		
{
	int number;
	int ret_val;

	printf("Please input the number of seat you want to book (1 to 12):\n");
	while ((ret_val = scanf("%d", &number)) != 1|| number < 1 || number > 12 || 
		ps[number - 1].isassign == 1)
	{
		if (ret_val != 1 || number < 1 || number > 12)
			printf("Sorry, please input a integer from 1 to 12.\n");
		else
			printf("Sorry, the seat is assigned, please reselect:\n");
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
		continue;
	printf("Now, input your firstname:\n");
	s_gets(ps[number - 1].fname, LEN);
	printf("Input your lastname:\n");
	s_gets(ps[number - 1].lname, LEN);
	ps[number - 1].isassign = 1;
	printf("OK.\n");
}


void delete_seat(struct seat * ps)
{
	int number;

	printf("Please input the number of seat you want to delete (1 to 12):\n");
	while (scanf("%d", &number) != 1 || number < 1 || number > 12 || 
		ps[number - 1].isassign == 0)
	{
		if (ps[number - 1].isassign == 1)
			printf("Sorry, the seat is empty, please reselect:\n");
		else
			printf("Sorry, please input a integer from 1 to 12.\n");
		while (getchar() != '\n')
			continue;
	}
	getchar();
	strcpy(ps[number - 1].fname, "");
	strcpy(ps[number - 1].lname, "");
	ps[number - 1].isassign = 0;
	printf("OK.\n");
}

void write_file(struct seat * ps)
{
	FILE * fp;

	fp = fopen("seat.txt", "w+b");
	fwrite(ps, sizeof(struct seat), MAX, fp);
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
		