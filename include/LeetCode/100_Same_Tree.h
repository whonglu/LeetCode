/*
100. Same Tree
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
Subscribe to see which companies asked this question
Tags:  Tree Depth-first Search
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include "I_Struct.h"
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		if (NULL == p && NULL == q)
		{
			return true;
		}

		if (NULL != p && NULL != q)
		{
			if (p->val == q->val)
			{
				return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
			}
			else
			{
				return false;
			}
		}
		return false;
	}
#pragma region �ǵݹ鷽ʽ
	bool isSameTree_1(TreeNode *p, TreeNode *q) 
	{
		if(!isSameNode(p, q))
			return false;
		if(!p && !q)
			return true;

		queue<TreeNode*> lqueue;
		queue<TreeNode*> rqueue;
		lqueue.push(p);
		rqueue.push(q);
		while(!lqueue.empty() && !rqueue.empty())
		{
			TreeNode* lfront = lqueue.front();
			TreeNode* rfront = rqueue.front();

			lqueue.pop();
			rqueue.pop();

			if(!isSameNode(lfront->left, rfront->left))
				return false;
			if(lfront->left && rfront->left)
			{
				lqueue.push(lfront->left);
				rqueue.push(rfront->left);
			}

			if(!isSameNode(lfront->right, rfront->right))
				return false;
			if(lfront->right && rfront->right)
			{
				lqueue.push(lfront->right);
				rqueue.push(rfront->right);
			}
		}
		return true;
	}
	bool isSameNode(TreeNode* p, TreeNode *q)
	{
		if(!p && !q)
			return true;
		if((p && !q) || (!p && q) || (p->val != q->val))
			return false;
		return true;
	}
#pragma endregion
};