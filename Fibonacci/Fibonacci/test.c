#define _CRT_SECURE_NO_WARNINGS 1
//1 1 2 3 5 8 13 21 34 55...
//求第n个斐波那契数
#include<stdio.h>
int Fibonacci1(int n)
{
	if (n <= 2)
		return 1;
	else
		return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}//递归法（重复计算次数过多，效率慢）
int Fibonacci2(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n - 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}//迭代法（不需重复计算）
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret1 = Fibonacci1(n);
	int ret2 = Fibonacci2(n);
	printf("ret1=%d\n", ret1);
	printf("ret2=%d\n", ret2);
	return 0;
}