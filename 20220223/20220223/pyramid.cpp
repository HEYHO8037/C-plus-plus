#include <iostream>

using namespace std;

int main(void)
{
	//4. �Ƕ�̵� ���(���ʱ��� ��,��, �������� ��,��) ( ���� ���� ) - �ʺ��� ��� ���� ���� �� ��� (5��¥�� -> �� �̻� �������)

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5-i; ++j)
		{
			cout << "*";
		}
		cout << " " << endl;
	}
	
	cout << "===================" << endl;

	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << "*";
		}
		cout << " " << endl;
	}

	cout << "===================" << endl;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << " ";
		}

		for (int k = 5; k > i; --k)
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << "===================" << endl;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 4; j > i; --j)
		{
			cout << " ";
		}

		for (int k = 0; k <= i; ++k)
		{
			cout << "*";
		}

		cout << endl;
	}

	return 0;
}