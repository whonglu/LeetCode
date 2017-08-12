/*

235. Lowest Common Ancestor of a Binary Search Tree
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±

_______6______
/              \
___2__          ___8__
/      \        /      \
0      _4       7       9
/  \
3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Subscribe to see which companies asked this question

Tags£º Tree
Similar Problems£º (M) Lowest Common Ancestor of a Binary Tree
*/
#include "I_Struct.h"
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root == NULL || p == NULL || q == NULL)
		{
			return NULL;
		}

		std::stack<TreeNode *> staPath_p;
		std::stack<TreeNode *> staPath_q;
		GetBinaryTreePath(root, p, staPath_p);
		GetBinaryTreePath(root, q, staPath_q);

		int pSize = staPath_p.size();
		int qSize = staPath_q.size();

		if (pSize > qSize)
		{
			for (int i=0; i<pSize-qSize; i++)
			{
				staPath_p.pop();
			}		
		}
		else
		{
			for (int i=0; i<qSize-pSize; i++)
			{
				staPath_q.pop();
			}	

		}

		while (staPath_p.top() != staPath_q.top())
		{
			staPath_p.pop();
			staPath_q.pop();
		}
		return staPath_p.top();
	}

private:
	bool GetBinaryTreePath(TreeNode* root, TreeNode* pDesNode, std::stack<TreeNode *> &staPath)
	{
		bool bIsFind = false;
		staPath.push(root);
		if (root == pDesNode)
		{			
			return true;
		}

		if (NULL == staPath.top()->left && NULL == staPath.top()->right)
		{
			staPath.pop();
			return false;
		}

		if (NULL != root->left)
		{
			bIsFind = GetBinaryTreePath(root->left, pDesNode, staPath);
		}
		if ( NULL != root->right && !bIsFind)
		{
			bIsFind = GetBinaryTreePath(root->right, pDesNode, staPath);
		}

		if (false == bIsFind)
		{
			staPath.pop();
			return false;
		}
		else
		{
			return true;
		}
	}
};