/*
242. Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
Note:
You may assume the string contains only lowercase alphabets.
Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
Subscribe to see which companies asked this question
Tags£º Hash Table Sort
Similar Problems£º (M) Group Anagrams (E) Palindrome Permutation
*/
#include "I_Struct.h"
class Solution {
public:
	bool isAnagram(string s, string t) 
	{
		std::map<char, int> sMap,tMap;
		for (int i=0; i<s.size(); i++)
		{
			sMap[s[i]]++;
		}
		for (int i=0; i<t.size(); i++)
		{
			tMap[t[i]]++;
		}
		if (tMap.size() == sMap.size())
		{
			std::map<char, int>::iterator tIt=tMap.begin();
			std::map<char, int>::iterator sIt=sMap.begin();			
			for (;tIt!=tMap.end() && sIt != sMap.end(); tIt++,sIt++)
			{
				if (tIt->first == sIt->first && tIt->second == sIt->second)
				{
					continue;
				}
				else
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}
};