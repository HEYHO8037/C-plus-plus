#include "stdafx.h"
#include "GradeProgram.h"


CGradeProgram::CGradeProgram()
{
	m_vecStudent.clear();
}

CGradeProgram::~CGradeProgram()
{
	vector<CStudent*>::iterator iter;
	vector<CStudent*>::iterator iterEnd = m_vecStudent.end();

	for (iter = m_vecStudent.begin(); iter != iterEnd; ++iter)
	{
		delete (*iter);
	}

	m_vecStudent.clear();
}

void CGradeProgram::Menu()
{
	int iInput;

	while (true)
	{
		system("cls");
		cout << " 1. 입력, 2. 전체 출력 3. 검색 출력, 4. 검색 삭제, 5. 종료" << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			system("cls");
			AddStudent();
			break;
		case 2:
			system("cls");
			ShowAllStudent();
			break;
		case 3:
			system("cls");
			ShowSearchStudent();
			break;
		case 4:
			system("cls");
			DeleteSearchStudent();
			break;
		case 5:
			return;
		default:
			cout << "다시 입력하세요" << endl;
			system("pause");
		}
	}
}

void CGradeProgram::AddStudent()
{
	CStudent* saveStudent;

	string strName;
	int iKorean;
	int iEnglish;
	int iMath;

	cout << "이름 : ";
	cin >> strName;

	cout << "국어 : ";
	cin >> iKorean;

	cout << "영어 : ";
	cin >> iEnglish;

	cout << "수학 : ";
	cin >> iMath;

	saveStudent = new CStudent();
	saveStudent->SetScore(strName.c_str(), iKorean, iEnglish, iMath);

	m_vecStudent.push_back(saveStudent);
}

void CGradeProgram::ShowSearchStudent()
{
	string szName;
	cout << "검색할 이름을 입력하세요 : ";
	cin >> szName;

	vector<CStudent*>::iterator iter;
	vector<CStudent*>::iterator iterEnd = m_vecStudent.end();

	for (iter = m_vecStudent.begin(); iter != iterEnd; ++iter)
	{
		if (szName == (*iter)->GetName())
		{
			(*iter)->ShowScore();
			system("pause");
			return;
		}
	}

	cout << "검색된 이름이 없습니다." << endl;
	system("pause");
}

void CGradeProgram::ShowAllStudent()
{
	vector<CStudent*>::iterator iter;
	vector<CStudent*>::iterator iterEnd = m_vecStudent.end();

	for (iter = m_vecStudent.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->ShowScore();
	}

	system("pause");
}

void CGradeProgram::DeleteSearchStudent()
{
	string szName;
	cout << "삭제할 학생 이름을 입력하세요 : ";
	cin >> szName;

	vector<CStudent*>::iterator iter;
	vector<CStudent*>::iterator iterEnd = m_vecStudent.end();

	for (iter = m_vecStudent.begin(); iter != iterEnd; ++iter)
	{
		if (szName == (*iter)->GetName())
		{
			delete (*iter);
			m_vecStudent.erase(iter);
			cout << "삭제되었습니다." << endl;
			system("pause");
			return;
		}
	}

	cout << "검색된 이름이 없습니다." << endl;
	system("pause");
}
