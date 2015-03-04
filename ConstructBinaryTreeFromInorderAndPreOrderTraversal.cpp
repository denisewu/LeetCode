/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTreeAux(vector<int> &preorder, int l1, int r1,
                            vector<int> &inorder, int l2, int r2)
    {
        int len = r1 - l1 + 1;
        if(len <= 0)
            return NULL;
        if(len == 1)
        {
            TreeNode *root = new TreeNode(preorder[l1]);
            return root;
        }
        
        int rootval = preorder[l1];
        TreeNode *root = new TreeNode(rootval);
        
        int mid = l2;
        for(; mid < r2 + 1; mid++)
        {
            if(inorder[mid] == rootval)
                break;
        }
        int leftlen = mid - l2;
        int rightlen = r2 - mid;
        if(leftlen > 0)
            root->left = buildTreeAux(preorder, l1 + 1, l1 + leftlen, inorder, l2, mid - 1);
        
        if(rightlen > 0)
            root->right = buildTreeAux(preorder, l1 + leftlen + 1, r1, inorder, mid + 1, r2);
        
        return root;
    }
    
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int len = preorder.size();
        return buildTreeAux(preorder, 0, len - 1, inorder, 0, len - 1);
    }
};
