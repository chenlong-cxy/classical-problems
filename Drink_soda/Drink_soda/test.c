#define _CRT_SECURE_NO_WARNINGS 1
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ
//#include<stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	empty = money;
//	total = empty;
//	while (empty>=2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//	return 0;
//}


#include<stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	scanf("%d", &money);
	if (money > 0)
		total = money * 2 - 1;//��Ŀ���൱�ں�һƿ��ˮ5ëǮ����
	printf("%d\n", total);    //������ƿ���ܻ�һƿ��ˮ�����Ի�ʣ��һ����ƿ��Ҫ��һ
	return 0;
}