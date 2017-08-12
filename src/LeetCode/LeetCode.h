#pragma once
/*! * LeetCode����ࡣ
*  \brief     ����LeetCode�е����.
*  \details   ����LeetCode�е����.
*  \author    Wang HongLu
*  \version   1.0
*  \date      2016.12.13
*  \pre       ��
*  \bug       ��
*  \warning   ��
*  \copyright ��Ȩ�� ����³ ������.
*/
#include "I_Struct.h"
class CLeetCode
{
private:
	CLeetCode(void);
	~CLeetCode(void);
public:
	static CLeetCode* GetInstance();
private:
	static CLeetCode* m_pLeetCode;
public:
#pragma region ���ò���
	bool isAlphaNumeric(char ch);//�ж��Ƿ������ֻ���ĸ
	void ReverseString(string &strSrc, int iStart, int iEnd);//��ת�ַ���strSrc�У���iStart����iEndֹ����Χ�ڵ��ַ���
	int to_int(string str);
#pragma endregion


#pragma region Tree

	/*! \fn.
	* \brief E112. Path Sum.
	* \details ����һ����������һ��ֵsum���ж��Ƿ����һ���Ӹ��ڵ㵽Ҷ�ӽڵ��·����ʹ��·����ÿ���ڵ�ֵ֮�͵���sum?
	*/
	bool hasPathSum_E112(TreeNode* root, int sum);//112. Path Sum

	/*! \fn.
	* \brief M113. Path Sum II.
	* \details ����һ����������һ��ֵsum���ҳ��Ӹ��ڵ㵽Ҷ�ӽڵ�ĺ͵���sum������·��?
	*/
	vector<vector<int>> pathSum_M113(TreeNode* root, int sum);//113. Path Sum II
	/*! \fn int pathSum_437(TreeNode* root, int sum).
	* \brief 437. Path Sum III.
	* \details   ��������ж���LeetCode�е����.
	* \param[in] root ���ڵ�.
	* \param[in] sum  ��.
	* \return ��Ϊsum������·���ĸ���.
	*/
	int pathSum_437_Method_whl(TreeNode* root, int sum);
	int pathSumDFS(TreeNode* root, int sum);
#pragma region ���㼶����
	/*! \fn vector<vector<int>> levelOrderBottom_107(TreeNode* root).
	* \brief 107. Binary Tree Level Order Traversal II.
	* \details ���¶��ϣ��������ң������������ڵ��ֵ.
	*/
	vector<vector<int>> levelOrderBottom_107(TreeNode* root);

	/*! \fn vector<vector<int>> levelOrder_102(TreeNode* root).
	* \brief 102. Binary Tree Level Order Traversal.
	* \details ���϶��£��������ң������������ڵ��ֵ.
	*/
	vector<vector<int>> levelOrder_102(TreeNode* root);

	/*! \fn vector<vector<int>> zigzagLevelOrder_103(TreeNode* root).
	* \brief 103. Binary Tree Zigzag Level Order Traversal.
	* \details ���϶��£��������ң��������������������ڵ��ֵ.
	*/
	vector<vector<int>> zigzagLevelOrder_103(TreeNode* root);

	/*! \fn int minDepth_111(TreeNode* root).
	* \brief 111. Minimum Depth of Binary Tree.
	* \details ��С���.
	*/
	int minDepth_111(TreeNode* root);
	/*! \fn int maxDepth_104(TreeNode* root).
	* \brief 104. Maximum Depth of Binary Tree.
	* \details ������.
	*/
	int maxDepth_104(TreeNode* root);


