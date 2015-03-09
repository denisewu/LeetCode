/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    int maxSum;
    int maxPathSumAux(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int leftMax = maxPathSumAux(root->left);
        int rightMax = maxPathSumAux(root->right);
        
        int sum = root->val;
        if(leftMax > 0)
            sum = leftMax + sum;
        if(rightMax > 0)
            sum = rightMax + sum;
        if(sum > maxSum)
            maxSum = sum;
        
        int depthSum = root->val;
        int temp = max(leftMax, rightMax);
        depthSum = (temp < 0)? depthSum: depthSum + temp;
        return depthSum;
    }
    
public:
    int maxPathSum(TreeNode *root) {
        maxSum = INT_MIN;
        maxPathSumAux(root);
        return maxSum;
    }
};
