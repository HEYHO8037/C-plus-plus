#include <iostream>

using namespace std;

int main(void)
{
	//2. for문을 이용해서 구구단 2단에서 9단까지 출력(이중포문)

	for (int i = 2; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			cout << i << " * " << j << " = " << i*j << endl;
		}
		cout << endl;
	}

	return 0;
}