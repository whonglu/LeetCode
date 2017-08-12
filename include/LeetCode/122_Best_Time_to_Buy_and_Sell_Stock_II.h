/*
122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Tags:Array Greedy
Similar Problems: (E) Best Time to Buy and Sell Stock (H) Best Time to Buy and Sell Stock III (H) Best Time to Buy and Sell Stock IV (M) Best Time to Buy and Sell Stock with Cooldown
*/
#include "I_Struct.h"
class Solution {
public:
	int maxProfit_Method1(vector<int>& prices) 
	{
		if (prices.empty())
		{
			return 0;
		}
		int sumPro = 0;
		for (int i=1; i<prices.size(); i++)
		{
			if (prices[i-1] < prices[i] )
			{
				sumPro += prices[i] - prices[i-1];
			}
		}
		return sumPro;
	}
	int maxProfit_Method2(vector<int> &prices)
	{
		if (prices.empty())
		{
			return 0;
		}
		int vSize = prices.size();
		int minBuyPrice = prices[0];
		int sumResult = 0;
		for(int i = 1; i < vSize; i++)
		{
			if(prices[i] < prices[i-1])//特色1.i的初始值为1，以避免数组越界
			{// 在i处有一个局部最优,所有的局部最优和就是全局最优
				sumResult += prices[i-1]- minBuyPrice;
				minBuyPrice = prices[i];
			}
		}
		sumResult += prices[vSize-1]- minBuyPrice;
		return sumResult;
	}
};