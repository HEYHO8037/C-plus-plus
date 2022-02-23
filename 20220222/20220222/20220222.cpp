#include <iostream>

using namespace std;

int main(void)
{
	// 1. while문으로 구구단 2단에서 9단까지 출력
	
	int iFirstNumber = 2;
	int iSecondNumber = 1;

	while (true)
	{
		if (iSecondNumber > 9)
		{
			cout << endl;

			iFirstNumber++;
			iSecondNumber = 1;
			
			if (iFirstNumber > 9)
			{
				break;
			}

		}
		else
		{
			cout << iFirstNumber << " * " << iSecondNumber << " = " << iFirstNumber * iSecondNumber << endl;
			iSecondNumber++;
		}
	}


	return 0;
}