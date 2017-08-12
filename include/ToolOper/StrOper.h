#pragma once
/*! * �ַ������ò����ࡣ
*  \brief     �����˳��õ��ַ�������.
*  \details   �����˳��õ��ַ�������.
*  \author    Wang HongLu
*  \version   1.0
*  \date      2016.11.19
*  \pre       ��
*  \bug       ��
*  \warning   ��
*  \copyright ��Ȩ�� ����³ ������.
*/
#include <string>
#include <vector>
#include <stdarg.h>//Ϊ������ ��va_start �� ��va_end
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
	* \brief ���ַ�����׷��ָ����ʽ���ַ���.
	* \param[in] pszsrc Դ�ַ���.
	* \param[in] pszformat �����ʽ.
	* \return ׷��ָ����ʽ���ַ�����������ַ���.
	*/
	std::string AppendFt(const char* pszsrc, const char* pszformat,...);
};

