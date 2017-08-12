/*
463. Island Perimeter
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
Example:
[[0,1,0,0],
[1,1,1,0],
[0,1,0,0],
[1,1,0,0]]
Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
Tags£ºHash Table
*/
#include "I_Struct.h"
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid)
	{
		int iRow = 0;
		int iCol = 0;
		int nSum = 0;
		for (; iRow<grid.size(); iRow++)
		{
			for (iCol=0; iCol<grid.at(iRow).size(); iCol++)
			{
				if (0 == grid[iRow][iCol])
				{
					continue;
				}
				nSum += (4-GetN(iRow, iCol, grid));
			}
		}
		return nSum;
	}
private:
	int GetN(int iRow, int iCol, vector<vector<int>> &grid)
	{
		int n = 0;
		if (iRow-1 >= 0)//ÅÐ¶ÏÉÏ²à
		{
			if (1 == grid[iRow-1][iCol])
			{
				n++;
			}
		}

		if (iRow+1 < grid.size())//ÅÐ¶ÏÏÂ²à
		{
			if (1 == grid[iRow+1][iCol])
			{
				n++;
			}
		}

		if (iCol-1 >= 0)//ÅÐ¶Ï×ó²à
		{
			if (1 == grid[iRow][iCol-1])
			{
				n++;
			}
		}

		if (iCol+1 < grid[iRow].size())//ÅÐ¶ÏÓÒ²à
		{
			if (1 == grid[iRow][iCol+1])
			{
				n++;
			}
		}
		return n;
	}
};
