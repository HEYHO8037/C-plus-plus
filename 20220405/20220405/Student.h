#pragma once

#include "stdafx.h"

class CStudent
{
private:
	string m_strName;
	int m_iKorean;
	int m_iEnglish;
	int m_iMath;
	int m_iTotal;
	float m_fAverage;

public:
	CStudent();
	CStudent(const CStudent& student);
	~CStudent();

public:
	string GetName() const;

public:
	void SetScore(const char* _pName, int _iKorean, int _iEnglish, int _iMath);
	void ShowScore();

};

