#include <iostream>

using namespace std;
int main(void)
{
	// 3. ���Ǳ� �����ϱ�(while) -  ������ �Է� - �ܾ� ǥ���Ͽ� ��� - �޴��� ��� 1. �ݶ�(100), 2. ���̴�(200). 3. ȯŸ(300) 4. ��ȯ
	// - ���ÿ� ���� ���Ž� �ܾ��� �ٲ����� - �������� ������ ��� ���Ŵ� �Ұ��� �ϰ�, �ܾ��� �����ϴٰ� ���, 4���� ������ �ܾ��� ---���Դϴ�.
	// ����� ����, system("cls") ���, system("pause") ���

	int iMoney = 0;
	int iSelect = 0;

	cout << "������ �Է� : ";
	cin >> iMoney;

	while (true)
	{
		system("cls");

		cout << "�ܾ� : " << iMoney << endl;
		cout << "1. �ݶ�(100��)" << endl;
		cout << "2. ���̴�.(200��)" << endl;
		cout << "3. ȯŸ(300��)" << endl;
		cout << "4. ��ȯ" << endl;

		cin >> iSelect;

		if (iSelect == 1)
		{
			if (iMoney >= 100)
			{
				iMoney -= 100;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�." << endl;
				system("pause");
			}
		}
		else if (iSelect == 2)
		{
			if (iMoney >= 200)
			{
				iMoney -= 200;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�." << endl;
				system("pause");
			}
		}
		else if (iSelect == 3)
		{
			if (iMoney >= 300)
			{
				iMoney -= 300;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�." << endl;
				system("pause");
			}
		}
		else if (iSelect == 4)
		{
			system("cls");
			cout << "�ܵ��� ��ȯ�մϴ�." << endl;
			cout << "�ܵ� : " << iMoney << endl;
			break;
		}
		else
		{
			cout << "�߸��� �����Դϴ� �ٽ� �Է����ּ���" << endl;
			system("pause");
		}
	}

	return 0;
}