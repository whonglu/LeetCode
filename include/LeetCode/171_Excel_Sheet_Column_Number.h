/*
171. Excel Sheet Column Number
Related to question Excel Sheet Column Title
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
Tags£º Math
Similar Problems£º (E) Excel Sheet Column Title
*/
#include "I_Struct.h"
class Solution {
public:
	int titleToNumber(string s)
	{
		int sum = 0;
		for (int i=0; i<s.size(); i++)
		{
			int t = s[i] - 'A' + 1;
			sum = 26*sum + t;
		}
		return sum;
	}
};