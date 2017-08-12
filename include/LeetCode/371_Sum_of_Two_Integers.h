/*
371. Sum of Two Integers
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
Example:
Given a = 1 and b = 2, return 3.
Tags£ºBit Manipulation
Similar Problems£º (M) Add Two Numbers
*/
class Solution {
public:
	int getSum(int a, int b) 
	{
		while (b)
		{
			int sum = a ^ b;
			int carray = (a & b) << 1;
			a = sum; 
			b = carray;
		}
		return a;
	}
};
