/*
Given a binary tree, return the postorder traversal of its nodes' values.
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root == NULL)
            return ret;
        
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* prev = NULL;
        while(!s.empty())
        {
           TreeNode* p = s.top();
           if((p->left == NULL && p->right == NULL) || 
                (prev != NULL && (prev == p->left || prev == p->right)))
                {
                    ret.push_back(p->val);
                    prev = p;
                    s.pop();
                }
            else
            {
                if(p->right != NULL)
                    s.push(p->right);
                if(p->left != NULL)
                    s.push(p->left);
            }
        }
        return ret;
    }
};
