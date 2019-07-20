#include<iostream>
#include<cstring>

class CMystring
{
public:
	CMystring(char* pData = nullptr) : m_pData(pData) {}
	CMystring(const CMystring& str);
	~CMystring();

	CMystring& operator=(const CMystring& rhs);

private:
	char* m_pData;
};

CMystring::CMystring(const CMystring& str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}

CMystring::~CMystring()
{
	delete []m_pData;
}

CMystring& CMystring::operator=(const CMystring& rhs)
{
	if(&rhs == this)
		return *this;

	CMystring strTemp(rhs);
	char* pTemp = strTemp.m_pData;
	strTemp.m_pData = m_pData;
	m_pData = pTemp;

	return *this;
}

int main()
{
	CMystring A(new char[3]{'a', 'b', 'c'});
	CMystring B(new char[4]{'d', 'e', 'f', 'g'});
	CMystring C(A);

	A = B;
	A = A;
	C = A = B;
	
}
