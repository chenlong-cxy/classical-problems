#define _CRT_SECURE_NO_WARNINGS 1
//S形蛇形填数
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int arr[100][100] = { 0 };
//	scanf("%d", &n);//输入需要填充的数组的大小，arr[n][n]
//	//填充数组
//	int i = 0;
//	int num = 1;
//	for (i = 0; i < n; i++)//需要打印n列数字
//	{
//		if (i % 2 == 0)//偶数列填充
//		{
//			int x = 0;
//			int y = i;
//			for (x = 0; x <= n-1; x++)
//			{
//				arr[x][y] = num;
//				num++;
//			}
//		}
//		else//奇数列填充
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
//	//打印数组
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

//螺旋形蛇形填数
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int arr[100][100] = { 0 };
//	scanf("%d", &n);//输入需要填充的数组的大小，arr[n][n]
//	//填充数组
//	int i = 0;
//	int num = 1;
//	for (i = 0; i < n / 2; i++)//循环的次数
//	{
//		int x = i;
//		int y = n - 1 - i;
//		for (x = i; x <= n - 2 - i; x++)//第一步，列不变，行依次++
//		{
//			arr[x][y] = num;
//			num++;
//		}
//		for (y = n - 1 - i; y >= i + 1; y--)//第二步，行不变，列依次--
//		{
//			arr[x][y] = num;
//			num++;
//		}
//		for (x = n - 1 - i; x >= i + 1; x--)//第三步，列不变，行依次--
//		{
//			arr[x][y] = num;
//			num++;
//		}
//		for (y = i; y <= n - 2 - i; y++)//第四步，行不变，列依次++
//		{
//			arr[x][y] = num;
//			num++;
//		}
//	}
//	if (n % 2 != 0)//判断n是否为奇数
//		arr[n / 2][n / 2] = num;//填充正中央的数
//	//打印数组
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

//三角形蛇形填数
#include<stdio.h>
int main()
{
	int n = 0;
	int arr[100][100] = { 0 };
	scanf("%d", &n);//输入需要填充的数组的大小，arr[n][n]
	//填充数组
	int i = 0;
	int num = 1;
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)//i为偶数时，数字从左下向右上填充
		{
			int x = i;
			int y = 0;
			while (x+1)//每次循环填充的数字个数为i+1即x+1个
			{
				arr[x][y] = num;
				num++;
				x--;
				y++;
			}
		}
		else//i为奇数时，数字从右上向左下填充
		{
			int x = 0;
			int y = i;
			while (y+1)//每次循环填充的数字个数为i+1即y+1个
			{
				arr[x][y] = num;
				num++;
				x++;
				y--;
			}
		}
	}
	//打印数组
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