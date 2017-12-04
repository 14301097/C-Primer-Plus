#include <stdio.h>
#include <stdlib.h>
#define SIZE 256
int main(int argc, char * argv[])
{
	FILE * fs;		//ԭʼ�ļ�ָ��
	FILE * fa;		//Ŀ���ļ�ָ��
	char temp[SIZE];
	size_t bytes;

	//��������в���
	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//�Զ�ģʽ��ԭʼ�ļ�
	if ((fs = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	//�Զ�дģʽ��Ŀ���ļ�
	if ((fa = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	//��������
	{
		while ((bytes = fread(temp, sizeof(char), SIZE, fs)) > 0)
			fwrite(temp, sizeof(char), bytes, fa);
	}

	fclose(fs);
	fclose(fa);

	return 0;
}



