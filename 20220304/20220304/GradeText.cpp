#include <iostream>

using namespace std;

const int maxLength = 3;
const int maxCharLength = 100;

void InputGrade(int* _pNumber, char(*_pName)[maxCharLength], int* _pKorean, int* _pMath, int* _pEnglish);
void ShowAllGrade(int* _pNumber, char(*_pName)[maxCharLength], int* _pKorean, int* _pMath, int* _pEnglish);
void ShowSearchGrade(int* _pNumber, char(*_pName)[maxCharLength], int* _pKorean, int* _pMath, int* _pEnglish);


int main(void)
{
	// 4. 3명의 입력 가능한 성적표 프로그램 만들기(이름, 국어, 영어, 수학, 총점, 평균)(구조체 사용금지)
	// 1. 입력 2. 전체 출력 3. 검색 출력 4. 종료

	char cName[maxLength][maxCharLength];
	int iKorean[maxLength];
	int iMath[maxLength];
	int iEnglish[maxLength];
	int iInput = 0;
	int iCount = 0;

	while (true)
	{
		system("cls");
		cout << "1. 입력 2. 전체출력 3. 검색출력 4. 종료" << endl;
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
			cout << "다시 입력해주세요" << endl;
			system("pause");
		}
	}





	return 0;
}

void InputGrade(int* _pNumber, char(*_pName)[maxCharLength], int* _pKorean, int* _pMath, int* _pEnglish)
{
	if((*_pNumber) == 3)
	{
		cout << "3명 초과되었습니다." << endl;
		return;
	}
	else
	{
		cout << "이름 : ";
		cin >> _pName[*_pNumber];
		cout << "수학 : ";
		cin >> _pMath[*_pNumber];
		cout << "영어 : ";
		cin >> _pEnglish[*_pNumber];
		cout << "국어 : ";
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
		cout << "수학 : " << _pMath[i];
		cout << " 영어 : " << _pEnglish[i];
		cout << " 국어 : " << _pKorean[i];
		cout << " 총점 : " << iTotal;
		cout << " 평균 : " << iAverage << endl;
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

	cout << "검색할 이름 : ";
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
		cout << "수학 : " << _pMath[iSaveNumber];
		cout << " 영어 : " << _pEnglish[iSaveNumber];
		cout << " 국어 : " << _pKorean[iSaveNumber];
		cout << " 총점 : " << iTotal;
		cout << " 평균 : " << iAverage << endl;
	}
	else
	{
		cout << "일치하는 결과가 없습니다." << endl;
	}

}
