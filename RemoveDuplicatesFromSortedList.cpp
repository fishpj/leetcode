/*
 * Filename:	RemoveDuplicatesFromSortedList.cpp
 * Author:		fishpj
 * Date:		09/03/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		ListNode *deleteDuplicates(ListNode *head)
		{
			ListNode *p1 = head, *p2 = head;

			while (p1 != NULL)
			{
				//循环删除多个重复节点，避免多次更新指针
				while (p2->next != NULL && p2->val == p2->next->val)
				  p2->next = p2->next->next;
				if (p1 == p2)
				{
					p2 = p2->next;
					p1 = p2;
				}
				else
				{
					p1 = p2;
				}
			}
			return head;
		}
};

int main(int argc, char *argv[])
{
	ListNode ln1(1);
	ListNode ln2(1);
	ListNode ln3(3);
	ListNode ln4(4);
	ListNode ln5(5);
	ListNode ln6(6);

	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln6;
	ListNode *head = NULL;

	Solution so;
	head = so.deleteDuplicates(&ln1);

	while (head)
	{
		std::cout << head->val << std::endl;
		head = head->next;
	}
	return 0;
}

