//Sort a linked list in O(n log n) time using constant space complexity.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode * merge(ListNode* head1, ListNode* head2)
    {
        ListNode* p1 = head1, *p2 = head2, *prev1 = NULL;
        while(p1 && p2)
        {
            ListNode* np2 = p2->next;
            if(p1->val > p2->val)
            {
                if(prev1 != NULL)
                    prev1->next = p2;
                else
                    head1 = p2;
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
            return head1 == NULL? head2: head1;
        }
        if(p2)
        {
           prev1->next = p2;
        }
        return head1;
    }
    
    ListNode * mergeSort(ListNode* head)
    {
         if(head == NULL || head->next == NULL)
            return head;
        ListNode* fast = head, *slow = head, *prev = NULL;
        while(fast && fast->next)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        prev->next = NULL;
        
        ListNode* lp = mergeSort(head);
        ListNode* rp = mergeSort(slow);
        return merge(lp, rp);
    }
    
    ListNode * quickSort(ListNode* head, ListNode* tail)
    {
            if(head == NULL || head->next == tail)
                return head;
            ListNode * pNewHead;
            ListNode* pMid = partition(head, tail, &pNewHead);
            ListNOde* pHeadLeft = NULL, *pHeadRight = NULL;
            if(pNewHead != pMid)
                pHeadLeft = quickSort(pNewHead, pMid);
            if(pMid->next != tail)
                pHeadRight = quickSort(pMid->next, tail);
            return pNewHead == pMid? pMid: pHeadLeft;
    }
    
     ListNode *partition(ListNode *head, ListNode *tail, ListNode** ppNewHead) {
       if(head == NULL)
            return head;
            
        ListNode* pSmall = NULL, *pLarge = NULL, 
                *pHeadLarge = NULL, *pHeadSmall = NULL;
                
        ListNode* p = head->next;
        int x = head->val;
        while(p != tail)
        {
           if(p->val <= x)
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
        if(pHeadLarge == NULL)
        {
            head->next = tail;
        }
        else
        {
            head->next = pHeadLarge;
        }
            
        if(pSmall != NULL)
        {
            pSmall->next = head;
            *ppNewHead = pHeadSmall;
        }
        else
            *ppNewHead = head;
        
       if(pLarge != NULL)
            pLarge->next = tail;
        else
            head->next = tail;
            
        return head;
    }
    
public:
    ListNode *sortList(ListNode *head) {
        return quickSort(head, NULL);
    }
};
