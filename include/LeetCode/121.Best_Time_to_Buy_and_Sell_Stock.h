/*
121. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
Tags:Array Dynamic Programming
Similar Problems:(M) Maximum Subarray (M) Best Time to Buy and Sell Stock II (H) Best Time to Buy and Sell Stock III (H) Best Time to Buy and Sell Stock IV (M) Best Time to Buy and Sell Stock with Cooldown
*/
/*
分析：此题就是选择买入卖出股票的最大收益，对于第i天卖出的最大收益即为第i天的股市价格减去[0,i-1]天内的最小股市价格，当第i天的股市价格比前面最低股市价格还低，则更新最低股市价格。然后取最大的股市收益，为DP问题。
用profit[i]表示第i天的收益，则minBuyPrice = min(minBuyPrice, prices[i]),并且profit[i] = prices[i]-minBuyPrice. 
然后取profit中的最大值。
*/
#include "I_Struct.h"
class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.empty())
		{
			return 0;
		}
		int iMinPrices = prices[0]; // 用于记录当前天买进的最小值
		int iRet = 0;
		for (int i=1; i<prices.size(); i++)
		{
			if (iMinPrices > prices[i])
			{
				iMinPrices = prices[i];
			}

			if (iRet < prices[i] - iMinPrices)// 全局最大利益是否小于当天的利益
			{
				iRet = prices[i] - iMinPrices;
			}
		}
		return iRet;
	}
};