#include <iostream>

using namespace std;

void Factorial(int _iNumber, int _iNumber2);

int main(void)
{
	 //1. 5 팩토리얼을 함수로 구현하시오

	Factorial(1,10);

	return 0;
}

void Factorial(int _iNumber, int _iNumber2)
{
	if (_iNumber2 == 0)
	{
		cout << _iNumber << endl;
		return;
	}

	_iNumber *= _iNumber2;
	_iNumber2 = _iNumber2 - 1;
	return Factorial(_iNumber, _iNumber2);
}