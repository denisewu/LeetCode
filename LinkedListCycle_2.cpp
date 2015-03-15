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
    ListNode *detectCycle(ListNode *head) {
       if(head == NULL || head->next == NULL)
            return NULL;
       ListNode* fast = head->next->next, * slow = head->next;
       ListNode* start = NULL;
       while(fast && slow)
       {
           if(fast == slow)
            {
                start = fast;
                break;
            }
            slow = slow->next;
            fast = fast->next;
            if(!fast)
                return NULL;
            fast = fast->next;
       }
       if(start == NULL)
            return NULL;
        ListNode * p1 = start, *p2 = head;
        while(p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
