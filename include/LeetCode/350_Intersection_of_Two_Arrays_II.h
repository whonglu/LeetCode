/*
350. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
Subscribe to see which companies asked this question
Tags£º Binary Search Hash Table Two Pointers Sort
Similar Problems£º (E) Intersection of Two Arrays
*/
#include "I_Struct.h"
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		std::vector<int> vResult;
		std::map<int, int> m1,m2;
		for (int i=0; i<nums1.size(); i++)
		{
			m1[nums1[i]]++;
		}

		for (int i=0; i<nums2.size(); i++)
		{
			if (0 != m1.count(nums2[i]))
			{
				m2[nums2[i]]++;
				m1[nums2[i]]--;
				if (0 == m1[nums2[i]])
				{
					m1.erase(nums2[i]);
				}
			}			
		}

		std::map<int, int>::iterator it = m2.begin();
		while (it != m2.end())
		{
			for (int i=0; i<it->second; i++)
			{
				vResult.push_back(it->first);
			}
			it++;
		}
		return vResult;
	}
};