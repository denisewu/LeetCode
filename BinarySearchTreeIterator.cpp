/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
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
class BSTIterator {
    int nextnode;
    stack<TreeNode* > s;
public:
    BSTIterator(TreeNode *root) {
        TreeNode * p = root;
        while(p)
        {
            s.push(p);
            p = p->left;
        }
        if(root != NULL)
            nextnode = s.top()->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(s.empty())
            return false;
        TreeNode* p = s.top();
        nextnode = p->val;
        s.pop();
        p = p->right;
        while(p)
        {
            s.push(p);
            p = p->left;
        }
        return true;
    }

    /** @return the next smallest number */
    int next() {
        return nextnode;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
