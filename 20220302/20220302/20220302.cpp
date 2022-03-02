#include <iostream>

using namespace std;
	
int GetMoney();
void ShowUI(int* _pMoney);
int CheckMoney(int* _pMoney);
void VendingMachine(int* _pMoney);


int main(void)
{
	// 1. 자판기를 포인터를 이용하여 만들기.

	int Money = GetMoney();

	VendingMachine(&Money);

	return 0;
}

int GetMoney()
{
	int iMoney = 0;

	cout << "소지금 입력 : ";
	cin >> iMoney;

	return iMoney;
}

void ShowUI(int* _pMoney)
{
	system("cls");

	cout << "잔액 : " << *_pMoney << endl;
	cout << "1. 콜라(100원)" << endl;
	cout << "2. 사이다.(200원)" << endl;
	cout << "3. 환타(300원)" << endl;
	cout << "4. 반환" << endl;
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
			cout << "잔액이 부족합니다." << endl;
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
			cout << "잔액이 부족합니다." << endl;
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
			cout << "잔액이 부족합니다." << endl;
			system("pause");
			return *_pMoney;
		}

	}
	else if (iSelect == 4)
	{
		system("cls");
		cout << "잔돈을 반환합니다." << endl;
		cout << "잔돈 : " << *_pMoney << endl;
		return -1;
	}
	else
	{
		cout << "잘못된 접근입니다 다시 입력해주세요" << endl;
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