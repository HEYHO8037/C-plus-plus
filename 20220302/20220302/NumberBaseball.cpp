#include <iostream>
#include <random>

using namespace std;

void InputArray(int* _pArray);
void InputPlayerNumber(int* _pArray);
bool CheckArray(int* _pRound, int* _pNumArray, int* _pPlayerArray);

int main(void)
{
	// 4. �߱����� - 1~9���� ���� 3���� ����, ������ ���� ����, �Է��ϴ� ���ڿ� ������ ������ ���� �ڸ��� ��ġ�ϸ� ��Ʈ����ũ, ���� ��ġ�ϸ� ��, ��ȸ �Է��� �� ��Ʈ����ũ �� �� ���
	// 3��Ʈ����ũ�� ������ ���� �¸�
	// 9������� ����, 3��Ʈ����ũ�� �� ����� �й�

	int iArray[3];
	int iRound = 0;
	int iInputArray[3];

	InputArray(iArray);

	for (int i = 0; 9 > i; ++i)
	{
		system("cls");
		InputPlayerNumber(iInputArray);
		if (CheckArray(&iRound, iArray, iInputArray))
		{
			cout << "������Ʈ����ũ �÷��̾� �¸��߽��ϴ�." << endl;
			break;
		}
	}
	

	return 0;
}


void InputArray(int* _pArray)
{
	random_device randomDevice;
	mt19937 random(randomDevice());
	uniform_int_distribution<int> range(1, 9);
	int iRandom = 0;

	for (int i = 0; 3 > i; ++i)
	{
		iRandom = range(random);
		if (!i)
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
void InputPlayerNumber(int* _pArray)
{
	cout << "���ڸ� �Է��Ͻÿ�" << endl;
	
	for (int i = 0; 3 > i; ++i)
	{
		cin >> *_pArray;
		_pArray++;
	}
}

bool CheckArray(int* _pRound, int* _pNumArray, int* _pPlayerArray)
{
	int iStrike = 0;
	int iBall = 0;
	(*_pRound)++;

	for (int i = 0; 3 > i; ++i)
	{
		for (int j = 0; 3 > j; ++j)
		{
			if (_pNumArray[i] == _pPlayerArray[j] && i == j)
			{
				iStrike++;
				break;
			}
			else if (_pNumArray[i] == _pPlayerArray[j] && i != j)
			{
				iBall++;
				break;
			}
		}
	}

	cout << *_pRound << "���� ����Դϴ�." << endl;
	cout << iStrike << " ��Ʈ����ũ " << iBall << " ��" << endl;
	system("pause");

	if (iStrike == 3)
	{
		return true;
	}
	else
	{
		if ((*_pRound) == 9)
		{
			cout << "��ǻ�Ͱ� �¸��߽��ϴ�." << endl;
		}
		return false;
	}
}