#include <iostream>

using namespace std;

int main(void)
{
	// 2. ���ڿ��� �Է¹޾� null���ڸ� ������ �������ڿ��� ���̸� ���ϴ� �Լ��� ������(strlen ������)

	char inputText[100];
	int iLength = 0;

	cout << "�Է��ϼ���(��/��) : ";
	cin >> inputText;


	for (int i = 0; '\0' != inputText[i]; ++i)
	{
		iLength++;
	}

	cout << "���� : " << iLength << endl;



	return 0;
}