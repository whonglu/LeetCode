/*
9. Palindrome Number
Determine whether an integer is a palindrome. Do this without extra space.
click to show spoilers.
Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.
Tags: Math
Similar Problems: (E) Palindrome Linked List
*/
class Solution {
public:
	bool isPalindrome(int x)
	{
		if (x < 0)
		{
			return false;
		}

		int len = 1;
		for (; (x/len) >= 10; len *= 10);

		while (0 != x) 
		{
			int left = x / len;
			int right = x % 10;

			if(left != right)
			{
				return false;
			}

			x = (x%len) / 10;
			len /= 100;
		}
		return true;
	}
};