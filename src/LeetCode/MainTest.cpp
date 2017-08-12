#include "LeetCode.h"

void main()
{
	vector<string> strs;
	strs.push_back("abcde");
	strs.push_back("");
	strs.push_back("abcede");
	strs.push_back("abcdee");
	vector<int> vInt;
	vInt.push_back(1);
	vInt.push_back(2);
	vInt.push_back(1);
	vInt.push_back(3);
	vInt.push_back(2);
	vInt.push_back(5);
	//vInt.push_back(5);

	TreeNode *p = new TreeNode(1);
	bool b = CLeetCode::GetInstance()->hasPathSum_E112(p, 0);
	int a = 0;
}






