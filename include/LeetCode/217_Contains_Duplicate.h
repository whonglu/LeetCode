/*

217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Subscribe to see which companies asked this question

Tags£º Array Hash Table
Similar Problems£º (E) Contains Duplicate II (M) Contains Duplicate III
*/
#include "I_Struct.h"
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) 
	{
		std::map<int, bool> tMap;
		for (int i=0; i<nums.size(); i++)
		{
			if (0 == tMap.count(nums[i]))
			{
				tMap[nums[i]] = true;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};