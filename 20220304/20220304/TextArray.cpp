#include <iostream>

using namespace std;

int main(void)
{
	// 2. 문자열을 입력받아 null문자를 제외한 순수문자열의 길이를 구하는 함수를 만들어라(strlen 쓰지마)

	char inputText[100];
	int iLength = 0;

	cout << "입력하세요(한/영) : ";
	cin >> inputText;


	for (int i = 0; '\0' != inputText[i]; ++i)
	{
		iLength++;
	}

	cout << "길이 : " << iLength << endl;



	return 0;
}