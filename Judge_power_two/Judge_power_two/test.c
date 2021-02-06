#define _CRT_SECURE_NO_WARNINGS 1
//判断一个正整数是否可表示为2的n次方
#include<stdio.h>
int main()
{
	int num = 0;
	scanf("%d", &num);
	int c = num&(num - 1);
	if (c == 0)
	{
		int count = 0;
		num = num - 1;
		while (num)//计算num-1二进制中1的个数，即次方数
		{
			num = num&(num - 1);
			count++;
		}
		printf("可以表示为2的%d次方\n", count);
	}
	else
		printf("%d不能表示为2的n次方\n", num);
	return 0;
}