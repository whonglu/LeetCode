/*
283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
Tags:  Array Two Pointers
Similar Problems:  (E) Remove Element
*/
class Solution {
public:
	void moveZeroes(vector<int>& nums)
	{
		//思路一：类似冒泡法
		for (size_t i=0; i<nums.size(); i++)
		{
			if (0 == nums[i])
			{
				for (size_t j=i+1; j<nums.size(); j++)
				{
					if (0!=nums[j])
					{
						nums[i] = nums[j];
						nums[j] = 0;
						break;
					}
				}
			}
		}

		/* 思路二
		for (int i = 0, j = 0; i < nums.size(); i++) 
		{
			if (nums[i] != 0) 
			{
				if (i != j) 
				{
					nums[j] = nums[i];
					nums[i] = 0;
				}
				j++;
			}
		}
		*/
	}
};
