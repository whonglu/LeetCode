/*
119. Pascal's Triangle II
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3,
Return [1,3,3,1].
Note:Could you optimize your algorithm to use only O(k) extra space?
Tags: Array
Similar Problems: (E) Pascal's Triangle
*/
#include "I_Struct.h"
class Solution {
public:
	vector<int> getRow_1(int rowIndex) {
		vector<int> vCurRow;
		if (rowIndex < 0)
		{
			return vCurRow;
		}

		if (rowIndex >= 0)
		{
			vCurRow.push_back(1);
		}

		if (rowIndex >= 1)
		{
			vCurRow.push_back(1);
		}

		vector<int> vLastRow = vCurRow;
		for (int i=2; i<=rowIndex; i++)
		{	
			vCurRow.clear();
			for (int j=0; j<=i; j++)
			{
				if (0 == j)
				{
					vCurRow.push_back(1);
				}
				else if (i == j)
				{
					vCurRow.push_back(1);
				}
				else
				{
					vCurRow.push_back(vLastRow[j] + vLastRow[j-1]);
				}
			}
			vLastRow= vCurRow;
		}
		return vCurRow;
	}

	vector<int> getRow_2(int rowIndex) {  
		vector<int> result;  
		vector<int> tmp;  
		result.push_back(1);  
		if (rowIndex <= 0)  
			return result;  

		for (int i=1; i<=rowIndex; i++)  
		{  
			tmp=result;  
			result.clear();  
			result.push_back(1);  
			for (int i=0; i<tmp.size()-1; i++)  
			{  
				result.push_back(tmp[i] + tmp[i+1]);  
			}  
			result.push_back(1);  

		}  
		return result;  
	}  
};