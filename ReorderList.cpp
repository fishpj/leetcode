/*
 * Filename:	ReorderList;
 * Author:		fishpj
 * Date:		09/02/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		void reverseList(ListNode *head)
		{
			//将head作为头节点处理
			ListNode *p1 = head->next, *p2 = head->next;
			while (p1->next)
			{
				p2 = p1->next;
				p1->next = p1->next->next;
				p2->next = head->next;
				head->next = p2;
			}
			return;
		}
		void reorderList(ListNode *head)
		{
			//链表长度小于2时直接返回
			if (NULL == head || NULL == head->next || NULL == head->next->next)
			  return;
			//通过快慢指针找到中间节点
			ListNode *slow = head, *fast = head;
			while (fast->next && fast->next->next)
			{
				slow = slow->next;
				fast = fast->next->next;
			}
			//将后半部分节点逆序
			reverseList(slow);
			//在slow处断开链表	
			ListNode *p1 = head, *p2 = slow->next;
			slow->next = NULL;
			//标记待合并节点
			ListNode *p = p2;
			while (p2 != NULL)
			{
				p = p2;
				//std::cout << p->val << std::endl;
				p2 = p2->next;
				p->next = p1->next;
				p1->next = p;
				p1 = p1->next->next;
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
