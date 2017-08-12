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
	va_list a_list;//Step 1. �ڵ��ò�����֮ǰ������һ�� va_list ���͵ı�����
	va_start(a_list, pszformat);//Step 2. ��ʼ����ͨ�� va_start �� a_list ���г�ʼ��������ָ��ɱ����������ĵ�һ������������1�� a_list��������2���ڱ�α�ǰ������ŵ�һ������,����...��֮ǰ���Ǹ�������
	int nBytes = _vscprintf(pszformat, a_list);//Step 3. ��ȡ����������va_arg�����ĵ�һ��������ap���ڶ���������Ҫ��ȡ�Ĳ�����ָ�����ͣ�Ȼ�󷵻����ָ�����͵�ֵ�����Ұ� ap ��λ��ָ���α����һ������λ�ã�
	std::vector<char> vabuf;
	vabuf.resize(nBytes+1);
	vsprintf(&vabuf[0], pszformat, a_list);
	va_end(a_list);//Step 4. ��ȡ���еĲ���֮���б�Ҫ����� a_list ָ��ص������ⷢ��Σ�գ������ǵ��� va_end����������Ĳ��� ap ��Ϊ NULL��Ӧ�����ɻ�ȡ�������֮��ر�ָ���ϰ�ߡ�
	vabuf.push_back(0);
	string sr = pszsrc;
	sr += &vabuf[0];
	return sr;
}
