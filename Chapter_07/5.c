#include <stdio.h>
int main(void)
{
	char ch;
	int n_repl = 0;				//�滻����
	
	printf("Enter some texts(# to quit):\n");
	while ((ch = getchar()) != '#') {
		switch (ch)
		{
			case '.': ch = '!';
					  n_repl++;
					  break;
			case '!': printf("!");
					  n_repl++;
					  break;
			default: break;		
		}						//����switch�������滻
		printf("%c",ch);
	}
	printf("\n%d substitutions were made.\n", n_repl);

	return 0;
}



