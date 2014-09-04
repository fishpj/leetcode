/*
 * Filename:	ReorderList;
 * Author:		fishpj
 * Date:		09/02/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		void reorderList(ListNode *head)
		{
			if (NULL == head || NULL == head->next || NULL == head->next->next)
			  return;
			ListNode *p1 = head, *p2 = head->next;
			while (p2->next)
			{
				p1 = p2->next;
				p2->next = p1->next;
				p1 = head->next;
				head->next = p1;
			}
			return ;
		}
};

int main(int argc, char *argv[])
{
	ListNode ln1(1);
	ListNode ln2(2);
	ListNode ln3(3);
	ListNode ln4(4);
	ListNode ln5(5);

	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	ln4.next = &ln5;

	ListNode *head = &ln1;
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
	Solution so;
	head = &ln1;
	so.reorderList(head);
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
	return 0;

}
