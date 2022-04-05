#pragma once

#include "Student.h"

class CGradeProgram
{
private:
	vector<CStudent*> m_vecStudent;

public:
	CGradeProgram();
	~CGradeProgram();

public:
	void Menu();
	void AddStudent();
	void ShowSearchStudent();
	void ShowAllStudent();
	void DeleteSearchStudent();
};

