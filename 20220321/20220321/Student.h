#pragma once
#include "stdafx.h"

class CStudent
{
private:
	char m_cName[256];
	int m_iMath;
	int m_iKorean;
	int m_iEnglish;
	int m_iTotal;
	float m_fAverage;

public:
	CStudent();
	~CStudent();

public:
	void SetName(char* _pName);
	void SetMath(int _iMath);
	void SetEnglish(int _iEnglish);
	void SetKorean(int _iKorean);
	void Calculate();

	char* GetName() const;
	int GetMath() const;
	int GetKorean() const;
	int GetEnglish() const;
	int GetTotal() const;
	float GetAverage() const;
};