#include <iostream>

using namespace std;

const int maxLength = 3;
const int maxCharLength = 100;

void InputGrade(int* _pNumber, char(*_pName)[maxCharLength], int* _pKorean, int* _pMath, int* _pEnglish);
void ShowAllGrade(int* _pNumber, char(*_pName)[maxCharLength], int* _pKorean, int* _pMath, int* _pEnglish);
void ShowSearchGrade(int* _pNumber, char(*_pName)[maxCharLength], int* _pKorean, int* _pMath, int* _pEnglish);


int main(void)
{
	// 4. 3���� �Է� ������ ����ǥ ���α׷� �����(�̸�, ����, ����, ����, ����, ���)(����ü ������)
	// 1. �Է� 2. ��ü ��� 3. �˻� ��� 4. ����

	char cName[maxLength][maxCharLength];
	int iKorean[maxLength];
	int iMath[maxLength];
	int iEnglish[maxLength];
	int iInput = 0;
	int iCount = 0;

	while (true)
	{
		system("cls");
		cout << "1. �Է� 2. ��ü��� 3. �˻���� 4. ����" << endl;
		cin >> iInput;

		if (iInput == 1)
		{
			InputGrade(&iCount, cName, iKorean, iMath, iEnglish);
		}
		else if (iInput == 2)
		{
			ShowAllGrade(&iCount, cName, iKorean, iMath, iEnglish);
			system("pause");
		}
		else if (iInput == 3)
		{
			ShowSearchGrade(&iCount, cName, iKorean, iMath, iEnglish);
			system("pause");
		}
		else if (iInput == 4)
		{
			break;
		}
		else
		{
			cout << "�ٽ� �Է����ּ���" << endl;
			system("pause");
		}
	}





	return 0;
}

void InputGrade(int* _pNumber, char(*_pName)[maxCharLength], int* _pKorean, int* _pMath, int* _pEnglish)
{
	if((*_pNumber) == 3)
	{
		cout << "3�� �ʰ��Ǿ����ϴ�." << endl;
		return;
	}
	else
	{
		cout << "�̸� : ";
		cin >> _pName[*_pNumber];
		cout << "���� : ";
		cin >> _pMath[*_pNumber];
		cout << "���� : ";
		cin >> _pEnglish[*_pNumber];
		cout << "���� : ";
		cin >> _pKorean[*_pNumber];
		(*_pNumber)++;
	}

}
void ShowAllGrade(int* _pNumber, char(*_pName)[maxCharLength], int* _pKorean, int* _pMath, int* _pEnglish)
{
	int iAverage = 0;
	double iTotal = 0;

	for (int i = 0; (*_pNumber) > i; ++i)
	{
		iTotal = (_pMath)[i] + (_pEnglish)[i] + (_pKorean)[i];
		iAverage = (double)iTotal / 3.0;

		cout << _pName[i] << " : ";
		cout << "���� : " << _pMath[i];
		cout << " ���� : " << _pEnglish[i];
		cout << " ���� : " << _pKorean[i];
		cout << " ���� : " << iTotal;
		cout << " ��� : " << iAverage << endl;
	}
}
void ShowSearchGrade(int* _pNumber, char(*_pName)[maxCharLength], int* _pKorean, int* _pMath, int* _pEnglish)
{
	char cSearchName[100];
	int iIsEqual = 0;
	int iSaveNumber = 0;
	int iTotal = 0;
	int iAverage = 0;
	int iLength = 0;

	cout << "�˻��� �̸� : ";
	cin >> cSearchName;

	for (int i = 0; *_pNumber > i; ++i)
	{
		for (int k = 0; '\0' != _pName[i][k]; ++k)
		{
			iLength++;
		}


		for (int j = 0; j < iLength; ++j)
		{
			if (cSearchName[j] == _pName[i][j])
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
		iTotal = (_pMath)[iSaveNumber] + (_pEnglish)[iSaveNumber] + (_pKorean)[iSaveNumber];
		iAverage = (double)iTotal / 3.0;
		cout << _pName[iSaveNumber] << " : ";
		cout << "���� : " << _pMath[iSaveNumber];
		cout << " ���� : " << _pEnglish[iSaveNumber];
		cout << " ���� : " << _pKorean[iSaveNumber];
		cout << " ���� : " << iTotal;
		cout << " ��� : " << iAverage << endl;
	}
	else
	{
		cout << "��ġ�ϴ� ����� �����ϴ�." << endl;
	}

}
