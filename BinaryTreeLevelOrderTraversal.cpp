//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        queue<TreeNode* > q;
        
        if(!root)
            return ret;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode *p = q.front();
            vector<int> tempv;
            while(p)
            {
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                tempv.push_back(p->val);
                q.pop();
                p = q.front();
            }
            q.pop();
            q.push(NULL);
            
            ret.push_back(tempv);
        }
        
        return ret;
    }
};
