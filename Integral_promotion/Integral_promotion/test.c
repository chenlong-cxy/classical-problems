
//C������������������������ȱʡ�������͵ľ��������е�
//Ϊ�˻��������ȣ�����ʽ�е��ַ��Ͷ����Ͳ���������ʹ��֮ǰ��ת��Ϊ��ͨ���ͣ�����ת����Ϊ��������

//#include<stdio.h>
//int main()
//{
//	//char--signed char
//	char a = 3;
//	//00000000000000000000000000000011
//	//00000011-a
//	char b = 127;
//	//00000000000000000000000001111111
//	//01111111-b
//	char c = a + b;
//	//a��b�Ĵ�С����һ�����ʹ�С������Ҫ������������
//	//���������ǰ��ձ���ԭ����λ��������
//	//10000010-c
//	//11111111111111111111111110000010-����
//	//11111111111111111111111110000001-����
//	//10000000000000000000000001111110-ԭ��
//	//-126
//	printf("%d\n", c);
//	//%d-���з������ʹ�ӡ
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	char a = 0x16;//����λΪ0����������ʱ��0
//	short b = 0xb600;//����λΪ1����������ʱ��1
//	int c = 0xb6000000;//��������������
//	if (a == 0x16)
//		printf("a");
//	if (b == 0xb600)
//		printf("b");
//	if (c == 0xb6000000)
//		printf("c");
//	return 0;
//}


#include<stdio.h>
int main()
{
	char a = 1;
	printf("%u\n", sizeof(a));
	printf("%u\n", sizeof(+a));//a�������㣬��������
	printf("%u\n", sizeof(-a));//a�������㣬��������
	return 0;
}