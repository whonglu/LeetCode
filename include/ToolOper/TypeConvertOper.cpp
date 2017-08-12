#include "TypeConvertOper.h"

CTypeConvertOper* CTypeConvertOper::m_pTypeConvertOper = NULL;
CTypeConvertOper::CTypeConvertOper(void)
{
}


CTypeConvertOper::~CTypeConvertOper(void)
{
}

CTypeConvertOper* CTypeConvertOper::GetInstance()
{
	if (NULL == m_pTypeConvertOper)
	{
		m_pTypeConvertOper = new CTypeConvertOper();
	}
	return m_pTypeConvertOper;
}

int CTypeConvertOper::Str2Int( string strVal, int iMethod /*= 0*/ )
{
	int iResult;
	switch (iMethod)
	{
	case 0:
		break;
	case 1:
		break;
	default:
		break;
	}
	return iResult;
}

std::string CTypeConvertOper::Int2Str( int iVal, int iMethod /*= 0*/ )
{
	//ע�⣬��intת��string����ʹ��to_string();Ҳ����ʹ��stringstream 
	string strResult;
	stringstream ss;
	switch (iMethod)
	{
	case 0:
		strResult = std::to_string((_LONGLONG)iVal);//ʹ��to_string()
		break;
	case 1:
		ss<<iVal;
		strResult = ss.str();//ʹ��stringstream
		break;
	default:
		break;
	}
	return strResult;
}


