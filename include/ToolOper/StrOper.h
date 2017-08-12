#pragma once
/*! * 字符串常用操作类。
*  \brief     定义了常用的字符串操作.
*  \details   定义了常用的字符串操作.
*  \author    Wang HongLu
*  \version   1.0
*  \date      2016.11.19
*  \pre       无
*  \bug       无
*  \warning   无
*  \copyright 版权归 王鸿鲁 所所有.
*/
#include <string>
#include <vector>
#include <stdarg.h>//为了引用 宏va_start 与 宏va_end
using namespace std;
class CStrOper
{
public:
	CStrOper(void);
	~CStrOper(void);
	static CStrOper* GetInstance();
private:
	static CStrOper* m_pStrOper;
public:
	/*! \fn std::string AppendFt(const char* pszsrc, const char* pszformat,...)
	* \brief 在字符串后追加指定格式的字符串.
	* \param[in] pszsrc 源字符串.
	* \param[in] pszformat 输入格式.
	* \return 追加指定格式的字符串后的完整字符串.
	*/
	std::string AppendFt(const char* pszsrc, const char* pszformat,...);
};

