/*
 * Filename:	SortList.cpp
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
		/*
		ListNode *sortList(ListNode *head)
		{
			if (!head || head->next == NULL)
			  return head;

			ListNode* pA= head, *pB = head;

			while (pA && pB && pB->next && pB->next->next)
			{
				pA = pA->next;
				pB = pB->next->next;
			}
			pB = pA->next;
			pA->next = NULL;
			pA = head;

			pA = sortList(pA);
			pB = sortList(pB);

			return mergeTwoLists(pA, pB);
		}*/
		
		ListNode *sortList(ListNode *head)
		{
			if (NULL == head || NULL == head->next)
			  return head;
			ListNode *slow = head, *fast = head;
			/*
			while (fast != NULL && fast->next != NULL)
			{
				fast = fast->next;
				if (fast->next)
				{
					fast = fast->next;
					slow = slow->next;
				}
			}
			*/
			while (slow && fast && fast->next && fast->next->next)
			{
				slow = slow->next;
				fast = fast->next->next;
			}

			fast = slow->next;
			slow->next = NULL;
			slow = head;

			slow = sortList(slow);
			fast = sortList(fast);
			return mergeTwoLists(slow, fast);
		}

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
			while (pCurr)
			{
				pCurr = pCurr->next;
			}
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
	//ln10.next = &ln3;
	ln3.next = &ln2;
	ln2.next = &ln4;
	ln4.next = &ln5;
	//ln5.next = &ln1;
	/*
	ln1.next = &ln3;
	ln3.next = &ln5;
	ln5.next = &ln7;
	ln7.next = &ln9;
	ln9.next = &ln2;
	ln2.next = &ln4;
	ln4.next = &ln6;
	ln6.next = &ln8;
	ln8.next = &ln5;
	*/
	Solution so;
	ListNode *head = NULL;
	//head = &ln8;

	head = so.sortList(&ln3);
	while (head)
	{
		std::cout << head->val << std::endl;
		head = head->next;
	}
	return 0;
}
