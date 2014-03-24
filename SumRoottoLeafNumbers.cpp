/** * Definition for binary tree * struct TreeNode { *     int val; *     TreeNode *left; *     TreeNode *right; *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} * }; */
class Solution {
	private:
		int sumNumbersCore(TreeNode *root, int sum)
		{
			if(root == NULL)
			{
				return 0;
			}
			if (root->left == NULL && root->right == NULL)
			{
				return sum * 10 + root->val;
			}
			else
			{
				return sumNumbersCore(root->left, sum*10 + root->val)
						+
						sumNumversCore(root->right, sum*10 + root->val);
			}
		
		}
	public:    
		int sumNumbers(TreeNode *root) 
		{
			return sumNumbersCore(root, 0);
		}
		
};
