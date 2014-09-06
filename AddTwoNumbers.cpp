/*
 * Filename:	AddTwoNumbers.cpp
 * Author:		fishpj
 * Date:		09/06/2014
 */

#include "leetCode.h"
#include <cassert>

class Solution
{
	public:
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
		{
			if (nullptr == l1)
			  return l2;
			if (nullptr == l2)
			  return l1;
			int iOverflow = 0;
			ListNode *p1 = l1, *p2 = l2, *p3 = l1;
			while (p1 && p2)
			{
				p1->val = p1->val + p2->val + iOverflow;
				iOverflow = p1->val/10;
				if (iOverflow)
				  p1->val %=10;
				p3 = p1;
				p1 = p1->next;
				p2 = p2->next;
			}
			if (!iOverflow)
			{
				//p1不为空不需处理
				if (p2)
				  p3->next = p2;
			}
			else if (iOverflow)
			{
				ListNode *ln = new ListNode(iOverflow);
				assert(ln);
				if (nullptr == p1)
				{
					p3->next = addTwoNumbers(ln, p2);
				}
				else
				  p3->next = addTwoNumbers(ln, p1);
			}
			return l1;
		}
};

int main(int argc, char *argv[])
{
	ListNode ln0(0);
	ListNode ln1(1);
	ListNode ln2(2);
	ListNode ln3(3);
	ListNode ln4(4);
	ListNode ln5(5);
	ListNode ln6(6);
	ListNode ln7(7);
	ListNode ln8(4);
	ListNode ln9(9);

	ListNode *head = NULL;

	ln2.next = &ln4;
	ln4.next = &ln9;
	ln5.next = &ln6;
	//ln6.next = &ln9;

	Solution so;
	head = so.addTwoNumbers(&ln2, &ln5);
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
	return 0;
}
