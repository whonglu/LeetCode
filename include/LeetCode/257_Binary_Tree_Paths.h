/*
257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.
For example, given the following binary tree:
	1
  /   \
 2     3
  \
   5
All root-to-leaf paths are:
["1->2->5", "1->3"]
Tags: Tree Depth-first Search
Similar Problems: (M) Path Sum II
*/
#include "I_Struct.h"
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) 
	{
		vector<string> vPath;
		if (!root)
		{
			return vPath;
		}
		vector<int> curPath;
		GetBtPath(root, curPath, vPath);
		return vPath;
	}
private:
	void GetBtPath(TreeNode *root, vector<int> &curPath,vector<string> &vPath)
	{
		curPath.push_back(root->val);
		if (!root->left && !root->right)
		{
			string path;
			for (int i=0; i<curPath.size(); i++)
			{
				int num = curPath.at(i);
				char str[255];
				sprintf(str, "%d", num); 
				string strVal(str);
				if (i != curPath.size() - 1)
				{
					path = path + strVal + "->";
				}
				else
				{
					path = path + strVal;
				}
			}
			if (!path.empty())
			{
				vPath.push_back(path);
			}
		}
		if (root->left)
		{
			GetBtPath(root->left, curPath, vPath);
		}
		if (root->right)
		{
			GetBtPath(root->right, curPath, vPath);
		}

		curPath.erase(curPath.end()-1);
	}
};