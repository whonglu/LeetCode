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
	while (i != vTNode.size())//����Vectorʵ��queue�Ĺ��ܡ�ѭ����ʽ
	{
		vector<int> tResult;
		int vSize = vTNode.size();
		for (; i<vSize; i++)
		{
			tResult.push_back(vTNode[i]->m_nVal);//��������
			if (vTNode[i]->m_pLeft)
			{
				vTNode.push_back(vTNode[i]->m_pLeft);
			}
			if (vTNode[i]->m_pRight)
			{
				vTNode.push_back(vTNode[i]->m_pRight);
			}
		}
		vResult.insert(vResult.begin(), tResult);//���¶���
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
	while (i != vTNode.size())//����Vectorʵ��queue�Ĺ��ܡ�ѭ����ʽ
	{
		vector<int> tResult;
		int vSize = vTNode.size();
		for (; i<vSize; i++)
		{
			tResult.push_back(vTNode[i]->m_nVal);//��������
			if (vTNode[i]->m_pLeft)
			{
				vTNode.push_back(vTNode[i]->m_pLeft);
			}
			if (vTNode[i]->m_pRight)
			{
				vTNode.push_back(vTNode[i]->m_pRight);
			}
		}
		//vResult.insert(vResult.begin(), tResult);//���¶���
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
	while (i != vTNode.size())//����Vectorʵ��queue�Ĺ��ܡ�ѭ����ʽ
	{
		vector<int> tResult;
		int vSize = vTNode.size();
		for (; i<vSize; i++)
		{
			if (0 != iLevel%2)
			{
				tResult.push_back(vTNode[i]->m_nVal);//��������
			}
			else
			{
				tResult.insert(tResult.begin(), vTNode[i]->m_nVal);//��������
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
		//vResult.insert(vResult.begin(), tResult);//���¶���
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
	while (i != vTNode.size())//����Vectorʵ��queue�Ĺ��ܡ�ѭ����ʽ
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
	while (i != vTNode.size())//����Vectorʵ��queue�Ĺ��ܡ�ѭ����ʽ
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
		int iMid = iLow + (iHigh - iLow)/2;//ע�⣺��ʹ��iMid = (iHigh + iLow)/2;����ܵ������
		if (isBadVersion(iMid))//����
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
#pragma region ��һ�γ���
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

	//����1��nTemp�Ƿ����Ϊ���������ǣ���nTemp = nTemp >> 1����ѭ�������䣺��Ŀ����˵��ȫ������
	//����2��ѭ���Ĵ�����nTemp��λ����ͬ���Ƿ���ԸĽ�
	//�ο�����ָOffer�� ������1�ĸ���
#pragma endregion

#pragma region �Ľ��㷨
	if (true)
	{
		int nTemp = x ^ y;
		int nSum = 0;
		while (0 != nTemp)
		{
			nSum++;
			nTemp = nTemp&(nTemp-1);//�൱�ڰ�nTemp���Ҳ��1��Ϊ0
		}
		return nSum;
	}	
#pragma endregion

}

int CLeetCode::totalHammingDistance_M477( vector<int>& nums )
{
#pragma region ��һ�γ��ԣ��ᳬʱ
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
					nTemp = nTemp&(nTemp-1);//�൱�ڰ�nTemp���Ҳ��1��Ϊ0
				}
				nSum += nSubSum;
			}
		}
		return nSum;
	}
#pragma endregion

#pragma region �Ľ��㷨
	//ÿһλ�ϵ�����Ҫô��1��Ҫô��0����ô������4�����֣���λ�϶����Ʒֱ�Ϊ0,1,0,1��
	//��ô��ʵ��λ�ϵĺ�������֮��,2*2��2��1,2��0��

	//һ���ж�����������Ԫ�ص�һλ���ӵ͵��ߡ�
	//���ĳλ�ϣ�Ϊ0��Ԫ����m����Ϊ1��Ԫ����n�������λ�������Hamming distanceΪm*n��������λ���������
	if (true)
	{
		int nSum = 0;
		int iFlag = 1;
		int nCurBit = 0;//��¼��ǰλ��1�ĸ���
		int nCount = nums.size();
		while (iFlag)//������ϵͳλ��ʱֹͣ
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
	//�ŵ�1�������ں��и������������������ѭ��
	//�ŵ�2�����øı�ԭ������
#pragma endregion

#pragma region �����㷨1
	if (true)//����3
	{
		int nSum = 0;
		bool bTag = true;
		int nCurBit = 0;//��¼��ǰλ��1�ĸ���
		int nCount = nums.size();
		while (bTag)//������ϵͳλ��ʱֹͣ
		{
			bTag = false;
			nCurBit = 0;
			for (int i=0; i<nCount; i++)
			{
				if (nums[i] & 1)
				{
					nCurBit++;
				}
				nums[i] = nums[i] >> 1;//��Ϊ��Ŀ��˵��ȫ�����������Կ���ֱ�����ƣ������������ѭ���������ڸ���ʱ����˷�����ȡ��
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
		nTemp = nTemp&(nTemp-1);//�൱�ڰ�nTemp���Ҳ��1��Ϊ0
	}
	return nSum;
}

bool CLeetCode::isPowerOfTwo_E231( int n )
{
	//˼·������2��n�η�����������������ҽ���1λΪ1
	if (true)//����1
	{
		if (n<=0)
		{
			return false;
		}
		return (n & (n-1)) == 0;//(n & (n-1))��n���Ҳ��1��Ϊ0
	}

	if (false)//����2��ͳ�ƶ�����Ϊ1��λ�ĸ���
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
	if(true) //����1
	{
		while (n && n % 3 == 0) 
		{
			n /= 3;
		}
		return n == 1;
	}

	if(true)//����2:һ����������ʵ�������n��3��x�η�����ô��3Ϊ�Ͷ�����һ����һ��������������
	{
		double res = log10((double)n) / log10(3.0);  //�о������⣬��Ҫ����ָ��2.718Ϊ�͵�log����  
		return (res - int(res) == 0) ? true : false;  

	}

	if(true)//����3:�κ�һ��3��x�η�һ���ܱ�int��������3��x�η�����
	{
		return (n > 0 && 1162261467 % n == 0);
	}

}

bool CLeetCode::isPowerOfFour_E342( int num )
{
	if(true)//����1
	{
		while (num && (num % 4 == 0)) {
			num /= 4;
		}
		return num == 1;
	}

	if(true)//����2
	{
		if(num<=0) return false;
		return (num&(num-1))==0&&(num&0x55555555)==num;
	}

	if(true)//����3
	{
		if(num <= 0) return false;
		if(num & (num - 1)) return false; // ���ж��Ƿ��� 2 �� N �η�
		if(num & 0x55555555) return true; // �ٽ����� 4 �� N �η�������ȥ��
		return false;
	}

	if(true)//����4
	{
		return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
	}
	if(true)//����5
	{  
		if(num <= 0) return false;  
		if(num & num-1) return false;  
		return num % 3 == 1;  
	}
}

uint32_t CLeetCode::reverseBits_E190( uint32_t n )
{
	if (true)//��������һ�γ���
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
	if (true)//���������緽��1
	{
		//����revers integer��˼·�� ע��������㡣
		//����value = (value<<1 )|((n&mask)>>i);  �����n&mask����ȡ��n�ĵ�0��1��2��, , , 31λ������ȡ��֮�󣬻���Ҫ�����ӵ��𽥹�����value��ȥ��
		//�Ҳ��õ���ģ��reverse integer�ķ�������ÿ��ȡ�õ�n&mask�������Ϊ��0λ����֮������ӵ�value��ȥ��
		uint32_t value = 0;  
		uint32_t mask = 1;  
		for (uint32_t i = 0; i < 32; ++i) 
		{  
			value = (value<<1 )|((n&mask)>>i);  
			mask <<= 1;  
		}  
		return value; 
	}
	if (true)//���������緽��2
	{
		//����������һ�¡��������ڣ���һ��������ÿ���ƶ�mask���ڶ���������ÿ��������������ֱ���mask��Զ��1.
		uint32_t value = 0;  
		for (uint32_t i = 0; i < 32; ++i) 
		{  
			value = (value<<1 )|((n>>i) & 1);  
		}  
		return value; 
	}
	if (true)////������follow up�ϵķ���
	{
		uint32_t x = n;  
		x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);  
		x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);  
		x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);  
		x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);  
		x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);  
		return x;  
		//�����16����������:
		//0x55555555 =         0101 0101 0101 0101 0101 0101 0101 0101
		//0xAAAAAAAA =     1010 1010 1010 1010 1010 1010 1010 1010
		//0x33333333 =        0011 0011 0011 0011 0011 0011 0011 0011
		//0xCCCCCCCC =   1100 1100 1100 1100 1100 1100 1100 1100
	}
}

