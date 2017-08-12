/*
118. Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
Tags£ºArray
Similar Problems£º(E) Pascal's Triangle II
*/
class Solution {
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> vResult;
		vector<int> vCurRow;
		vector<int> vLastRow;
		if (numRows <= 0)
		{
			return vResult;
		}
		if (1 <= numRows)
		{
			vCurRow.push_back(1);
			vResult.push_back(vCurRow);
		}

		if (2 <= numRows)
		{
			vCurRow.push_back(1);
			vResult.push_back(vCurRow);
		}
		vLastRow = vCurRow;

		if (3 <= numRows)
		{
			for (int i=3; i<=numRows; i++)
			{
				vCurRow.clear();
				for (int j=0; j<i; j++)
				{
					if (0 == j)
					{
						vCurRow.push_back(1);
					}
					else if (i-1 == j)
					{
						vCurRow.push_back(1);
					}
					else
					{
						int num = vLastRow[j-1] + vLastRow[j];
						vCurRow.push_back(num);
					}
				}
				vResult.push_back(vCurRow);
				vLastRow = vCurRow;
			}
		}

		return vResult;
	}
};