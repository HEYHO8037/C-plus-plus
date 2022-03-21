#pragma once
#include "stdafx.h"

class CStudent
{
private:
	char m_cName[256] = "";
	int m_iMath = 0;
	int m_iKorean = 0;
	int m_iEnglish = 0;
	int m_iTotal = 0;
	float m_fAverage = 0.f;

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