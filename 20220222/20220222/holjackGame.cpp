#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	// 4. Ȧ¦ ���� - ������ �̾Ƽ� �� ���ڰ� Ȧ���� ¦���� �Ǻ��ϴ� ���� ������ 1���� 10���� �� �ϳ��� ����, 1. Ȧ�� 2. ¦�� 3. ���� �� 5���带 �ǽ�
	// ������ ���� ����� ��� ���и� ��� �� ���� ���� ������ ���� ����

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
			cout << "���� " << iWin << "�� " << iLose << "�� ���Դϴ�." << endl;
			cout << "1. Ȧ��" << endl;
			cout << "2. ¦��" << endl;
			cout << "3. ����" << endl;

			cin >> iPlayer;

			if (iPlayer == 1)
			{
				if (iComputer % 2 != 0)
				{
					cout << "Ȧ���Դϴ�. ��ǻ�� �� : " << iComputer << endl;
					cout << "�÷��̾� �¸�" << endl;
					iWin++;
					system("pause");
				}
				else
				{
					cout << "¦���Դϴ�. ��ǻ�� �� : " << iComputer << endl;
					cout << "��ǻ�� �¸�" << endl;
					iLose++;
					system("pause");
				}
			}
			else if (iPlayer == 2)
			{
				if (iComputer % 2 == 0)
				{
					cout << "¦���Դϴ�. ��ǻ�� �� : " << iComputer << endl;
					cout << "�÷��̾� �¸�" << endl;
					iWin++;
					system("pause");
				}
				else
				{
					cout << "Ȧ���Դϴ�. ��ǻ�� �� : " << iComputer << endl;
					cout << "��ǻ�� �¸�" << endl;
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
				cout << "�߸��� �Է��Դϴ�." << endl;
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

	cout << iWin << "�� " << iLose << "�� �ϼ̽��ϴ�." << endl;
	cout << "������ �����մϴ�." << endl;
}