#define _CRT_SECURE_NO_WARNINGS 1
//用自定义函数实现strcpy函数功能
#include<stdio.h>
#include<assert.h>
//void my_strcpy(char* dest, char* sour)
//{
//	while (*sour != '\0')
//	{
//		*dest = *sour;
//		dest++;
//		sour++;
//	}
//	*dest = *sour;
//}//较简单

char* my_strcpy(char* dest, const char* sour)
{
	char* ret = dest;//存储目标字符串首元素地址
	assert(dest != NULL);
	assert(sour != NULL);//传入空指针时报错
	while (*(dest++) = *(sour++))//当读取到'\0'时，循环结束
	{
		;
	}
	return ret;
}//更健壮
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "#############";
	printf("%s\n",my_strcpy(arr2, arr1));
	return 0;
}