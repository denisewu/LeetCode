/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * p1 = l1, * p2 = l2;
        ListNode * head = NULL, *prev = NULL;
        int carry = 0;
        while(p1 && p2)
        {
            int sum = p1->val + p2->val + carry;
            ListNode * p = new ListNode(sum % 10);
            if(head == NULL)
                head = p;
            if(prev != NULL)
                prev->next = p;
            prev = p;
            carry = sum / 10;
            p1 = p1->next;
            p2 = p2->next;
            
        }
        
        while(p1)
        {
            int sum = p1->val + carry;
            ListNode * p = new ListNode(sum % 10);
            if(head == NULL)
                head = p;
            if(prev != NULL)
                prev->next = p;
            prev = p;
            carry = sum / 10;
            p1 = p1->next;
        }
        
        while(p2)
        {
            int sum = p2->val + carry;
            ListNode * p = new ListNode(sum % 10);
            if(head == NULL)
                head = p;
            if(prev != NULL)
                prev->next = p;
            prev = p;
            carry = sum / 10;
            p2 = p2->next;
        }
        if(carry > 0)
        {
            ListNode * p = new ListNode(carry);
            prev->next = p;
        }
        
        return head;
    }
};
