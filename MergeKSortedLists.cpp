/*
 * Filename:	MergeKSortedLists.cpp
 * Author:		fishpj
 * Date:		09/03/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		//对vector中的ListNode作归并排序
		ListNode *mergeKLists(vector<ListNode *> &Lists)
		{

		}
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
		{
			//构造头指针方便操作
			ListNode *head = new ListNode(0);
			assert(head);
			ListNode *pCurr = head;

			while (l1 != NULL && l2 != NULL)
			{
				if (l1->val < l2->val)
				{
					pCurr->next = l1;
					l1 = l1->next;
				}
				else
				{
					pCurr->next = l2;
					l2 = l2->next;
				}
				pCurr = pcurr->next;
			}
			if (l1 != NULL)
			  pCurr->next = l1;
			if (l2 != NULL)
			  pCurr->next = l2;
			pCurr = head->next;
			delete head;
			head = pCurr;
			return head;
		}
};

int main(int argc, char 8argv[])
{
	return o;
}
