/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode* ret;
        
        if(k < 2)
            return head;
            
        int pos = 0;
        ListNode* p = head, *left = head, *right = NULL, *prev = NULL;
        while(p)
        {
            if((pos + 1) % k == 0)
            {
                right = p;
                p = right->next;
                
                //reverse
                ListNode *tp = left->next;
                ListNode *prevp = left;
                while(tp != p)
                {
                    ListNode *np = tp->next;
                    tp->next = prevp;
                    prevp = tp;
                    tp = np;
                }
                if(prev == NULL)
                {
                    ret = right;
                }
                else
                    prev->next = right;
                prev = left;
                left = p;
            }
            else
                p = p->next;
            pos++;
        }
        if(prev == NULL)
            ret = left;
        else
            prev->next = left;
        return ret;
    }
};
