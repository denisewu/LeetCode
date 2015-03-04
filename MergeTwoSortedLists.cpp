//Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
       ListNode* p1 = l1, *p2 = l2, *prev1 = NULL;
        while(p1 && p2)
        {
            ListNode* np2 = p2->next;
            if(p1->val > p2->val)
            {
                if(prev1 != NULL)
                    prev1->next = p2;
                else
                    l1 = p2;
                prev1 = p2;
                p2->next = p1;
                p2 = np2;
            }
            else
            {
                prev1 = p1;
                p1 = p1->next;
            }
        }
        if(prev1 == NULL)
        {
            return l1 == NULL? l2: l1;
        }
        if(p2)
        {
           prev1->next = p2;
        }
        return l1;
    }
}
