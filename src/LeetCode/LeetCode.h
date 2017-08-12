#pragma once
/*! * LeetCode题库类。
*  \brief     定义LeetCode中的题库.
*  \details   定义LeetCode中的题库.
*  \author    Wang HongLu
*  \version   1.0
*  \date      2016.12.13
*  \pre       无
*  \bug       无
*  \warning   无
*  \copyright 版权归 王鸿鲁 所所有.
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
#pragma region 公用操作
	bool isAlphaNumeric(char ch);//判断是否是数字或字母
	void ReverseString(string &strSrc, int iStart, int iEnd);//反转字符串strSrc中，自iStart起，至iEnd止，范围内的字符串
	int to_int(string str);
#pragma endregion


#pragma region Tree

	/*! \fn.
	* \brief E112. Path Sum.
	* \details 给定一个二叉树和一个值sum，判断是否存在一个从根节点到叶子节点的路径，使得路径上每个节点值之和等于sum?
	*/
	bool hasPathSum_E112(TreeNode* root, int sum);//112. Path Sum

	/*! \fn.
	* \brief M113. Path Sum II.
	* \details 给定一个二叉树和一个值sum，找出从根节点到叶子节点的和等于sum的所有路径?
	*/
	vector<vector<int>> pathSum_M113(TreeNode* root, int sum);//113. Path Sum II
	/*! \fn int pathSum_437(TreeNode* root, int sum).
	* \brief 437. Path Sum III.
	* \details   求二叉树中定义LeetCode中的题库.
	* \param[in] root 根节点.
	* \param[in] sum  和.
	* \return 和为sum的所有路径的个数.
	*/
	int pathSum_437_Method_whl(TreeNode* root, int sum);
	int pathSumDFS(TreeNode* root, int sum);
#pragma region 按层级遍历
	/*! \fn vector<vector<int>> levelOrderBottom_107(TreeNode* root).
	* \brief 107. Binary Tree Level Order Traversal II.
	* \details 自下而上，自左向右，逐层输出各个节点的值.
	*/
	vector<vector<int>> levelOrderBottom_107(TreeNode* root);

	/*! \fn vector<vector<int>> levelOrder_102(TreeNode* root).
	* \brief 102. Binary Tree Level Order Traversal.
	* \details 自上而下，自左向右，逐层输出各个节点的值.
	*/
	vector<vector<int>> levelOrder_102(TreeNode* root);

	/*! \fn vector<vector<int>> zigzagLevelOrder_103(TreeNode* root).
	* \brief 103. Binary Tree Zigzag Level Order Traversal.
	* \details 自上而下，自左向右，自右向左，逐层输出各个节点的值.
	*/
	vector<vector<int>> zigzagLevelOrder_103(TreeNode* root);

	/*! \fn int minDepth_111(TreeNode* root).
	* \brief 111. Minimum Depth of Binary Tree.
	* \details 最小深度.
	*/
	int minDepth_111(TreeNode* root);
	/*! \fn int maxDepth_104(TreeNode* root).
	* \brief 104. Maximum Depth of Binary Tree.
	* \details 最大深度.
	*/
	int maxDepth_104(TreeNode* root);


	/*! \fn bool isBalanced_110(TreeNode* root).
	* \brief 110. Balanced Binary Tree.
	* \details 判断是否是平衡二叉树.
	*/
	bool isBalanced_110(TreeNode* root);
#pragma endregion

#pragma endregion


#pragma region
	/*! \fn int firstBadVersion_E278(int n).
	* \brief 从1到n个版本号中，找出第一个错误的版本号.
	*/
	int firstBadVersion_E278(int n);
	/*! \fn vector<int> searchRange_M34(vector<int>& nums, int target).
	* \brief 在有序数组中找出指定数字的开始与结束位置.
	*/
	vector<int> searchRange_M34(vector<int>& nums, int target);
	/*! \fn int searchInsert_M35(vector<int>& nums, int target).
	* \brief 在有序数组中查找某数，若找到，则返回其位置；否则，返回其应该插入的位置.
	*/
	int searchInsert_M35(vector<int>& nums, int target);
