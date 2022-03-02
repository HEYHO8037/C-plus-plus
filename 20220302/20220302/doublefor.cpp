#include <iostream>

using namespace std;

int main(void)
{
	// 2. 이중for문과 배열을 이용하여 다음처럼 출력하시오
	// 1,2,3,4,5
	// 6,7,8,9,10
	// 11,12,13,14,15
	// 16,17,18,19,20
	// 21,22,23,24,25

	int iArray[25];
	int iCheck = 0;

	for (int i = 0; 25 > i; ++i)
	{
		iArray[i] = i + 1;
	}

	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			cout << iArray[iCheck] << " ";
			iCheck++;
		}
		cout << endl;
	}
}