/*************************************************************************
	> File Name: ReverseLinkedListII.cpp
	> Author: fishpj
	> Mail: 
	> Created Time: 2014年09月12日 星期五 00时24分43秒
 ************************************************************************/

#include "leetCode.h"
#include <cassert>

class Solution
{

    public:
    ListNode *reverseBetween(ListNode *head, int m ,int n)
    {
        if (!head || !head->next || 0 == n-m)
            return head;
        ListNode *root = new ListNode(0);
        assert(root);
        root->next = head;

        ListNode *p1 = root, *p2 = root;
        int iLength = n - m;
        while (--m)
            p1 = p1->next;
        head = p1;
        p1 = p1->next;
        while (iLength--)
        {
            p2 = p1->next;
            p1->next = p1->next->next;
            p2->next = head->next;
            head->next  = p2;
        }
        head = root->next;
        delete root;
        return head;
    }
    void ListTraversal(ListNode *head)
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
    ln1.next = &ln2;
    ln2.next = &ln3;
    ln3.next = &ln4;
    ln4.next = &ln5;

    ListNode *head = &ln1;
    Solution so;
    so.ListTraversal(head);

    head = so.reverseBetween(head, 1, 5);
    so.ListTraversal(head);
    return 0;
}

