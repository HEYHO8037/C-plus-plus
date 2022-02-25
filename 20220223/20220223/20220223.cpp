#include <iostream>
#include <random>

using namespace std;

int main(void)
{
	//1. ���������� ���� - ���� 0~2���� �ϳ��� ���� 1. ���� 2. ���� 3. �� 4. ����
	//�Է��� ���� ������ ���ؼ� ���������� ������ ������ �� �� �и� �Ǻ� �� 5���� ���� �� ��,��,�� ���(����)

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

		cout << "1. ���� 2. ���� 3. �� 4, ����" << endl;
		cin >> iPlayer;


		if (iPlayer == 1)
		{
			if (0 == iRandom)
			{
				cout << "���º� �Դϴ�." << endl;
				++iDraw;
			}
			else if (1 == iRandom)
			{
				cout << "�й� �Դϴ�." << endl;
				++iLose;
			}
			else
			{
				cout << "�¸� �Դϴ�." << endl;
				++iWin;
			}
		}
		else if (iPlayer == 2)
		{
			if (0 == iRandom)
			{
				cout << "�¸� �Դϴ�." << endl;
				++iWin;
			}
			else if (1 == iRandom)
			{
				cout << "���º� �Դϴ�." << endl;
				++iDraw;
			}
			else
			{
				cout << "�й� �Դϴ�." << endl;
				++iLose;
			}
		}
		else if (iPlayer == 3)
		{
			if (0 == iRandom)
			{
				cout << "�й� �Դϴ�." << endl;
				++iLose;
			}
			else if (1 == iRandom)
			{
				cout << "�¸� �Դϴ�." << endl;
				++iWin;
			}
			else
			{
				cout << "���º� �Դϴ�." << endl;
				++iDraw;
			}
		}
		else if (iPlayer == 4)
		{
			break;
		}
		else
		{
			cout << "�߸��� �Է��Դϴ� �ٽ� �Է����ּ���" << endl;
		}
	}

	cout << iWin << "�� " << iDraw << "�� " << iLose << "�� �Դϴ�." << endl;

	return 0;
}