#include "StrOper.h"

CStrOper* CStrOper::m_pStrOper = NULL;
CStrOper::CStrOper(void)
{
}

CStrOper::~CStrOper(void)
{
}

CStrOper* CStrOper::GetInstance()
{
	if ( NULL == m_pStrOper )
	{
		m_pStrOper = new CStrOper();
	}
	return m_pStrOper;
}

std::string CStrOper::AppendFt( const char* pszsrc, const char* pszformat,... )
{
	va_list a_list;//Step 1. 在调用参数表之前，定义一个 va_list 类型的变量；
	va_start(a_list, pszformat);//Step 2. 初始化：通过 va_start 对 a_list 进行初始化，让它指向可变参数表里面的第一个参数（参数1是 a_list本身，参数2是在变参表前面紧挨着的一个变量,即“...”之前的那个参数；
	int nBytes = _vscprintf(pszformat, a_list);//Step 3. 获取参数，调用va_arg，它的第一个参数是ap，第二个参数是要获取的参数的指定类型，然后返回这个指定类型的值，并且把 ap 的位置指向变参表的下一个变量位置；
	std::vector<char> vabuf;
	vabuf.resize(nBytes+1);
	vsprintf(&vabuf[0], pszformat, a_list);
	va_end(a_list);//Step 4. 获取所有的参数之后，有必要将这个 a_list 指针关掉，以免发生危险，方法是调用 va_end，他是输入的参数 ap 置为 NULL，应该养成获取完参数表之后关闭指针的习惯。
	vabuf.push_back(0);
	string sr = pszsrc;
	sr += &vabuf[0];
	return sr;
}
