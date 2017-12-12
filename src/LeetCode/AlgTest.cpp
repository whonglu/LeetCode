
#include "AlgTest.h"

CAlgTest* CAlgTest::m_pAlgTest = NULL;
TreeNode* CAlgTest::m_pBtTree = NULL;
CAlgTest::CAlgTest(void)
{

}

CAlgTest::~CAlgTest(void)
{

}

CAlgTest* CAlgTest::GetInstance()
{
	if ( NULL == m_pAlgTest )
	{
		m_pAlgTest = new CAlgTest();
	}
	return m_pAlgTest;
}

TreeNode* CAlgTest::GetBinaryTreeObj()
{
	if (!m_pBtTree)
	{
		m_pBtTree = new TreeNode(3);
		TreeNode *pLeft = new TreeNode(9);
		TreeNode *pRight = new TreeNode(20);
		m_pBtTree->m_pLeft = pLeft;
		m_pBtTree->m_pRight = pRight;

		pRight->m_pLeft = new TreeNode(15);
		//pRight->right = new TreeNode(7);
	}
	return m_pBtTree;	
}

ListNode* CAlgTest::GetListNodeObj()
{
	ListNode *head = new ListNode(1);
	ListNode *N1 = new ListNode(3);
	head->next = N1;

	ListNode *N2 = new ListNode(2);
	N1->next = N2;

	ListNode *N3 = new ListNode(3);
	N2->next = N3;

	ListNode *N4 = new ListNode(4);
	N3->next = N4;

	ListNode *N5 = new ListNode(3);
	N4->next = N5;

	return head;
}

int CAlgTest::Dfs( TreeNode* root, int sum )
{
	if (NULL == root)
	{
		return 0;
	}

	if (root->m_nVal == sum)
	{
		return 1;
	}

	return Dfs(root->m_pLeft, sum - root->m_nVal) + Dfs(root->m_pLeft, sum - root->m_nVal);
}