	/*! \fn bool isBalanced_110(TreeNode* root).
	* \brief 110. Balanced Binary Tree.
	* \details �ж��Ƿ���ƽ�������.
	*/
	bool isBalanced_110(TreeNode* root);
#pragma endregion

#pragma endregion


#pragma region
	/*! \fn int firstBadVersion_E278(int n).
	* \brief ��1��n���汾���У��ҳ���һ������İ汾��.
	*/
	int firstBadVersion_E278(int n);
	/*! \fn vector<int> searchRange_M34(vector<int>& nums, int target).
	* \brief �������������ҳ�ָ�����ֵĿ�ʼ�����λ��.
	*/
	vector<int> searchRange_M34(vector<int>& nums, int target);
	/*! \fn int searchInsert_M35(vector<int>& nums, int target).
	* \brief �����������в���ĳ�������ҵ����򷵻���λ�ã����򣬷�����Ӧ�ò����λ��.
	*/
	int searchInsert_M35(vector<int>& nums, int target);
#pragma endregion

#pragma region Bit Manipulation
	/*! \fn.
	* \brief 461. Hamming Distance.
	* \details   ���������ĺ�������.
	*/
	int hammingDistance_E461(int x, int y);

	/*! \fn.
	* \brief 477. Total Hamming Distance.
	* \details   �������������人������ĺ�.
	*/
	int totalHammingDistance_M477(vector<int>& nums);

	/*! \fn.
	* \brief 191. Number of 1 Bits.
	* \details   �������Ķ���������λΪ1�ĸ���.
	*/
	int hammingWeight_E191(uint32_t n);

	/*! \fn.
	* \brief 231. Power of Two.
	* \details   �жϸ��������Ƿ���2��ĳ�η�.
	*/	
	bool isPowerOfTwo_E231(int n);

	/*! \fn.
	* \brief 326. Power of Three.
	* \details   �жϸ��������Ƿ���3��ĳ�η�.
	*/
	bool isPowerOfThree_E326(int n);

	/*! \fn.
	* \brief 342. Power of Four.
	* \details   �жϸ��������Ƿ���4��ĳ�η�.
	*/	
	bool isPowerOfFour_E342(int num);

	uint32_t reverseBits_E190(uint32_t n);
	int findComplement_E476(int num);
	string toHex_E405(int num);//405. Convert a Number to Hexadecimal

	/*! \fn.
	* \brief 338. Counting Bits.
	* \details ͳ�ƶ���������num����ÿ�����С�1���ĸ���.
	*/	
	vector<int> countBits_M338(int num);//338. Counting Bits
	/*! \fn.
	* \brief 78. Subsets.
	* \details ����һ���������ϣ�����Ԫ�ؾ��������ԣ���������е��Ӽ���.��ps. ����ͬ����ָoffer��������28��
	*/	
	vector<vector<int>> subsets_M78(vector<int>& nums);//78. Subsets
	void subsetsHelper_M78_Help(vector<vector<int> >& result, vector<int>& tmp, vector<int>& nums, int k, int start);
	void dfs_M78_Help(vector<int>& nums,int pos,vector<int> & path,vector<vector<int>> & result);
	int singleNumber_E136(vector<int>& nums);//136. Single Number
	int singleNumber_M137(vector<int>& nums);//137. Single Number II
	vector<int> singleNumber_M260(vector<int>& nums);//260. Single Number III. ͬ����ָoffer��������211
	/*! \fn.
	* \brief 318. Maximum Product of Word Lengths.
	* \details .
	*/	
	int maxProduct_M318(vector<string>& words);//318. Maximum Product of Word Lengths

