#include "LeetCode.h"

CLeetCode::CLeetCode(void)
{
}

CLeetCode::~CLeetCode(void)
{
}

CLeetCode* CLeetCode::GetInstance()
{
	static CLeetCode tLeetCode;
	return &tLeetCode;
}

int CLeetCode::pathSum_E437_Method_whl( TreeNode* root, int sum )
{
	if (!root)
	{
		return 0;
	}
	return pathSumDFS(root, sum) + pathSumDFS(root->m_pLeft, sum - root->m_nVal) + pathSumDFS(root->m_pRight, sum - root->m_nVal);
}

int CLeetCode::pathSumDFS( TreeNode* root, int sum )
{
	if (!root)
	{
		return 0;
	}
	if (sum == root->m_nVal)
	{
		return 1;
	}
	return pathSumDFS(root->m_pLeft, sum - root->m_nVal) + pathSumDFS(root->m_pRight, sum - root->m_nVal);
}

vector<vector<int>> CLeetCode::levelOrderBottom_107( TreeNode* root )
{
	vector<vector<int>> vResult;
	if (!root)
	{
		return vResult;
	}
	vector<TreeNode*> vTNode;
	vTNode.push_back(root);
	int i = 0;
	while (i != vTNode.size())//利用Vector实现queue的功能、循环方式
	{
		vector<int> tResult;
		int vSize = vTNode.size();
		for (; i<vSize; i++)
		{
			tResult.push_back(vTNode[i]->m_nVal);//自左向右
			if (vTNode[i]->m_pLeft)
			{
				vTNode.push_back(vTNode[i]->m_pLeft);
			}
			if (vTNode[i]->m_pRight)
			{
				vTNode.push_back(vTNode[i]->m_pRight);
			}
		}
		vResult.insert(vResult.begin(), tResult);//自下而上
	}
	return vResult;
}

vector<vector<int>> CLeetCode::levelOrder_102( TreeNode* root )
{
	vector<vector<int>> vResult;
	if (!root)
	{
		return vResult;
	}
	vector<TreeNode*> vTNode;
	vTNode.push_back(root);
	int i = 0;
	while (i != vTNode.size())//利用Vector实现queue的功能、循环方式
	{
		vector<int> tResult;
		int vSize = vTNode.size();
		for (; i<vSize; i++)
		{
			tResult.push_back(vTNode[i]->m_nVal);//自左向右
			if (vTNode[i]->m_pLeft)
			{
				vTNode.push_back(vTNode[i]->m_pLeft);
			}
			if (vTNode[i]->m_pRight)
			{
				vTNode.push_back(vTNode[i]->m_pRight);
			}
		}
		//vResult.insert(vResult.begin(), tResult);//自下而上
		vResult.push_back(tResult);
	}
	return vResult;
}

vector<vector<int>> CLeetCode::zigzagLevelOrder_103( TreeNode* root )
{
	vector<vector<int>> vResult;
	if (!root)
	{
		return vResult;
	}
	vector<TreeNode*> vTNode;
	vTNode.push_back(root);
	int i = 0;
	int iLevel = 1;
	while (i != vTNode.size())//利用Vector实现queue的功能、循环方式
	{
		vector<int> tResult;
		int vSize = vTNode.size();
		for (; i<vSize; i++)
		{
			if (0 != iLevel%2)
			{
				tResult.push_back(vTNode[i]->m_nVal);//自左向右
			}
			else
			{
				tResult.insert(tResult.begin(), vTNode[i]->m_nVal);//自左向右
			}

			if (vTNode[i]->m_pLeft)
			{
				vTNode.push_back(vTNode[i]->m_pLeft);
			}
			if (vTNode[i]->m_pRight)
			{
				vTNode.push_back(vTNode[i]->m_pRight);
			}
		}
		//vResult.insert(vResult.begin(), tResult);//自下而上
		iLevel++;
		vResult.push_back(tResult);
	}
	return vResult;
}

int CLeetCode::minDepth_111( TreeNode* root )
{
	if (!root)
	{
		return 0;
	}

	vector<TreeNode *> vTNode;
	vTNode.push_back(root);
	int i = 0;
	int iLevel = 0;
	while (i != vTNode.size())//利用Vector实现queue的功能、循环方式
	{
		iLevel++;
		vector<int> tResult;
		int vSize = vTNode.size();
		for (; i<vSize; i++)
		{
			if (NULL == vTNode[i]->m_pLeft && NULL == vTNode[i]->m_pRight)
			{
				return iLevel;
			} 
			else
			{
				if (vTNode[i]->m_pLeft)
				{
					vTNode.push_back(vTNode[i]->m_pLeft);
				}
				if (vTNode[i]->m_pRight)
				{
					vTNode.push_back(vTNode[i]->m_pRight);
				}
			}
		}
	}
	return iLevel;
}

int CLeetCode::maxDepth_104( TreeNode* root )
{
	if (!root)
	{
		return 0;
	}

	vector<TreeNode *> vTNode;
	vTNode.push_back(root);
	int i = 0;
	int iLevel = 0;
	while (i != vTNode.size())//利用Vector实现queue的功能、循环方式
	{
		iLevel++;
		vector<int> tResult;
		int vSize = vTNode.size();
		for (; i<vSize; i++)
		{	
			if (vTNode[i]->m_pLeft)
			{
				vTNode.push_back(vTNode[i]->m_pLeft);
			}
			if (vTNode[i]->m_pRight)
			{
				vTNode.push_back(vTNode[i]->m_pRight);
			}
		}
	}
	return iLevel;
}

