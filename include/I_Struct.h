#pragma once
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <stdint.h>
#include <string>
#include <bitset>
#include <sstream>
#include <stdint.h>
using namespace std;
using std::bitset;
struct TreeNode {
	int m_nVal;
	TreeNode *m_pLeft;
	TreeNode *m_pRight;
	TreeNode(int x) : m_nVal(x), m_pLeft(NULL), m_pRight(NULL) 
	{
	}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};