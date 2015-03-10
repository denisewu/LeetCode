/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    bool isValidBSTAux(TreeNode *root, int &minInTree, int &maxInTree)
    {
        if(root == NULL)
        {
            minInTree = INT_MAX;
            maxInTree = INT_MIN;
            return true;
        }
        int leftMin, rightMin, rightMax, leftMax;
        bool leftValid = isValidBSTAux(root->left, leftMin, leftMax);
        bool rightValid = isValidBSTAux(root->right, rightMin, rightMax);
        
        minInTree = min(leftMin, rightMin);
        minInTree = min(minInTree, root->val);
        maxInTree = max(leftMax, rightMax);
        maxInTree = max(maxInTree, root->val);
        
        bool ret = leftValid && rightValid;
        
        if(root->left)
            ret = ret && (leftMax < root->val);
        
        if(root->right)
            ret = ret && (rightMin > root->val);
        return ret;
    }
    
    bool inOrder(TreeNode * root)
    {
         stack<TreeNode *> s;
        TreeNode *p = root, *prev = NULL;
        while(!s.empty() || p)
        {
            if(p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                s.pop();
                if(prev != NULL && prev->val >= p->val)
                    return false;
                prev = p;
                p = p->right;
            }
        }
        return true;
    }
    
public:
    bool isValidBST(TreeNode *root) {
        /*
        return inOrder(root); 
        */
      
        int max = INT_MIN, min = INT_MAX;
        return isValidBSTAux(root, min, max);
    }
};
