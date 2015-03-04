/*
Given a binary tree, return the preorder traversal of its nodes' values.
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode* > s;
        if(root == NULL)
            return ret;
            
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode *p = s.top();
            ret.push_back(p->val);
            s.pop();
            if(p->right)
                s.push(p->right);
            if(p->left)
                s.push(p->left);
            
        }
        return ret;
    }
};
