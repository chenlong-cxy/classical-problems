#define _CRT_SECURE_NO_WARNINGS 1
//S����������
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int arr[100][100] = { 0 };
//	scanf("%d", &n);//������Ҫ��������Ĵ�С��arr[n][n]
//	//�������
//	int i = 0;
//	int num = 1;
//	for (i = 0; i < n; i++)//��Ҫ��ӡn������
//	{
//		if (i % 2 == 0)//ż�������
//		{
//			int x = 0;
//			int y = i;
//			for (x = 0; x <= n-1; x++)
//			{
//				arr[x][y] = num;
//				num++;
//			}
//		}
//		else//���������
//		{
//			int x = n - 1;
//			int y = i;
//			for (x = n - 1; x >= 0; x--)
//			{
//				arr[x][y] = num;
//				num++;
//			}
//		}
//	}
//	//��ӡ����
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%-3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//��������������
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int arr[100][100] = { 0 };
//	scanf("%d", &n);//������Ҫ��������Ĵ�С��arr[n][n]
//	//�������
//	int i = 0;
//	int num = 1;
//	for (i = 0; i < n / 2; i++)//ѭ���Ĵ���
//	{
//		int x = i;
//		int y = n - 1 - i;
//		for (x = i; x <= n - 2 - i; x++)//��һ�����в��䣬������++
//		{
//			arr[x][y] = num;
//			num++;
//		}
//		for (y = n - 1 - i; y >= i + 1; y--)//�ڶ������в��䣬������--
//		{
//			arr[x][y] = num;
//			num++;
//		}
//		for (x = n - 1 - i; x >= i + 1; x--)//���������в��䣬������--
//		{
//			arr[x][y] = num;
//			num++;
//		}
//		for (y = i; y <= n - 2 - i; y++)//���Ĳ����в��䣬������++
//		{
//			arr[x][y] = num;
//			num++;
//		}
//	}
//	if (n % 2 != 0)//�ж�n�Ƿ�Ϊ����
//		arr[n / 2][n / 2] = num;//������������
//	//��ӡ����
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%-3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//��������������
#include<stdio.h>
int main()
{
	int n = 0;
	int arr[100][100] = { 0 };
	scanf("%d", &n);//������Ҫ��������Ĵ�С��arr[n][n]
	//�������
	int i = 0;
	int num = 1;
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)//iΪż��ʱ�����ִ��������������
		{
			int x = i;
			int y = 0;
			while (x+1)//ÿ��ѭ���������ָ���Ϊi+1��x+1��
			{
				arr[x][y] = num;
				num++;
				x--;
				y++;
			}
		}
		else//iΪ����ʱ�����ִ��������������
		{
			int x = 0;
			int y = i;
			while (y+1)//ÿ��ѭ���������ָ���Ϊi+1��y+1��
			{
				arr[x][y] = num;
				num++;
				x++;
				y--;
			}
		}
	}
	//��ӡ����
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%-3d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}