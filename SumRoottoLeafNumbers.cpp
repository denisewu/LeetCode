/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.
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
    void sumNumbersAux(TreeNode* root, int pathSum, int& total)
    {
        if(root == NULL)
            return;
        if(!root->left && !root->right)
        {
            pathSum = pathSum * 10 + root->val;
            total += pathSum;
            return;
        }
        sumNumbersAux(root->left, pathSum * 10 + root->val, total);
        sumNumbersAux(root->right, pathSum * 10 + root->val, total);
    }
public:
    int sumNumbersRecursive(TreeNode * root)
    {
       int total = 0;
       sumNumbersAux(root, 0, total);
       return total;
    }
    
    int sumNumbers(TreeNode *root) {
       stack<TreeNode* > s;
       stack<int> s2;
       int total = 0;
       if(root == NULL)
            return 0;
       s.push(root);
       s2.push(root->val);
       while(!s.empty())
       {
           TreeNode * p = s.top();
           int sum = s2.top();
           s.pop();
           s2.pop();
           if(!p->left && !p->right)
           {
               total += sum;
           }
           if(p->right)
            {
                s.push(p->right);
                s2.push(sum * 10 + p->right->val);
            }
            if(p->left)
            {
                s.push(p->left);
                s2.push(sum * 10 + p->left->val);
            }
       }
       return total;
    }
};
