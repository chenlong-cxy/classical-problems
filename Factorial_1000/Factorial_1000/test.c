#define _CRT_SECURE_NO_WARNINGS 1
//��1000���м�λ��
#include<stdio.h>
#include<math.h>
int main()
{
	int n = 1000;
	double sum = 0.0;//��ֹ���ݶ�ʧ
	int i = 0;
	for (i = 1; i <= 1000; i++)
	{
		sum = sum + log10(i);
	}
	int ret = (int)sum + 1;
	printf("%d\n", ret);
	return 0;
}