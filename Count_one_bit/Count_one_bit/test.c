#define _CRT_SECURE_NO_WARNINGS 1
//ͳ��һ������������1�ĸ���
#include<stdio.h>
//��һ
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
//}//��Ҫ���������ǿ��ת��Ϊunsigned int

//����
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
//}//ÿ������Ҫѭ��32��

//����
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