#include <iostream>
#include <random>

using namespace std;

void InputArray(int* _pArray);
void InputPlayerNumber(int* _pArray);
bool CheckArray(int* _pRound, int* _pNumArray, int* _pPlayerArray);

int main(void)
{
	// 4. 야구게임 - 1~9까지 숫자 3개를 추출, 정렬은 하지 않음, 입력하는 숫자와 무작위 숫자의 값의 자리가 일치하면 스트라이크, 값만 일치하면 볼, 매회 입력후 몇 스트라이크 몇 볼 출력
	// 3스트라이크가 나오면 게임 승리
	// 9라운드까지 진행, 3스트라이크를 못 만들면 패배

	int iArray[3];
	int iRound = 0;
	int iInputArray[3];

	InputArray(iArray);

	for (int i = 0; 9 > i; ++i)
	{
		system("cls");
		InputPlayerNumber(iInputArray);
		if (CheckArray(&iRound, iArray, iInputArray))
		{
			cout << "쓰리스트라이크 플레이어 승리했습니다." << endl;
			break;
		}
	}
	

	return 0;
}


void InputArray(int* _pArray)
{
	random_device randomDevice;
	mt19937 random(randomDevice());
	uniform_int_distribution<int> range(1, 9);
	int iRandom = 0;

	for (int i = 0; 3 > i; ++i)
	{
		iRandom = range(random);
		if (!i)
		{
			_pArray[i] = iRandom;
		}
		else
		{
			for (int j = 0; i > j; ++j)
			{
				if (iRandom == _pArray[j])
				{
					--j;
					iRandom = range(random);
				}
				else
				{
					_pArray[i] = iRandom;
				}
			}
		}
	}
}
void InputPlayerNumber(int* _pArray)
{
	cout << "숫자를 입력하시오" << endl;
	
	for (int i = 0; 3 > i; ++i)
	{
		cin >> *_pArray;
		_pArray++;
	}
}

bool CheckArray(int* _pRound, int* _pNumArray, int* _pPlayerArray)
{
	int iStrike = 0;
	int iBall = 0;
	(*_pRound)++;

	for (int i = 0; 3 > i; ++i)
	{
		for (int j = 0; 3 > j; ++j)
		{
			if (_pNumArray[i] == _pPlayerArray[j] && i == j)
			{
				iStrike++;
				break;
			}
			else if (_pNumArray[i] == _pPlayerArray[j] && i != j)
			{
				iBall++;
				break;
			}
		}
	}

	cout << *_pRound << "라운드 결과입니다." << endl;
	cout << iStrike << " 스트라이크 " << iBall << " 볼" << endl;
	system("pause");

	if (iStrike == 3)
	{
		return true;
	}
	else
	{
		if ((*_pRound) == 9)
		{
			cout << "컴퓨터가 승리했습니다." << endl;
		}
		return false;
	}
}