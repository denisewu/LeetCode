//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

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
    
    bool isSymmetricRec(TreeNode * root)
    {
        if(!root)
            
    }
    
    bool isSymmetric(TreeNode *root) {
       
       if(!root) return true;
       vector<TreeNode*> v;
       v.push_back(root);
       while(!v.empty())
       {
           
           for(int i = 0; i < ((int)v.size() / 2); i++)
           {
               TreeNode* lp = v[i];
               TreeNode * rp = v[v.size() - i - 1];
               if( (!lp && rp) || (lp && !rp) )
                    return false;
                if(lp && rp && lp->val != rp->val)
                    return false;
           }
           
           vector<TreeNode* > tempv;
           for(int i = 0; i < v.size(); i++)
           {
               TreeNode* p = v[i];
               if(p)
               {
                   tempv.push_back(p->left);
                   tempv.push_back(p->right);
               }
           }
           v = tempv;
       }
       return true;
    }
};
