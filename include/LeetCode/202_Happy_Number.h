/*
202. Happy Number
Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
Example: 19 is a happy number
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Tags: Hash Table Math
Similar Problems: (E) Add Digits (E) Ugly Number
*/
#include "I_Struct.h"
class Solution {
public:
	bool isHappy(int n) 
	{
		std::set<int> tSet;
		tSet.insert(n);
		while (true)
		{
			int t = Sum(n);
			if (t == 1)
			{
				return true;
			}
			if (0 != tSet.count(t))
			{
				return false;
			}
			tSet.insert(t);
			n = t;
		}
	}
	int Sum(int n)
	{
		int sum = 0;
		while (0 != n)
		{
			int t = n%10;
			n = n/10;
			sum += t*t;
		}
		return sum;
	}
};