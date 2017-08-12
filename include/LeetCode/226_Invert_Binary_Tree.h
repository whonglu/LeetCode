/*
226. Invert Binary Tree
Invert a binary tree.
4
/   \
2     7
/ \   / \
1   3 6   9
to
4
/   \
7     2
/ \   / \
9   6 3   1
Tag: Tree
*/
//Definition for a binary tree node.
#include "I_Struct.h"
class Solution 
{
public:
	TreeNode* invertTree(TreeNode* root)//递归实现
	{
		if (NULL == root)
		{
			return root;
		}
		if (NULL != root->left && NULL != root->right)
		{
			TreeNode *pt = root->right;
			root->right = root->left;
			root->left = pt;
			invertTree(root->left);
			invertTree(root->right);
			return root;
		}
	}
	TreeNode* invertTree2(TreeNode* root)//递归实现
	{
		if (NULL == root)
		{
			return root;
		} 
		TreeNode *pt = root->left;  
		root->left = invertTree2(root->right);  
		root->right = invertTree2(pt);  
		return root; 
	}
	TreeNode* invertTree3(TreeNode* root)//非递归方式：利用栈实现
	{
		if(NULL == root) 
		{
			return NULL;
		}
		std::stack<TreeNode *> tSta;
		tSta.push(root);
		while (!tSta.empty())
		{			
			TreeNode *pCur = tSta.top();
			tSta.pop();
			TreeNode *pt = pCur->left;
			pCur->left = pCur->right;
			pCur->right = pt;
			if (NULL != pCur->left)
			{
				tSta.push(pCur->left);
			}
			if (NULL != pCur->right)
			{
				tSta.push(pCur->right);
			}			
		}
		return root;  
	}
};