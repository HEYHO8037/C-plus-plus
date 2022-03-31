#include "stdafx.h"
#include "String.h"

CString::CString()
	: m_Str(nullptr),
	  m_strSize(0)
{
}

CString::CString(CString & otherString)
{
	m_strSize = otherString.m_strSize;

	m_Str = new char[m_strSize];

	for (int i = 0; i < m_strSize; ++i)
	{
		m_Str[i] = otherString.m_Str[i];
	}
}

CString::~CString()
{
	delete[] m_Str;
	m_Str = nullptr;
}

CString::CString(char * pChar)
{
	for (int i = 0; pChar[i] != '\0'; ++i)
	{
		m_strSize++;
	}

	m_strSize += 1;

	m_Str = new char[m_strSize];

	for (int i = 0; i < m_strSize; ++i)
	{
		if (i == (m_strSize - 1))
		{
			m_Str[i] = '\0';
			continue;
		}

		m_Str[i] = pChar[i];
	}
}

bool CString::operator==(const CString & otherString)
{
	int iCount = 0;

	for (int i = 0; i < m_strSize; ++i)
	{
		if (m_Str[i] == otherString.m_Str[i])
		{
			iCount++;
		}
	}

	if (iCount == m_strSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CString::operator==(const char * pChar)
{
	int iCount = 0;

	for (int i = 0; i < m_strSize; ++i)
	{
		if (m_Str[i] == pChar[i])
		{
			iCount++;
		}
	}

	if (iCount == m_strSize)
	{
		return true;
	}
	else
	{
		return false;
	}

}

CString CString::operator+(const CString & otherString)
{
	CString Str;
	int iCount = 0;
	Str.m_strSize = (m_strSize + otherString.m_strSize - 1);

	Str.m_Str = new char[Str.m_strSize];

	for (int i = 0; i < (m_strSize - 1); ++i)
	{
		Str.m_Str[iCount] = m_Str[iCount];
		iCount++;
	}

	for (int i = 0; i < otherString.m_strSize; ++i)
	{
		Str.m_Str[iCount] = otherString.m_Str[i];
		iCount++;
	}

	return Str;
}

CString CString::operator+(const char * pChar)
{
	CString Str;
	int iCount = 0;
	int iSaveNum = 0;

	for (int i = 0; pChar[i] != '\0'; ++i)
	{
		iCount++;
	}

	Str.m_strSize = (m_strSize + iCount);

	Str.m_Str = new char[Str.m_strSize];

	for (int i = 0; i < (m_strSize - 1); ++i)
	{
		Str.m_Str[iSaveNum] = m_Str[iSaveNum];
		iSaveNum++;
	}

	for (int i = 0; i < iCount; ++i)
	{
		Str.m_Str[iSaveNum] = pChar[i];
		iSaveNum++;
	}

	Str.m_Str[iSaveNum] = '\0';

	return Str;
}

CString & CString::operator=(const CString & otherString)
{
	// TODO: 여기에 반환 구문을 삽입합니다.

	if (m_Str == nullptr)
	{
		m_strSize = otherString.m_strSize;

		m_Str = new char[m_strSize];

		for (int i = 0; i < m_strSize; ++i)
		{
			m_Str[i] = otherString.m_Str[i];
		}
	}
	else
	{
		delete[] m_Str;

		m_strSize = otherString.m_strSize;

		m_Str = new char[m_strSize];

		for (int i = 0; i < m_strSize; ++i)
		{
			m_Str[i] = otherString.m_Str[i];
		}
	}


	return (*this);
}

CString & CString::operator=(const char * pChar)
{
	if (m_Str == nullptr)
	{
		for (int i = 0; pChar[i] != '\0'; ++i)
		{
			m_strSize++;
		}

		m_strSize += 1;

		m_Str = new char[m_strSize];

		for (int i = 0; i < m_strSize; ++i)
		{
			if (i == (m_strSize - 1))
			{
				m_Str[i] = '\0';
				continue;
			}

			m_Str[i] = pChar[i];
		}
	}
	else
	{
		delete[] m_Str;
		m_strSize = 0;

		for (int i = 0; pChar[i] != '\0'; ++i)
		{
			m_strSize++;
		}

		m_strSize += 1;

		m_Str = new char[m_strSize];

		for (int i = 0; i < m_strSize; ++i)
		{
			if (i == (m_strSize - 1))
			{
				m_Str[i] = '\0';
				continue;
			}

			m_Str[i] = pChar[i];
		}
	}

	return (*this);
}
