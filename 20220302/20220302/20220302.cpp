#include <iostream>

using namespace std;
	
int GetMoney();
void ShowUI(int* _pMoney);
int CheckMoney(int* _pMoney);
void VendingMachine(int* _pMoney);


int main(void)
{
	// 1. ���Ǳ⸦ �����͸� �̿��Ͽ� �����.

	int Money = GetMoney();

	VendingMachine(&Money);

	return 0;
}

int GetMoney()
{
	int iMoney = 0;

	cout << "������ �Է� : ";
	cin >> iMoney;

	return iMoney;
}

void ShowUI(int* _pMoney)
{
	system("cls");

	cout << "�ܾ� : " << *_pMoney << endl;
	cout << "1. �ݶ�(100��)" << endl;
	cout << "2. ���̴�.(200��)" << endl;
	cout << "3. ȯŸ(300��)" << endl;
	cout << "4. ��ȯ" << endl;
}

int CheckMoney(int* _pMoney)
{
	int iSelect;

	cin >> iSelect;

	if (iSelect == 1)
	{
		if (*_pMoney >= 100)
		{
			*_pMoney -= 100;
			return *_pMoney;
		}
		else
		{
			cout << "�ܾ��� �����մϴ�." << endl;
			system("pause");
			return *_pMoney;
		}
		return *_pMoney;
	}
	else if (iSelect == 2)
	{
		if (*_pMoney >= 200)
		{
			*_pMoney -= 200;
			return *_pMoney;
		}
		else
		{
			cout << "�ܾ��� �����մϴ�." << endl;
			system("pause");
			return *_pMoney;
		}
	}
	else if (iSelect == 3)
	{
		if (*_pMoney >= 300)
		{
			*_pMoney -= 300;
			return *_pMoney;
		}
		else
		{
			cout << "�ܾ��� �����մϴ�." << endl;
			system("pause");
			return *_pMoney;
		}

	}
	else if (iSelect == 4)
	{
		system("cls");
		cout << "�ܵ��� ��ȯ�մϴ�." << endl;
		cout << "�ܵ� : " << *_pMoney << endl;
		return -1;
	}
	else
	{
		cout << "�߸��� �����Դϴ� �ٽ� �Է����ּ���" << endl;
		system("pause");
		return *_pMoney;
	}
}

void VendingMachine(int* _pMoney)
{
	int iSelect = 0;
	int saveMoney = 0;

	while (true)
	{
		ShowUI(_pMoney);

		saveMoney = CheckMoney(_pMoney);

		if (-1 == saveMoney)
		{
			break;
		}
		else
		{
			*_pMoney = saveMoney;
		}


	}
}