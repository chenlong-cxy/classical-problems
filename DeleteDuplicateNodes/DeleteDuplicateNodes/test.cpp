//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

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
				//找到重复的
				while (next && cur->val == next->val)
				{
					next = next->next;
				}
				//删除重复的
				while (cur != next)
				{
					ListNode* del = cur;
					cur = cur->next;
					free(del);
				}
				if (prev == NULL)//说明删除的是链表前面一段数据
				{
					pHead = cur;
				}
				else//将删除后的两段链表链接起来
				{
					prev->next = cur;
				}
				if (next)//next更新
				{
					next = next->next;
				}
			}
		}
		return pHead;
	}
};