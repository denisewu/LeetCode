//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
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
    void levelOrderHelper(vector<vector<int> >& lists, TreeNode* root, int level)
    {
        if(!root) return;
        if(level >= (int)lists.size())
        {
            vector<int> temp;
            lists.push_back(temp);
        }
            
        levelOrderHelper(lists, root->left, level + 1);
        levelOrderHelper(lists, root->right, level + 1);
        lists[level].push_back(root->val);
    }
    
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        levelOrderHelper(ret, root, 0);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
