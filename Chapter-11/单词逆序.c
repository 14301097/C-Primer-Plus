#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char str[81];
	char *p, temp;
	int i,n,length;
	int count;
	gets(str);
	for (p = str,i=0,n = strlen(str); i<n/2; i++)//�������ַ�������
	{
		temp = *(p+n-1-i);
		*(p+n-1-i) = *(p+i);
		*(p+i) = temp;
	}
	puts(str);
	count = 0;
	//���ַ����е�ÿ�����ʵ���
	do
	{
		if (!isspace(*p) && !ispunct(*p) && *p)
			count++;
		else 
		{
			for (i = 0; i < count / 2; i++)
			{
				temp = *(p - count + i);
				*(p - count + i) = *(p - i -1);
				*(p - i -1) = temp;
			}
			count = 0;
		}
	} while (*p++);
	puts(str);

	return 0;
}