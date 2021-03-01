//����һ���ַ��� s ��һ������ k �������ҳ� s �е���Ӵ���?
//Ҫ����Ӵ��е�ÿһ�ַ����ִ����������� k ��������һ�Ӵ��ĳ��ȡ�
//
//ʾ�� 1��
//���룺s = "aaabb", k = 3
//�����3
//���ͣ���Ӵ�Ϊ "aaa" ������ 'a' �ظ��� 3 �Ρ�
//
//ʾ�� 2��
//���룺s = "ababbc", k = 2
//�����5
//���ͣ���Ӵ�Ϊ "ababb" ������ 'a' �ظ��� 2 �Σ� 'b' �ظ��� 3 �Ρ�

#include<stdio.h>
#include<string.h>
int tmp(char* s, int left, int right, int k)
{
	int table[26] = { 0 };
	int i = 0;
	for (i = left; i <= right; i++)
	{
		table[s[i] - 'a']++;
	}//table[0]����ַ���s��'a'�ĸ�����table[1]���'b'�ĸ������Դ�����
	int ch = 0;
	for (i = 0; i <26;i++)
	{
		if (table[i] > 0 && table[i] < k)
		{
			ch = i + 'a';
			break;
		}//�ҵ����ִ���С��k��һ����ĸ
	}
	if (ch == 0)//��ĸ���ִ��������ڴ���k
		return right - left + 1;
	int ret = 0;
	int j = left;
	while (j <= right)
	{
		while (j <= right&&s[j] == ch)
		{
			j++;
		}
		if (j > right)
			return ret;
		int start = j;
		while (j <= right&&s[j] != ch)
			j++;
		int length = tmp(s, start, j - 1, k);
		ret = length > ret ? length : ret;
	}
	return ret;
}
int longestSubstring(char * s, int k)
{
	return tmp(s, 0, strlen(s) - 1, k);
}
int main()
{
	char arr[] = "ababbc";
	int ret = longestSubstring(arr, 2);
	printf("%d\n", ret);
	return 0;
}