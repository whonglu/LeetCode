/*
102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]

Tags:Tree Breadth-first Search
Similar Problems: (M) Binary Tree Zigzag Level Order Traversal (E) Binary Tree Level Order Traversal II (E) Minimum Depth of Binary Tree (M) Binary Tree Vertical Order Traversal

*/
#include "I_Struct.h"
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) 
	{
		vector<vector<int>> vResult;
		if (!root)
		{
			return vResult;
		}

		queue<TreeNode *> qTree;
		qTree.push(root);
		while (!qTree.empty())
		{
			vector<int> vLevel;
			int qSize = qTree.size();
			for (int i=0; i<qSize; i++)
			{
				vLevel.push_back(qTree.front()->val);
				if (NULL != qTree.front()->left)
				{
					qTree.push(qTree.front()->left);
				}
				if (NULL != qTree.front()->right)
				{
					qTree.push(qTree.front()->right);
				}
				qTree.pop();
			}
			vResult.push_back(vLevel);
		}
		return vResult;
	}
};