
//��������ַ���(���ո�)
#include<stdio.h>
void Reverse(char* pc)
{
	char ch = getchar();
	if (ch != '\n')
	{
		Reverse(&ch);
		putchar(ch);
	}
}
int main()
{
	char ch;
	while ((ch = getchar()) != EOF)
	{
		Reverse(&ch);
		putchar(ch);
	}
	return 0;
}//��������ַ���(���ո�)