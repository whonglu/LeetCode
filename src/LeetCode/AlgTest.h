#pragma once
#include "I_Struct.h"
class CAlgTest
{
public:
	CAlgTest(void);
	~CAlgTest(void);
	static CAlgTest* GetInstance();
private:
	static CAlgTest* m_pAlgTest;
	static TreeNode* m_pBtTree;
public:
	TreeNode* GetBinaryTreeObj();
	ListNode* GetListNodeObj();
public:
	//和为sum的所有路径（无需起于根节点或止于叶节点）

	int Dfs(TreeNode* root, int sum);	//提取二叉树的所有路径

	//按层次遍历，自下而上，自左向右，输出各层次节点(循环or迭代)
	vector<vector<int>> levelOrderBottom_107(TreeNode *root);

	//求二叉树的最小深度
	int minDeepth_111(TreeNode *root);

	//判断是否是平衡二叉树
	bool isBalanced_110(TreeNode *root);
	int Strstr_28(string haystack, string needle);

	vector<vector<int>> palindromepairs_336(vector<string> &words);

	//独立题目
	string GetHint_E299(string secret, string gues);
	string CountAndSay_E38(int n);

	//字符串
	bool WordPattern_E290(string Pattrn, string str);
	bool isIsomorphic_E205(string s, string t);

	bool isAnagram_E240(string s, string t);
	vector<int> findAnagrams_E438(string s, string p);

	//链表
	ListNode *ReverseList_E206_XH(ListNode *head);
	bool isPalindrome_125(string s);
	bool isPalindrome_9(int x);
	bool isPalindrome_234(ListNode *head);

#pragma region 二分查找
	int guess_E374(int num){return 0;};
	int guessNumber_E374(int n);
#pragma endregion
	
	//按格式输出字符串
	string convert_E6(string s, int numRows);

#pragma region 按条件移除指定元素
	int removeElement_E27(vector<int> &nums, int Val);
	int removeDuplicates_E26(vector<int> &nums);
	ListNode *removeElements_E203(ListNode *head, int val);
	void deleteNode_E237(ListNode *node);
	void moveZeros_E283(vector<int> &nums);
#pragma endregion
	

	vector<int> maxSlidingWindow_H239(vector<int> &nums, int k);
	int minSubArrayLen_209(int s, vector<int> &nums);

#pragma region 位操作
	unsigned int reversebits_E190(unsigned int n);
	int hammingWeight_E191(unsigned int n);
	int hammingDistance_E461(int x, int y);
	int totalHammingDistance_M477(vector<int> &nums);
#pragma endregion
};

class MinStack_E155
{
public:
	MinStack_E155(){}
	void push(int x)
	{
		m_vMyStack.push_back(x);
		if (m_vMyMinStack.empty())
		{
			m_vMyMinStack.push_back(x);
		}
		else
		{
			int iCurMin = m_vMyMinStack[m_vMyMinStack.size() - 1];
			if (x < iCurMin)
			{
				iCurMin = x;
			}
			m_vMyMinStack.push_back(iCurMin);
		}
		
	}
	void pop()
	{
		m_vMyStack.pop_back();
		m_vMyMinStack.pop_back();
	}
	int top()
	{
		if (m_vMyStack.empty())
		{
			return -1;
		}
		return m_vMyStack.back();//m_vMyStack[m_vMyStack.size() - 1];
	}
	int GetMin()
	{
		if (m_vMyMinStack.empty())
		{
			return -1;
		}
		return m_vMyStack.back();//m_vMyMinStack[m_vMyMinStack.size() - 1];
	}
private:
	vector<int> m_vMyStack;
	vector<int> m_vMyMinStack;


};