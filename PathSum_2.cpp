/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void pathSumDFS(TreeNode* p, int sum, vector<int> &path, vector<vector<int> > &ret)
    {
        if(p == NULL)
            return;
        path.push_back(p->val);
        if(p->left == NULL && p->right == NULL && sum == p->val)
        {
            
            ret.push_back(path);
            path.pop_back();
            return;
        }
        
        if(p->left != NULL)
            pathSumDFS(p->left, sum - p->val, path, ret);
        
        if(p->right != NULL)
            pathSumDFS(p->right, sum - p->val, path, ret);
        
        path.pop_back();
    }
    
public:
    vector<vector<int> > pathSumIterative(TreeNode *root, int sum)
    {
        vector<vector<int> > ret;
        if(root == NULL)
            return ret;
            
        stack<TreeNode*> s;
        vector<int> path;
        int pathsum = 0;
        TreeNode *p = root;
        while(!s.empty() || p != NULL)
        {
            if(p != NULL)
            {
                s.push(p);
                pathsum += p->val;
                path.push_back(p->val);
                if(p->left == NULL && p->right == NULL)
                {
                    if(pathsum == sum)
                    {
                        ret.push_back(path);
                    }
                }
                path.pop_back():
            }
            else
            {
                TreeNode *tp = s.top();
                if(tp->right != NULL)
                    p = tp->right;
                else
                {
                    s.pop();
                    pathsum -= tp->val;
                    path.pop_back();
                }
            }
        }
        return ret;
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        /*
        vector<vector<int> > ret;
        vector<int> path;
        pathSumDFS(root, sum, path, ret);
        return ret;
        */
        return pathSumIterative(root, sum);
    }
};
