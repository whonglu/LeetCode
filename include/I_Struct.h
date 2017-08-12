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
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};