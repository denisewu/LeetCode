//Given a binary tree, flatten it to a linked list in-place.
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
    TreeNode * prev;
   void preOrder(TreeNode * root)
   {
        if(root == NULL)
            return ;
        if(prev != NULL)
        {
            prev->right = root;
            prev->left = NULL;
        }
        prev = root;
        TreeNode* l = root->left, *r = root->right;
        preOrder(l);
        preOrder(r);
   }
   
   void flatternInterative(TreeNode * root)
   {
        if(root == NULL)
            return ;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode * prev = NULL;
        while(!s.empty())
        {
            TreeNode* p = s.top();
            if(prev != NULL)
            {
                prev->right = p;
                prev->left = NULL;
            }
            prev = p;
            s.pop();
            if(p->right) s.push(p->right);
            if(p->left) s.push(p->left);
        }
   }
   
public:
    void flatten(TreeNode *root) {
        prev = NULL;
        preOrder(root);
    }
       
};
