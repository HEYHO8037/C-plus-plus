#include <iostream>
#include <random>

using namespace std;

int main(void)
{
	//1. 가위바위보 게임 - 난수 0~2에서 하나를 생성 1. 가위 2. 바위 3. 보 4. 종료
	//입력한 값과 난수를 비교해서 가위바위보 게임을 시작함 승 무 패를 판별 총 5라운드 실행 후 승,무,패 출력(자율)

	int iRandom = 0;
	int iPlayer = 0;
	int iWin = 0;
	int iLose = 0;
	int iDraw = 0;

	random_device randomDevice;
	mt19937 random(randomDevice());
	uniform_int_distribution<int> range(1, 3);

	for (int i = 0; 5 > i; ++i)
	{
		iRandom = range(random);

		cout << "1. 가위 2. 바위 3. 보 4, 종료" << endl;
		cin >> iPlayer;


		if (iPlayer == 1)
		{
			if (0 == iRandom)
			{
				cout << "무승부 입니다." << endl;
				++iDraw;
			}
			else if (1 == iRandom)
			{
				cout << "패배 입니다." << endl;
				++iLose;
			}
			else
			{
				cout << "승리 입니다." << endl;
				++iWin;
			}
		}
		else if (iPlayer == 2)
		{
			if (0 == iRandom)
			{
				cout << "승리 입니다." << endl;
				++iWin;
			}
			else if (1 == iRandom)
			{
				cout << "무승부 입니다." << endl;
				++iDraw;
			}
			else
			{
				cout << "패배 입니다." << endl;
				++iLose;
			}
		}
		else if (iPlayer == 3)
		{
			if (0 == iRandom)
			{
				cout << "패배 입니다." << endl;
				++iLose;
			}
			else if (1 == iRandom)
			{
				cout << "승리 입니다." << endl;
				++iWin;
			}
			else
			{
				cout << "무승부 입니다." << endl;
				++iDraw;
			}
		}
		else if (iPlayer == 4)
		{
			break;
		}
		else
		{
			cout << "잘못된 입력입니다 다시 입력해주세요" << endl;
		}
	}

	cout << iWin << "승 " << iDraw << "무 " << iLose << "패 입니다." << endl;

	return 0;
}