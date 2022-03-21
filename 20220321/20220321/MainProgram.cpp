#include "stdafx.h"
#include "MainProgram.h"

void CMainProgram::InitStudent(int _iMaxCount)
{
	m_iMaxCount = _iMaxCount;
	m_iCount = 0;
	m_pStudent = new CStudent[m_iMaxCount];
}

void CMainProgram::ReleaseStudent()
{
	delete[] m_pStudent;
	m_pStudent = nullptr;
}

void CMainProgram::ProgramMain()
{
	InitStudent();

	int iInput;

	while (true)
	{
		system("cls");
		iInput = ShowMenu();

		if (1 == iInput)
		{
			InputGrade();
			system("pause");
		}
		else if (2 == iInput)
		{
			ShowAllGrade();
			system("pause");
		}
		else if (3 == iInput)
		{
			ShowSearchGrade();
			system("pause");
		}
		else if (4 == iInput)
		{
			AdditionalGrade();
			system("pause");
		}
		else if (5 == iInput)
		{
			ReleaseStudent();
			return;
		}
		else
		{
			cout << "다시 입력해주세요" << endl;
			system("pause");
		}
	}

	ReleaseStudent();
}

int CMainProgram::ShowMenu()
{
	int iInput;

	cout << "1. 입력 2. 전체출력 3. 검색출력 4. 추가입력(3개 이상), 5. 종료" << endl;
	cin >> iInput;

	return iInput;
}

void CMainProgram::InputGrade()
{
	char cName[256];
	int iMath;
	int iKorean;
	int iEnglish;

	if (m_iMaxCount == m_iCount)
	{
		cout <<  m_iMaxCount << " 명 초과되었습니다." << endl;
		return;
	}
	else
	{
		cout << "이름 : ";
		cin >> cName;
		cout << "수학 : ";
		cin >> iMath;
		cout << "영어 : ";
		cin >> iEnglish;
		cout << "국어 : ";
		cin >> iKorean;

		m_pStudent[m_iCount].SetName(cName);
		m_pStudent[m_iCount].SetEnglish(iEnglish);
		m_pStudent[m_iCount].SetKorean(iKorean);
		m_pStudent[m_iCount].SetMath(iMath);
		m_pStudent[m_iCount].Calculate();
		m_iCount++;
	}
}

void CMainProgram::ShowAllGrade()
{
	int iAverage = 0;
	double iTotal = 0;

	for (int i = 0; m_iCount > i; ++i)
	{

		cout << m_pStudent[i].GetName() << " : ";
		cout << "수학 : " << m_pStudent[i].GetMath();
		cout << " 영어 : " << m_pStudent[i].GetEnglish();
		cout << " 국어 : " << m_pStudent[i].GetKorean();
		cout << " 총점 : " << m_pStudent[i].GetTotal();
		cout << " 평균 : " << m_pStudent[i].GetAverage() << endl;
	}
}

void CMainProgram::ShowSearchGrade()
{
	char cSearchName[100];
	int iIsEqual = 0;
	int iSaveNumber = 0;
	int iTotal = 0;
	int iAverage = 0;
	int iLength = 0;

	cout << "검색할 이름 : ";
	cin >> cSearchName;

	for (int i = 0; m_iCount > i; ++i)
	{
		for (int k = 0; '\0' != m_pStudent[i].GetName()[k]; ++k)
		{
			iLength++;
		}


		for (int j = 0; j < iLength; ++j)
		{
			if (cSearchName[j] == m_pStudent[i].GetName()[j])
			{
				iIsEqual++;
			}
		}

		if (iIsEqual == iLength)
		{
			iSaveNumber = i;
			break;
		}
		else
		{
			iIsEqual = 0;
		}
	}

	if (iIsEqual == iLength)
	{
		cout << m_pStudent[iSaveNumber].GetName() << " :";
		cout << " 수학 : " << m_pStudent[iSaveNumber].GetMath();
		cout << " 영어 : " << m_pStudent[iSaveNumber].GetEnglish();
		cout << " 국어 : " << m_pStudent[iSaveNumber].GetKorean();
		cout << " 총점 : " << m_pStudent[iSaveNumber].GetTotal();
		cout << " 평균 : " << m_pStudent[iSaveNumber].GetAverage() << endl;
	}
	else
	{
		cout << "일치하는 결과가 없습니다." << endl;
	}
}

void CMainProgram::AdditionalGrade()
{
	int iInput;

	cout << "몇명을 더 추가할지 입력하세요 : ";
	cin >> iInput;

	if (iInput > 0)
	{
		m_iMaxCount += iInput;
		CStudent* saveStudent = new CStudent[m_iMaxCount];

		for (int i = 0; i < m_iCount; ++i)
		{
			saveStudent[i].SetName(m_pStudent[i].GetName());
			saveStudent[i].SetEnglish(m_pStudent[i].GetEnglish());
			saveStudent[i].SetMath(m_pStudent[i].GetMath());
			saveStudent[i].SetKorean(m_pStudent[i].GetKorean());
			saveStudent[i].Calculate();
		}

		ReleaseStudent();

		m_pStudent = saveStudent;
		saveStudent = nullptr;

		cout << "추가 완료했습니다." << endl;
	}
	else
	{
		cout << "추가 할 수 없습니다." << endl;
	}
}