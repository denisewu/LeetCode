/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        if(head->next == NULL)
            return false;
        ListNode* fast = head->next, *slow = head;
        while(fast && slow)
        {
            if(fast == slow)
                return true;
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            else
                break;
        }
        return false;
    }
};
