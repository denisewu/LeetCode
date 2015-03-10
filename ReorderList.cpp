/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head) {
        int len = 0;
        stack<ListNode *> s;
        ListNode* p = head;
        while(p)
        {
            len++;
            s.push(p);
            p = p->next;
        }
        p = head;
        ListNode* prev = NULL;
        while(len > 1)
        {
            ListNode* np = p->next;
            ListNode* p2 = s.top();
            s.pop();
            p->next = p2;
            if(prev != NULL)
                prev->next = p;
            prev = p2;
            p = np;
            len -= 2;
        }
        
        if(len == 1 && prev != NULL)
        {
            prev->next = p;
            p->next = NULL;
        }
        if(len == 0 && prev != NULL)
            prev->next = NULL;
            
    }
};
