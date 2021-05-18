//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* prev = NULL;
		ListNode* cur = pHead;
		ListNode* next = cur->next;
		while (next)
		{
			if (cur->val != next->val)
			{
				prev = cur;
				cur = next;
				next = next->next;
			}
			else
			{
				//�ҵ��ظ���
				while (next && cur->val == next->val)
				{
					next = next->next;
				}
				//ɾ���ظ���
				while (cur != next)
				{
					ListNode* del = cur;
					cur = cur->next;
					free(del);
				}
				if (prev == NULL)//˵��ɾ����������ǰ��һ������
				{
					pHead = cur;
				}
				else//��ɾ���������������������
				{
					prev->next = cur;
				}
				if (next)//next����
				{
					next = next->next;
				}
			}
		}
		return pHead;
	}
};