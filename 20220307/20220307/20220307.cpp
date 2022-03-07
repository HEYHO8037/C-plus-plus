
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
	// 1. 성적표 프로그램을 구조체를 통해서 만들수 있도록 바꿔보기

	Student Grade[3];
	void(*ptrFunc[3])(int*, Student*) = { InputGrade, ShowAllGrade, ShowSearchGrade };
	int iInput;
	int iCount = 0;

	while (true)
	{
		system("cls");
		cout << "1. 입력 2. 전체출력 3. 검색출력 4. 종료" << endl;
		cin >> iInput;

		if (iInput < 0 || iInput > 4)
		{
			cout << "다시 입력하세요" << endl;
			system("pause");
		}
		else if (iInput == 4)
		{
			cout << "프로그램을 종료합니다." << endl;
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
		cout << "3명 초과되었습니다." << endl;
		return;
	}
	else
	{
		cout << "이름 : ";
		cin >> Grade[*_pNumber].czName;
		cout << "수학 : ";
		cin >> Grade[*_pNumber].iMath;
		cout << "영어 : ";
		cin >> Grade[*_pNumber].iEnglish;
		cout << "국어 : ";
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
		cout << "수학 : " << Grade[i].iMath;
		cout << " 영어 : " << Grade[i].iEnglish;
		cout << " 국어 : " << Grade[i].iKorean;
		cout << " 총점 : " << Grade[i].iTotal;
		cout << " 평균 : " << Grade[i].fAverage << endl;
	}
}
void ShowSearchGrade(int* _pNumber, Student Grade[])
{
	char cSearchName[100];
	bool bIsEqual = false;
	int iSaveNumber = 0;

	cout << "검색할 이름 : ";
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
		cout << "수학 : " << Grade[iSaveNumber].iMath;
		cout << " 영어 : " << Grade[iSaveNumber].iEnglish;
		cout << " 국어 : " << Grade[iSaveNumber].iKorean;
		cout << " 총점 : " << Grade[iSaveNumber].iTotal;
		cout << " 평균 : " << Grade[iSaveNumber].fAverage << endl;
	}
	else
	{
		cout << "일치하는 결과가 없습니다." << endl;
	}

}
