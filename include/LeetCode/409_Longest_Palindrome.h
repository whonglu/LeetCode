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
����һ���ַ���������Сд�����ַ����е��ַ����һ�����Ĵ������Ҫ��Ļ��Ĵ�����󳤶ȣ�
˼·��ͳ���ַ�����ÿ���ַ����ֵĴ��� �ٽ��д���
�տ�ʼ���󣺱����ַ������ַ����ֵĴ�����ż���ε�ֱ�Ӽӽ�ȥ�������εļ����ġ�  �����εĿ���ȥ��һ�����ż����Ȼ��ӽ�ȥ���� aaaba���Ա��abba
*/