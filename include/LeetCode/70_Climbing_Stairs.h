/*
70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Tags£ºDynamic Programming
*/
class Solution 
{
	//f(1) = 1;
	//f(2) = 2;
	//f(3) = f(2) + f(1);
public:
	//µÝ¹é
	int climbStairs_recur(int n)
	{
		if (1 == n)
		{
			return  1;
		}
		else if (2 == n)
		{
			return 2;
		}
		else
		{
			return climbStairs_recur(n-2) + climbStairs_recur(n-1);
		}
	}
	//Ñ­»·
	int climbStairs_loop(int n)
	{
		if (1 == n)
		{
			return  1;
		}
		else if (2 == n)
		{
			return 2;
		}

		int cur = 2;
		int last = 1;
		for (int i=3; i<=n; i++)
		{
			int t =  last + cur;
			last = cur;
			cur = t;
		}
		return cur;		
	}
};