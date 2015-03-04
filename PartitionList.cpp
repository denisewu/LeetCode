/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL)
            return head;
        ListNode* pSmall = NULL, *pLarge = NULL, 
                *pHeadLarge = NULL, *pHeadSmall = NULL;
        ListNode* p = head;
        while(p)
        {
           if(p->val < x)
           {
               if(pSmall != NULL)
               {
                   pSmall->next = p;
               }
               if(pHeadSmall == NULL)
                    pHeadSmall = p;
               pSmall = p;
            }
           else
           {
               if(pLarge != NULL)
               {
                   pLarge->next = p;
               }
               if(pHeadLarge == NULL)
                   pHeadLarge = p;
               pLarge = p;
           }
           p = p->next;
        }
        if(pLarge != NULL)
            pLarge->next = NULL;
        else
            pSmall->next = NULL;
            
        if(pSmall != NULL)
            pSmall->next = pHeadLarge;
        return pHeadSmall != NULL? pHeadSmall: pHeadLarge;
    }
};
