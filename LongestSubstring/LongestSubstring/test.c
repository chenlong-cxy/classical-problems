//给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串，?
//要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
//
//示例 1：
//输入：s = "aaabb", k = 3
//输出：3
//解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
//
//示例 2：
//输入：s = "ababbc", k = 2
//输出：5
//解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

#include<stdio.h>
#include<string.h>
int tmp(char* s, int left, int right, int k)
{
	int table[26] = { 0 };
	int i = 0;
	for (i = left; i <= right; i++)
	{
		table[s[i] - 'a']++;
	}//table[0]存放字符串s中'a'的个数，table[1]存放'b'的个数，以此类推
	int ch = 0;
	for (i = 0; i <26;i++)
	{
		if (table[i] > 0 && table[i] < k)
		{
			ch = i + 'a';
			break;
		}//找到出现次数小于k的一个字母
	}
	if (ch == 0)//字母出现次数均大于大于k
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