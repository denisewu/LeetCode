/*
Recover Binary Search Tree Total Accepted: 27552 Total Submissions: 113697 My Submissions Question Solution 
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    TreeNode* prev, *mistake1, *mistake2;
    
    void inOrder(TreeNode* root)
    {
        if(root == NULL)
            return;
        inOrder(root->left);
        if(prev != NULL && prev->val > root->val)
        {
            if(mistake1 == NULL)
            {
                mistake1 = prev;
                mistake2 = root;
            }
            else
                mistake2 = root;

        }
        prev = root;
        inOrder(root->right);
    }
    
    void inOrderIter(TreeNode* root)
    {
        if(root == NULL)
            return;
        stack<TreeNode *> s;
        TreeNode* p = root;
        while(!s.empty() || p)
        {
            if(p) 
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                if(prev != NULL && prev->val > p->val)
                {
                    if(mistake1 == NULL)
                    {
                        mistake1 = prev;
                        mistake2 = p;
                    }
                    else
                        mistake2 = p;

                }
                prev = p;
                s.pop();
                p = p->right;
            }
        }
    }
    
public:
    void recoverTree(TreeNode *root) {
        prev = mistake1 = mistake2 = NULL;
       //inOrder(root);
        inOrderIter(root);
        if(mistake1 != NULL && mistake2 != NULL)
        {
            int temp = mistake1->val;
            mistake1->val = mistake2->val;
            mistake2->val = temp;
        }
    }
};
