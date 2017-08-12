/*
415. Add Strings
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.
Note:
1. The length of both num1 and num2 is < 5100.
2. Both num1 and num2 contains only digits 0-9.
3. Both num1 and num2 does not contain any leading zero.
4. You must not use any built-in BigInteger library or convert the inputs to integer directly.
Tags: Math
Similar Problems: (M) Add Two Numbers (M) Multiply Strings
*/
#include "I_Struct.h"
class Solution {
public:
	string addStrings(string num1, string num2)
	{
		if (num1.empty())
		{
			return num2;
		}
		if (num2.empty())
		{
			return num1;
		}
		int len1 = num1.length()-1;
		int len2 = num2.length()-1;
		string strResult;
		int iCarry = 0;//进位
		for (; len1>=0 && len2>=0; len1--, len2--)
		{
			int iCurBitSum = (num1[len1] - '0') + (num2[len2] - '0') + iCarry;
			iCarry = iCurBitSum / 10;
			int iCurBit = iCurBitSum % 10;

			string strVal;
			stringstream ss;//#include <sstream> 
			ss << iCurBit;
			strResult = ss.str() + strResult;
			//strResult = std::to_string(_LONGLONG(iCurBit)) + strResult;
		}
		if (len1<0 && len2<0)
		{
			if (1 == iCarry)
			{
				return "1" + strResult;
			}
			return strResult;
		}
		if (len1<0)
		{
			if (0 == iCarry)
			{
				return num2.substr(0, len2+1) + strResult;
			}
			stringstream ss;//#include <sstream> 
			ss << iCarry;
			num1 = ss.str();//std::to_string(_LONGLONG(iCarry));
			num2 = num2.substr(0, len2+1);
			return addStrings(num1, num2) + strResult;
		}

		if (len2<0 )
		{
			if (0 == iCarry)
			{
				return num1.substr(0, len1+1) + strResult;
			}
			num1 = num1.substr(0, len1+1);
			stringstream ss;//#include <sstream> 
			ss << iCarry;
			num2 = ss.str();//std::to_string(_LONGLONG(iCarry));
			return addStrings(num1, num2) + strResult;
		}
	}

	string addStrings_2(string num1, string num2)
	{
		string strResult;
		int iLen1 = num1.length();
		int iLen2 = num2.length();
		int carry = 0;

		for (int i = iLen1 - 1, j = iLen2 - 1; i >= 0 || j >= 0; --i, --j)
		{
			int temp = 0;
			if (i >= 0)//特色1：
			{
				temp += num1[i] - '0';
			}
			if (j >= 0)
			{
				temp += num2[j] - '0';
			}
			if (carry)//特色2；
			{
				++temp;
			}
			carry = temp / 10;
			temp = temp % 10;

			strResult = char(temp + '0') + strResult;//特色3：字符型char 可以 与 字符串型string 进行加法运算
		}
		if (carry)
		{
			strResult = char(carry + '0') + strResult;
		}

		return strResult;
	}
};