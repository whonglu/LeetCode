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
Tag：Math
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
方法1：
Summary:
对于一个长度为n的整型数数组，每步将n-1个元素加1，求最少需要多少步，能使数组中的数字全部相同。
Analysis:
若使数组尽快满足题目要求，则需要每次给除去最大值的其余数字加1，但这种方法效率过低，可以换一种思路。
每次将数组中的n-1个数字加1，相当于将剩余的一个数字减1。
所以只需找到数组中的最小值m，计算m与数组中其他数字差的累计和即可。

方法2：
我的代码：
1）首先花了几分钟理解题意：给出一个整数非空数组，每次使得其中n-1个数字+1（n为数组长度）问最少几次使得数组中的每个数据相等？
2）其次既然询问最少次数，我们观察例子中如何达到最少：每次选择的n-1个均避开当前数组中最大值。
3）如果在代码中将数组变换的中间结果列出，算法复杂度肯定较大，所以我们逆向思考：目的都是数组中每个数据彼此相等，那么每次使得其中1个数据-1，最终达到目的 与题意的moves相同。
4）3）中的思路可以转换为数组中的每个非最小值到最小值的次数，则moves += ！min[i] - min。同样可以转换为数组的sum - min*n
*/


