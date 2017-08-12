/*
404. Sum of Left Leaves
Find the sum of all left leaves in a given binary tree.
Example:
	3
   / \
  9  20
    /  \
   15   7
There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
Tags:Tree
*/
#include "I_Struct.h"
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root)
	{
		if(NULL == root)
			return 0;
		return GetLeftNum(root->left, true) + GetLeftNum(root->right, false);
	}
private:
	int GetLeftNum(TreeNode *pNode, bool bIsLeft)
	{
		if (NULL == pNode)
		{
			return 0;
		}
		if (bIsLeft)
		{
			if (NULL == pNode->right && NULL == pNode->left)
			{
				return pNode->val;
			}
		}
		else
		{
			if (NULL == pNode->right && NULL == pNode->left)
			{
				return 0;
			}
			
		}

		if (NULL == pNode->left)
		{
			return GetLeftNum(pNode->right, false);
		}
		if (NULL == pNode->right)
		{
			return GetLeftNum(pNode->left, true);
		}
		if (pNode->right && pNode->left)
		{
			return GetLeftNum(pNode->left, true) + GetLeftNum(pNode->right, false);
		}
	}
};