/*
 * Filename:	RotateList.cpp
 * Author:		fishpj
 * Date:		09/05/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		ListNode *rotateRight(ListNode *head, int k)
		{
			//对head为空或者只有一个节点时的处理
			if (nullptr == head || nullptr == head->next)
			  return head;
			//由于该题存在k大于链表长度时由取模处理
			ListNode *p1 = head, *p2 = head;
			int iLen = 0;
			while (p1)
			{
				iLen++;
				p1 = p1->next;
			}
			k = k%iLen;
			p1 = head;
			//将前指针指向第k个位置
			while (k--)
			  p2 = p2->next;
			//增加k为整个链表最后一个位置处理
			if (p2)
			{
				//找到右边开始第k个位置
				while (p2->next)
				{
					p1 = p1->next;
					p2 = p2->next;
				}
				p2->next = head;
				head = p1->next;
				p1->next = nullptr;
				return head;
			}
			return head;
		}
};

int main(int argc, char *argv[])
{
	ListNode tn1(1);
	ListNode tn2(2);
	ListNode tn3(3);
	ListNode tn4(4);
	ListNode tn5(5);

	tn1.next = &tn2;
	tn2.next = &tn3;
	tn3.next = &tn4;
	tn4.next = &tn5;

	ListNode *head = &tn1;
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;

	Solution so;
	head = so.rotateRight(&tn1, 3);
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
	return 0;
}
