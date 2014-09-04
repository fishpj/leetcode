/*
 * Filename:	LinkedListCycle.cpp
 * Author:		fishpj
 * Date:		09/01/2014
 */

#include "leetCode.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL)
	{}
};

class Solution
{
	public:
		bool hasCycle(ListNode *head)
		{
			if (NULL == head || NULL == head->next)
			  return false;
			ListNode *p1 = NULL, *p2 = NULL;
			p1 = head; p2 = head;
			while (p2 && p2->next)
			{
				p1 = p1->next;
				p2 = p2->next->next;
				if (p1 == p2)
				{
					return true;
				}
			}
			return false;
		}
};

int main(int argc, char *argv[])
{
	ListNode ln1(1);
	ListNode ln2(2);
	ln1.next = &ln2;
	ListNode ln3(3);
	ln2.next = &ln3;
	ListNode ln4(4);
	ListNode Ln5(5);

	Solution so;
	std::cout << so.hasCycle(&ln1) << std::endl;

	return 0;
}
