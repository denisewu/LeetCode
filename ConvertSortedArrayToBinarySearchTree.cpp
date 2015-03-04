//Convert Sorted Array to Binary Search Tree 
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.empty())
            return NULL;
            
        int mid = (0 + num.size() - 1) / 2;
        TreeNode* root = new TreeNode(num[mid]);
        vector<int> leftArray(num.begin(), num.begin() + mid);
        vector<int> rightArray(num.begin() + mid + 1, num.end());
        
        root->left = sortedArrayToBST(leftArray);
        root->right = sortedArrayToBST(rightArray);
        return root;
    }
};
