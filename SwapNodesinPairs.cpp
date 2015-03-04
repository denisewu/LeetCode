/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL)
            return head;
        ListNode * left = head, * right = head->next, * prev = NULL;
        while(left != NULL && right != NULL)
        {
            ListNode * nextl = right->next;
            right->next = left;
            left->next = NULL;
            if(prev == NULL)
                head = right;
            else
                prev->next = right;
            prev = left;
            left = nextl;
            if(left)
                right = left->next;
        }
        if(left && prev)
        {
            prev->next = left;
        }
        return head;
        
    }
};
