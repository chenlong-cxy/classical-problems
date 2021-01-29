#define _CRT_SECURE_NO_WARNINGS 1
//统计一个数二进制中1的个数
#include<stdio.h>
//法一
//int count_one_bit(size_t num)
//{
//	int count = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//			count++;
//		num /= 2;
//	}
//	return count;
//}//需要将传入参数强制转化为unsigned int

//法二
//int count_one_bit(int num)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((num >> i) & 1) == 1)
//			count++;
//	}
//	return count;
//}//每个数都要循环32次

//法三
int count_one_bit(int num)
{
	int count = 0;
	while (num)
	{
		num = num&(num - 1);
		count++;
	}
}//
int main()
{
	int num = 0;
	scanf("%d", &num);
	int n = count_one_bit(num);
	printf("%d\n", n);
	return 0;
}
//      n: 1111111
//    n-1: 1111110
//n&(n-1): 1111110