/*
278. First Bad Version
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
Tags: Binary Search
Similar Problems: (M) Search for a Range (M) Search Insert Position (E) Guess Number Higher or Lower
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion_1(int n) 
	{
		int low = 1;
		int high = n;
		int mid;
		while (low <= high)
		{
			mid = (low + high)/2;
			if (isBadVersion(mid))
			{
				if (1 == mid)
				{
					break;
				}

				if (!isBadVersion(mid-1))
				{
					break;
				}
				else
				{
					high = mid;
				}
			}
			else
			{
				if (isBadVersion(mid + 1))
				{
					mid = mid + 1;
					break;
				}
				else
				{
					low = mid + 1;
				}
			}
		}
		return mid;
	}

	//如果你把 mid = (low + high)/2; 那就会出现超时错误，因为直接相加可能溢出，仅此一点，剩下的很简单
	int firstBadVersion_2(int n)
	{
		int low = 1;
		int high = n;
		int mid = 0;
		while (low < high)
		{
			mid = low + (high - low) / 2;
			if (isBadVersion(mid)) 
			{
				high = mid;
			} 
			else 
			{
				low = mid + 1;
			}
		}
		return low;
	}
};