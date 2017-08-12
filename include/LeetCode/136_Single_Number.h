/*
136. Single Number
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
Tags: Hash Table Bit Manipulation
Similar Problems: (M) Single Number II (M) Single Number III (M) Missing Number (H) Find the Duplicate Number (E) Find the Difference
*/
#include "I_Struct.h"
class Solution {
public:
	int singleNumber(vector<int>& nums) 
	{
		if (0 == nums.size())
		{
			return 0;
		}

		int n = nums[0];
		for (int i=1; i<nums.size(); i++)
		{
			n = n ^ nums[i];
		}
		return n;
	}
};