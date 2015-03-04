/*
Given a binary tree
opulate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeLinkNode *prev = NULL;
            queue<TreeLinkNode*> tempq;
            while(!q.empty())
            {
                TreeLinkNode * p = q.front();
                if(prev != NULL)
                {
                    prev->next = p;
                }
                prev = p;
                q.pop();
                if(p->left) tempq.push(p->left);
                if(p->right) tempq.push(p->right);
            }
            
            q = tempq;
        }
    }
};
