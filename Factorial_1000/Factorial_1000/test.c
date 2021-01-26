#define _CRT_SECURE_NO_WARNINGS 1
//求1000！有几位数
#include<stdio.h>
#include<math.h>
int main()
{
	int n = 1000;
	double sum = 0.0;//防止数据丢失
	int i = 0;
	for (i = 1; i <= 1000; i++)
	{
		sum = sum + log10(i);
	}
	int ret = (int)sum + 1;
	printf("%d\n", ret);
	return 0;
}