#pragma once
/*! * �ַ������ò����ࡣ
*  \brief     �����˳��õ�����ת������.
*  \details   �����˳��õ�����ת������.
*  \author    Wang HongLu
*  \version   1.0
*  \date      2016.11.19
*  \pre       ��
*  \bug       ��
*  \warning   ��
*  \copyright ��Ȩ�� ����³ ������.
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
	* \brief ��string�ַ���ת��Ϊ����.
	* \param[in] strVal  Ҫת�����ַ���.
	* \param[in] iMethod ���õ�ת������.
	* \return ת����Ľ��.
	*/
	int Str2Int(string strVal, int iMethod = 0);
	/*! \fn string Int2Str(int iVal, int iMethod = 0).
	* \brief ��int�ͱ�����ת��Ϊstring�ַ���.
	* \param[in] iVal    Ҫת����int����.
	* \param[in] iMethod ���õ�ת������.
	* \return ת����Ľ��.
	*/
	string Int2Str(int iVal, int iMethod = 0);
};

