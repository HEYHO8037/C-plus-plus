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
		cout << " 1. �Է�, 2. ��ü ��� 3. �˻� ���, 4. �˻� ����, 5. ����" << endl;
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
			cout << "�ٽ� �Է��ϼ���" << endl;
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

	cout << "�̸� : ";
	cin >> strName;

	cout << "���� : ";
	cin >> iKorean;

	cout << "���� : ";
	cin >> iEnglish;

	cout << "���� : ";
	cin >> iMath;

	saveStudent = new CStudent();
	saveStudent->SetScore(strName.c_str(), iKorean, iEnglish, iMath);

	m_vecStudent.push_back(saveStudent);
}

void CGradeProgram::ShowSearchStudent()
{
	string szName;
	cout << "�˻��� �̸��� �Է��ϼ��� : ";
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

	cout << "�˻��� �̸��� �����ϴ�." << endl;
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
	cout << "������ �л� �̸��� �Է��ϼ��� : ";
	cin >> szName;

	vector<CStudent*>::iterator iter;
	vector<CStudent*>::iterator iterEnd = m_vecStudent.end();

	for (iter = m_vecStudent.begin(); iter != iterEnd; ++iter)
	{
		if (szName == (*iter)->GetName())
		{
			delete (*iter);
			m_vecStudent.erase(iter);
			cout << "�����Ǿ����ϴ�." << endl;
			system("pause");
			return;
		}
	}

	cout << "�˻��� �̸��� �����ϴ�." << endl;
	system("pause");
}
