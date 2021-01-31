#define _CRT_SECURE_NO_WARNINGS 1
//求两个数中，bit位不同的个数
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = a^b;
	int count = 0;
	while (c)
	{
		c = c&(c - 1);
		count++;
	}
	printf("%d\n", count);
	return 0;
}
//c:      1111
//c-1:    1110
//c&(c-1):1110