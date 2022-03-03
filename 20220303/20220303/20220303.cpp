#include <iostream>

using namespace std;
void InitArray(int(*_pArray)[4]);
void Rotation(int(*_pArray)[4]);
void ShowArray(int(*_pArray)[4]);

int main(void)
{
	// 1. 2차원 배열을 이용하여 90도 시계방향으로 4회전하여 출력하기(4x4 권장)

	int iArray[4][4];

	InitArray(iArray);
	ShowArray(iArray);

	cout << "==================" << endl;

	Rotation(iArray);
	ShowArray(iArray);

	cout << "==================" << endl;

	Rotation(iArray);
	ShowArray(iArray);

	cout << "==================" << endl;

	Rotation(iArray);
	ShowArray(iArray);

	cout << "==================" << endl;

	Rotation(iArray);
	ShowArray(iArray);

	cout << "==================" << endl;


	return 0;
}

void InitArray(int(*_pArray)[4])
{
	for (int i = 0; 4 > i; ++i)
	{
		for (int j = 0; 4 > j; ++j)
		{
			_pArray[i][j] = i * 4 + j + 1;
		}
	}
}

void Rotation(int(*_pArray)[4])
{
	int iMaxArrayNum = 3;
	int saveArray[4][4] = { 0 };

	for (int i = 0; 4 > i; ++i)
	{
		for (int j = 0; 4 > j; ++j)
		{
			saveArray[i][j] = _pArray[iMaxArrayNum - j][i];
		}
	}


	for (int i = 0; 4 > i; ++i)
	{
		for (int j = 0; 4 > j; ++j)
		{
			_pArray[i][j] = saveArray[i][j];
		}
	}

}

void ShowArray(int(*_pArray)[4])
{
	for (int i = 0; 4 > i; ++i)
	{
		for (int j = 0; 4 > j; ++j)
		{
			cout <<_pArray[i][j] << " ";
		}
		cout << endl;
	}
}