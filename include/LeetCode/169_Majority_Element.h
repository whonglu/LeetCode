/*
169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
Tags: Array Divide and Conquer Bit Manipulation
Similar Problems： (M) Majority Element II
*/
class Solution {
public:
	int majorityElement(vector<int>& nums) 
	{
		int lastNum = nums[0];
		int count = 0;
		for (int i=0; i<nums.size(); i++)
		{
			if (lastNum == nums[i])
			{
				count++;
			}
			else
			{
				count--;
				if (0 == count)
				{
					lastNum = nums[i];
					count++;
				}
			}			
		}
		return lastNum;
	}
};