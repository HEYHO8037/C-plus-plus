#include <iostream>

using namespace std;

void Swap(int* _pSwapA, int* _pSwapB);

int main(void)
{
	/*
	iA = 10, IB = 20;

	���

	? : �Լ��� �����͸� ���� �� ���ڸ� ��ȯ�Ͽ� ����϶�.
	��Ʈ : ���� ������ �̿��Ͻÿ�.

	���
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