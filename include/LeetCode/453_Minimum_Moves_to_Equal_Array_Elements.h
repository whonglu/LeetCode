/*
453. Minimum Moves to Equal Array Elements
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements 
equal, where a move is incrementing n - 1 elements by 1.
Example:
Input:
[1,2,3]
Output:
3
Explanation:
Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
Tag��Math
*/

#include "I_Struct.h"
class Solution {
public:
	int minMoves_1(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int len = nums.size(), res = 0;

		for (int i = 1; i < len; i++) {
			res += nums[i] - nums[0];
		}
		return res;
	}
	int minMoves_2(vector<int> &nums)
	{  
		int sum = 0;  
		int min = INT_MAX;  
		for (int i = 0; i < nums.size(); i++){  
			if (nums[i] < min){  
				min = nums[i];  
			}  
			sum += nums[i];  
		}  
		return sum - min*nums.size();  
	} 
};
/*
����1��
Summary:
����һ������Ϊn�����������飬ÿ����n-1��Ԫ�ؼ�1����������Ҫ���ٲ�����ʹ�����е�����ȫ����ͬ��
Analysis:
��ʹ���龡��������ĿҪ������Ҫÿ�θ���ȥ���ֵ���������ּ�1�������ַ���Ч�ʹ��ͣ����Ի�һ��˼·��
ÿ�ν������е�n-1�����ּ�1���൱�ڽ�ʣ���һ�����ּ�1��
����ֻ���ҵ������е���Сֵm������m���������������ֲ���ۼƺͼ��ɡ�

����2��
�ҵĴ��룺
1�����Ȼ��˼�����������⣺����һ�������ǿ����飬ÿ��ʹ������n-1������+1��nΪ���鳤�ȣ������ټ���ʹ�������е�ÿ��������ȣ�
2����μ�Ȼѯ�����ٴ��������ǹ۲���������δﵽ���٣�ÿ��ѡ���n-1�����ܿ���ǰ���������ֵ��
3������ڴ����н�����任���м����г����㷨���Ӷȿ϶��ϴ�������������˼����Ŀ�Ķ���������ÿ�����ݱ˴���ȣ���ôÿ��ʹ������1������-1�����մﵽĿ�� �������moves��ͬ��
4��3���е�˼·����ת��Ϊ�����е�ÿ������Сֵ����Сֵ�Ĵ�������moves += ��min[i] - min��ͬ������ת��Ϊ�����sum - min*n
*/


