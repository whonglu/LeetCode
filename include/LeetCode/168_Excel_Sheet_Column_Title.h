/*
168. Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:

1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB 
Tags: Math
Similar Problems: (E) Excel Sheet Column Number
*/
class Solution {
public:
	string convertToTitle(int n)
	{
        string ret = "";
        while(n)
        {
            ret = (char)((n-1)%26+'A') + ret;
            n = (n-1)/26;
        }
        return ret;
    }
};
//学习如何将整数 转换成 字符