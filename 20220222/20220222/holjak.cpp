#include <iostream>

using namespace std;

int main(void)
{
	// 2. do while���� �̿��ؼ� ���ڸ� �Է¹ް�(5ȸ) ¦���� ��쿡�� ���� ���ϴ� ���α׷� �����

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