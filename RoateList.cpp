/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL)
            return head;
            
        int size = 0;
        ListNode * p = head;
        ListNode* lastp = head;
        while(p)
        {
            size++;
            lastp = p;
            p = p->next;
        }
        k = k % size;
        if(k == 0)
            return head;
            
        p = head;
        int i = size - k - 1;
        while(i > 0)
        {
            p = p->next;
            i--;
        }
        ListNode * tp = p->next;
        p->next = NULL;
        lastp->next = head;
        
        return tp;
    }
};
