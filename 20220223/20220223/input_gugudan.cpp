#include <iostream>

using namespace std;

int main(void)
{
	//3. for문을 이용해서 단과 곱을 입력받아서 구구단을 출력  -> 5단 6곱 -> 2단부터 5단까지, ? * 6 곱 까지 출력하게 만들어야 함

	int iDan = 0;
	int iGop = 0;

	cout << "최대출력할 단을 입력하세요 : ";
	cin >> iDan;

	cout << "최대출력할 곱을 입력하세요 : ";
	cin >> iGop;

	for (int i = 2; i <= iDan; ++i)
	{
		for (int j = 1; j <= iGop; ++j)
		{
			cout << i << " * " << j << " = " << i*j << endl;
		}
		cout << endl;
	}

	return 0;
}