bool CLeetCode::isBalanced_110( TreeNode* root )
{
	if (!root)
	{
		return true;
	}
	if (!root->m_pLeft && !root->m_pRight)
	{
		return true;
	}
	TreeNode *pOtherNode = root->m_pRight;
	if (!root->m_pLeft && pOtherNode)
	{
		if (!pOtherNode->m_pLeft && !pOtherNode->m_pRight)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	pOtherNode = root->m_pLeft;
	if (!root->m_pRight && pOtherNode)
	{
		if (!pOtherNode->m_pLeft && !pOtherNode->m_pRight)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return isBalanced_110(root->m_pLeft) && isBalanced_110(root->m_pRight);
}
bool isBadVersion(int version)
{
	if (version < 1702766719)
	{
		return false;
	}
	else
	{
		return true;
	}
	//return 0;
}
int CLeetCode::firstBadVersion_E278( int n )
{
	int iLow = 1;
	int iHigh = n;
	while(iLow<=iHigh)
	{
		int iMid = iLow + (iHigh - iLow)/2;//注意：若使用iMid = (iHigh + iLow)/2;则可能导致溢出
		if (isBadVersion(iMid))//若是
		{
			if (!isBadVersion(iMid-1))
			{
				return iMid;
			}
			iHigh = iMid - 1;
		}
		else
		{
			if (isBadVersion(iMid+1))
			{
				return iMid+1;
			}
			iLow = iMid + 1;
		}
	}
	return 0;
}

vector<int> CLeetCode::searchRange_M34( vector<int>& nums, int target )
{
	vector<int> vResult;
	if (nums.empty())
	{
		vResult.push_back(-1);
		vResult.push_back(-1);
		return vResult;
	}
	int iLow = 0;
	int iHigh = nums.size() - 1;
	while (iLow <= iHigh)
	{
		size_t iMid = (iLow + iHigh)/ 2;
		if (nums[iMid] == target)
		{
			int temp = iMid;
			if (iMid - 1 >= 0)
			{
				if(target != nums[iMid-1])
				{					
					iMid--;
					if (iMid - 1 < 0)
					{
						break;
					}
				}	
			}					
			vResult.push_back(iMid);

			iMid = temp;
			if (iMid+1 <= nums.size()-1)
			{
				while (target == nums[iMid+1])
				{					
					iMid++;
					if (iMid+1 > nums.size()-1)
					{
						break;
					}
				}	
			}	
			vResult.push_back(iMid);
		}
		else if (nums[iMid] < target)
		{
			iLow = iMid + 1;
		}
		else
		{
			iHigh = iMid - 1;
		}
	}
	if (vResult.empty())
	{
		vResult.push_back(-1);
		vResult.push_back(-1);
	}
	return vResult;
}

int CLeetCode::searchInsert_M35( vector<int>& nums, int target )
{
	int iLow = 0;
	int iHigh = nums.size() - 1;
	while (iLow <= iHigh)
	{
		int iMid = (iLow + iHigh)/ 2;
		if (nums[iMid] == target)
		{
			return iMid;
		}
		else if (nums[iMid] < target)
		{
			iLow = iMid + 1;
		}
		else
		{
			iHigh = iMid - 1;
		}
	}
	return iLow;
}

int CLeetCode::hammingDistance_E461( int x, int y )
{
#pragma region 第一次尝试
	if (true)
	{
		int nTemp = x ^ y;
		int nSum = 0;
		while (0 != nTemp)
		{
			if (nTemp & 1)
			{
				nSum++;
			}
			nTemp = nTemp >> 1;
		}
		return nSum;
	}

	//不足1：nTemp是否可能为负数，若是，则nTemp = nTemp >> 1无限循环。补充：题目中已说明全是正数
	//不足2：循环的次数与nTemp的位数相同，是否可以改进
	//参考《剑指Offer》 求数字1的个数
#pragma endregion

#pragma region 改进算法
	if (true)
	{
		int nTemp = x ^ y;
		int nSum = 0;
		while (0 != nTemp)
		{
			nSum++;
			nTemp = nTemp&(nTemp-1);//相当于把nTemp最右侧的1变为0
		}
		return nSum;
	}	
#pragma endregion

}

int CLeetCode::totalHammingDistance_M477( vector<int>& nums )
{
#pragma region 第一次尝试：会超时
	if (true)
	{
		int nSum = 0;
		for (size_t iFir=0; iFir<nums.size(); iFir++)
		{
			for (size_t iSec=iFir+1; iSec<nums.size(); iSec++)
			{
				int nTemp = nums[iFir] ^ nums[iSec];
				int nSubSum = 0;
				while (0 != nTemp)
				{
					nSubSum++;
					nTemp = nTemp&(nTemp-1);//相当于把nTemp最右侧的1变为0
				}
				nSum += nSubSum;
			}
		}
		return nSum;
	}
#pragma endregion

#pragma region 改进算法
	//每一位上的数字要么是1，要么是0，那么假如有4个数字，个位上二进制分别为0,1,0,1，
	//那么其实个位上的海明距离之和,2*2（2个1,2个0）

	//一次判断数组中所有元素的一位，从低到高。
	//如果某位上，为0的元素有m个，为1的元素有n个，则该位会产生的Hamming distance为m*n个。所有位的依次相加
	if (true)
	{
		int nSum = 0;
		int iFlag = 1;
		int nCurBit = 0;//记录当前位，1的个数
		int nCount = nums.size();
		while (iFlag)//当超出系统位数时停止
		{
			nCurBit = 0;
			for (int i=0; i<nCount; i++)
			{
				if (nums[i] & iFlag)
				{
					nCurBit++;
				}
			}
			nSum += nCurBit * (nCount-nCurBit);
			iFlag = iFlag << 1;
		}
		return nSum;
	}
	//优点1：适用于含有负数的情况，不会无限循环
	//优点2：不用改变原有数组
#pragma endregion

#pragma region 网络算法1
	if (true)//方法3
	{
		int nSum = 0;
		bool bTag = true;
		int nCurBit = 0;//记录当前位，1的个数
		int nCount = nums.size();
		while (bTag)//当超出系统位数时停止
		{
			bTag = false;
			nCurBit = 0;
			for (int i=0; i<nCount; i++)
			{
				if (nums[i] & 1)
				{
					nCurBit++;
				}
				nums[i] = nums[i] >> 1;//因为题目中说明全是正数，所以可以直接右移，不会出现无限循环（若存在负数时，则此法不可取）
				if (nums[i])
				{
					bTag = true;
				}
			}
			nSum += nCurBit * (nCount-nCurBit);
		}
		return nSum;
	}
#pragma endregion
}

int CLeetCode::hammingWeight_E191( uint32_t n )
{
	uint32_t nTemp = n;
	int nSum = 0;
	while (0 != nTemp)
	{
		nSum++;
		nTemp = nTemp&(nTemp-1);//相当于把nTemp最右侧的1变为0
	}
	return nSum;
}

bool CLeetCode::isPowerOfTwo_E231( int n )
{
	//思路：若是2的n次方，则其二进制中有且仅有1位为1
	if (true)//方法1
	{
		if (n<=0)
		{
			return false;
		}
		return (n & (n-1)) == 0;//(n & (n-1))将n最右侧的1置为0
	}

	if (false)//方法2：统计二进制为1的位的个数
	{
		int count = 0;
		while (n > 0) 
		{
			count += (n & 1);
			n >>= 1;
		}
		return count == 1;
	}
}

bool CLeetCode::isPowerOfThree_E326( int n )
{
	if(true) //方法1
	{
		while (n && n % 3 == 0) 
		{
			n /= 3;
		}
		return n == 1;
	}

	if(true)//方法2:一个基本的事实就是如果n是3的x次方，那么以3为低对数后一定是一个整数，否则不是
	{
		double res = log10((double)n) / log10(3.0);  //有精度问题，不要用以指数2.718为低的log函数  
		return (res - int(res) == 0) ? true : false;  

	}

	if(true)//方法3:任何一个3的x次方一定能被int型里最大的3的x次方整除
	{
		return (n > 0 && 1162261467 % n == 0);
	}

}

bool CLeetCode::isPowerOfFour_E342( int num )
{
	if(true)//方法1
	{
		while (num && (num % 4 == 0)) {
			num /= 4;
		}
		return num == 1;
	}

	if(true)//方法2
	{
		if(num<=0) return false;
		return (num&(num-1))==0&&(num&0x55555555)==num;
	}

	if(true)//方法3
	{
		if(num <= 0) return false;
		if(num & (num - 1)) return false; // 先判断是否是 2 的 N 次方
		if(num & 0x55555555) return true; // 再将不是 4 的 N 次方的数字去掉
		return false;
	}

	if(true)//方法4
	{
		return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
	}
	if(true)//方法5
	{  
		if(num <= 0) return false;  
		if(num & num-1) return false;  
		return num % 3 == 1;  
	}
}

uint32_t CLeetCode::reverseBits_E190( uint32_t n )
{
	if (true)//方法：第一次尝试
	{
		uint32_t iFlag = 0;
		for (int i=0; i<32; i++)
		{
			iFlag = iFlag << 1;
			if (n & 1)
			{
				iFlag = iFlag + 1;			
			}		
			n = n >> 1;
		}
		return iFlag;
	}
	if (true)//方法：网络方法1
	{
		//类似revers integer的思路， 注意比特运算。
		//比如value = (value<<1 )|((n&mask)>>i);  这句后的n&mask会逐渐取得n的第0，1，2，, , , 31位的数，取得之后，还需要把它加到逐渐滚动的value上去。
		//我采用的是模拟reverse integer的方法，把每次取得的n&mask的数表达为第0位的数之后再添加到value上去。
		uint32_t value = 0;  
		uint32_t mask = 1;  
		for (uint32_t i = 0; i < 32; ++i) 
		{  
			value = (value<<1 )|((n&mask)>>i);  
			mask <<= 1;  
		}  
		return value; 
	}
	if (true)//方法：网络方法2
	{
		//基本和上面一致。区别在于，第一种做法是每次移动mask。第二种做法是每次右移输入的数字本身，mask永远是1.
		uint32_t value = 0;  
		for (uint32_t i = 0; i < 32; ++i) 
		{  
			value = (value<<1 )|((n>>i) & 1);  
		}  
		return value; 
	}
	if (true)////方法：follow up上的方法
	{
		uint32_t x = n;  
		x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);  
		x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);  
		x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);  
		x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);  
		x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);  
		return x;  
		//上面的16进制数字中:
		//0x55555555 =         0101 0101 0101 0101 0101 0101 0101 0101
		//0xAAAAAAAA =     1010 1010 1010 1010 1010 1010 1010 1010
		//0x33333333 =        0011 0011 0011 0011 0011 0011 0011 0011
		//0xCCCCCCCC =   1100 1100 1100 1100 1100 1100 1100 1100
	}
}

int CLeetCode::findComplement_E476( int num )
{
	if (true)//方法：第一次尝试
	{
		int iResult = 0;
		int iMask = 1;
		for (int i=0; num != 0; i++)
		{			
			if (num & 1)
			{

			}
			else
			{
				iResult = iResult | iMask;
			}
			num = num >> 1;
			iMask = iMask << 1;
		}
		return iResult;
	}

	if (true)//方法2：网络方法
	{
		//如果我们能知道该数最高位的1所在的位置，就可以构造一个长度和该数据所占位置一样长的一个掩码mask，然后概述和mask进行异或即可。
		//例如：5的二进制是101，我们的构造的掩码为mask=111，两者异或则为010，即是所要的结果。
		int mask = 1;
		int temp = num;
		while(temp > 0) 
		{
			mask = mask << 1;
			temp = temp >> 1;
		}
		return num^(mask-1);
	}
}

