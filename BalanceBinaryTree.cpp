/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    int isBalancedAux(TreeNode * root, int& depth)
    {
       if(root == NULL)
       {
            depth = 0;
            return true;
       }
        int leftDepth, rightDepth;
        bool leftBalance = isBalancedAux(root->left, leftDepth);
        bool rightBalance = isBalancedAux(root->right, rightDepth);
        depth = max(leftDepth, rightDepth) + 1;
        if(leftBalance && rightBalance && abs(leftDepth - rightDepth) <= 1)
            return true;
        else
            return false;
    }
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalancedAux(root, depth);
    }
};
