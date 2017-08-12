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
�������������ѡ������������Ʊ��������棬���ڵ�i��������������漴Ϊ��i��Ĺ��м۸��ȥ[0,i-1]���ڵ���С���м۸񣬵���i��Ĺ��м۸��ǰ����͹��м۸񻹵ͣ��������͹��м۸�Ȼ��ȡ���Ĺ������棬ΪDP���⡣
��profit[i]��ʾ��i������棬��minBuyPrice = min(minBuyPrice, prices[i]),����profit[i] = prices[i]-minBuyPrice. 
Ȼ��ȡprofit�е����ֵ��
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
		int iMinPrices = prices[0]; // ���ڼ�¼��ǰ���������Сֵ
		int iRet = 0;
		for (int i=1; i<prices.size(); i++)
		{
			if (iMinPrices > prices[i])
			{
				iMinPrices = prices[i];
			}

			if (iRet < prices[i] - iMinPrices)// ȫ����������Ƿ�С�ڵ��������
			{
				iRet = prices[i] - iMinPrices;
			}
		}
		return iRet;
	}
};