	/*! \fn.
	* \brief 187. Repeated DNA Sequences.
	* \details .
	*/	
	vector<string> findRepeatedDnaSequences_M187(string s);//187. Repeated DNA Sequences
	/*! \fn.
	* \brief 397. Integer Replacement.
	* \details .
	*/	
	int integerReplacement_M397(int n);//397. Integer Replacement
	int findMaximumXOR_M421(vector<int>& nums);//421. Maximum XOR of Two Numbers in an Array
	/*! \fn.
	* \brief 393. UTF-8 Validation.
	* \details .
	*/	
	bool validUtf8_M393(vector<int>& data);//393. UTF-8 Validation
	int rangeBitwiseAnd_M201(int m, int n);//201. Bitwise AND of Numbers Range
	/*! \fn.
	* \brief 268. Missing Number.
	* \details ����һ��������0,1,2...,n��ȡ�����Ļ�����ͬ�����֣����������ҳ�һ����ʧ������.
	*/	
	int missingNumber_E268( vector<int> nums);//268 Missing Number
#pragma endregion
#pragma region string
	string longestCommonPrefix_E14(vector<string>& strs);//14. Longest Common Prefix
	bool isPalindrome_E125(string s);//125. Valid Palindrome
	bool isValid_E20(string s);//20. Valid Parentheses
	bool repeatedSubstringPattern_E459(string s);//459. Repeated Substring Pattern
	bool detectCapitalUse_E520(string word);//520. Detect Capital
	int countSegments_E434(string s);//434. Number of Segments in a String
	bool canConstruct_E383(string ransomNote, string magazine);//383. Ransom Note
	string reverseString_E344(string s);//344. Reverse String
	string reverseVowels_E345(string s);//345. Reverse Vowels of a String
	string addBinary_E67(string a, string b);//67. Add Binary
	int strStr_E28(string haystack, string needle);//28. Implement strStr()
	int lengthOfLastWord_E58(string s);//58. Length of Last Word
	/*! \fn.
	* \brief 541. Reverse String II.
	* \details ����һ���ַ�����һ������k����ת���ַ�����ʼ������ÿ2k���ַ���ǰk���ַ���
	* \���ʣ������k���ַ����������ַ�����ת��
	* \���С��2k�����ڻ����k���ַ�����תǰk���ַ���������һ����Ϊԭʼ�ַ���
	*/	
	string reverseStr_E541(string s, int k);//541. Reverse String II

	/*! \fn.
	* \brief 38. Count and Say.
	* \details .
	*/	
	string countAndSay_E38(int n);//38. Count and Say

	/*! \fn.
	* \brief 5. Longest Palindromic Substring.
	* \details ��������Ӵ�����������һ���ַ�����Ҫ�����һ���Ӵ���ʹ���Ӵ�����Ļ���.
	*/
	string longestPalindrome_M5(string s);//5. Longest Palindromic Substring
	string longestPalindrome_M5_helper(string s, int left, int right);
	string longestPalindrome_M5_helper2(string s);

	/*! \fn.
	* \brief 3. Longest Substring Without Repeating Characters.
	* \details �󲻺��ظ��ַ�����Ӵ�.
	*/
	int lengthOfLongestSubstring_M3(string s);//3. Longest Substring Without Repeating Characters

	string intToRoman_M12(int num);//12. Integer to Roman

	/*! \fn.
	* \brief 43. Multiply Strings.
	* \details �ַ����˷�.
	*/
	string multiply_M43(string num1, string num2);

	/*! \fn.
	* \brief 8. String to Integer (atoi).
	* \details .
	*/
	int myAtoi_M8(string str);//8. String to Integer (atoi)

	/*! \fn.
	* \brief 151. Reverse Words in a String.
	* \details .
	*/
	void reverseWords_M151(string &s);//151. Reverse Words in a String. ͬ����ָoffer��������42.

	/*! \fn.
	* \brief 93. Restore IP Addresses.
	* \details .
	*/
	vector<string> restoreIpAddresses_M93(string s);
	void restoreIpAddresses_M93_helper(string &str, int step, int index, string ip, vector<string> &result);
	/*! \fn.
	* \brief 49. Group Anagrams.
	* \details .
	*/
	vector<vector<string>> groupAnagrams_M49(vector<string>& strs);//49. Group Anagrams
	string strSort_M49_Helper(string s);

	/*! \fn.
	* \brief 91. Decode Ways.
	* \details .
	*/
	int numDecodings_M91(string s);//91. Decode Ways
#pragma endregion

};

