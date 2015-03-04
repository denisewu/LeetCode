/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode * hp = new ListNode(0);
        hp->next = head;
        ListNode * prevl = hp;
        ListNode * left = head;
        while(left)
        {
            int count = 0;
            int v = left->val;
            ListNode * prev = NULL;
            while(left && left->val == v)
            {
                count++;
                prev = left;
                ListNode * tp = left->next;
                if(count > 1)
                    delete left;
                left = tp;
            }
            if(count > 1)
            {
                ListNode * tp = prevl->next;
                prevl->next = left;
                delete tp;
            }
            else
                prevl = prev;
        }
        return hp->next;
    }
};