#pragma endregion

#pragma region Bit Manipulation
	/*! \fn.
	* \brief 461. Hamming Distance.
	* \details   求两个数的汉明距离.
	*/
	int hammingDistance_E461(int x, int y);

	/*! \fn.
	* \brief 477. Total Hamming Distance.
	* \details   求多个数的两两间汉明距离的和.
	*/
	int totalHammingDistance_M477(vector<int>& nums);

	/*! \fn.
	* \brief 191. Number of 1 Bits.
	* \details   求整数的二进制书中位为1的个数.
	*/
	int hammingWeight_E191(uint32_t n);

	/*! \fn.
	* \brief 231. Power of Two.
	* \details   判断给定整数是否是2的某次方.
	*/	
	bool isPowerOfTwo_E231(int n);

	/*! \fn.
	* \brief 326. Power of Three.
	* \details   判断给定整数是否是3的某次方.
	*/
	bool isPowerOfThree_E326(int n);

	/*! \fn.
	* \brief 342. Power of Four.
	* \details   判断给定整数是否是4的某次方.
	*/	
	bool isPowerOfFour_E342(int num);

	uint32_t reverseBits_E190(uint32_t n);
	int findComplement_E476(int num);
	string toHex_E405(int num);//405. Convert a Number to Hexadecimal

	/*! \fn.
	* \brief 338. Counting Bits.
	* \details 统计二进制数字num以内每个数中‘1’的个数.
	*/	
	vector<int> countBits_M338(int num);//338. Counting Bits
	/*! \fn.
	* \brief 78. Subsets.
	* \details 给出一个整数集合（集合元素具有相异性），求出所有的子集合.【ps. 方法同《剑指offer》面试题28】
	*/	
	vector<vector<int>> subsets_M78(vector<int>& nums);//78. Subsets
	void subsetsHelper_M78_Help(vector<vector<int> >& result, vector<int>& tmp, vector<int>& nums, int k, int start);
	void dfs_M78_Help(vector<int>& nums,int pos,vector<int> & path,vector<vector<int>> & result);
	int singleNumber_E136(vector<int>& nums);//136. Single Number
	int singleNumber_M137(vector<int>& nums);//137. Single Number II
	vector<int> singleNumber_M260(vector<int>& nums);//260. Single Number III. 同《剑指offer》面试题211
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
	* \details 给定一个包含从0,1,2...,n中取出来的互不相同的数字，从数组中找出一个丢失的数字.
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
	* \details 给定一个字符串和一个整数k，反转从字符串开始计数的每2k个字符的前k个字符。
	* \如果剩余少于k个字符，则将所有字符都反转。
	* \如果小于2k但大于或等于k个字符，则反转前k个字符，并将另一个作为原始字符。
	*/	
	string reverseStr_E541(string s, int k);//541. Reverse String II

	/*! \fn.
	* \brief 38. Count and Say.
	* \details .
	*/	
	string countAndSay_E38(int n);//38. Count and Say

	/*! \fn.
	* \brief 5. Longest Palindromic Substring.
	* \details 求最长回文子串：给定输入一个字符串，要求输出一个子串，使得子串是最长的回文.
	*/
	string longestPalindrome_M5(string s);//5. Longest Palindromic Substring
	string longestPalindrome_M5_helper(string s, int left, int right);
	string longestPalindrome_M5_helper2(string s);

	/*! \fn.
	* \brief 3. Longest Substring Without Repeating Characters.
	* \details 求不含重复字符的最长子串.
	*/
	int lengthOfLongestSubstring_M3(string s);//3. Longest Substring Without Repeating Characters

	string intToRoman_M12(int num);//12. Integer to Roman

	/*! \fn.
	* \brief 43. Multiply Strings.
	* \details 字符串乘法.
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
	void reverseWords_M151(string &s);//151. Reverse Words in a String. 同《剑指offer》面试题42.

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

