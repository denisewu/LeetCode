/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m >= n)
            return head;
            
        ListNode *hp = new ListNode(0);
        hp->next = head;
        ListNode *p = head;
        ListNode *left = hp, *right = hp, *first = NULL, *prev = NULL;
        int i = 0;
        while(p)
        {
            i++;
            if(i < m)
            {
                left = left->next;
                p = p->next;
            }
            else if(i <= n)
            {
                ListNode* nextp = p->next;;
                if(prev == NULL)
                    first = p;
                else
                {
                    p->next = prev;
                }
                prev = p;
                p = nextp;
            }
            else
                break;
        }
        left->next = prev;
        first->next = p;
        return hp->next;
    }
};
