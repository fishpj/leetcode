/*
 * Filename:	SwapNodesInPairs.cpp
 * Author:		fishpj
 * Date:		09/09/2014
 */

#include "leetCode.h"
#include <cassert>

class Solution
{
	public:
		ListNode *swapPairs(ListNode *head)
		{
			if (!head || !head->next)
			  return head;
			//建立头节点方便处理
			ListNode *root = new ListNode(0);
			assert(root);
			root->next = head;
			ListNode *p = root, *p1 = p, *p2 = p;
			while (p && p->next && p->next->next)
			{
				p1 = p->next;
				p2 = p1->next;
				p1->next = p2->next;
				p2->next = p->next;
				p->next = p2;
				p = p->next->next;
			}
			p = root->next;
			delete root;
			return p;
		}
		void listTraversal(ListNode *head)
		{
			while(head)
			{
				std::cout << head->val << " ";
				head = head->next;
			}
			std::cout << std::endl;
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
	ListNode ln6(6);
	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	ln4.next = &ln5;
	ln5.next = &ln6;
	ListNode *head = &ln1;
	Solution so;
	so.listTraversal(head);
	head = so.swapPairs(&ln1);
	so.listTraversal(head);
	return 0;
}
