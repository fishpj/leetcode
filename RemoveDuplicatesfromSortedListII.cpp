/*
 * Filename:	RemoveDuplicatesfromSortedListII.cpp
 * Author:		fishpj1107
 * Date:		09/06/2014
 */

#include "leetCode.h"
#include <cassert>

class Solution
{
	public:
		ListNode *deleteDuplicates(ListNode *head)
		{
			if (nullptr == head || nullptr == head->next)
			  return head;

			//创建头节点以方便链表操作
			ListNode *result = new ListNode(0);
			assert(result);
			result->next = head;
			ListNode *p1 = result, *p2 = head;
			//遍历整个链表直到表尾
			while (nullptr != p2->next)
			{
				//std::cout << __LINE__ <<std::endl;
				ListNode *p3 = p2;
				while (p2->next && p2->val == p2->next->val)
				  p2 = p2->next; 
				//查找到存在相等的局部链表段
				if (p3 != p2 && p3->val == p2->val)
				{
					p1->next = p2->next;
					p2 = p1->next;
					//删除为空了直接跳出循环
					if (!p2)
					  break;
				}
				//没有局部相等的链表段
				else
				{
					p1 = p3;
					p2 = p2->next;
				}
			}
			p1 = result->next;
			delete result;
			return p1;
		}
};

int main(int argc, char *argv[])
{
	ListNode ln1(1);
	ListNode ln2(1);
	ListNode ln3(2);
	ListNode ln4(2);
	ListNode ln5(4);
	ListNode ln6(4);
	ListNode ln7(4);
	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	//ln4.next = &ln5;
	ln5.next = &ln6;
	ln6.next = &ln7;

	ListNode *head = &ln1;
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
	Solution so;
	head = so.deleteDuplicates(&ln3);
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;

	return 0;
}
