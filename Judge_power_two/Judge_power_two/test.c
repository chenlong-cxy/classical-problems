#define _CRT_SECURE_NO_WARNINGS 1
//�ж�һ���������Ƿ�ɱ�ʾΪ2��n�η�
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
		while (num)//����num-1��������1�ĸ��������η���
		{
			num = num&(num - 1);
			count++;
		}
		printf("���Ա�ʾΪ2��%d�η�\n", count);
	}
	else
		printf("%d���ܱ�ʾΪ2��n�η�\n", num);
	return 0;
}