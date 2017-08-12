/*
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
Note that 1 is typically treated as an ugly number.
Tags: Math
Similar Problems: (E) Happy Number (E) Count Primes (M) Ugly Number II
*/
class Solution {
public:
	bool isUgly(int num) 
	{
		if (num <= 0)
		{
			return false;
		}
		while (0 == num%2)
		{
			num = num/2;
		}
		while (0 == num%3)
		{
			num = num/3;
		}
		while (0 == num%5)
		{
			num = num/5;
		}
		if (1 == num)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};