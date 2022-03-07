
#include <iostream>

using namespace std;

const int maxLength = 3;
const int maxCharLength = 100;

struct Student
{
	char czName[maxCharLength];
	int iKorean;
	int iEnglish;
	int iMath;
	int iTotal;
	float fAverage;
};

void InputGrade(int* _pNumber, Student Grade[]);
void ShowAllGrade(int* _pNumber, Student Grade[]);
void ShowSearchGrade(int* _pNumber, Student Grade[]);


int main(void)
{
	// 1. ����ǥ ���α׷��� ����ü�� ���ؼ� ����� �ֵ��� �ٲ㺸��

	Student Grade[3];
	void(*ptrFunc[3])(int*, Student*) = { InputGrade, ShowAllGrade, ShowSearchGrade };
	int iInput;
	int iCount = 0;

	while (true)
	{
		system("cls");
		cout << "1. �Է� 2. ��ü��� 3. �˻���� 4. ����" << endl;
		cin >> iInput;

		if (iInput < 0 || iInput > 4)
		{
			cout << "�ٽ� �Է��ϼ���" << endl;
			system("pause");
		}
		else if (iInput == 4)
		{
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
		else
		{
			ptrFunc[iInput - 1](&iCount, Grade);
		}
	}

	return 0;
}

void InputGrade(int* _pNumber, Student Grade[])
{
	if ((*_pNumber) == 3)
	{
		cout << "3�� �ʰ��Ǿ����ϴ�." << endl;
		return;
	}
	else
	{
		cout << "�̸� : ";
		cin >> Grade[*_pNumber].czName;
		cout << "���� : ";
		cin >> Grade[*_pNumber].iMath;
		cout << "���� : ";
		cin >> Grade[*_pNumber].iEnglish;
		cout << "���� : ";
		cin >> Grade[*_pNumber].iKorean;

		Grade[*_pNumber].iTotal = Grade[*_pNumber].iMath + Grade[*_pNumber].iKorean + Grade[*_pNumber].iEnglish;
		Grade[*_pNumber].fAverage = (float)Grade[*_pNumber].iTotal / 3.f;
		(*_pNumber)++;
	}

}
void ShowAllGrade(int* _pNumber, Student Grade[])
{
	for (int i = 0; (*_pNumber) > i; ++i)
	{
		cout << Grade[i].czName << " : ";
		cout << "���� : " << Grade[i].iMath;
		cout << " ���� : " << Grade[i].iEnglish;
		cout << " ���� : " << Grade[i].iKorean;
		cout << " ���� : " << Grade[i].iTotal;
		cout << " ��� : " << Grade[i].fAverage << endl;
	}
}
void ShowSearchGrade(int* _pNumber, Student Grade[])
{
	char cSearchName[100];
	bool bIsEqual = false;
	int iSaveNumber = 0;

	cout << "�˻��� �̸� : ";
	cin >> cSearchName;


	for (int i = 0; i < *_pNumber; ++i)
	{
		if (!strcmp(cSearchName, Grade[i].czName))
		{
			bIsEqual = true;
			iSaveNumber = i;
			break;
		}
	}

	if (bIsEqual)
	{
		cout << Grade[iSaveNumber].czName << " : ";
		cout << "���� : " << Grade[iSaveNumber].iMath;
		cout << " ���� : " << Grade[iSaveNumber].iEnglish;
		cout << " ���� : " << Grade[iSaveNumber].iKorean;
		cout << " ���� : " << Grade[iSaveNumber].iTotal;
		cout << " ��� : " << Grade[iSaveNumber].fAverage << endl;
	}
	else
	{
		cout << "��ġ�ϴ� ����� �����ϴ�." << endl;
	}

}
