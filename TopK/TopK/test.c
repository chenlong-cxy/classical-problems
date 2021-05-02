//��������arr���ҳ���������k������
//���磬����4��5��1��6��2��7��3��8��8�����֣�������4��������5��6��7��8��
#include <stdio.h>
//����һ������

//��������
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//�ѵ����µ�����С�ѣ�
void AdjustDown(int* a, int n, int parent)
{
	//child��¼���Һ�����ֵ��С�ĺ��ӵ��±�
	int child = 2 * parent + 1;//��Ĭ�������ӵ�ֵ��С
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] < a[child])//�Һ��Ӵ��ڲ����Һ��ӱ����ӻ�С
		{
			child++;//��С�ĺ��Ӹ�Ϊ�Һ���
		}
		if (a[child] < a[parent])//���Һ����н�С���ӵ�ֵ�ȸ���㻹С
		{
			//����������С���ӽ�㽻��
			Swap(&a[child], &a[parent]);
			//�������½��е���
			parent = child;
			child = 2 * parent + 1;
		}
		else//�ѳɶ�
		{
			break;
		}
	}
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
	*returnSize = k;
	int i = 0;
	//��С��
	for (i = (arrSize - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, arrSize, i);
	}
	//�Ž���
	int end = arrSize - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
	//������k������������
	int* retArr = (int*)malloc(sizeof(int)*k);
	for (i = 0; i < k; i++)
	{
		retArr[i] = arr[i];
	}
	return retArr;//��������k����
}

//�������ȡ�Ѷ�����

//��������
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//�ѵ����µ�������ѣ�
void AdjustDown(int* a, int n, int parent)
{
	//child��¼���Һ�����ֵ�ϴ�ĺ��ӵ��±�
	int child = 2 * parent + 1;//��Ĭ�������ӵ�ֵ�ϴ�
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])//�Һ��Ӵ��ڲ����Һ��ӱ����ӻ���
		{
			child++;//�ϴ�ĺ��Ӹ�Ϊ�Һ���
		}
		if (a[child] > a[parent])//���Һ����нϴ��ӵ�ֵ�ȸ���㻹��
		{
			//���������ϴ���ӽ�㽻��
			Swap(&a[child], &a[parent]);
			//�������½��е���
			parent = child;
			child = 2 * parent + 1;
		}
		else//�ѳɶ�
		{
			break;
		}
	}
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
	*returnSize = k;
	int i = 0;
	//�����
	for (i = (arrSize - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, arrSize, i);
	}
	//������k������������
	int* retArr = (int*)malloc(sizeof(int)*k);
	int end = arrSize - 1;
	for (i = 0; i < k; i++)
	{
		retArr[i] = arr[0];//ȡ�Ѷ�����
		Swap(&arr[0], &arr[end]);//�����Ѷ����������һ������
		//����һ�����µ������������һ�����ݿ��������������ݣ����Դ���������Ϊend=arrSize-1
		AdjustDown(arr, end, 0);
		end--;//���һ�����ݵ��±�ı�
	}
	return retArr;//��������k����
}

//���������������ݴ���
//��������
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//�ѵ����µ�����С�ѣ�
void AdjustDown(int* a, int n, int parent)
{
	//child��¼���Һ�����ֵ��С�ĺ��ӵ��±�
	int child = 2 * parent + 1;//��Ĭ�������ӵ�ֵ��С
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] < a[child])//�Һ��Ӵ��ڲ����Һ��ӱ����ӻ�С
		{
			child++;//��С�ĺ��Ӹ�Ϊ�Һ���
		}
		if (a[child] < a[parent])//���Һ����н�С���ӵ�ֵ�ȸ���㻹С
		{
			//����������С���ӽ�㽻��
			Swap(&a[child], &a[parent]);
			//�������½��е���
			parent = child;
			child = 2 * parent + 1;
		}
		else//�ѳɶ�
		{
			break;
		}
	}
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
	*returnSize = k;
	if (k == 0)
		return NULL;
	//�������ǰK������С��
	int i = 0;
	int* retArr = (int*)malloc(sizeof(int)*k);
	for (i = 0; i < k; i++)
	{
		retArr[i] = arr[i];
	}
	for (i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(retArr, k, i);
	}
	//ʣ�µ�N-k����������Ѷ����ݱȽ�
	for (i = k; i < arrSize; i++)
	{
		if (arr[i]>retArr[0])
		{
			retArr[0] = arr[i];//�Ѷ������滻
		}
		AdjustDown(retArr, k, 0);//����һ�����µ���
	}
	return retArr;//��������k����
}