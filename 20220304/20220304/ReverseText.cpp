#include <iostream>

using namespace std;

int main(void)
{
	// 3. 입력받는 문자열을 뒤집는 함수를 만들기

	char inputText[100];
	int iLength = 0;
	int iHalfPoint = 0;

	cout << "입력하세요(영어) : ";
	cin >> inputText;


	for (int i = 0; '\0' != inputText[i]; ++i)
	{
		iLength++;
	}

	iHalfPoint = iLength / 2;

	for (int i = (iLength - 1); iHalfPoint <= i; --i)
	{
		char saveText = inputText[(iLength - 1) - i];
		inputText[(iLength - 1) - i] = inputText[i];
		inputText[i] = saveText;
	}

	cout << inputText << endl;



	return 0;
}
