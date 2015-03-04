/**
//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* sortedListToBSTAux(ListNode * head, int len)
    {
        if(head == NULL || len < 1)
            return NULL;
            
        ListNode* p = head, prev = NULL;
        int mid = (len - 1) / 2;
        int i = mid;
        while(i)
        {
            p = p->next;
            i--;
        }
        TreeNode* root = new TreeNode(p->val);
        root->left = sortedListToBSTAux(head, mid);
        root->right = sortedListToBSTAux(p->next, len - mid - 1);
    }
    
public:
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode* p = head;
        int len = 0;
        while(p != NULL)
        {
            len++;
            p = p->next;
        }
        return sortedListToBSTAux(head, len);
    }
};
