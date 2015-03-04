//Construct Binary Tree from Inorder and Postorder Traversal 
/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode *buildTreeAux(vector<int> &inorder, int l1, int r1,
                            vector<int> &postorder, int l2, int r2)
    {
        int len = r1 - l1 + 1;
        
        if(len <= 0)
           return NULL;
           
        if(len == 1)
        {
            TreeNode* root = new TreeNode(inorder[l1]);
            return root;
        }
        
        int rootval = postorder[r2];
        TreeNode* root = new TreeNode(rootval);
        int mid = l1;
        for(; mid < r1 + 1; mid++)
        {
            if(inorder[mid] == rootval)
                break;
        }
        int leftlen = mid - l1;
        int rightlen = r1 - mid;
        
        if(leftlen > 0)
            root->left = buildTreeAux(inorder, l1, mid - 1, postorder, l2, l2 + leftlen - 1);
        
        if(rightlen > 0)
            root->right = buildTreeAux(inorder, mid + 1, r1, postorder, l2 + leftlen, r2 - 1);
        
        return root;
    }
    
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            int len = postorder.size();
            TreeNode * root = buildTreeAux(inorder, 0, len - 1, postorder,  0, len - 1);
            return root;
    }
};
