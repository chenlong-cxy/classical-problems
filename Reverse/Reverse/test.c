
//��������ַ���(���ո�)
//��һ
//#include<stdio.h>
//void Reverse(char* pc)
//{
//	char ch = getchar();
//	if (ch != '\n')
//	{
//		Reverse(&ch);
//		putchar(ch);
//	}
//}
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != EOF)
//	{
//		Reverse(&ch);
//		putchar(ch);
//	}
//	return 0;
//}//��������

//����
//#include<stdio.h>
//#include<string.h>
//void Reverse(char* str)
//{
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	while (left < right)
//	{
//		int temp = *(left);
//		*(left) = *(right);
//		*(right) = temp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	Reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//����
#include<stdio.h>
#include<string.h>
void Reverse(char* str)
{
	int len = strlen(str);
	char temp = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if (strlen(str + 1) >= 2)
	{
		Reverse(str + 1);
	}
	*(str + len - 1) = temp;
}//�ݹ�
int main()
{
	char arr[] = "abcdef";
	Reverse(arr);
	printf("%s\n", arr);
	return 0;
}