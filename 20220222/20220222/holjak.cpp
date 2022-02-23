#include <iostream>

using namespace std;

int main(void)
{
	// 2. do while문을 이용해서 숫자를 입력받고(5회) 짝수인 경우에만 합을 구하는 프로그램 만들기

	int iCount = 0;
	int iGetNumber = 0;
	int iTotal = 0;

	do
	{
		cin >> iGetNumber;

		if (iGetNumber % 2 == 0)
		{
			iTotal += iGetNumber;
		}

		iCount++;

	} while (iCount < 5);

	cout << "====================" << endl;
	cout << "Result : " << iTotal << endl;

	return 0;
}