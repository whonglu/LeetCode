/*
101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

1
/ \
2   2
/ \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
1
/ \
2   2
\   \
3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
Tags: Tree Depth-first Search Breadth-first Search

*/
#include "I_Struct.h"
class Solution {
public:
	bool isSymmetric(TreeNode* root) 
	{
		if (!root)
		{
			return true;
		}
		if (NULL != root->left && NULL != root->right)
		{
			return isSymme(root->left, root->right);
		}
		else if (NULL == root->left && NULL == root->right)
		{
			return true;
		}
		else
		{
			return false;	
		}
	}
private:
	bool isSymme(TreeNode* lh, TreeNode* rh)
	{
		if (NULL == lh && NULL == rh)
		{
			return true;
		}
		else if (NULL != lh && NULL != rh)
		{
			if (lh->val != rh->val)
			{
				return false;
			}
			else
			{
				return isSymme(lh->left, rh->right) && isSymme(lh->right, rh->left);
			}
		}
		else
		{
			return false;
		}		
	}
};