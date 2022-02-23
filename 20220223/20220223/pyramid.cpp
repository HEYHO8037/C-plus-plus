#include <iostream>

using namespace std;

int main(void)
{
	//4. 피라미드 출력(왼쪽기준 상,하, 우측기준 상,하) ( 이중 포문 ) - 초보인 경우 왼쪽 기준 상만 출력 (5단짜리 -> 그 이상 상관없음)

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