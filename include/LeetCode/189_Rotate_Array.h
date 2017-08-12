/*
189. Rotate Array
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II
Tags: Array
Similar Problems: (M) Rotate List (M) Reverse Words in a String II
*/
#include "I_Struct.h"
#include <algorithm>
class Solution {
public:
	void rotate_1(vector<int>& nums, int k) 
	{
		int vSize = nums.size();
		k = k % vSize;
		for (int i=0; i<vSize/2; i++)
		{
			int t = nums[i];
			nums[i] = nums[vSize-1-i];
			nums[vSize-1-i] = t;
		}

		for (int i=0; i<k/2; i++)
		{
			int t = nums[i];
			nums[i] = nums[k-1-i];
			nums[k-1-i] = t;
		}

		for (int i=k; i<k + (vSize-k)/2; i++)
		{
			int t = nums[i];
			nums[i] = nums[vSize-1-i+k];
			nums[vSize-1-i+k] = t;
		}
	}

	void rotate_2(vector<int>& nums, int k)//使用reverse()函数需引入#include <algorithm>
	{
		k = k % nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin()+k);
		reverse(nums.begin()+k, nums.end());
	}
};