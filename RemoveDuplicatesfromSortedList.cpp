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
        if(!head)
            return head;
            
        ListNode *left = head, *right = head->next;
        while(right)
        {
            while(right && left->val == right->val)
            {
                ListNode* p = right->next;
                delete right;
                right = p;
            }
            if(right)
            {
                left->next = right;
                left = right;
                right = left->next;
            }
        }
        left->next = NULL;
        return head;
    }
};
