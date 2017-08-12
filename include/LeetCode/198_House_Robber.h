/*
198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
Tags: Dynamic Programming
Similar Problems: (M) Maximum Product Subarray (M) House Robber II (M) Paint House (E) Paint Fence (M) House Robber III
*/
#include "I_Struct.h"
class Solution {
public:
	int rob(vector<int>& nums)
	{
		int vSize = nums.size();
		if (0 == vSize)
		{
			return 0;
		}
		int Rob_last = 0;
		int UnRob_last = 0;	
		int Rob = 0;
		int UnRob = 0;

		for (int i=0; i<vSize; i++)
		{
			Rob = nums[i] + UnRob_last;
			UnRob = Rob_last > UnRob_last ? Rob_last : UnRob_last;

			UnRob_last = UnRob;
			Rob_last = Rob;
		}

		return Rob > UnRob ? Rob : UnRob;
	}
};