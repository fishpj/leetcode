/*************************************************************************
	> File Name: ReverseNodesInKGroup.cpp
	> Author: fishpj
	> Mail: 
	> Created Time: 2014年09月12日 星期五 23时47分15秒
 ************************************************************************/

#include "leetCode.h"
#include<iostream>
using namespace std;

class Solution
{
    public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int iCount = k;
        ListNode *newHead = head;
        while (iCount > 0 && newHead)
        {
            newHead = newHead->next;
            iCount--;
        }
        if (iCount > 0)
            return head;
        ListNode *prev = NULL;
        ListNode *current = head;
        while (current!= newHead)
        {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head->next = reverseKGroup(newHead, k);
        return prev;
    }
    void printCheck(ListNode *head)
    {
        while (head)
        {
            std::cout << head->val << " -> ";
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
    so.printCheck(head);
    head = so.reverseKGroup(&ln1, 2);
    so.printCheck(head);
    return 0;
}
