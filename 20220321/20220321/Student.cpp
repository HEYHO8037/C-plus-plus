#include "stdafx.h"
#include "Student.h"

CStudent::CStudent()
	: m_cName(""),
	  m_iKorean(0),
	  m_iEnglish(0),
	  m_iMath(0),
	  m_iTotal(0),
	  m_fAverage(0.f)
{
}

CStudent::~CStudent()
{

}

void CStudent::SetName(char* _pName)
{
	for (int i = 0; _pName[i] != '\0'; ++i)
	{
		m_cName[i] = _pName[i];
	}
}

void CStudent::SetMath(int _iMath)
{
	m_iMath = _iMath;
}

void CStudent::SetEnglish(int _iEnglish)
{
	m_iEnglish = _iEnglish;
}

void CStudent::SetKorean(int _iKorean)
{
	m_iKorean = _iKorean;
}

void CStudent::Calculate()
{
	m_iTotal = m_iKorean + m_iMath + m_iEnglish;
	m_fAverage = (float)m_iTotal / 3.f;
}

char* CStudent::GetName() const
{
	return (char*)m_cName;
}

int CStudent::GetMath() const
{
	return m_iMath;
}

int CStudent::GetKorean() const
{
	return m_iKorean;
}

int CStudent::GetEnglish() const
{
	return m_iEnglish;
}

int CStudent::GetTotal() const
{
	return m_iTotal;
}

float CStudent::GetAverage() const
{
	return m_fAverage;
}