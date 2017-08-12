/*
26. Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
Tags�� Array Two Pointers
Similar Problems�� (E) Remove Element
*/
#include "I_Struct.h"
class Solution {
public:
	int removeDuplicates(vector<int>& nums)
	{
		int vSize = nums.size();
		if (vSize <= 1)
		{
			return vSize;
		}
		int len = 1;
		for (int i=1; i<vSize; i++)
		{
			if (nums[i] != nums[i-1])
			{
				nums[len] = nums[i];
				len++;
			}
		}
		return len;
	}
};