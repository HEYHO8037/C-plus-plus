#pragma once
#include "Student.h"

class CMainProgram
{
private:
	int m_iCount = 0;
	int m_iMaxCount = 3;
	CStudent* m_pStudent = nullptr;

public:
	void InitStudent(int _iMaxCount = 3);
	void ReleaseStudent();

public:
	void ProgramMain();
	int ShowMenu();
	void InputGrade();
	void ShowAllGrade();
	void ShowSearchGrade();
	void AdditionalGrade();
};