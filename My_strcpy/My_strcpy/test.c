#define _CRT_SECURE_NO_WARNINGS 1
//���Զ��庯��ʵ��strcpy��������
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
//}//�ϼ�

char* my_strcpy(char* dest, const char* sour)
{
	char* ret = dest;//�洢Ŀ���ַ�����Ԫ�ص�ַ
	assert(dest != NULL);
	assert(sour != NULL);//�����ָ��ʱ����
	while (*(dest++) = *(sour++))//����ȡ��'\0'ʱ��ѭ������
	{
		;
	}
	return ret;
}//����׳
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "#############";
	printf("%s\n",my_strcpy(arr2, arr1));
	return 0;
}