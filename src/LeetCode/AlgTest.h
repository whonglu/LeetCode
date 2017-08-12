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
	//��Ϊsum������·�����������ڸ��ڵ��ֹ��Ҷ�ڵ㣩

	int Dfs(TreeNode* root, int sum);	//��ȡ������������·��

	//����α��������¶��ϣ��������ң��������νڵ�(ѭ��or����)
	vector<vector<int>> levelOrderBottom_107(TreeNode *root);

	//�����������С���
	int minDeepth_111(TreeNode *root);

	//�ж��Ƿ���ƽ�������
	bool isBalanced_110(TreeNode *root);
	int Strstr_28(string haystack, string needle);

	vector<vector<int>> palindromepairs_336(vector<string> &words);

	//������Ŀ
	string GetHint_E299(string secret, string gues);
	string CountAndSay_E38(int n);

	//�ַ���
	bool WordPattern_E290(string Pattrn, string str);
	bool isIsomorphic_E205(string s, string t);

	bool isAnagram_E240(string s, string t);
	vector<int> findAnagrams_E438(string s, string p);

	//����
	ListNode *ReverseList_E206_XH(ListNode *head);
	bool isPalindrome_125(string s);
	bool isPalindrome_9(int x);
	bool isPalindrome_234(ListNode *head);

#pragma region ���ֲ���
	int guess_E374(int num){return 0;};
	int guessNumber_E374(int n);
#pragma endregion
	
	//����ʽ����ַ���
	string convert_E6(string s, int numRows);

#pragma region �������Ƴ�ָ��Ԫ��
	int removeElement_E27(vector<int> &nums, int Val);
	int removeDuplicates_E26(vector<int> &nums);
	ListNode *removeElements_E203(ListNode *head, int val);
	void deleteNode_E237(ListNode *node);
	void moveZeros_E283(vector<int> &nums);
#pragma endregion
	

	vector<int> maxSlidingWindow_H239(vector<int> &nums, int k);
	int minSubArrayLen_209(int s, vector<int> &nums);

#pragma region λ����
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