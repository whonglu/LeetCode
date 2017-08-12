/*
110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
Subscribe to see which companies asked this question
Tags: Tree, Depth-first Search
Similar Problems: (E) Maximum Depth of Binary Tree
*/
#include "I_Struct.h"
class Solution {
public:
    bool isBalanced(TreeNode* root) 
	{
        if (NULL == root)
        {
			return true;
        }
		int ld = getBinaryDepth(root->left);
		int rd = getBinaryDepth(root->right);
		if (ld-rd>1 || rd-ld>1)
		{
			return false;
		}
		else
		{
			return isBalanced(root->left) && isBalanced(root->right);
		}
    }
private:
	int getBinaryDepth(TreeNode* root)
	{
		if (NULL == root)
		{
			return 0;
		}
		int ld = 1 + getBinaryDepth(root->left);
		int rd = 1 + getBinaryDepth(root->right);
		return ld > rd ? ld : rd;
	}
};

