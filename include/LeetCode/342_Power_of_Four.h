/*
342. Power of Four
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
Example:
Given num = 16, return true. Given num = 5, return false.
Follow up: Could you solve it without loops/recursion?
Tags: Bit Manipulation
Similar Problems: (E) Power of Two (E) Power of Three
*/
class Solution {
public:
	bool isPowerOfFour_1(int num) 
	{
		while (num && (num % 4 == 0)) 
		{
			num /= 4;
		}
		return num == 1;
	}

	//public boolean isPowerOfFour(int num) {
	//	if(num<=0) return false;
	//	return (Math.log10(num)/Math.log10(4)-(int)(Math.log10(num)/Math.log10(4)))==0;
	//}

	bool isPowerOfFour_3_1(int num) 
	{
		if(num<=0) return false;
		return (num&(num-1))==0&&(num&0x55555555)==num;
	}

	bool isPowerOfFour_3_2(int num)
	{
		if(num <= 0) return false;
		if(num & (num - 1)) return false; // 先判断是否是 2 的 N 次方
		if(num & 0x55555555) return true; // 再将不是 4 的 N 次方的数字去掉
		return false;
	}

	bool isPowerOfFour_4_1(int num)
	{
		return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
	}
	bool isPowerOfFour_4_2(int num)
	{  
		if(num <= 0) return false;  
		if(num & num-1) return false;  
		return num % 3 == 1;  
	}
};

