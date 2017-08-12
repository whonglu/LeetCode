/*
104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Tags:  Tree Depth-first Search
Similar Problems:  (E) Balanced Binary Tree (E) Minimum Depth of Binary Tree
*/
#include "I_Struct.h"
class Solution {
public:
	//非递归方法(利用队列实现)
	int maxDepth(TreeNode* root) 
	{
		if (NULL == root)
		{
			return 0;
		}
		std::queue<TreeNode *> tQue;
		tQue.push(root);
		int ndepth = 0;
		while (!tQue.empty())
		{
			ndepth++;
			int nSize = tQue.size();			
			for (int i=0; i<nSize; i++)
			{
				TreeNode *pCur = tQue.front();
				tQue.pop();
				if (NULL != pCur->left)
				{
					tQue.push(pCur->left);
				}
				if (NULL != pCur->right)
				{
					tQue.push(pCur->right);
				}
			}
		}
		return ndepth;
	}
	//递归实现（运行时间超时）
	int maxDepth_1(TreeNode* root) 
	{
		if (NULL == root)
		{
			return 0;
		}
		return 1+(maxDepth(root->left)>maxDepth(root->right) ? maxDepth(root->left):maxDepth(root->right));
	}
};