/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        stack<TreeNode* > s;
        if(root == NULL)
            return ret;
        bool dir = true; // from left
        s.push(root);
        
        while(!s.empty())
        {
            vector<int> row;
            stack<TreeNode *> ts;
            while(!s.empty())
            {
                TreeNode * p = s.top();
                row.push_back(p->val);
                if(dir)
                {
                    if(p->left) ts.push(p->left);
                    if(p->right) ts.push(p->right);
                }
                else
                {
                    if(p->right) ts.push(p->right);
                    if(p->left) ts.push(p->left);
                }
                s.pop();
            }
            dir = dir? false: true;
            ret.push_back(row);
            s = ts;
        }
        return ret;
    }
};
