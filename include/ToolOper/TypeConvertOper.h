#pragma once
/*! * 字符串常用操作类。
*  \brief     定义了常用的类型转换操作.
*  \details   定义了常用的类型转换操作.
*  \author    Wang HongLu
*  \version   1.0
*  \date      2016.11.19
*  \pre       无
*  \bug       无
*  \warning   无
*  \copyright 版权归 王鸿鲁 所所有.
*/
#include <string>
#include <iostream>
#include <sstream> 
using namespace std;
class CTypeConvertOper
{
public:
	CTypeConvertOper(void);
	~CTypeConvertOper(void);
	static CTypeConvertOper* GetInstance();
private:
	static CTypeConvertOper* m_pTypeConvertOper;
public:
	/*! \fn int Str2Int(string strVal, int iMethod = 0).
	* \brief 将string字符串转换为整形.
	* \param[in] strVal  要转换的字符串.
	* \param[in] iMethod 采用的转换方法.
	* \return 转换后的结果.
	*/
	int Str2Int(string strVal, int iMethod = 0);
	/*! \fn string Int2Str(int iVal, int iMethod = 0).
	* \brief 将int型变量，转换为string字符串.
	* \param[in] iVal    要转换的int整数.
	* \param[in] iMethod 采用的转换方法.
	* \return 转换后的结果.
	*/
	string Int2Str(int iVal, int iMethod = 0);
};

