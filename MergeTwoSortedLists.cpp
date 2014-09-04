/*
 * Filename:	MergeTwoSortedLists.cpp
 * Author:		fishpj
 * Date:		09/02/2014
 */

#include "leetCode.h"
#include <cassert>
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL)
	{
	}
};

class Solution
{
	public:	
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
		{
			ListNode *head = new ListNode(0);
			assert(head);
			ListNode *pCurr = head;

			while ( l1 != NULL && l2 != NULL)
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
				pCurr = pCurr->next;
				std::cout << pCurr->val << std::endl;
			}
			if (l1 != NULL)
			{
				pCurr->next = l1;
			}
			else if(l2 != NULL)
			{
				pCurr->next = l2;
			}
			pCurr = head->next;
			delete head;
			head = pCurr;
			return head;
		}
};

int main(int argc, char *argv[])
{
	ListNode ln1(1);
	ListNode ln2(2);
	ListNode ln3(3);
	ListNode ln4(4);
	ListNode ln5(5);
	ListNode ln6(6);
	ListNode ln7(7);
	ListNode ln8(8);
	ListNode ln9(9);
	ListNode ln10(10);
	ln1.next = &ln3;
	ln3.next = &ln5;
	ln5.next = &ln7;
	ln7.next = &ln9;
	ln2.next = &ln4;
	ln4.next = &ln6;
	ln6.next = &ln8;
	ln8.next = &ln10;

	Solution so;
	ListNode *head = NULL;
	head = &ln2;
	head = so.mergeTwoLists(&ln1, &ln2);
	while (head)
	{
		std::cout << head->val << std::endl;
		head = head->next;
	}
	return 0;
}
