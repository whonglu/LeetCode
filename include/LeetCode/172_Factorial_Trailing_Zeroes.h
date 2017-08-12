/*
172. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
Tags: Math
Similar Problems: (H) Number of Digit One
*/
class Solution {
public:
	int trailingZeroes(int n) 
	{ 
		if(n < 1) 
		{
			return 0;
		}
		int nCount = 0;
		while (0 != n/5)
		{
			n = n/5;
			nCount = nCount + n;
		}
		return nCount;
	}
};