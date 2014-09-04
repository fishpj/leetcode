/*
 * Filename:	LinkedListCycle.cpp
 * Author:		fishpj
 * Date:		09/03/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		ListNode *detectCycle(ListNode *head)
		{
			ListNode *slow = head, *fast = head, *p = head;
			while (slow && fast && fast->next && fast->next->next)
			{
				slow = slow->next;
				fast = fast->next->next;
				if (slow == fast)
				{
					while ( p != slow)
					{
						p = p->next;
						slow = slow->next;
					}
					return p;
				}
			}
			return NULL;
		}
};

int main(int argc, char *argv[])
{
	ListNode ln1(1);
	ln1.next = &ln1;
	ListNode *head;
	Solution so;
	head = so.detectCycle(&ln1);
	if (head)
	  std::cout << head->val << std::endl;
	return 0;
}
