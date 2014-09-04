/*
 * Filename:	InsertionSortList.cpp
 * Author:		fishpj
 * Date:		09/02/2014
 */

#include "leetCode.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution
{
	public:
		ListNode *insertionSortList(ListNode *head)
		{
			if (NULL == head || NULL == head->next)
			  return head;
			ListNode *pCur = head->next;
			ListNode *pPos = NULL;
			ListNode *pBeg = head;
			ListNode *pEnd = head;
			while (pCur)
			{
				//检查是否大于头节点
				if (pCur->val < pBeg->val)
				{
					pEnd->next = pCur->next;
					pCur->next = pBeg;
					pBeg = pCur;
					pCur = pEnd->next;
					continue;
				}
				//寻找插入位置
				pPos = pBeg;
				while (pPos->next->val < pCur->val && pPos != pEnd->next)
				  pPos = pPos->next;
				//插入节点
				if (pPos->next != pEnd->next)
				{
					pEnd->next = pCur->next;
					pCur->next = pPos->next;
					pPos->next = pCur;
				}
				else
				{
					pEnd = pEnd->next;
				}
				pCur = pEnd->next;
			}
			return pBeg;
		}

};

int main(int argc, char *argv[])
{
	ListNode ln1(1);
	ListNode ln2(2);
	ListNode ln3(3);
	ListNode ln4(7);
	ListNode ln5(5);

	ln5.next = &ln4;
	ln4.next = &ln3;
	ln3.next = &ln2;
	ln2.next = &ln1;

	Solution so;
	ListNode *head;
	head = so.insertionSortList(&ln5);

	while(head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;

	return 0;
}
