//Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL)
            return head;
        ListNode * right = head->next, *lastp = NULL;;
        while(right)
        {
            ListNode* np = right->next;
            ListNode* left = head, *prev = NULL;
            while(left != right)
            {
                if(left->val > right->val)
                    break;
                prev = left;
                left = left->next;
            }
            ListNode * insertp = left;
            lastp = left;
            while(left != right)
            {
                lastp = left;
                left = left->next;
            }
            if(insertp != right)
            {
                if(prev != NULL)
                {
                    right->next = prev->next;
                    prev->next = right;
                }
                else
                {
                    right->next = head;
                    head = right;
                }
            }
            lastp->next = np;
            right = np;
        }
        return head;
    }
};
