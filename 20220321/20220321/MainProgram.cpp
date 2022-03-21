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
			cout << "�ٽ� �Է����ּ���" << endl;
			system("pause");
		}
	}

	ReleaseStudent();
}

int CMainProgram::ShowMenu()
{
	int iInput;

	cout << "1. �Է� 2. ��ü��� 3. �˻���� 4. �߰��Է�(3�� �̻�), 5. ����" << endl;
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
		cout <<  m_iMaxCount << " �� �ʰ��Ǿ����ϴ�." << endl;
		return;
	}
	else
	{
		cout << "�̸� : ";
		cin >> cName;
		cout << "���� : ";
		cin >> iMath;
		cout << "���� : ";
		cin >> iEnglish;
		cout << "���� : ";
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
		cout << "���� : " << m_pStudent[i].GetMath();
		cout << " ���� : " << m_pStudent[i].GetEnglish();
		cout << " ���� : " << m_pStudent[i].GetKorean();
		cout << " ���� : " << m_pStudent[i].GetTotal();
		cout << " ��� : " << m_pStudent[i].GetAverage() << endl;
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

	cout << "�˻��� �̸� : ";
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
		cout << " ���� : " << m_pStudent[iSaveNumber].GetMath();
		cout << " ���� : " << m_pStudent[iSaveNumber].GetEnglish();
		cout << " ���� : " << m_pStudent[iSaveNumber].GetKorean();
		cout << " ���� : " << m_pStudent[iSaveNumber].GetTotal();
		cout << " ��� : " << m_pStudent[iSaveNumber].GetAverage() << endl;
	}
	else
	{
		cout << "��ġ�ϴ� ����� �����ϴ�." << endl;
	}
}

void CMainProgram::AdditionalGrade()
{
	int iInput;

	cout << "����� �� �߰����� �Է��ϼ��� : ";
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

		cout << "�߰� �Ϸ��߽��ϴ�." << endl;
	}
	else
	{
		cout << "�߰� �� �� �����ϴ�." << endl;
	}
}