/*
409. Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1,010.
Example:
Input:
"abccccdd"
Output:
7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
Tag: Hash Table
Similar Problems: (E) Palindrome Permutation
*/
#include "I_Struct.h"
class Solution {
public:
	int longestPalindrome(string s) 
	{
		std::map<char, int> ch2num;
		for (int i=0; i<s.length(); i++)
		{
			ch2num[s[i]]++;
		}

		std::map<char, int>::iterator it = ch2num.begin();
		std::map<char, int>::iterator itEnd = ch2num.end();
		int num = 0;
		bool bIsFindSig = false;
		while (it != itEnd)
		{
			if (0 == it->second % 2)
			{
				num += it->second;
			}
			else
			{
				num += it->second - 1;
				bIsFindSig = true;
			}
			it++;
		}
		if (bIsFindSig)
		{
			return num + 1;
		}
		return num;
	}
};
/*
给定一个字符串包含大小写，用字符串中的字符组成一个回文串求符合要求的回文串的最大长度，
思路：统计字符串中每个字符出现的次数 再进行处理
刚开始错误：遍历字符串中字符出现的次数，偶数次的直接加进去，奇数次的加最大的。  奇数次的可以去掉一个变成偶数次然后加进去，如 aaaba可以变成abba
*/