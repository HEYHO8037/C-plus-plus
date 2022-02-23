#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	// 4. 홀짝 게임 - 난수를 뽑아서 그 숫자가 홀인지 짝인지 판별하는 게임 난수는 1에서 10까지 중 하나를 생성, 1. 홀수 2. 짝수 3. 종료 총 5라운드를 실시
	// 마지막 라운드 종료시 몇승 몇패를 출력 매 라운드 마다 난수를 새로 뽑음

	int iComputer = 0;
	int iPlayer = 0;
	int iCount = 0;
	int iWin = 0;
	int iLose = 0;

	while (true)
	{
		srand((unsigned)time(NULL));
		iComputer = rand() % 11;

		if (iComputer == 0)
		{
			srand((unsigned)time(NULL));
			iComputer = rand() % 11;
		}
		else
		{

			system("cls");
			cout << "현재 " << iWin << "승 " << iLose << "패 중입니다." << endl;
			cout << "1. 홀수" << endl;
			cout << "2. 짝수" << endl;
			cout << "3. 종료" << endl;

			cin >> iPlayer;

			if (iPlayer == 1)
			{
				if (iComputer % 2 != 0)
				{
					cout << "홀수입니다. 컴퓨터 수 : " << iComputer << endl;
					cout << "플레이어 승리" << endl;
					iWin++;
					system("pause");
				}
				else
				{
					cout << "짝수입니다. 컴퓨터 수 : " << iComputer << endl;
					cout << "컴퓨터 승리" << endl;
					iLose++;
					system("pause");
				}
			}
			else if (iPlayer == 2)
			{
				if (iComputer % 2 == 0)
				{
					cout << "짝수입니다. 컴퓨터 수 : " << iComputer << endl;
					cout << "플레이어 승리" << endl;
					iWin++;
					system("pause");
				}
				else
				{
					cout << "홀수입니다. 컴퓨터 수 : " << iComputer << endl;
					cout << "컴퓨터 승리" << endl;
					iLose++;
					system("pause");
				}
			}
			else if (iPlayer == 3)
			{
				system("cls");
				break;
			}
			else
			{
				cout << "잘못된 입력입니다." << endl;
				system("pause");
			}

			iCount++;

			if (iCount == 5)
			{
				system("cls");
				break;
			}
		}
	}

	cout << iWin << "승 " << iLose << "패 하셨습니다." << endl;
	cout << "게임을 종료합니다." << endl;
}