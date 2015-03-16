/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
  struct comparator
    {
        bool operator() ( ListNode* i, ListNode* j)
         {
            return i->val > j->val;
         }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparator> minHeap;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != NULL)
                minHeap.push(lists[i]);
        }
        if(minHeap.empty())
            return NULL;
        ListNode * prev = NULL, *head = NULL;
        while(!minHeap.empty())
        {
            if(head == NULL)
                head = minHeap.top();
            if(prev != NULL)
                prev->next = minHeap.top();
            prev = minHeap.top();
            minHeap.pop();
            if(prev->next != NULL && !minHeap.empty())
            {
                minHeap.push(prev->next);
            }
        }
        return head;
    }
};
