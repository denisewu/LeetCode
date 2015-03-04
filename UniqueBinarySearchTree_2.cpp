/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    
    vector<TreeNode *> generateTreesAux(int low, int high)
    {
        vector<TreeNode* > ret;
        if(low >= high)
        {
            ret.push_back(NULL);
            return ret;
        }
        
       for(int i = low; i < high; i++)
       {
           
           vector<TreeNode*> leftTrees = generateTreesAux(low, i);
           vector<TreeNode*> rightTrees = generateTreesAux(i + 1, high);
           for(int j = 0; j < leftTrees.size(); j++)
                for(int k = 0; k < rightTrees.size(); k++)
                {
                    TreeNode * root = new TreeNode(i);
                    root->left = leftTrees[j];
                    root->right = rightTrees[k];
                    ret.push_back(root);
                }
       }
       return ret;
    }
    
public:
    vector<TreeNode *> generateTrees(int n) {
       
        return generateTreesAux(1, n + 1);
    }
};
