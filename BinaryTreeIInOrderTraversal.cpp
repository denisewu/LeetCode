
//Given a binary tree, return the inorder traversal of its nodes' values.
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root == NULL)
            return ret;
        stack<TreeNode* > s;
      
        s.push(root);
        TreeNode* p = root;
        while(!s.empty())
        {
            while(p && p->left)
            {
                s.push(p->left);
                p = p->left;
            }
            
            p = s.top();
            ret.push_back(p->val);
            s.pop();
            p = p->right;
            if(p)
                s.push(p);
        }
        return ret;
    }
};
