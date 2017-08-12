/*
349. Intersection of Two Arrays
	Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
Note:
Each element in the result must be unique.
The result can be in any order.
Tags:  Binary Search Hash Table Two Pointers Sort
Similar Problems:  (E) Intersection of Two Arrays II
*/
//349. Intersection of Two Arrays
#include "I_Struct.h"
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
	{
		std::vector<int> tVec;
		if (nums1.empty() || nums2.empty())
		{
			return tVec;
		}
		std::set<int> tSet;
		std::set<int> tResultSet;
		for (int i=0; i<nums1.size(); i++)
		{
			tSet.insert(nums1.at(i));
		}
		for (int i=0; i<nums2.size(); i++)
		{
			if (tSet.find(nums2.at(i)) != tSet.end())
			{
				tResultSet.insert(nums2.at(i));
			}
		}
		std::set<int>::iterator it; 
		for(it = tResultSet.begin(); it != tResultSet.end(); it++)  
		{  
			tVec.push_back(*it); 
		}  
		return tVec;		
	}
};