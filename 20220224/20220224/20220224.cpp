#include <iostream>

using namespace std;

int GetMoney();
void ShowUI(int _iMoney);
int CheckMoney(int _iMoney);
void VendingMachine(int _iMoney);


int main(void)
{
	// 3. ���Ǳ� �����ϱ�(while) -  ������ �Է� - �ܾ� ǥ���Ͽ� ��� - �޴��� ��� 1. �ݶ�(100), 2. ���̴�(200). 3. ȯŸ(300) 4. ��ȯ
	// - ���ÿ� ���� ���Ž� �ܾ��� �ٲ����� - �������� ������ ��� ���Ŵ� �Ұ��� �ϰ�, �ܾ��� �����ϴٰ� ���, 4���� ������ �ܾ��� ---���Դϴ�.
	// ����� ����, system("cls") ���, system("pause") ���

	VendingMachine(GetMoney());

	return 0;
}

int GetMoney()
{
	int iMoney = 0;

	cout << "������ �Է� : ";
	cin >> iMoney;

	return iMoney;
}

void ShowUI(int _iMoney)
{
	system("cls");

	cout << "�ܾ� : " << _iMoney << endl;
	cout << "1. �ݶ�(100��)" << endl;
	cout << "2. ���̴�.(200��)" << endl;
	cout << "3. ȯŸ(300��)" << endl;
	cout << "4. ��ȯ" << endl;
}

int CheckMoney(int _iMoney)
{
	int iSelect;

	cin >> iSelect;

	if (iSelect == 1)
	{
		if (_iMoney >= 100)
		{
			_iMoney -= 100;
			return _iMoney;
		}
		else
		{
			cout << "�ܾ��� �����մϴ�." << endl;
			system("pause");
			return -2;
		}
		return _iMoney;
	}
	else if (iSelect == 2)
	{
		if (_iMoney >= 200)
		{
			_iMoney -= 200;
			return _iMoney;
		}
		else
		{
			cout << "�ܾ��� �����մϴ�." << endl;
			system("pause");
			return -2;
		}
	}
	else if (iSelect == 3)
	{
		if (_iMoney >= 300)
		{
			_iMoney -= 300;
			return _iMoney;
		}
		else
		{
			cout << "�ܾ��� �����մϴ�." << endl;
			system("pause");
			return _iMoney;
		}

	}
	else if (iSelect == 4)
	{
		system("cls");
		cout << "�ܵ��� ��ȯ�մϴ�." << endl;
		cout << "�ܵ� : " << _iMoney << endl;
		return -1;
	}
	else
	{
		cout << "�߸��� �����Դϴ� �ٽ� �Է����ּ���" << endl;
		system("pause");
		return _iMoney;
	}
}

void VendingMachine(int _iMoney)
{
	int iSelect = 0;
	int saveMoney = 0;

	while (true)
	{
		ShowUI(_iMoney);
		
		saveMoney = CheckMoney(_iMoney);

		if (-1 == saveMoney)
		{
			break;
		}
		else
		{
			_iMoney = saveMoney;
		}
		
		
	}
}