vector<vector<int>> CAlgTest::levelOrderBottom_107( TreeNode *root )
{
	vector<vector<int>> vResult;
	if (!root)
	{
		return vResult;
	}
	//queue<TreeNode *>
	vector<TreeNode *> vTNode;
	vTNode.push_back(root);
	int i = 0;
	int iNumber = 107;
	int iLevel = 1;
	while (i != vTNode.size())//利用vector实现queue的功能、循环方式
	{
		vector<int> tResult;
		int vSize = vTNode.size();
		for (; i<vSize; i++)
		{			
			switch (iNumber)
			{
			case 102:
				tResult.push_back(vTNode[i]->m_nVal);//自左向右
				break;

			case 103:
				if (0 != iLevel%2)
				{
					tResult.push_back(vTNode[i]->m_nVal);//自左向右
				}
				else
				{
					tResult.insert(tResult.begin(), vTNode[i]->m_nVal);//自右向左
				}
				break;

			case 107:
				tResult.push_back(vTNode[i]->m_nVal);//自左向右
				break;
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
		switch (iNumber)
		{
		case 107:
			vResult.insert(vResult.begin(), tResult);//自下而上
			break;
		case 102:
			vResult.push_back(tResult);//自上而下
			break;
		case 103:
			iLevel++;
			vResult.push_back(tResult);//自上而下
			break;
		}
	}
	return vResult;
	//思考：如何分析该段代码的时间复杂度
}

int CAlgTest::minDeepth_111( TreeNode *root )
{
	if (!root)
	{
		return 0;
	}
	//queue<TreeNode *>
	vector<TreeNode *> vTNode;
	vTNode.push_back(root);
	int i = 0;
	int iLevel = 0;
	while (i != vTNode.size())//利用vector实现queue的功能、循环方式
	{
		iLevel++;
		vector<int> tResult;
		int vSize = vTNode.size();
		for (; i<vSize; i++)
		{
			if (NULL == vTNode[i]->m_pLeft || NULL == vTNode[i]->m_pRight)
			{
				return iLevel;
			}
			else
			{
				vTNode.push_back(vTNode[i]->m_pLeft);
				vTNode.push_back(vTNode[i]->m_pRight);
			}
		}
	}
	return iLevel;
}

bool CAlgTest::isBalanced_110( TreeNode *root )
{
	if (!root)
	{
		return true;
	}
	if (NULL == root->m_pLeft && NULL == root->m_pRight)
	{
		return true;
	}

	TreeNode *pOtherNode = root->m_pRight;
	if (NULL == root->m_pLeft && pOtherNode)
	{
		if (!pOtherNode->m_pLeft && !pOtherNode)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	pOtherNode = root->m_pLeft;
	if (NULL == root->m_pRight && pOtherNode)
	{
		if (!pOtherNode->m_pLeft && !pOtherNode)
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

int CAlgTest::Strstr_28( string haystack, string needle )
{
	if (haystack.empty() || needle.empty())
	{
		return -1;
	}
	if (haystack.size() < needle.size())
	{
		return -1;
	}
	for (int i=0; i<haystack.size(); i++)
	{
		if (haystack[i] = needle[0])
		{
			bool bSuc = true;
			if (haystack.size()-i < needle.size())
			{
				return -1;
			}
			for (int j=0; j<needle.size(); j++)
			{
				if (haystack[i+j] != needle[j])
				{
					bSuc = false;
				}
			}
			if (bSuc)
			{
				return i;
			}
		}
	}
	return -1;
}

vector<vector<int>> CAlgTest::palindromepairs_336( vector<string> &words )
{
	vector<vector<int>> vResult;
	multimap<char, int> mStart;
	multimap<char, int> mEnd;
	for (int i=0; i<words.size(); i++)
	{
		mStart.insert(std::make_pair(words[i][0], i));
		mEnd.insert(std::make_pair(words[i][words[i].size()-1], i));
	}

	multimap<char, int>::iterator it = mEnd.begin();
	multimap<char, int>::iterator itE = mEnd.end();
	for (; it != itE; it++)
	{
		int nCount = mStart.count(it->first);
		if (0 != nCount)
		{
			multimap<char, int>::iterator ite = mStart.find(it->first);
			for (int i=0; i<nCount; i++, ite++)
			{
				vector<int> vTemp;
				vTemp.push_back(ite->second);
				vTemp.push_back(it->second);
				vResult.push_back(vTemp);
			}
		}
	}
	return vResult;
}

string CAlgTest::GetHint_E299( string secret, string gues )
{
	set<char> sSec;
	set<char> sGue;
	int iBull = 0;
	int iCow = 0;
	for (int i=0; i<secret.size(); i++)
	{
		if (secret.at(i) == gues.at(i))
		{
			iBull++;
		}
		else
		{
			sSec.insert(secret.at(i));
			sGue.insert(gues.at(i));
		}
	}
	set<char>::iterator it = sGue.begin();
	for (;it != sGue.end(); it++)
	{
		if (sSec.count(*it))
		{
			iCow++;
		}
	}
	stringstream sA;
	sA << iBull;

	stringstream sB;
	sB << iCow;

	string strResult = sA.str() + "A";
	strResult += sB.str() + "B";
	return strResult;

}

string CAlgTest::CountAndSay_E38( int n )
{
	if (n < 1)
	{
		return "";
	}
	string strResult = "1";
	for (int i=1; i<n; i++)
	{
		string strTemp;
		int iCount = 0;
		string strT = "";
		for (int j=0; j<strResult.size(); j++)
		{
			if (j==0)
			{
				iCount++;
				continue;
			}

			if (strResult.at(j) == strResult.at(j-1))
			{
				iCount++;
			}
			else
			{
				stringstream ss;
				ss << iCount;
				strT += ss.str() + strResult.at(j-1);
				iCount = 1;
			}
		}
		stringstream ss;
		ss << iCount;
		strT += ss.str() + strResult.at(strResult.size()-1);
		iCount = 1;

		strResult = strT;
	}
	return strResult;
}

bool CAlgTest::WordPattern_E290( string Pattrn, string str )
{
	map<char, string> mPattern;
	string strRet = str;//剩余未比较的串
	for (int i=0; i<Pattrn.size(); i++)
	{
		string strCur;
		string::size_type pSta = strRet.find_first_not_of(' ');
		string::size_type pEnd = strRet.find(' ');
		if (pSta != string::npos && pEnd != string::npos)
		{
			strCur = strRet.substr(pSta, pEnd - pSta);
			strRet = strRet.substr(pEnd+1,strRet.size() - pEnd -1);
		}
		else if (pSta != string::npos && pEnd == string::npos)
		{
			strCur = strRet.substr(pSta, strRet.size()-pSta);
			strRet = "";
		}
		else
		{
			return false;
		}

		if (0 == mPattern.count(Pattrn.at(i)))//若不存在，则插入新串
		{
			mPattern.insert(std::make_pair(Pattrn.at(i), strCur));
		}
		else//取之进行比较
		{
			if (0 != strcmp(strCur.c_str(), mPattern[Pattrn.at(i)].c_str()))
			{
				return false;
			}
		}
	}
	return true;
}

bool CAlgTest::isIsomorphic_E205( string s, string t )
{
	if (s.size() != t.size())
	{
		return false;
	}
	map<char, char> sM;
	for (int i=0; i<s.size(); i++)
	{
		if (0 == sM.count(s[i]))
		{
			sM.insert(std::make_pair(s[i], t[i]));
		}
		else if (1 == sM.count(s[i]))
		{
			if (sM[s[i]] != t[i])
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

bool CAlgTest::isAnagram_E240( string s, string t )
{
	if (s.size() != t.size())
	{
		return false;
	}
	map<char, int> sM;
	map<char, int> tM;
	for (int i=0; i<s.size(); i++)
	{
		if (0 == sM.count(s[i]))
		{
			sM.insert(std::make_pair(s[i], 1));
		}
		else
		{
			sM[s[i]]++;
		}
	}

	for (int i=0; i<t.size(); i++)
	{
		if (0 == tM.count(t[i]))
		{
			tM.insert(std::make_pair(t[i], 1));
		}
		else
		{
			tM[t[i]]++;
		}
	}

	if (sM.size() != tM.size())
	{
		return false;
	}
	map<char, int>::iterator sIt = sM.begin();
	map<char, int>::iterator tIt = tM.begin();
	for (; sIt != sM.end(); sIt++, tIt++)
	{
		if (sIt->first != tIt->first)
		{
			return false;
		}
		else
		{
			if (sIt->second != tIt->second)
			{
				return false;
			}
		}
	}
	return true;
}

vector<int> CAlgTest::findAnagrams_E438( string s, string p )
{
	vector<int> vResult;
	string strRet = s;
	string::size_type pos = s.find_first_of(p);
	int idx = pos;
	while (pos != string::npos)
	{
		string strCur = strRet.substr(pos, p.size());
		if (isAnagram_E240(strCur, p))
		{
			vResult.push_back(idx);
			strRet = strRet.substr(pos+p.size(), strRet.size() - pos - p.size());
			idx += p.size();
		}
		else
		{
			strRet = strRet.substr(pos+1, strRet.size() - pos - 1);
			idx++;
		}
		pos = strRet.find_first_of(p);
		idx += pos;
	}
	return vResult;
}

ListNode * CAlgTest::ReverseList_E206_XH( ListNode *head )
{
	if (!head)
	{
		return NULL;
	}
	ListNode *ptr;
	ptr = head->next;
	head->next = NULL;
	while (NULL != ptr)
	{
		ListNode *pTemp = ptr;
		ptr = ptr->next;
		pTemp->next = head;
		head = pTemp;
	}
	return head;
}

bool CAlgTest::isPalindrome_125( string s )
{
	if (s.empty())
	{
		return true;
	}
	int iStart = 0;
	int iEnd = s.size() - 1;
	char cS,cE;
	for (; iEnd-iStart != 0;)
	{
		if (0 == isalpha(s[iStart]))
		{
			iStart++;
			continue;
		}
		if (0 == isalpha(s[iEnd]))
		{
			iEnd--;
			continue;
		}
		if (s[iStart] >= 'a' && s[iStart] <= 'z')
		{
			cS = s[iStart];
		}
		else
		{
			cS = s[iStart] + 32;
		}
		if (s[iEnd] >= 'a' && s[iEnd] <= 'z')
		{
			cE = s[iEnd];
		}
		else
		{
			cE = s[iEnd] + 32;
		}

		if (cS != cE)
		{
			return false;			
		}
		else
		{
			iStart++;
			iEnd--;
		}
	}
	return true;
}

bool CAlgTest::isPalindrome_9( int x )
{
	if (x < 0)
	{
		x = -x;
	}
	vector<int> vResult;
	while (x != 0)
	{
		int iRet = x%10;
		x = x/10;
	}
	int iStart = 0;
	int iEnd = vResult.size() - 1;
	while (0 != iStart - iEnd)
	{
		if (vResult[iStart] != vResult[iEnd])
		{
			return false;
		}
	}
	return true;
}

bool CAlgTest::isPalindrome_234( ListNode *head )
{
	if (!head)
	{
		return false;
	}
	ListNode *ptr = ReverseList_E206_XH(head);
	while (ptr != NULL)
	{
		if (ptr->val != head->val)
		{
			return false;
		}
		ptr = ptr->next;
		head = head->next;
	}
	return true;
}

int CAlgTest::guessNumber_E374( int n )
{
	int iLow = 1;
	int iHigh = n;
	while(iLow<=iHigh)
	{
		int iGuess = (iLow+iHigh)/2;
		switch (guess_E374(iGuess))
		{
		case -1:
			iLow = iGuess+1;
			break;
		case 0:
			return iGuess;
			break;
		case 1:
			iHigh = iGuess-1;
			break;
		}
	}
	return 0;
}




string CAlgTest::convert_E6( string s, int numRows )
{
	string strResult;
	int iSize = numRows * 2 - 2;
	for (int iRow=0; iRow < numRows; iRow++)
	{
		if (0 == iRow || iRow == numRows - 1 )//若是第1行 or 最后一行
		{
			for (int j=iRow; j<s.size(); j += iSize)
			{
				strResult.push_back(s[j]);
			}
		}
		else
		{
			for (int j=iRow, k=iSize-iRow; j<s.size(); j += iSize, k += iSize)
			{
				strResult.push_back(s[j]);
				if (k < s.size())
				{
					strResult.push_back(s[k]);
				}
			}
		}
	}
	return strResult;
}

vector<int> CAlgTest::maxSlidingWindow_H239( vector<int> &nums, int k )
{
	deque<int> qmax;//用于存储前K个相邻数中的最大值的队列
	vector<int> vResult;
	int iMax = nums[0];
	for (int i=0; i<nums.size(); i++)
	{
		if (i<k)
		{
			if (iMax < nums[i])
			{
				iMax  = nums[i];
			}
		}
		else
		{
			if (nums[i] < qmax.back())
			{
				iMax = qmax.back();
			}
			else
			{
				iMax = nums[i];
			}
		}
		qmax.push_back(iMax);
		if (i>=k-1)
		{
			vResult.push_back(iMax);
		}
	}
	return vResult;
}

int CAlgTest::minSubArrayLen_209( int s, vector<int> &nums )
{
	return 0;
}

int CAlgTest::removeElement_E27( vector<int> &nums, int Val )
{
	int iLow = 0;
	int iHigh = nums.size() - 1;
	if (nums.empty())
	{
		return 0;
	}
	for (; iLow<=iHigh; iLow++)
	{
		if (Val == nums[iLow])
		{
			while (Val == nums[iHigh])
			{
				iHigh--;
			}
			nums[iLow] = nums[iHigh];
			nums[iHigh] = Val;
			iHigh--;
		}
	}
	return iHigh+1;
}

int CAlgTest::removeDuplicates_E26( vector<int> &nums )
{
	if (nums.empty())
	{
		return 0;
	}
	int iInterLoc = 1;
	int iCur = 1;
	int iLast = nums[0];
	for (; iCur<nums.size(); iCur++)
	{
		if (nums[iCur] == iLast)
		{
			//iCur++;
		}
		else
		{
			nums[iInterLoc] = nums[iCur];
			iInterLoc++;
		}
		iLast = nums[iCur];
	}
	return iInterLoc;
}

ListNode * CAlgTest::removeElements_E203( ListNode *head, int val )
{
	ListNode *ptr = head;
	ListNode *pLastNode = NULL;
	ListNode *pNewHead = NULL;
	while (ptr)
	{
		if (val == ptr->val)
		{
			if (pLastNode)
			{
				pLastNode->next = ptr->next;
			}
		}
		else
		{
			if (NULL == pLastNode)
			{
				pNewHead = ptr;
			}
			pLastNode = ptr;
		}
		ptr = ptr->next;
	}
	return pNewHead;
}

void CAlgTest::deleteNode_E237( ListNode *node )
{
	if (NULL == node)
	{
		return;
	}
	ListNode *ptr = node->next;
	if (NULL != ptr)
	{
		node->val = ptr->val;
		node->next = ptr->next;
	}
}

void CAlgTest::moveZeros_E283( vector<int> &nums )
{
	int iCur = 0;
	int iRet = 0;
	for(; iCur<nums.size(); iCur++)
	{
		if (0 == nums[iCur])
		{
			continue;
		}
		else
		{
			nums[iRet] = nums[iCur];
			iRet++;
		}
	}
	for (; iRet < iCur-1; iRet++)
	{
		nums[iRet] = 0;
	}
}

unsigned int CAlgTest::reversebits_E190( unsigned int n )
{
	int nRelust = 0;
	int nTime = 32;
	while (nTime > 0)
	{
		int i = n & 1;
		n = n >> 1;
		nRelust = nRelust * 2 + i;
		nTime--;
	}
	return nRelust;
}

int CAlgTest::hammingWeight_E191( unsigned int n )
{
	bitset<32> b((int)n);
	return b.count();
}

int CAlgTest::hammingDistance_E461( int x, int y )
{
	int iResult = x ^ y;
	bitset<32> b((int) iResult);
	return b.count();
}

int CAlgTest::totalHammingDistance_M477( vector<int> &nums )
{
	int nResult = 0;
	for (int i=0; i<nums.size(); i++)
	{
		int x = nums[i];
		for (int j=i+1; j<nums.size(); j++)
		{
			int y = nums[j];
			int iResult = x ^ y;
			bitset<32> b((int) iResult);
			nResult += b.count();
		}
	}
	return nResult;
}