std::string CLeetCode::toHex_E405( int num )
{
	if (false)//第一次尝试
	{
		uint32_t unum;
		string strResult;
		string strCh;
		int iMask = 15;
		int iTemp = 0;
		bool bFlag = true;//true：正数，false：负数
		if (num < 0)
		{
			unum = 0xffffffff + num + 1;
		}
		else
		{
			unum = num;
		}
		if (0 == num)
		{
			return "0";
		}
		char hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
		while (0 != unum)
		{
			iTemp = unum & iMask;
			unum = unum >> 4;
			if (0 == iTemp && 0 == unum)
			{
				break;
			}
			strResult = hex[iTemp] + strResult;
		}
		return strResult;
	}

	if (true)//方法2：网络解法
	{
		//把一个十进制数转换成用字符串表示的16进制字符串，不需要过多的考虑负数问题，
		//因为负数在做位操作时已经自动转换成了补码+1的形式直接进行正常操作即可
		//每四位取一次，用一个数组表示对应关系
		string strResult; 
		char hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

		if(num<10 && num>=0) 
		{
			return strResult + hex[num]; 
		}

		for(int i=0; i<8 && num!=0; i++) 
		{  
			strResult.insert(0 ,1, hex[num & 15]);  
			num = num>>4;  
		}  
		return strResult;
	}
}

vector<int> CLeetCode::countBits_M338( int num )
{
	if (true)//第一次尝试
	{
		vector<int> vResult;
		for (int i=0; i<=num; i++)
		{
			int t = i;
			int nSum = 0;
			while (t)
			{
				t = t & (t-1);
				nSum++;
			}
			vResult.push_back(nSum);
		}
		return vResult;
	}

	if (true)//网络方法1
	{
		//我们先拿num=3为例，结果为[0, 1, 1, 2]，得到3以内数字的结果之后，4~7的结果可以在此基础上确定，如下0~3二进制表示为：
		//	bin                ret
		//	000                0
		//	001                1
		//	010                1
		//	011                2
		//	4~7二进制表示为：
		//	bin                ret
		//	100                1
		//	101                2
		//	110                2
		//	111                3
		//	从上面分析可以看出，4~7除了最高位其他位和0~3是相同的，而最高位是1，这样4~7的结果就可以在0~3的基础上分别加1获得，题目就很容易解决了，具体代码：
		vector<int> vResult(1, 0);  
		int iCurNum = 0;  
		while(iCurNum < num) 
		{  
			int vSize = vResult.size();
			for(int i=0; i<vSize && iCurNum<num; ++i,++iCurNum)//【特色】很巧妙，利用vSize来判断是否应该进位
			{  
				vResult.push_back(vResult[i]+1);  
			}  
		}  
		return vResult;
	}

	if (true)//网络方法2
	{
		//上面从高位入手找出解决办法，还可以从低位入手。
		//‘1’的个数等于除了最低位之外的‘1’的个数加上最低位‘1’的个数，
		//即ret[n] = ret[n>>1] + n%2，具体代码：

		//进一步解释：可以从每个数的最低位开始分析，例如1001001，
		//它的二进制1的个数等于100100 总二进制个数 + 1 。
		//即 f = f/2 + (f 的最低位)
		vector<int> vResult(num+1, 0);  
		for(int i=1; i<=num; ++i) 
		{
			vResult[i] = vResult[i>>1] + i%2;
		}
		return vResult; 
	}
}

vector<vector<int>> CLeetCode::subsets_M78( vector<int>& nums )
{
	if (true)//网络方法1
	{
		/*
		【解题思路】手动模拟该过程，结果应该包含：含有0个元素的集合（空集），含有1个元素的集合，含有2个元素的集合……含有n个元素的集合（全集）。
		对于含有k个元素的集合应该怎么找呢？
		第一次从集合的第一个元素开始找，同时k-1，
		第二次从剩下的第一个元素开始找，同时k-1……一直到k为0，说明这样的集合找到了。
		递归的奥妙就在于，第一轮中：换掉的只是最后一个元素，保持前面的元素不变，换换换一直换到原集合的最后一个元素。
		这么换完了一轮以后，这时候换掉的可不止一个元素了，应该是换完倒数第二个元素以后，再进行新的一轮换最后一个元素。
		这么进行递归就会得到所有的情况。
		建议手动模拟整个递归调用的过程。
		*/
		vector<int> tmp;
		vector<vector<int>> vResult;
		sort(nums.begin(),nums.end());
		for(size_t i = 0; i <= nums.size(); i++)
		{
			subsetsHelper_M78_Help(vResult, tmp, nums, i, 0);
		}
		return vResult;
	}
	if (true)//网络方法2：位操作【特色】
	{
		/*
		对于数组[1,2,3]，可以用一个下标0和1表示是否选择该数字，0表示未选择，1表示选中，
		那么每一组3个0和1的组合表示一种选择，3位共有8种选择，分别是： 
		000 对应[] 
		001 对应[3] 
		010 对应[2] 
		011 对应[2,3] 
		100 … 
		101 
		110 
		111 
		那么上面为1的位表示数组中该位被选中。 
		那么只需要遍历0到1<< length中的数，判断每一个数中有那几位为1，为1的那几位即会构成一个子集中的一个元素。
		*/
		int length = nums.size();
		sort(nums.begin(),nums.end());
		vector<vector<int> > vResult;
		for(int i=0; i<1<<length; i++)
		{
			vector<int> tmp;
			//计算i中有那几位为1
			for(int j=0;j<length;j++)
			{
				//判断i中第j位是否为1
				if(i&1<<j)
				{
					tmp.push_back(nums[j]);
				}
			}
			vResult.push_back(tmp);
		}
		return vResult;
	}
	if (true)//网络方法3：回溯法
	{
		vector<vector<int>> vResult;
		vector<int> path;
		sort(nums.begin(),nums.end());
		vResult.push_back(path);
		dfs_M78_Help(nums,0,path,vResult);
		return vResult;
	}
}
void CLeetCode::subsetsHelper_M78_Help( vector<vector<int> >& result, vector<int>& tmp, vector<int>& nums, int k, int start )
{       
	if(k == 0)
	{
		result.push_back(tmp);
		return;
	}

	for(size_t i = start; i < nums.size(); i++)
	{
		tmp.push_back(nums[i]);
		subsetsHelper_M78_Help(result, tmp, nums, k-1, i+1);
		tmp.pop_back();
	}
}

void CLeetCode::dfs_M78_Help( vector<int>& nums,int pos,vector<int> & path,vector<vector<int>> & result )
{
	if(pos == nums.size())
		return;

	for(size_t i=pos;i<nums.size();i++)
	{
		path.push_back(nums[i]);
		result.push_back(path);
		dfs_M78_Help(nums,i+1,path,result);
		path.pop_back();
	}
}


int CLeetCode::singleNumber_E136( vector<int>& nums )
{
	if (nums.empty())
	{
		return 0;
	}
	int tResult = nums[0];
	for (size_t i=1; i<nums.size(); i++)
	{
		tResult ^= nums[i];
	}
	return tResult;
}

int CLeetCode::singleNumber_M137( vector<int>& nums )
{
	if (true)//借鉴网络上思路完成
	{
		int arr[32];
		uint32_t iFlag = 1;
		int tSum = 0;
		for (int i=0; i<32; i++)//逐位运算
		{
			tSum = 0;
			iFlag = iFlag<<i;
			for (size_t j=0; j<nums.size(); j++)//逐位求和
			{
				tSum += (nums[j] & iFlag)>>i;
			}
			arr[i] = tSum % 3;
			iFlag = 1;
		}
		int iResult = 0;
		iFlag = 1;
		for (int i=0; i<32; i++)
		{
			if (1 == arr[i])
			{
				iResult = iResult | (iFlag << i);
			}
		}	
		return iResult;
	}

	if (true)//网络解法
	{
		int ary[32] = {0};
		int res=0;
		int len = nums.size();
		for(int i=0; i<32; i++)
		{
			for(int j=0; j<len; j++)
			{
				if(((1<<i)&(nums[j]))!=0)
				{
					ary[i]++;
				}
			}
			ary[i]=ary[i]%3;
			res+=(ary[i]<<i);
		}
		return res;
	}

}

