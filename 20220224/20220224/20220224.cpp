#include <iostream>

using namespace std;

int GetMoney();
void ShowUI(int _iMoney);
int CheckMoney(int _iMoney);
void VendingMachine(int _iMoney);


int main(void)
{
	// 3. 자판기 구현하기(while) -  소지금 입력 - 잔액 표기하여 출력 - 메뉴가 출력 1. 콜라(100), 2. 사이다(200). 3. 환타(300) 4. 반환
	// - 선택에 의해 구매시 잔액이 바뀌어야함 - 소지금이 부족할 경우 구매는 불가능 하고, 잔액이 부족하다고 출력, 4번을 누르면 잔액은 ---원입니다.
	// 출력후 종료, system("cls") 사용, system("pause") 사용

	VendingMachine(GetMoney());

	return 0;
}

int GetMoney()
{
	int iMoney = 0;

	cout << "소지금 입력 : ";
	cin >> iMoney;

	return iMoney;
}

void ShowUI(int _iMoney)
{
	system("cls");

	cout << "잔액 : " << _iMoney << endl;
	cout << "1. 콜라(100원)" << endl;
	cout << "2. 사이다.(200원)" << endl;
	cout << "3. 환타(300원)" << endl;
	cout << "4. 반환" << endl;
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
			cout << "잔액이 부족합니다." << endl;
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
			cout << "잔액이 부족합니다." << endl;
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
			cout << "잔액이 부족합니다." << endl;
			system("pause");
			return _iMoney;
		}

	}
	else if (iSelect == 4)
	{
		system("cls");
		cout << "잔돈을 반환합니다." << endl;
		cout << "잔돈 : " << _iMoney << endl;
		return -1;
	}
	else
	{
		cout << "잘못된 접근입니다 다시 입력해주세요" << endl;
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