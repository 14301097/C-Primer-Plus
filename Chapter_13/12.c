#include <stdio.h>
#include <stdlib.h>
#define LEN 40
#define ROW 20
#define COL 30
int main(void)
{
	FILE * fs, * fd;				//fsָ��Դ�ļ�,fdָ��Ŀ���ļ�
	char name[LEN];
	char digit[ROW][COL];
	char result[ROW][COL + 1];
	char ch[] = {" .':~*= %#"};		//�����ַ���Ӧ�ķ���
	int i, j;

	printf("Please enter the source file name:\n");
	gets(name);
	//��Դ�ļ�
	if ((fs = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Could not open %s.", name);
		exit(EXIT_FAILURE);
	}
	//���ļ����ݶ��� 20 * 30 ��int������
	//����ת������Ӧ���ŷ��� 20 * 31 ���ַ�������
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			fscanf(fs, "%d", &digit[i][j]);
			result[i][j] = ch[digit[i][j]]; 
		}
		result[i][j] = '\0';
	}
	printf("Enter the destination file name:\n");
	gets(name);
	//��Ŀ���ļ�
	if ((fd = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Could not open %s.", name);
		exit(EXIT_FAILURE);
	}
	//�������ӡ������д��Ŀ���ļ�
	for (i = 0; i < ROW; i++)
	{
		fprintf(stdout, "%s\n", result[i]);
		fprintf(fd, "%s\n", result[i]);
	}
	//�ر��ļ�
	if (fclose(fs) != 0 || fclose(fd) != 0)
		fprintf(stderr, "Error for closing file.\n");

	return 0;
}