vector<int> CLeetCode::singleNumber_M260( vector<int>& nums )
{
	int tResult = nums[0];
	for (size_t i=1; i<nums.size(); i++)
	{
		tResult ^= nums[i];
	}
	uint32_t iFlag = 1;
	while (0 == (tResult & iFlag))
	{
		iFlag = iFlag<<1;
	}
	bool bIsFir1 = true;
	bool bIsFir2 = true;
	int Res1, Res2;
	for (size_t i=0; i<nums.size(); i++)
	{
		if (0 == (nums[i] & iFlag))
		{
			if (bIsFir1)
			{
				Res1 = nums[i];
				bIsFir1 = false;
				continue;
			}
			Res1 ^= nums[i];
		}
		else
		{
			if (bIsFir2)
			{
				Res2 = nums[i];
				bIsFir2 = false;
				continue;
			}
			Res2 ^= nums[i];
		}
	}
	vector<int> vResult;
	vResult.push_back(Res1);
	vResult.push_back(Res2);
	return vResult;
}

int CLeetCode::maxProduct_M318( vector<string>& words )
{
	if (true)//网络方法
	{
		//难点是怎么判断两个字符串是否不含有相同的字符。
		//用一个int，32位；而小写字母只有26个，后26位用来表示对应的字符是否存在。
		//最后两个int相与，如果结果为0，说明两个对应的字符串没有相同的字符!
		vector<int> vMask(words.size(), 0);  
		int maxPro = 0;
		int vSizeWords = words.size();
		for (int i = 0; i < vSizeWords; i++)//逐个遍历
		{  
			int len = words[i].size();  
			for (int k=0; k<len; k++)//【特色】初始化每个字符串的Mask
			{
				vMask[i] |= (1 << (words[i][k]- 'a'));  
			}  
			for (int j = 0; j < i; j++)
			{  
				if ((vMask[i] & vMask[j]) == 0)
				{  
					int pro = words[i].size() * words[j].size();  
					if (pro > maxPro)
					{  
						maxPro = pro;  
					}  
				}  
			}  
		}
		return maxPro; 
	}
}

vector<string> CLeetCode::findRepeatedDnaSequences_M187( string s )
{
	if (true)//网络方法1
	{
		//思路：将字符串中所有长度为10的子串以及出现的次数用map保存，但是需要消耗很大的空间。
		//考虑到只有4中可能的字符A,C,G,T;可以对字符进行编码，用2bit来表示一个字符，一个含有10个字符的子串只要20bit就能表示，用一个int类型就能表示。
		//总长度为n的字符串，可能的子串共有n-9种，因此最多用n-9个int就能表示所有的字符组合。最坏的情况下，20bit共有2^20中组合，即1024*1024，
		//一个int类型4byte,因此额外消耗4MB的二外空间。
		vector<string> vResult;
		if (s.size() < 10)
		{
			return vResult;
		}
		map<char, int> ch2Int;
		ch2Int.insert(std::make_pair('A', 0));
		ch2Int.insert(std::make_pair('C', 1));
		ch2Int.insert(std::make_pair('G', 2));
		ch2Int.insert(std::make_pair('T', 3));

		int hash = 0; 
		set<int> tSet;
		set<int> tUniqueSet;
		for (size_t i=0; i<s.size(); i++)
		{
			char ch = s.at(i);  
			if(i<9) 
			{  
				hash = (hash<<2) + ch2Int[ch];  
			} 
			else 
			{  
				hash = (hash<<2) + ch2Int[ch];
				hash &= (1<<20) - 1;//【特色】将超过20bit的部分清零
				if ((1 == tSet.count(hash)) && (0 == tUniqueSet.count(hash)))
				{
					vResult.push_back(s.substr(i-9, 10));  
					tUniqueSet.insert(hash);
				}
				else
				{
					tSet.insert(hash);
				}
			}  
		}
		return vResult;
	}
}

int CLeetCode::integerReplacement_M397( int n )
{
	return 0;
}

int CLeetCode::findMaximumXOR_M421( vector<int>& nums )
{
	return 0;
}

