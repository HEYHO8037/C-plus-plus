#include "stdafx.h"
#include "Student.h"


CStudent::CStudent()
	: m_iEnglish(0),
	  m_iMath(0),
	  m_iKorean(0),
	  m_iTotal(0),
	  m_fAverage(0)
{
}

CStudent::CStudent(const CStudent & student)
	: m_strName(student.m_strName),
	  m_iEnglish(student.m_iEnglish),
	  m_iMath(student.m_iMath),
	  m_iKorean(student.m_iKorean),
	  m_iTotal(student.m_iTotal),
	  m_fAverage(student.m_fAverage)
{
}


CStudent::~CStudent()
{
}

string CStudent::GetName() const
{
	return m_strName;
}

void CStudent::SetScore(const char * _pName, int _iKorean, int _iEnglish, int _iMath)
{
	m_strName = _pName;
	m_iKorean = _iKorean;
	m_iEnglish = _iEnglish;
	m_iMath = _iMath;

	m_iTotal = m_iKorean + m_iEnglish + m_iMath;
	m_fAverage = static_cast<float>(m_iTotal) / 3.f;
}

void CStudent::ShowScore()
{
	cout << "이름 : " << m_strName;
	cout << " 국어 : " << m_iKorean;
	cout << " 영어 : " << m_iEnglish;
	cout << " 수학 : " << m_iMath;
	cout << " 평균 : " << m_fAverage << endl;
}
