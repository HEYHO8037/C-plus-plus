#include <iostream>

using namespace std;

const int iArraySize = 5;

void InitArray(int(*_pArray)[iArraySize]);
void ShowArray(int(*_pArray)[iArraySize]);
int InputArray(int(*_pArray)[iArraySize]);
void SwapArray(int(*_pArray)[iArraySize], int _iInputNumber, int* saveX, int* saveY);

int main(void)
{
	// 1. 0 숫자이동 - 5*5로 0~24까지 출력, 으로 숫자를 0을 이동, 더 이상 갈수 없으면 움직임 불가

	int iArray[iArraySize][iArraySize];
	int iX = 0;
	int iY = 0;

	InitArray(iArray);

	while (true)
	{
		system("cls");
		ShowArray(iArray);
		SwapArray(iArray, InputArray(iArray), &iX, &iY);
	}

	return 0;
}

void InitArray(int(*_pArray)[iArraySize])
{
	for (int i = 0; iArraySize > i; ++i)
	{
		for (int j = 0; iArraySize > j; ++j)
		{
			_pArray[i][j] = i * iArraySize + j;
		}
	}
}

void ShowArray(int(*_pArray)[iArraySize])
{
	for (int i = 0; iArraySize > i; ++i)
	{
		for (int j = 0; iArraySize > j; ++j)
		{
			cout << _pArray[i][j] << "\t";
		}
		cout << endl;
	}
}

int InputArray(int(*_pArray)[iArraySize])
{
	int iInputNumber = 0;

	cout << "==========================================" << endl;
	cout << "2(아래) 4(왼쪽) 8(위쪽) 6(오른쪽)" << endl;
	cin >> iInputNumber;

	return iInputNumber;

}

void SwapArray(int(*_pArray)[iArraySize], int _iInputNumber, int* saveX, int* saveY)
{
	int saveNumber = 0;

	if ((_iInputNumber) == 2)
	{
		if (*saveY >= 0 && *saveY < 4)
		{
			saveNumber = _pArray[(*saveY) + 1][(*saveX)];
			_pArray[(*saveY) + 1][(*saveX)] = _pArray[(*saveY)][(*saveX)];
			_pArray[(*saveY)][(*saveX)] = saveNumber;
			(*saveY) += 1;
		}
	}
	else if ((_iInputNumber) == 4)
	{

		if (*saveX >= 1 && *saveX <= 4)
		{
			saveNumber = _pArray[(*saveY)][(*saveX) - 1];
			_pArray[(*saveY)][(*saveX) - 1] = _pArray[(*saveY)][(*saveX)];
			_pArray[(*saveY)][(*saveX)] = saveNumber;
			(*saveX) -= 1;
		}
	}
	else if ((_iInputNumber) == 6)
	{
		if (*saveX >= 0 && *saveX < 4)
		{
			saveNumber = _pArray[(*saveY)][(*saveX) + 1];
			_pArray[(*saveY)][(*saveX) + 1] = _pArray[(*saveY)][(*saveX)];
			_pArray[(*saveY)][(*saveX)] = saveNumber;
			(*saveX) += 1;
		}
	}
	else if ((_iInputNumber) == 8)
	{
		if (*saveY >= 1 && *saveY <= 4)
		{
			saveNumber = _pArray[(*saveY) - 1][(*saveX)];
			_pArray[(*saveY) - 1][(*saveX)] = _pArray[(*saveY)][(*saveX)];
			_pArray[(*saveY)][(*saveX)] = saveNumber;
			(*saveY) -= 1;
		}
	}
	else
	{
		cout << "잘못된 입력입니다" << endl;
		cout << "다시 입력하세요" << endl;
	}
}