#include <iostream>
#include <random>

using namespace std;

void InputArray(int* _pArray);
void SortArray(int* _pArray);
void ShowArray(int* _pArray);

int main(void)
{
	// 3. 로또 만들기 - 배열을 이용하여 1~45사이의 수중 무작위로 6개의 숫자를 5회를 출력,
	//같은 회차에서는 절대 중복 번호가 나올수가 없음, 오름차순으로 정렬(버블정렬)

	int iArray[6];

	InputArray(iArray);
	SortArray(iArray);
	ShowArray(iArray);
	
	
	return 0;
}

void InputArray(int* _pArray)
{
	random_device randomDevice;
	mt19937 random(randomDevice());
	uniform_int_distribution<int> range(1, 45);
	int iRandom = 0;

	for (int i = 0; 5 > i; ++i)
	{
		iRandom = range(random);
		if (i == 0)
		{
			_pArray[i] = iRandom;
		}
		else
		{
			for (int j = 0; i > j; ++j)
			{
				if (iRandom == _pArray[j])
				{
					--j;
					iRandom = range(random);
				}
				else
				{
					_pArray[i] = iRandom;
				}
			}
		}
	}
}

void SortArray(int* _pArray)
{
	int iSwap = 0;

	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			if (i == j)
			{
				continue;
			}
			else
			{
				if (_pArray[i] < _pArray[j])
				{
					iSwap = _pArray[i];
					_pArray[i] = _pArray[j];
					_pArray[j] = iSwap;
				}
			}
		}
	}
}

void ShowArray(int* _pArray)
{
	for (int i = 0; 5 > i; ++i)
	{
		cout << _pArray[i] << " ";
	}

	cout << endl;
}