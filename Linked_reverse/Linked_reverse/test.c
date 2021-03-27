#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;//�����������ͣ��ɸ�����Ҫ�����������Ͷ���
//�����㶨��
typedef struct ListNode
{
	ElementType Data;//�����򣬴洢����
	struct ListNode* Next;//ָ���򣬴洢��һ�����ĵ�ַ
}Node, *PNode;
PNode CreateList()
{
	PNode PHead, PTail;//����ͷָ���βָ��
	PHead = (PNode)malloc(sizeof(Node));//��������һ��ͷ����ڴ�ռ�
	if (PHead == NULL)
	{
		printf("ͷ�ڵ��ڴ�ռ俪��ʧ��\n");//malloc�������ٿռ�ʧ��
		exit(-1);
	}
	//��ֻ��һ�����ʱ���ýڵ����ͷ��㣬����β��㣬����ͷָ���βָ��ָ��һ��λ��
	PTail = PHead;
	PTail->Next = NULL;//β����ָ����ΪNULL
	int i = 0;
	int len = 0;//��������ĳ���
	printf("���������Ž�����:>");
	scanf("%d", &len);
	for (i = 0; i < len; i++)//ѭ������len�����
	{
		PNode PNew = (PNode)malloc(sizeof(Node));//����һ���½��
		if (PNew == NULL)
		{
			printf("�½�㴴��ʧ��\n");//malloc�������ٿռ�ʧ��
			exit(-1);
		}
		printf("�������%d����:>", i + 1);
		scanf("%d", &(PNew->Data));//����������ݴ洢���½���������
		PNew->Next = NULL;//���½���ָ������ΪNULL
		PTail->Next = PNew;//�½��ĵ�ַ�洢��β����ָ����
		PTail = PNew;//�½�����µ�β��㣬����βָ��ָ����½��
	}
	printf("�������ɹ�\n");
	return PHead->Next;//����ͷ���λ��
}
void TraverseList(PNode List)
{
	PNode P = List; //����һ���������ݵĽ���ַ��ֵ��P
	printf("���������ֵΪ:>");
	if (P == NULL)
	{
		printf("����Ϊ��\n");
	}
	while (P != NULL)//PΪNULLʱ��������ӡ
	{
		printf("%d ", P->Data);//��ӡPָ��Ľ���������
		P = P->Next;//���ý���ָ����ֵ��P��ʹPָ����һ�����
	}
	printf("\n");
}
PNode ReverseList(PNode List)
{
	PNode Old_head = List;//��һ���������ݵĽ���ַ
	PNode New_head = NULL;
	while (Old_head != NULL)
	{
		PNode Temp = Old_head->Next;//Temp�洢��һ�����ĵ�ַ
		Old_head->Next = New_head;//�ı�ָ��ָ��
		New_head = Old_head;//New_head����
		Old_head = Temp;//Old_head��ȡ��һ�����ĵ�ַ
	}
	return New_head;
}
int main()
{
	PNode List = CreateList();//�������ú���List���յ�һ���������ݵĽ��λ��
	TraverseList(List);//����һ���������ݵĽ��λ�ô��룬��ӡ������
	List = ReverseList(List);//��List������ת���µ�������ʼ��ַ
	TraverseList(List);//����һ���������ݵĽ��λ�ô��룬��ӡ������
	return 0;
}