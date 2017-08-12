/*
401. Binary Watch
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.
For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
Tag: Backtracking Bit Manipulation
Similar Problems: (M) Letter Combinations of a Phone Number (E) Number of 1 Bits
*/
#include "I_Struct.h"
#include <bitset>
class Solution
{
public:
	vector<string> readBinaryWatch_Method1_whl(int num)//遍历法
	{
		vector<string> vResult;
		if (num > 10 || num < 0)
		{
			return vResult;
		}
		if (0 == num)
		{
			vResult.push_back("0:00");
			return vResult;
		}

		//Step 1. 遍历所有可能的数（2的10次方）
		for (int i=1; i<1024; i++)
		{
			//Step 1. 遍历所有可能的数（2的10次方）
			int iBit = 1;
			int iCurNum = i;
			int iCount = 0;
			while (0 != iCurNum)//通过移位统计1的个数
			{
				if (iCurNum & iBit)
				{
					iCount++;
				}
				iCurNum = iCurNum >> 1;
			}

			if (iCount == num)
			{
				int iHour = i & 960;//提取小时
				iHour = iHour >> 6;

				int iMin = i & 63;//提取分钟
				if (iHour < 12 && iMin < 60)//只处理符合时间格式的数，特别注意，没有num =2时，没有12:00
				{
					stringstream ssH;
					ssH<<iHour;
					string strHour = ssH.str();//使用stringstream

					stringstream ssM;
					ssM<<iMin;
					string strMin = ssM.str();
					string strTime = strHour + ":" + (iMin < 10 ? "0":"") + strMin;
					vResult.push_back(strTime);
				}
			}
		}
		return vResult;
	}

	vector<string> readBinaryWatch_Method2(int num)//遍历法
	{
		vector<string> vResult;
		for (int iHour=0; iHour<12; iHour++)
		{
			for (int iMin=0; iMin<60; iMin++)
			{
				bitset<4> bHour((int)iHour);
				bitset<6> bMin((int)iMin);
				if (num == bHour.count() + bMin.count())
				{
					stringstream ssH;
					ssH<<iHour;
					string strHour = ssH.str();//使用stringstream

					stringstream ssM;
					ssM<<iMin;
					string strMin = ssM.str();
					string strTime = strHour + ":" + (iMin < 10 ? "0":"") + strMin;
					vResult.push_back(strTime);
				}
			}
		}
		return vResult;
	}

	vector<string> readBinaryWatch_Method3(int num);//DFS法-whl没看懂
};