bool CLeetCode::validUtf8_M393( vector<int>& data )
{
	if (true)//网络方法1
	{
		int len = data.size();
		int index = 0;
		int num,num1,num2,num3;
		while(index<len)
		{
			num = data[index];
			num &= 0xff;
			if(num>=0 && num<=0x7f)//0xxxxxxx
			{
				//is 1 byte character
				index++;
			}
			else if(num>=0xc0 && num<=0xdf)//110xxxxx 10xxxxxx
			{
				//is 2-byte character
				if(index+1<len)
				{
					num1 = data[index+1];
					num1 &= 0xff;
					if(!(num1<=0xbf && num1>=0x80))
					{
						return false;
					}
					//the second byte is right
					index += 2;
				}
				else
				{
					return false;
				}
			}
			else if(num>=0xe0 && num<=0xef)//1110xxxx 10xxxxxx 10xxxxxx
			{
				//it is a 3-byte character
				if(index+2 < len)
				{
					num1 = data[index+1];
					num2 = data[index+2];
					num1 &= 0xff;
					num2 &= 0xff;
					if(!(num1>=0x80 && num1<=0xbf && num2>=0x80 && num2<=0xbf))
					{
						return false;
					}
					index += 3;
				}
				else
				{
					return false;
				}
			}
			else if(num>=0xf0 && num<=0xf7)//11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
			{
				//is a 4-byte character
				if(index+3<len)
				{
					num1 = data[index+1];
					num2 = data[index+2];
					num3 = data[index+3];
					num1 &= 0xff;
					num2 &= 0xff;
					num3 &= 0xff;
					if(!(num1>=0x80 && num1<=0xbf && num2>=0x80 && num2<=0xbf && num3>=0x80 && num3<=0xbf))
					{
						return false;
					}
					index += 4;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		return true;
	}
}

int CLeetCode::rangeBitwiseAnd_M201( int m, int n )
{
	int iResult = m;
	for (int i=m+1; i<=n; i++)
	{
		iResult = iResult & i;
	}
	return iResult;
}

int CLeetCode::missingNumber_E268( vector<int> nums )
{
	if (true)
	{
		//int i=0;  

		//while(i<nums.size()) 
		//{  
		//	int x = nums[i];  
		//	if(x>=nums.length) {++i; continue;}  
		//	if(x!=i) 
		//		swap(nums, i, x);  
		//	else 
		//		i++;  
		//}  

		//for(int j=0; j<nums.length; j++) {  
		//	if(j != nums[j]) return j;  
		//}  

		//return nums.length;  
		return 0;
	}
}

std::string CLeetCode::longestCommonPrefix_E14( vector<string>& strs )
{
	if (true)//第一次尝试
	{
		if (strs.empty())
		{
			return "";
		}
		size_t iLongest = strs[0].size();
		for (size_t i=1; i<strs.size(); i++)
		{
			if (strs[i].empty())
			{
				return "";
			}
			for (size_t j=0; j<strs[i].size() && j<iLongest; j++)
			{
				if (strs[0][j] == strs[i][j])
				{
					if (j+1 == strs[i].size())
					{
						iLongest = j+1;
					}
				}
				else
				{
					if (j < iLongest)
					{
						iLongest = j;
					}
					break;
				}
			}
		}
		return strs[0].substr(0, iLongest);
	}

	if (true)//方法：取自网络
	{
		if (strs.empty())
		{
			return "";
		}

		char* pStr = (char*)malloc(sizeof(char)*(strs[0].size()+1));  
		for(size_t i=0; i<strs[0].size(); i++)
		{  
			pStr[i] = strs[0][i];  
		}  
		pStr[strs[0].size()]=0;  
		for(size_t i=1; i<strs.size(); i++)
		{  
			int j=0;  
			while(pStr[j] && strs[i][j] && pStr[j]==strs[i][j])
				j++;  
			pStr[j]=0;  
		}  
		return string(pStr);  
	}
}


bool CLeetCode::isPalindrome_E125( string s )
{
	if (true)//第一次尝试
	{
		if (s.empty())
		{
			return true;
		}

		int iLow = 0;
		int iHigh = s.length() - 1;
		while (iLow < iHigh)
		{
			while (!(isAlphaNumeric(s[iLow])) && iLow<iHigh)
			{
				iLow++;
			}
			while (!(isAlphaNumeric(s[iHigh])) && iLow<iHigh)
			{
				iHigh--;
			}

			if (tolower(s[iLow]) != tolower(s[iHigh]))
			{
				return false;
			}
			if (iLow == iHigh)
			{
				return true;
			}
			iLow++;
			iHigh--;
		}
		return true;
	}
	if (true)//取自网络
	{
		int iLow,iHigh;
		iLow = 0;
		iHigh = s.size() - 1;
		while (iLow <= iHigh)
		{
			while (!(isalnum(s[iLow])) && iLow < iHigh)//注意：isalnum()函数的用法
			{
				iLow++;
			}
			while (!(isalnum(s[iHigh])) && iLow < iHigh)
			{
				iHigh--;
			}
			if (toupper(s[iLow]) != toupper(s[iHigh]))
			{
				return false;
			}
			iLow++;
			iHigh--;
		}
		return true;
	}
}

bool CLeetCode::isValid_E20( string s )
{
	//"()" and "()[]{}"
	if (true)//第一次尝试
	{
		stack<char> tSta;
		for (size_t i=0; i<s.size(); i++)
		{
			if (tSta.empty())
			{
				tSta.push(s[i]);
				continue;
			}

			switch (tSta.top())
			{
			case '(':
				if (s[i] == ')')
				{
					tSta.pop();
				}
				else
				{
					tSta.push(s[i]);
				}
				break;
			case '[':
				if (s[i] == ']')
				{
					tSta.pop();
				}
				else
				{
					tSta.push(s[i]);
				}
				break;
			case '{':
				if (s[i] == '}')
				{
					tSta.pop();
				}
				else
				{
					tSta.push(s[i]);
				}
				break;
			default:
				tSta.push(s[i]);
			}		
		}
		if (tSta.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (true)//方法：取自网络
	{
		int iLength = (int)s.length();  
		std::stack<char> tSta;  
		for(int i=0; i<iLength; i++) 
		{  
			if( (s[i]=='(') || (s[i]=='[') || (s[i]=='{') )
			{  
				tSta.push(s[i]);  
			}
			else
			{  
				if(tSta.empty())  
					return false;  
				char chTop = tSta.top();  
				if( (chTop=='(' && s[i]==')') || (chTop=='[' && s[i]==']') || (chTop=='{' && s[i]=='}') )
				{  
					tSta.pop();  
				}else
				{  
					return false;  
				}  
			}  
		}  
		if(tSta.empty())  
			return true;  
		else  
			return false;  
	}

}

bool CLeetCode::repeatedSubstringPattern_E459( string s )
{
	int iLength = s.length();
	bool bIsRepeate = false;
	for (int i=1; i<=iLength/2; i++)
	{
		if (0 != iLength % i)//若无法整除
		{
			continue;
		}
		bIsRepeate = true;
		for (int j=0; j<iLength; j++)
		{
			if (s[j] != s[j%i])
			{
				bIsRepeate = false;
				break;;
			}
		}
		if (bIsRepeate)
		{
			break;;
		}
	}
	return bIsRepeate;
}

bool CLeetCode::detectCapitalUse_E520( string word )
{
	if (true)//方法：第一次尝试
	{
		if (word.empty())
		{
			return true;
		}
		bool bFirCapital = false;//第一个字母是否大写
		bool bSecCapital = false;//是否存在第二个大写字母
		bool bHaveLower = false;//是否存在小写字母

		if (word[0]>='a' && word[0]<='z')
		{
			bFirCapital = false;
			bHaveLower = true;
		}
		else
		{
			bFirCapital = true;
		}

		for (size_t i=1; i<word.length(); i++)
		{
			if (bFirCapital)//若首字母大写
			{
				if (word[i]>='a' && word[i]<='z')
				{
					bHaveLower = true;
					if (bSecCapital)
					{
						return false;
					}
				}
				else
				{
					bSecCapital = true;
					if (bHaveLower)
					{
						return false;
					}

				}
			}
			else
			{
				if (word[i]>='A' && word[i]<='Z')
				{
					return false;
				}
			}
		}
		return true;
	}
	if (true)//方法：取自网络
	{
		int mm=0,nn=0;
		if (word[0]>'Z')//第一个是小写字母
		{
			for (size_t j = 1; j < word.size();j++)//从第二个字母开始遍历
			{
				if (word[j]<'a')//遇到大写字母
				{
					return false;//错误
				}
			}
			return true;//全部是小写

		}
		else//第一个是大写字母
		{
			for (size_t k = 1; k < word.size(); k++)//遍历剩下的
			{
				if (word[k] >'Z')//遇到小写字母
				{
					mm=1;
				}
				else//遇到大写字母
				{
					nn=1;
				}
				if(nn+mm>1)//有大写有小写
				{
					return false;//错误
				}
			}
			return true;
		}
	}
}

bool CLeetCode::isAlphaNumeric( char ch )
{	
	if (ch >='a' && ch <= 'z')
	{
		return true;
	}
	if (ch >= 'A' && ch <= 'Z')
	{
		return true;
	}
	if (ch >= '0' && ch <= '9')
	{
		return true;
	}	
	return false;
}

int CLeetCode::countSegments_E434( string s )
{
	if (true)//方法1
	{
		string::size_type pos, pos_space;
		pos = s.find_first_not_of(' ');
		pos_space = s.find(' ');

		int nCount = 0;
		while (pos != string::npos && pos_space != string::npos)
		{
			if (pos_space < pos)
			{
				s = s.substr(pos+1, s.length() - pos + 1);
			}
			else
			{
				nCount++;
				s = s.substr(pos_space+1, s.length() - pos_space + 1);
			}
			pos_space = s.find(' ');
			pos = s.find_first_not_of(' ');
		}
		if (pos != string::npos)
		{
			nCount++;
		}	
		return nCount;
	}
	if (true)//方法2
	{
		int nCount=0;
		for(size_t i=0; i<s.size(); i++)
		{
			if (0 == i && ' ' != s[i])
			{
				nCount++;
			}
			if (i > 0 && ' ' == s[i-1] && ' ' != s[i])//如果当前不是空格,而前一个是空格,+1
			{
				nCount++;
			}
		}
		return nCount;
	}
}

bool CLeetCode::canConstruct_E383( string ransomNote, string magazine )
{
	if (true)//方法1
	{
		std::map<char, int> m1;
		int vMagazineSize = magazine.size();
		for (int i=0; i<vMagazineSize; i++)
		{
			m1[magazine[i]]++;
		}

		std::map<char, int> m2;
		int vRansomNoteSize = ransomNote.size();
		for (int i=0; i<vRansomNoteSize; i++)
		{
			m2[ransomNote[i]]++;
		}

		if (m2.size() > m1.size())
		{
			return false;
		}

		map<char, int>::iterator it = m2.begin();
		map<char, int>::iterator itEnd = m2.end();
		for (; it != itEnd; it++)
		{
			if (m1.count(it->first) == 0)
			{
				return false;
			}

			if (it->second > m1[it->first])
			{
				return false;
			}
		}
		return true;
	}
}


std::string CLeetCode::reverseString_E344( string s )
{
	if (true)//方法
	{
		if (s.empty())
		{
			return s;
		}
		int iLow = 0;
		int iHigh = s.size() - 1;
		while (iLow<iHigh)
		{
			char t = s[iHigh];
			s[iHigh] = s[iLow];
			s[iLow] = t;
			iLow++;
			iHigh--;
		}
		return s;
	}
}

std::string CLeetCode::reverseVowels_E345( string s )
{
	if (true)
	{
		string strVowels = "aAoOeEiIuU";
		string::size_type iLeft = -1;
		string::size_type iRight = s.size();
		while (true)
		{
			iLeft = s.find_first_of(strVowels, iLeft+1);
			iRight = s.find_last_of(strVowels, iRight-1);
			if (iLeft < iRight && iLeft != s.npos && iRight != s.npos)
			{
				char ch = s[iLeft];
				s[iLeft] = s[iRight];
				s[iRight] = ch;
			}
			else
			{
				break;
			}
		}
		return s;
	}
}
std::string CLeetCode::addBinary_E67( string a, string b )
{
	return "";
}

int CLeetCode::strStr_E28( string haystack, string needle )
{
	return 0;
}

int CLeetCode::lengthOfLastWord_E58( string s )
{
	return 0;
}

std::string CLeetCode::reverseStr_E541( string s, int k )
{
	if (true)//第一次尝试
	{
		int length = s.length();
		int iT = length / (2*k);
		for (int i=0; i<iT; i++)
		{
			ReverseString(s, i*2*k, i*2*k+k-1);
		}
		if (length%(2*k) < k)
		{
			ReverseString(s, iT*2*k, length-1);
		}
		else
		{
			ReverseString(s, iT*2*k, iT*2*k+k-1);
		}
		return s;  
	}

	if (true)//网络方法
	{
		int sz = s.length();
		for(int i = 0; i < sz; i += k) 
		{
			if(i%(2*k) == 0) 
			{
				int t = i+k-1;
				if (sz-1 < t)
				{
					t = sz - 1;
				}
				ReverseString(s, i, t);
			} 
		}
		return s;
	}
}

void CLeetCode::ReverseString( string &strSrc, int iStart, int iEnd )
{
	int iLen = strSrc.length();
	if ((iStart <= iEnd) && (iEnd < iLen))
	{
		int mid = (iStart + iEnd) / 2;
		for (int i=iStart; i < mid && iStart <= iEnd; i++)
		{
			char ch = strSrc[iStart];
			strSrc[iStart] = strSrc[iEnd];
			strSrc[iEnd] = ch;
			iStart++;
			iEnd--;
		}
	}
}

std::string CLeetCode::countAndSay_E38( int n )
{
	if (true)//第一次尝试
	{
		string str = "1";
		for (int i=1; i<=n; i++)
		{
			char ch;
			int k = 0;
			string strT;
			for (size_t j=0; j<str.length(); j++)
			{
				if (0 == j)
				{
					ch = str.at(j);
					k++;
					continue;
				}

				if (ch == str.at(j))
				{
					k++;
					continue;
				}
				else
				{
					strT += std::to_string((_LONGLONG)k) + ch;
					k = 1;
					ch = str.at(j);
				}
			}
			strT += std::to_string((_LONGLONG)k) + ch;
			str = strT;
		}
		return str;
	}
}

std::string CLeetCode::longestPalindrome_M5( string s )
{
	if (true)//网络方法1：中心扩展法
	{
		//采用中心扩展法，每个字符都有可能是回文字符串的中点。
		//依次求得各字符作为中心的回文字符串，取其中最长的那个即可。
		//注意到回文字符串分为奇、偶两种类型对应“aba”和“aa”，所以每个字符都要求两次回文字符。
		if(s.length() <= 1)
		{
			return s;  
		}
		string strLongest = s.substr(0,1);  
		for (size_t i=0; i<s.length(); i++)
		{  
			string tmp = longestPalindrome_M5_helper(s, i, i);//长度为奇数的候选回文字符串   
			if (tmp.length() > strLongest.length()) 
			{  
				strLongest = tmp;  
			}  
			tmp = longestPalindrome_M5_helper(s, i, i+1);//长度为偶数的候选回文字符串   
			if (tmp.length() > strLongest.length()) 
			{  
				strLongest = tmp;  
			}  
		} 
		return strLongest;  
	}

	if (true)//网络方法2：动态规划法
	{
		int n = s.length();  
		int longestBegin = 0;  
		int maxLen = 1;  
		bool table[1000][1000] = {false};  
		for (int i = 0; i < n; i++) 
		{  
			table[i][i] = true;  
		}  
		for (int i = 0; i < n-1; i++) 
		{  
			if (s[i] == s[i+1]) 
			{  
				table[i][i+1] = true;  
				longestBegin = i;  
				maxLen = 2;  
			}  
		}  
		for (int len = 3; len <= n; len++) 
		{  
			for (int i = 0; i < n-len+1; i++) 
			{  
				int j = i+len-1;  
				if (s[i] == s[j] && table[i+1][j-1]) 
				{  
					table[i][j] = true;  
					longestBegin = i;  
					maxLen = len;  
				}  
			}  
		}  
		return s.substr(longestBegin, maxLen); 
	}

	if (true)//网络方法3：O(N)
	{
		// Transform S into T.  
		// For example, S = "abba", T = "^#a#b#b#a#$".  
		// ^ and $ signs are sentinels appended to each end to avoid bounds checking  
		string T = longestPalindrome_M5_helper2(s);  
		int n = T.length();  
		int *P = new int[n];  
		int C = 0, R = 0;  
		for (int i = 1; i < n-1; i++) 
		{  
			int i_mirror = 2*C-i; // equals to i' = C - (i-C)  

			P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;  

			// Attempt to expand palindrome centered at i  
			while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) 
			{
				P[i]++;  
			}
			// If palindrome centered at i expand past R,  
			// adjust center based on expanded palindrome.  
			if (i + P[i] > R) 
			{  
				C = i;  
				R = i + P[i];  
			}  
		}  

		// Find the maximum element in P.  
		int maxLen = 0;  
		int centerIndex = 0;  
		for (int i = 1; i < n-1; i++) 
		{  
			if (P[i] > maxLen) 
			{  
				maxLen = P[i];  
				centerIndex = i;  
			}  
		}  
		delete[] P;  

		return s.substr((centerIndex - 1 - maxLen)/2, maxLen);  
	}
}

std::string CLeetCode::longestPalindrome_M5_helper( string s, int left, int right )
{
	int n = s.length();  
	while(left>=0 && right<=n-1 && s[left]==s[right])
	{  
		left--;  
		right++;  
	}  
	return s.substr(left+1, right-left-1);  
}

std::string CLeetCode::longestPalindrome_M5_helper2( string s )
{
	int n = s.length();  
	if (n == 0) 
	{
		return "^$";  
	}
	string ret = "^";  
	for (int i = 0; i < n; i++)
	{
		ret += "#" + s.substr(i, 1);  
	}
	ret += "#$";  
	return ret;  
}

int CLeetCode::lengthOfLongestSubstring_M3( string s )
{
	if (true)//网络方法1：时间复杂度为O(N)
	{
		/*
		使用iSta(代表候选的最长子串的开头)和iEnd(代表候选的最长子串的结尾)两个指针进行搜索。
		先假设iSta不动，那么在理想的情况下，我们希望可以一直右移iEnd，直到iEnd到达原字符串的结尾，
		此时iEnd-iSta就构成了一个候选的最长子串。每次都维护一个max_length，就可以选出最长子串了。
		实际情况是，不一定可以一直右移iEnd，如果字符iEnd已经重复出现过（假设在位置k），就需要停止右移了。
		记录当前的候选子串并和max_length做比较。接下来为下一次搜寻做准备。
		在下一次搜寻中，iSta应该更新到k+1。
		*/
		int iLen = s.length();  
		int iSta = 0;	//候选字符串的起点
		int iEnd = 0;	//候选字符串的终点
		int iMaxLen = 0;  
		int iCurLen = 0;  
		bool exist[256] = { false };//【特色】用一个数组来代表Map 
		while (iEnd < iLen) 
		{  
			if (!exist[s[iEnd]]) 
			{  
				exist[s[iEnd]] = true;  //遍历过，记录为true  
				iEnd++;  
			} 
			else 
			{  
				while(s[iSta] != s[iEnd]) 
				{  
					exist[s[iSta]] = false;   
					//新候选字串从第一个重复字符(当s[i] == s[j]时候的i)的后一位开始算，之前的i不算，
					//等效于没有被扫描到，所以设为false.  
					iSta++;  
				}  
				iSta++;  
				iEnd++;  
			}  
			iCurLen = iEnd - iSta;  
			iMaxLen = iMaxLen > iCurLen ? iMaxLen : iCurLen;  
		}  
		return iMaxLen;  
	}

	if (true)//网络方法2
	{
		char chCur;
		int max = 1;
		int count = 1;
		int iBegin,iRepeat;
		string strCurMax;
		if (s.empty())
		{
			return 0;
		}
		iBegin=0;
		for(size_t i=1;i<s.length();i++)
		{
			chCur = s[i];
			strCurMax = s.substr(iBegin,count);
			iRepeat = strCurMax.find_last_of(chCur);//【特色】
			if(string::npos == iRepeat)//若未找到
			{
				count++;
				if(count>max)
				{
					max=count;
				}
			}
			else//若找到
			{
				count = count - iRepeat;
				iBegin = iBegin + iRepeat + 1;
			}
		}
		return max;
	}
}

std::string CLeetCode::intToRoman_M12( int num )
{
	if (true)
	{
		return "";
	}
}

std::string CLeetCode::multiply_M43( string num1, string num2 )
{
	if (true)//网络方法1
	{
		/*
		这道题的要求是计算大数乘法。其中大数是以字符串的形式表示，任意大，非负，返回结果以字符串形式。
		这道题其实就是模拟整数乘法。
		假设两个整数的长度分别为了l1和l2，则其最后结果长度为l1+l2（最后有进位）或者l1+l2-1（最后没有有进位）。
		因此，可以先用长度为l1+l2的数组记录结果，最后再转成字符串。
		进行乘法的时候，先把各个位的相乘结果对应累加起来，即第1个整数的第i位（低位到高位）和第2个整数的第j位（低位到高位）相乘的结果应该存放在数组的i+j位。然后再统一处理进位。
		然后再统一处理进位。
		最后再将数组转成字符串前，需要跳过前面的零。如果结果只有0，则只返回0。
		时间复杂度：O(l1l2)（l1和l2分别为两个整数长度）
		空间复杂度：O(l1+l2)
		*/
		vector<int> iVResult(num1.size() + num2.size(), 0);//【特色】
		for(size_t i = 0; i < num1.size(); ++ i)////模拟手算从最后一位开始处理
		{
			for(size_t j = 0; j < num2.size(); ++ j)
			{
				iVResult[i + j] += (num1[num1.size() - i - 1] - '0') * (num2[num2.size() - j- 1] - '0');
			}
		}
		int iCarry = 0;
		for(size_t i = 0; i < iVResult.size(); i++)//处理进位
		{
			int num = iVResult[i] + iCarry;
			iVResult[i] = num % 10;
			iCarry = num / 10;
		}

		string s = "";
		size_t i = iVResult.size();
		while(-- i >= 0 && iVResult[i] == 0);
		if(i < 0)
		{
			s = "0";
		}
		else
		{
			for( ; i >= 0; -- i)
			{
				s += iVResult[i] + '0';
			}
		}
		return s;
	}

	if (true)//网络方法2
	{
		//如果有其中一个乘数的字符串表示为空，则返回空字符串
		if (num1.empty() || num2.empty())
			return string();

		if (num1 == "0" || num2 == "0")
			return "0";

		//按照整数从低位到高位计算，翻转两个乘数字符串
		reverse(num1.begin(), num1.end());//【特色】
		reverse(num2.begin(), num2.end());
		//求两个乘数字符串的长度
		int len1 = strlen(num1.c_str()), len2 = strlen(num2.c_str());

		//定义乘法结果字符串
		string ret = "";
		//保存进位
		int carry = 0; 

		for (int i = 0; i < len1; i++)
		{
			//乘数的处理起始位
			size_t pos = i;
			for (int j = 0; j < len2; j++)
			{
				int temp = (num1[i] - '0') * (num2[j] - '0') + carry;

				//向当前位加入结果
				if (pos < ret.length())
				{
					temp = temp + (ret[pos] - '0');
					ret[pos] = temp % 10 + '0';
				}//if
				else{
					ret.append(1, temp % 10 + '0');
				}//else
				//计算下一个进位
				carry = temp / 10;
				//处理乘数的下一位
				pos++;
			}//for
			if (carry > 0)
				ret.append(1, carry + '0');
			carry = 0;
		}//for

		//翻转整个结果字符串
		reverse(ret.begin(), ret.end());
		return ret;
	}
}

int CLeetCode::myAtoi_M8( string str )
{
	if (true)//网络方法
	{
		size_t idx = 0;  
		while(str[idx] == ' ')
		{
			idx++;  
		}
		int flag = 1;  
		if(str[idx] == '-')
		{  
			idx++;  
			flag=-1;  
		}
		else if(str[idx] == '+')
		{  
			idx++;  
		}  
		int res = 0;  
		while(idx < str.size())
		{  
			if(str[idx]<'0' || str[idx]>'9')
			{  
				return flag*res;  
			}  
			int digit=str[idx]-'0';  
			if(flag==1 && res*10.0+digit>INT_MAX)
			{  
				return INT_MAX;  
			}
			else if(flag==-1 && -(res*10.0+digit)<INT_MIN)
			{  
				return INT_MIN;  
			}  
			res = res*10+digit;  
			idx++;  
		}  
		return flag*res; 
	}	 
}

void CLeetCode::reverseWords_M151( string &s )
{
	if (true)//网络方法1
	{
		//两次反转法。这里注意单词之间的多个空格只留一个空格以及去掉前导0和后导0。
		if (s.empty())
		{
			return;
		}
		int size = s.size();

		int index = 0;
		while(' ' == s[index])// 前导0
		{
			++index;
		}

		int left = index;

		index = size - 1;
		while(' ' == s[index])// 后导0
		{
			--index;
		}
		int right = index;

		// 连续空格只保留一个
		for(int i = left;i <= right;)
		{
			if(i > left && s[i-1] == ' ' && s[i] == ' ')
			{
				s.erase(i-1,1);
				--right;
			}
			else
			{
				++i;
			}
		}

		// 翻转
		int start = left,end = left;
		for(int i = left;i <= right+1;++i)
		{
			if(i == right+1 || s[i] == ' ')
			{
				ReverseString(s,start,end-1);
				++end;
				start = end;
			}
			else
			{
				++end;
			}
		}

		// 整体翻转
		ReverseString(s,left,right);
		s = s.substr(left,right - left + 1);
	}


	if (true)//网络方法2
	{
		if (s.empty())
		{
			return;
		}

		int left = 0, right = 0;
		size_t i = 0;
		while(i < s.size())  
		{  
			while(i < s.size() && s[i] == ' ')
			{
				i++;  
			}
			if(i >= s.size()) 
			{
				break;
			}
			if(left != right) 
			{
				s[right++] = ' ';  
			}
			left = right;  
			while(i< s.size() && s[i] != ' ') 
			{
				s[right++] = s[i++];  
			}
			reverse(s.begin()+left, s.begin()+right); //【特色】
		}  
		s.resize(right); //【特色】
		reverse(s.begin(), s.end());  
	}
}
bool check_Helper_M93(string ip)
{
	int value = stoi(ip);
	if(ip[0] == '0')
	{
		return (ip.size() == 1);
	}
	else
	{
		if(value <= 255)
			return true;
		else
			return false;
	}
}
vector<string> CLeetCode::restoreIpAddresses_M93( string s )
{
	if (true)//网络方法1
	{
		/*
		基本思路就是取出一个合法的数字，作为IP地址的一项，然后递归处理剩下的项。
		可以想象出一颗树，每个结点有三个可能的分支（因为范围是0-255，所以可以由一位两位或者三位组成），
		每个数都必须小于等于255。并且这里树的层数不会超过四层，因为IP地址由四段组成，
		到了之后我们就没必要再递归下去，可以结束了。
		*/
		vector<string> vResult;
		if (s.empty())
		{
			return vResult;
		}
		int size = s.size();
		string ip;
		restoreIpAddresses_M93_helper(s, 1, 0, ip, vResult);
		return vResult;
	}

	if (true)//网络方法2
	{
		//stoi函数默认要求输入的参数字符串是符合int范围的[-2147483648, 2147483647]，否则会runtime error。
		//atoi函数则不做范围检查，若超过int范围，则显示-2147483648（溢出下界）或者2147483647（溢出上界）。
		vector<string> vResult;
		if(s.size() > 12)
		{
			return vResult;
		}

		for(size_t i = 0; i < s.size(); i ++)
		{// [0, i]
			for(size_t j = i+1; j < s.size(); j ++)
			{// [i+1, j]
				for(size_t k = j+1; k < s.size()-1; k ++)
				{// [j+1, k], [k+1, s.size()-1]
					string ip1 = s.substr(0, i+1);
					string ip2 = s.substr(i+1, j-i);
					string ip3 = s.substr(j+1, k-j);
					string ip4 = s.substr(k+1);
					if(check_Helper_M93(ip1) && check_Helper_M93(ip2) && check_Helper_M93(ip3) && check_Helper_M93(ip4))
					{
						string ip = ip1 + "." + ip2 + "." + ip3 + "." + ip4;
						vResult.push_back(ip);
					}
				}
			}
		}
		return vResult;
	}
}

int CLeetCode::to_int( string str )
{
	if (str.empty())
	{
		return 0;
	}

	int size = str.size();
	int result = 0;
	for(int i = 0;i < size;++i)
	{
		result = result * 10 + str[i] - '0';
	}
	return result;
}

void CLeetCode::restoreIpAddresses_M93_helper( string &str, int step, int index, string ip, vector<string> &result )
{
	// 终止条件
	int size = str.size();
	if(step == 5)
	{
		if(index == size)
		{
			result.push_back(ip);
		}
		return;
	}

	string strCutItem;
	for(int i = 1;i <= 3;++i)
	{
		// 不能以0开始(单个0可以)
		if(i != 1 && str[index] == '0')
		{
			break;
		}

		if(index+i <= size)
		{
			strCutItem = str.substr(index,i);//取出前i个字符子串
			if(to_int(strCutItem) <= 255)
			{
				string strCurIp = ip;
				if(step != 1)
				{
					strCurIp += ".";
				}
				strCurIp += strCutItem;
				restoreIpAddresses_M93_helper(str,step+1,index+i,strCurIp,result);
			}
		}
	}
}

vector<vector<string>> CLeetCode::groupAnagrams_M49( vector<string>& strs )
{
	if (true)//网络方法
	{
		/*
		这道题要把所有字母组成相同的单词归为一类。
		因此我们可以把每个字母都进行排序，然后利用一个hash_map保存。
		即以排序后的结果作为键，map的值可以是一个set，把排序前的结果插入到set当中。
		由于set的底层实现利用了平衡二叉搜索树，所以插入以后的元素是已经排好序的。这样归类就完成了。
		*/
		vector<vector<string>> vResult;
		if (strs.empty()) 
		{
			return vResult;
		}
		map<string, multiset<string>> um;
		for (size_t i=0; i<strs.size(); i++)
		{
			string strTemp = strs[i];
			sort(strTemp.begin(), strTemp.end());
			um[strTemp].insert(strs[i]);
		}

		map<string, multiset<string>>::iterator it = um.begin();
		for (; it != um.end(); it++)
		{
			vector<string> str(it->second.begin(), it->second.end());
			vResult.push_back(str);
		}
		return vResult;
	}

	if (true)//网络方法2
	{
		//实际上，由于对单词排序时，题目已经限定了单词只可能是26个小写字母组成的，
		//所以我们可以使用计数排序进一步加快算法的速度（排序部分速度从O(nlogn)变为O(n)），
		vector<vector<string>> vResult;
		if (strs.empty()) 
		{
			return vResult;
		}
		map<string, multiset<string>> um;
		for (size_t i=0; i<strs.size(); i++)
		{
			string strTemp = strSort_M49_Helper(strs[i]);
			um[strTemp].insert(strs[i]);
		}

		map<string, multiset<string>>::iterator it = um.begin();
		for (; it != um.end(); it++)
		{
			vector<string> str(it->second.begin(), it->second.end());
			vResult.push_back(str);
		}
		return vResult;
	}
}

std::string CLeetCode::strSort_M49_Helper( string s )
{
	vector<int> count(26, 0);
	for (size_t i = 0; i < s.length(); ++i) 
	{
		++count[s[i] - 'a'];
	}
	string res = "";
	for (int i = 0; i < 26; ++i) 
	{
		while (count[i]--) 
		{
			res += ('a' + i);
		}
	}
	return res;
}
bool isValid_M91_Helper1(char pre,char cur)
{
	if(pre == '1' || (pre == '2' && cur <= '6'))
	{
		return true;
	}//if
	return false;
}
bool isValid_M91_Helper1(char cur)
{
	if(cur >= '1' && cur <= '9')
	{
		return true;
	}//if
	return false;
}
int get_num_M91_Helper2(int *d,int i,int num)
{
	if(i>num) 
		return 1; 
	if(d[i]==0) 
		return get_num_M91_Helper2(d,i+1,num);
	int sum=1,a=1,b=1;
	while(d[i++]==1)
	{
		b=sum;
		sum+=a;
		a=b;
	}
	return sum*get_num_M91_Helper2(d,i,num);
}
int CLeetCode::numDecodings_M91( string s )
{
	if (true)//网络方法
	{
		int size = s.size();
		if(s[0] == '0')
		{
			return 0;
		}
		if(size == 0 || size == 1)
		{
			return size;
		}
		int pre = 1,cur = 1, iResult;
		for(int i = 1;i < size;++i)
		{
			if(isValid_M91_Helper1(s[i-1],s[i]) && isValid_M91_Helper1(s[i]))
			{
				iResult = pre + cur;
			}
			else if(!isValid_M91_Helper1(s[i-1],s[i]) && isValid_M91_Helper1(s[i]))
			{
				iResult = cur;
			}
			else if(isValid_M91_Helper1(s[i-1],s[i]) && !isValid_M91_Helper1(s[i]))
			{
				iResult = pre;
			}
			else
			{
				return 0;
			}
			pre = cur;
			cur = iResult;
		}
		return iResult;
	}

	if (true)//网络方法2
	{
		if (s.empty())
		{
			return 0;
		}

		if ('0' == s[0])
		{
			return 0;
		}

		if(s.size()==1) 
		{
			return 1;
		}

		int *d = new int[s.size()];
		memset(d,0,sizeof(int)*s.size());
		for(int i=1;i<s.size();i++)
		{
			if(s[i]=='0'&&(s[i-1]=='0'||s[i-1]>'2')) 
				{
					return 0;
			}
			if(s[i]=='0') 
			{
				d[i]=0;
				d[i-1]=0;
			}
			else if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<'7')) 
				{
					d[i]=1;
			}
		}
		return get_num_M91_Helper2(d,1,s.size()-1);
	}
}

bool CLeetCode::hasPathSum_E112( TreeNode* root, int sum )
{
	//static bool bIsHave = false;
	if (NULL == root)
	{
		return false;
	}

	if (NULL == root->m_pLeft && NULL == root->m_pRight && sum == root->m_nVal)
	{
		//bIsHave = true;
		return true;
	}

	////if (bIsHave)//只要存在符合条件的路径，即可终止，没有必要继续遍历
	////{
	////	return true;
	////}
	return hasPathSum_E112(root->m_pLeft, sum - root->m_nVal) || hasPathSum_E112(root->m_pRight, sum - root->m_nVal);
}

vector<vector<int>> CLeetCode::pathSum_M113( TreeNode* root, int sum )
{
	vector<vector<int>> vResult;
	vector<TreeNode *> vPath;
	pathSum_M113_helper(root, sum, vPath, vResult);
	
	return vResult;
}

bool CLeetCode::pathSum_M113_helper( TreeNode *root, int sum, vector<TreeNode *> &vPath, vector<vector<int>> &vResult )
{
	if (NULL == root)
	{
		return false;
	}
	vPath.push_back(root);
	bool bIsLeaf = (NULL == root->m_pRight) && (NULL == root->m_pLeft);
	if (bIsLeaf && sum == root->m_nVal)
	{
		vector<int> vTemp;
		//for (size_t i=0; i<vPath.size(); i++)
		//{
		//	vTemp.push_back(vPath[i]->m_nVal);
		//}
		vTemp.assign(vPath.begin(), vPath.end());//该方式比用循环的方式更好，参见《Effective STL 第5条》
		vResult.push_back(vTemp);
		vPath.pop_back();
		return true;
	}

	if (pathSum_M113_helper(root->m_pLeft, sum-root->m_nVal, vPath, vResult))
	{
		//vPath.pop_back();
	}

	if (pathSum_M113_helper(root->m_pRight, sum-root->m_nVal, vPath, vResult))
	{
		//vPath.pop_back();
	}
	vPath.pop_back();
	return false;
}

TreeNode* CLeetCode::GetTree()
{
	static TreeNode tRoot(5);
	static TreeNode tLeft(4);
	static TreeNode tRight(8);
	tRoot.m_pLeft = &tLeft;
	tRoot.m_pRight = &tRight;

	static TreeNode tRoot1(11);
	static TreeNode tLeft1(7);
	static TreeNode tRight1(2);
	tRoot1.m_pLeft = &tLeft1;
	tRoot1.m_pRight = &tRight1;
	tRoot.m_pLeft->m_pLeft = &tRoot1;

	
	static TreeNode tRoot2(4);
	static TreeNode tLeft2(5);
	static TreeNode tRight2(1);
	tRoot2.m_pLeft = &tLeft2;
	tRoot2.m_pRight = &tRight2;
	tRoot.m_pRight->m_pRight = &tRoot2;

	static TreeNode tRoot3(13);
	tRoot.m_pRight->m_pLeft = &tRoot3;
	return &tRoot;
}
