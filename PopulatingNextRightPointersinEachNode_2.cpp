/*
Populating Next Right Pointers in Each Node II 
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
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
            
        queue<TreeLinkNode* > q;
        q.push(root);
        while(!q.empty())
        {
            queue<TreeLinkNode*> tempq;
            TreeLinkNode* prev = NULL;
            while(!q.empty())
            {
                TreeLinkNode* p = q.front();
                if(prev != NULL)
                    prev->next = p;
                prev = p;
                if(p->left) tempq.push(p->left);
                if(p->right) tempq.push(p->right);
                q.pop();
            }
            q = tempq;
        }
        
    }
};
