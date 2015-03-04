/*
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if((!p && q) || (p && !q))
            return false;
        
        if(!p && !q)
            return true;
            
        stack<TreeNode*> s1, s2;
        s1.push(p);
        s2.push(q);
        
        while(!s1.empty() && !s2.empty())
        {
            TreeNode* p1 = s1.top();
            TreeNode* p2 = s2.top();
            if(p1->val != p2->val || (!p1->left && p2->left)
            || (p1->left && !p2->left) 
            || (!p1->right && p2->right)
            || (p1->right && !p2->right))
                return false;
           
            s1.pop();
            s2.pop();
            if(p1->left)
            {
                s1.push(p1->left);
                s2.push(p2->left);
            
            }
            if(p1->right)
            {
                s1.push(p1->right);
                s2.push(p2->right);
            }
        }
        return true;
    }
};
