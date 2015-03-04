/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode * hp = NULL;
        if(!head)
            return hp;
        RandomListNode * p = head;
        
        while(p)
        {
            RandomListNode * np = new RandomListNode(p->label);
            RandomListNode * tp = p->next;
            np->next = tp;
            p->next = np;;
            p = tp;
        }
        
        p = head;
        while(p)
        {
            RandomListNode * np = p->next;
            RandomListNode * rp = p->random;
            if(rp != NULL)
                np->random = rp->next;
            p = np->next;
        }
        
        p = head;
        RandomListNode * prev = NULL;
        while(p)
        {
            RandomListNode * np = p->next;
            if(prev == NULL)
                hp = np;
            else
                prev->next = np;
            prev = np;
            p->next = np->next;
            p = p->next;
        }
        
        return hp;
    }
};
