#include <iostream>

using namespace std;

void Swap(int* _pSwapA, int* _pSwapB);

int main(void)
{
	/*
	iA = 10, IB = 20;

	출력

	? : 함수와 포인터를 통해 두 숫자를 교환하여 출력하라.
	힌트 : 스왑 개념을 이용하시오.

	출력
	*/

	int iA = 10;
	int iB = 20;

	Swap(&iA, &iB);


	cout << "iA : " << iA << endl;
	cout << "iB : " << iB << endl;

	return 0;
}

void Swap(int* _pSwapA, int* _pSwapB)
{
	int saveNumber = 0;
	saveNumber = *(_pSwapB);
	*(_pSwapB) = *(_pSwapA);
	*(_pSwapA) = saveNumber;
}