#pragma once
#include "Student.h"

class CMainProgram
{
private:
	int m_iCount;
	int m_iMaxCount;
	CStudent* m_pStudent;

public:
	CMainProgram();
	~CMainProgram();

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