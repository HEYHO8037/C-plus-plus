#pragma once
#include "stdafx.h"

class CString
{
private:
	char* m_Str;
	int m_strSize;

public:
	CString();
	CString(const CString& otherString);
	~CString();
	CString(char* pChar);

public:
	bool operator==(const CString& otherString);
	bool operator==(const char* pChar);

	CString operator+(const CString& otherString);
	CString operator+(const char* pChar);

	CString& operator=(const CString& otherString);
	CString& operator=(const char* pChar);
};