int CLeetCode::findComplement_E476( int num )
{
	if (true)//��������һ�γ���
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

	if (true)//����2�����緽��
	{
		//���������֪���������λ��1���ڵ�λ�ã��Ϳ��Թ���һ�����Ⱥ͸�������ռλ��һ������һ������mask��Ȼ�������mask������򼴿ɡ�
		//���磺5�Ķ�������101�����ǵĹ��������Ϊmask=111�����������Ϊ010��������Ҫ�Ľ����
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
	if (false)//��һ�γ���
	{
		uint32_t unum;
		string strResult;
		string strCh;
		int iMask = 15;
		int iTemp = 0;
		bool bFlag = true;//true��������false������
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

	if (true)//����2������ⷨ
	{
		//��һ��ʮ������ת�������ַ�����ʾ��16�����ַ���������Ҫ����Ŀ��Ǹ������⣬
		//��Ϊ��������λ����ʱ�Ѿ��Զ�ת�����˲���+1����ʽֱ�ӽ���������������
		//ÿ��λȡһ�Σ���һ�������ʾ��Ӧ��ϵ
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
	if (true)//��һ�γ���
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

	if (true)//���緽��1
	{
		//��������num=3Ϊ�������Ϊ[0, 1, 1, 2]���õ�3�������ֵĽ��֮��4~7�Ľ�������ڴ˻�����ȷ��������0~3�����Ʊ�ʾΪ��
		//	bin                ret
		//	000                0
		//	001                1
		//	010                1
		//	011                2
		//	4~7�����Ʊ�ʾΪ��
		//	bin                ret
		//	100                1
		//	101                2
		//	110                2
		//	111                3
		//	������������Կ�����4~7�������λ����λ��0~3����ͬ�ģ������λ��1������4~7�Ľ���Ϳ�����0~3�Ļ����Ϸֱ��1��ã���Ŀ�ͺ����׽���ˣ�������룺
		vector<int> vResult(1, 0);  
		int iCurNum = 0;  
		while(iCurNum < num) 
		{  
			int vSize = vResult.size();
			for(int i=0; i<vSize && iCurNum<num; ++i,++iCurNum)//����ɫ�����������vSize���ж��Ƿ�Ӧ�ý�λ
			{  
				vResult.push_back(vResult[i]+1);  
			}  
		}  
		return vResult;
	}

	if (true)//���緽��2
	{
		//����Ӹ�λ�����ҳ�����취�������Դӵ�λ���֡�
		//��1���ĸ������ڳ������λ֮��ġ�1���ĸ����������λ��1���ĸ�����
		//��ret[n] = ret[n>>1] + n%2��������룺

		//��һ�����ͣ����Դ�ÿ���������λ��ʼ����������1001001��
		//���Ķ�����1�ĸ�������100100 �ܶ����Ƹ��� + 1 ��
		//�� f = f/2 + (f �����λ)
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
	if (true)//���緽��1
	{
		/*
		������˼·���ֶ�ģ��ù��̣����Ӧ�ð���������0��Ԫ�صļ��ϣ��ռ���������1��Ԫ�صļ��ϣ�����2��Ԫ�صļ��ϡ�������n��Ԫ�صļ��ϣ�ȫ������
		���ں���k��Ԫ�صļ���Ӧ����ô���أ�
		��һ�δӼ��ϵĵ�һ��Ԫ�ؿ�ʼ�ң�ͬʱk-1��
		�ڶ��δ�ʣ�µĵ�һ��Ԫ�ؿ�ʼ�ң�ͬʱk-1����һֱ��kΪ0��˵�������ļ����ҵ��ˡ�
		�ݹ�İ�������ڣ���һ���У�������ֻ�����һ��Ԫ�أ�����ǰ���Ԫ�ز��䣬������һֱ����ԭ���ϵ����һ��Ԫ�ء�
		��ô������һ���Ժ���ʱ�򻻵��Ŀɲ�ֹһ��Ԫ���ˣ�Ӧ���ǻ��굹���ڶ���Ԫ���Ժ��ٽ����µ�һ�ֻ����һ��Ԫ�ء�
		��ô���еݹ�ͻ�õ����е������
		�����ֶ�ģ�������ݹ���õĹ��̡�
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
	if (true)//���緽��2��λ��������ɫ��
	{
		/*
		��������[1,2,3]��������һ���±�0��1��ʾ�Ƿ�ѡ������֣�0��ʾδѡ��1��ʾѡ�У�
		��ôÿһ��3��0��1����ϱ�ʾһ��ѡ��3λ����8��ѡ�񣬷ֱ��ǣ� 
		000 ��Ӧ[] 
		001 ��Ӧ[3] 
		010 ��Ӧ[2] 
		011 ��Ӧ[2,3] 
		100 �� 
		101 
		110 
		111 
		��ô����Ϊ1��λ��ʾ�����и�λ��ѡ�С� 
		��ôֻ��Ҫ����0��1<< length�е������ж�ÿһ���������Ǽ�λΪ1��Ϊ1���Ǽ�λ���ṹ��һ���Ӽ��е�һ��Ԫ�ء�
		*/
		int length = nums.size();
		sort(nums.begin(),nums.end());
		vector<vector<int> > vResult;
		for(int i=0; i<1<<length; i++)
		{
			vector<int> tmp;
			//����i�����Ǽ�λΪ1
			for(int j=0;j<length;j++)
			{
				//�ж�i�е�jλ�Ƿ�Ϊ1
				if(i&1<<j)
				{
					tmp.push_back(nums[j]);
				}
			}
			vResult.push_back(tmp);
		}
		return vResult;
	}
	if (true)//���緽��3�����ݷ�
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
	if (true)//���������˼·���
	{
		int arr[32];
		uint32_t iFlag = 1;
		int tSum = 0;
		for (int i=0; i<32; i++)//��λ����
		{
			tSum = 0;
			iFlag = iFlag<<i;
			for (size_t j=0; j<nums.size(); j++)//��λ���
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

	if (true)//����ⷨ
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
	if (true)//���緽��
	{
		//�ѵ�����ô�ж������ַ����Ƿ񲻺�����ͬ���ַ���
		//��һ��int��32λ����Сд��ĸֻ��26������26λ������ʾ��Ӧ���ַ��Ƿ���ڡ�
		//�������int���룬������Ϊ0��˵��������Ӧ���ַ���û����ͬ���ַ�!
		vector<int> vMask(words.size(), 0);  
		int maxPro = 0;
		int vSizeWords = words.size();
		for (int i = 0; i < vSizeWords; i++)//�������
		{  
			int len = words[i].size();  
			for (int k=0; k<len; k++)//����ɫ����ʼ��ÿ���ַ�����Mask
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
	if (true)//���緽��1
	{
		//˼·�����ַ��������г���Ϊ10���Ӵ��Լ����ֵĴ�����map���棬������Ҫ���ĺܴ�Ŀռ䡣
		//���ǵ�ֻ��4�п��ܵ��ַ�A,C,G,T;���Զ��ַ����б��룬��2bit����ʾһ���ַ���һ������10���ַ����Ӵ�ֻҪ20bit���ܱ�ʾ����һ��int���;��ܱ�ʾ��
		//�ܳ���Ϊn���ַ��������ܵ��Ӵ�����n-9�֣���������n-9��int���ܱ�ʾ���е��ַ���ϡ��������£�20bit����2^20����ϣ���1024*1024��
		//һ��int����4byte,��˶�������4MB�Ķ���ռ䡣
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
				hash &= (1<<20) - 1;//����ɫ��������20bit�Ĳ�������
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
	if (true)//���緽��1
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
	if (true)//��һ�γ���
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

	if (true)//������ȡ������
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
	if (true)//��һ�γ���
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
	if (true)//ȡ������
	{
		int iLow,iHigh;
		iLow = 0;
		iHigh = s.size() - 1;
		while (iLow <= iHigh)
		{
			while (!(isalnum(s[iLow])) && iLow < iHigh)//ע�⣺isalnum()�������÷�
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
	if (true)//��һ�γ���
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

	if (true)//������ȡ������
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
		if (0 != iLength % i)//���޷�����
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
	if (true)//��������һ�γ���
	{
		if (word.empty())
		{
			return true;
		}
		bool bFirCapital = false;//��һ����ĸ�Ƿ��д
		bool bSecCapital = false;//�Ƿ���ڵڶ�����д��ĸ
		bool bHaveLower = false;//�Ƿ����Сд��ĸ

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
			if (bFirCapital)//������ĸ��д
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
	if (true)//������ȡ������
	{
		int mm=0,nn=0;
		if (word[0]>'Z')//��һ����Сд��ĸ
		{
			for (size_t j = 1; j < word.size();j++)//�ӵڶ�����ĸ��ʼ����
			{
				if (word[j]<'a')//������д��ĸ
				{
					return false;//����
				}
			}
			return true;//ȫ����Сд

		}
		else//��һ���Ǵ�д��ĸ
		{
			for (size_t k = 1; k < word.size(); k++)//����ʣ�µ�
			{
				if (word[k] >'Z')//����Сд��ĸ
				{
					mm=1;
				}
				else//������д��ĸ
				{
					nn=1;
				}
				if(nn+mm>1)//�д�д��Сд
				{
					return false;//����
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
	if (true)//����1
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
	if (true)//����2
	{
		int nCount=0;
		for(size_t i=0; i<s.size(); i++)
		{
			if (0 == i && ' ' != s[i])
			{
				nCount++;
			}
			if (i > 0 && ' ' == s[i-1] && ' ' != s[i])//�����ǰ���ǿո�,��ǰһ���ǿո�,+1
			{
				nCount++;
			}
		}
		return nCount;
	}
}

bool CLeetCode::canConstruct_E383( string ransomNote, string magazine )
{
	if (true)//����1
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
	if (true)//����
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
	if (true)//��һ�γ���
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

	if (true)//���緽��
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
	if (true)//��һ�γ���
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
	if (true)//���緽��1��������չ��
	{
		//����������չ����ÿ���ַ����п����ǻ����ַ������е㡣
		//������ø��ַ���Ϊ���ĵĻ����ַ�����ȡ��������Ǹ����ɡ�
		//ע�⵽�����ַ�����Ϊ�桢ż�������Ͷ�Ӧ��aba���͡�aa��������ÿ���ַ���Ҫ�����λ����ַ���
		if(s.length() <= 1)
		{
			return s;  
		}
		string strLongest = s.substr(0,1);  
		for (size_t i=0; i<s.length(); i++)
		{  
			string tmp = longestPalindrome_M5_helper(s, i, i);//����Ϊ�����ĺ�ѡ�����ַ���   
			if (tmp.length() > strLongest.length()) 
			{  
				strLongest = tmp;  
			}  
			tmp = longestPalindrome_M5_helper(s, i, i+1);//����Ϊż���ĺ�ѡ�����ַ���   
			if (tmp.length() > strLongest.length()) 
			{  
				strLongest = tmp;  
			}  
		} 
		return strLongest;  
	}

	if (true)//���緽��2����̬�滮��
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

	if (true)//���緽��3��O(N)
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
	if (true)//���緽��1��ʱ�临�Ӷ�ΪO(N)
	{
		/*
		ʹ��iSta(�����ѡ����Ӵ��Ŀ�ͷ)��iEnd(�����ѡ����Ӵ��Ľ�β)����ָ�����������
		�ȼ���iSta��������ô�����������£�����ϣ������һֱ����iEnd��ֱ��iEnd����ԭ�ַ����Ľ�β��
		��ʱiEnd-iSta�͹�����һ����ѡ����Ӵ���ÿ�ζ�ά��һ��max_length���Ϳ���ѡ����Ӵ��ˡ�
		ʵ������ǣ���һ������һֱ����iEnd������ַ�iEnd�Ѿ��ظ����ֹ���������λ��k��������Ҫֹͣ�����ˡ�
		��¼��ǰ�ĺ�ѡ�Ӵ�����max_length���Ƚϡ�������Ϊ��һ����Ѱ��׼����
		����һ����Ѱ�У�iStaӦ�ø��µ�k+1��
		*/
		int iLen = s.length();  
		int iSta = 0;	//��ѡ�ַ��������
		int iEnd = 0;	//��ѡ�ַ������յ�
		int iMaxLen = 0;  
		int iCurLen = 0;  
		bool exist[256] = { false };//����ɫ����һ������������Map 
		while (iEnd < iLen) 
		{  
			if (!exist[s[iEnd]]) 
			{  
				exist[s[iEnd]] = true;  //����������¼Ϊtrue  
				iEnd++;  
			} 
			else 
			{  
				while(s[iSta] != s[iEnd]) 
				{  
					exist[s[iSta]] = false;   
					//�º�ѡ�ִ��ӵ�һ���ظ��ַ�(��s[i] == s[j]ʱ���i)�ĺ�һλ��ʼ�㣬֮ǰ��i���㣬
					//��Ч��û�б�ɨ�赽��������Ϊfalse.  
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

	if (true)//���緽��2
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
			iRepeat = strCurMax.find_last_of(chCur);//����ɫ��
			if(string::npos == iRepeat)//��δ�ҵ�
			{
				count++;
				if(count>max)
				{
					max=count;
				}
			}
			else//���ҵ�
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
	if (true)//���緽��1
	{
		/*
		������Ҫ���Ǽ�������˷������д��������ַ�������ʽ��ʾ������󣬷Ǹ������ؽ�����ַ�����ʽ��
		�������ʵ����ģ�������˷���
		�������������ĳ��ȷֱ�Ϊ��l1��l2���������������Ϊl1+l2������н�λ������l1+l2-1�����û���н�λ����
		��ˣ��������ó���Ϊl1+l2�������¼����������ת���ַ�����
		���г˷���ʱ���ȰѸ���λ����˽����Ӧ�ۼ�����������1�������ĵ�iλ����λ����λ���͵�2�������ĵ�jλ����λ����λ����˵Ľ��Ӧ�ô���������i+jλ��Ȼ����ͳһ�����λ��
		Ȼ����ͳһ�����λ��
		����ٽ�����ת���ַ���ǰ����Ҫ����ǰ����㡣������ֻ��0����ֻ����0��
		ʱ�临�Ӷȣ�O(l1l2)��l1��l2�ֱ�Ϊ�����������ȣ�
		�ռ临�Ӷȣ�O(l1+l2)
		*/
		vector<int> iVResult(num1.size() + num2.size(), 0);//����ɫ��
		for(size_t i = 0; i < num1.size(); ++ i)////ģ����������һλ��ʼ����
		{
			for(size_t j = 0; j < num2.size(); ++ j)
			{
				iVResult[i + j] += (num1[num1.size() - i - 1] - '0') * (num2[num2.size() - j- 1] - '0');
			}
		}
		int iCarry = 0;
		for(size_t i = 0; i < iVResult.size(); i++)//�����λ
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

	if (true)//���緽��2
	{
		//���������һ���������ַ�����ʾΪ�գ��򷵻ؿ��ַ���
		if (num1.empty() || num2.empty())
			return string();

		if (num1 == "0" || num2 == "0")
			return "0";

		//���������ӵ�λ����λ���㣬��ת���������ַ���
		reverse(num1.begin(), num1.end());//����ɫ��
		reverse(num2.begin(), num2.end());
		//�����������ַ����ĳ���
		int len1 = strlen(num1.c_str()), len2 = strlen(num2.c_str());

		//����˷�����ַ���
		string ret = "";
		//�����λ
		int carry = 0; 

		for (int i = 0; i < len1; i++)
		{
			//�����Ĵ�����ʼλ
			size_t pos = i;
			for (int j = 0; j < len2; j++)
			{
				int temp = (num1[i] - '0') * (num2[j] - '0') + carry;

				//��ǰλ������
				if (pos < ret.length())
				{
					temp = temp + (ret[pos] - '0');
					ret[pos] = temp % 10 + '0';
				}//if
				else{
					ret.append(1, temp % 10 + '0');
				}//else
				//������һ����λ
				carry = temp / 10;
				//�����������һλ
				pos++;
			}//for
			if (carry > 0)
				ret.append(1, carry + '0');
			carry = 0;
		}//for

		//��ת��������ַ���
		reverse(ret.begin(), ret.end());
		return ret;
	}
}

int CLeetCode::myAtoi_M8( string str )
{
	if (true)//���緽��
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
	if (true)//���緽��1
	{
		//���η�ת��������ע�ⵥ��֮��Ķ���ո�ֻ��һ���ո��Լ�ȥ��ǰ��0�ͺ�0��
		if (s.empty())
		{
			return;
		}
		int size = s.size();

		int index = 0;
		while(' ' == s[index])// ǰ��0
		{
			++index;
		}

		int left = index;

		index = size - 1;
		while(' ' == s[index])// ��0
		{
			--index;
		}
		int right = index;

		// �����ո�ֻ����һ��
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

		// ��ת
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

		// ���巭ת
		ReverseString(s,left,right);
		s = s.substr(left,right - left + 1);
	}


	if (true)//���緽��2
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
			reverse(s.begin()+left, s.begin()+right); //����ɫ��
		}  
		s.resize(right); //����ɫ��
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
	if (true)//���緽��1
	{
		/*
		����˼·����ȡ��һ���Ϸ������֣���ΪIP��ַ��һ�Ȼ��ݹ鴦��ʣ�µ��
		���������һ������ÿ��������������ܵķ�֧����Ϊ��Χ��0-255�����Կ�����һλ��λ������λ��ɣ���
		ÿ����������С�ڵ���255�������������Ĳ������ᳬ���Ĳ㣬��ΪIP��ַ���Ķ���ɣ�
		����֮�����Ǿ�û��Ҫ�ٵݹ���ȥ�����Խ����ˡ�
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

	if (true)//���緽��2
	{
		//stoi����Ĭ��Ҫ������Ĳ����ַ����Ƿ���int��Χ��[-2147483648, 2147483647]�������runtime error��
		//atoi����������Χ��飬������int��Χ������ʾ-2147483648������½磩����2147483647������Ͻ磩��
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
	// ��ֹ����
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
		// ������0��ʼ(����0����)
		if(i != 1 && str[index] == '0')
		{
			break;
		}

		if(index+i <= size)
		{
			strCutItem = str.substr(index,i);//ȡ��ǰi���ַ��Ӵ�
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
	if (true)//���緽��
	{
		/*
		�����Ҫ��������ĸ�����ͬ�ĵ��ʹ�Ϊһ�ࡣ
		������ǿ��԰�ÿ����ĸ����������Ȼ������һ��hash_map���档
		���������Ľ����Ϊ����map��ֵ������һ��set��������ǰ�Ľ�����뵽set���С�
		����set�ĵײ�ʵ��������ƽ����������������Բ����Ժ��Ԫ�����Ѿ��ź���ġ��������������ˡ�
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

	if (true)//���緽��2
	{
		//ʵ���ϣ����ڶԵ�������ʱ����Ŀ�Ѿ��޶��˵���ֻ������26��Сд��ĸ��ɵģ�
		//�������ǿ���ʹ�ü��������һ���ӿ��㷨���ٶȣ����򲿷��ٶȴ�O(nlogn)��ΪO(n)����
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
	if (true)//���緽��
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

	if (true)//���緽��2
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

	////if (bIsHave)//ֻҪ���ڷ���������·����������ֹ��û�б�Ҫ��������
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
		vTemp.assign(vPath.begin(), vPath.end());//�÷�ʽ����ѭ���ķ�ʽ���ã��μ���Effective STL ��5����
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
