/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lengthA = 0, lengthB = 0;
        ListNode *pa = headA, *pb = headB;
        while(pa)
        {
            lengthA++;
            pa = pa->next;
        }
        while(pb)
        {
            lengthB++;
            pb = pb->next;
        }
        
        if(!lengthA || !lengthB)
            return NULL;
        
        int minus = abs(lengthA - lengthB);
        ListNode* p = (lengthA >= lengthB? headA: headB);
        for(int i = 0; i < minus && p; i++)
        {
            p = p->next;
        }
        ListNode* p2 = (lengthA >= lengthB? headB: headA);
        
        while(p && p2)
        {
            if(p == p2)
                break;
            p = p->next;
            p2 = p2->next;
        }
        return p;
    }
        
        
        

};
