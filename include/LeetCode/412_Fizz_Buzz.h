/*
412. Fizz Buzz
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output ¡°Fizz¡± instead of the number and for the multiples of five output ¡°Buzz¡±. For numbers which are multiples of both three and five output ¡°FizzBuzz¡±.
Example:
n = 15,
Return:
[
"1",
"2",
"Fizz",
"4",
"Buzz",
"Fizz",
"7",
"8",
"Fizz",
"Buzz",
"11",
"Fizz",
"13",
"14",
"FizzBuzz"
]
*/
#include "I_Struct.h"
class Solution {
public:
	vector<string> fizzBuzz(int n) 
	{
		vector<string> vResult;
		for (int i=1,iTir=1,iFive=1; i<=n; i++,iTir++,iFive++)
		{
			if (0 == iTir%3 && 0 == iFive%5)
			{
				vResult.push_back("FizzBuzz");
				iTir = 0;
				iFive = 0;
			}
			else if (0 == iTir%3)
			{
				vResult.push_back("Fizz");
				iTir = 0;
			}
			else if (0 == iFive%5)
			{
				vResult.push_back("Buzz");
				iFive = 0;
			}
			else
			{
				string strVal = std::to_string(i);
				vResult.push_back(strVal);
			}
		}
		return vResult;
	}
};
