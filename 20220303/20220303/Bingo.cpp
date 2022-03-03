#include <iostream>
#include <random>

using namespace std;

void InitArray(int(*_pPlayerArray)[5], int(*_pComputerArray)[5]);
void ShowArray(int(*_pPlayerArray)[5], int(*_pComputerArray)[5]);
void InputNumber(int* _pNumber);
void SelectArray(int(*_pPlayerArray)[5], int* _pNumber);
void ComputerArray(int(*_pComputerArray)[5]);
int CheckTopDownArray(int(*_pPlayerArray)[5]);
int CheckLeftRightArray(int(*_pPlayerArray)[5]);
int CheckDiagonalArray(int(*_pPlayerArray)[5]);
int CheckComputerTopDownArray(int(*_pComputerArray)[5]);
int CheckComputerLeftRightArray(int(*_pComputerArray)[5]);
int CheckComputerDiagonalArray(int(*_pComputerArray)[5]);

int main(void)
{
	// 2. ���� ����(���Ѵ��) - 5x5 �迭�� �̿��Ͽ� 1���� 25�������� �����ϰ� ���, ���ڸ� �����ؼ� �Է��ϸ� ��ġ�ϴ� ���ڴ� *�� ġȯ�Ͽ� ���
	// *�� ǥ�õ� ���ڰ� ���� ���� �밢������ 5���� �ɶ����� ���� �ϳ� ����, 5���� �Ǹ� �¸��� ����, aI �߰�
	
	int iPlayerArray[5][5];
	int iComputerArray[5][5];
	int iInputNumber = 0;
	int iPlayerBingo = 0;
	int iComputerBingo = 0;
	int iComputerSaveNumer = 0;

	InitArray(iPlayerArray, iComputerArray);

	while (true)
	{
		system("cls");
		ShowArray(iPlayerArray, iComputerArray);

		if (iPlayerBingo >= 5)
		{
			cout << "5 ���� �÷��̾� �¸�" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
		else if (iComputerBingo >= 5)
		{
			cout << "5 ���� ��ǻ�� �¸�" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
		else
		{
			iComputerBingo = 0;
			iPlayerBingo = 0;
		}

		InputNumber(&iInputNumber);
		SelectArray(iPlayerArray, &iInputNumber);
		ComputerArray(iComputerArray);

		iPlayerBingo += CheckTopDownArray(iPlayerArray);
		iPlayerBingo += CheckDiagonalArray(iPlayerArray);
		iPlayerBingo += CheckLeftRightArray(iPlayerArray);
		iComputerBingo += CheckComputerTopDownArray(iComputerArray);
		iComputerBingo += CheckComputerDiagonalArray(iComputerArray);
		iComputerBingo += CheckComputerLeftRightArray(iComputerArray);

		cout << "Player : " <<  iPlayerBingo << " ����" << endl;
		cout << "============================================" << endl;
		cout << "Computer : " << iComputerBingo << " ����" << endl;

		

		system("pause");
	}

	return 0;
}


void InitArray(int(*_pPlayerArray)[5], int(*_pComputerArray)[5])
{
	random_device randomDevice;
	mt19937 random(randomDevice());
	uniform_int_distribution<int> range(1, 25);

	int iMaxArray = 5;
	int iArray[25];
	int iSaveNum = 0;

	for (int i = 0; 25 > i; ++i)
	{
		iArray[i] = i + 1;
	}

	for (int i = 0; 10 > i; ++i)
	{
		int iRandomOne = range(random) - 1;
		int iRandomTwo = range(random) - 1;

		iSaveNum = iArray[iRandomTwo];

		iArray[iRandomTwo] = iArray[iRandomOne];

		iArray[iRandomOne] = iSaveNum;
	}


	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			_pPlayerArray[i][j] = iArray[i * iMaxArray + j];
		}
	}

	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			_pComputerArray[i][j] = iArray[i * iMaxArray + j];
		}
	}
}

void ShowArray(int(*_pPlayerArray)[5], int(*_pComputerArray)[5])
{
	cout << "Player Bingo" << endl;
	cout << "=============================" << endl;
	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			if (_pPlayerArray[i][j] == 0)
			{
				cout << "*" << "\t";
			}
			else
			{
				cout << _pPlayerArray[i][j] << "\t";
			}
		}

		cout << endl;
	}

	cout << endl;

	cout << "Computer Bingo" << endl;
	cout << "=============================" << endl;
	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			if (_pComputerArray[i][j] == 0)
			{
				cout << "*" << "\t";
			}
			else
			{
				cout << _pComputerArray[i][j] << "\t";
			}
		}

		cout << endl;
	}
}

void InputNumber(int* _pNumber)
{
	cout << "���ڸ� �Է��ϼ���" << endl;
	cin >> *_pNumber;
}
void SelectArray(int(*_pArray)[5], int* _pNumber)
{
	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			if (_pArray[i][j] == *(_pNumber))
			{
				_pArray[i][j] = 0;
				break;
			}
		}
	}
}

void ComputerArray(int(*_pComputerArray)[5])
{
	random_device randomDevice;
	mt19937 random(randomDevice());
	uniform_int_distribution<int> range(1, 25);

	int iRandom = range(random);

	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			if (_pComputerArray[i][j] == iRandom)
			{
				_pComputerArray[i][j] = 0;
				break;
			}
		}
	}
}

int CheckTopDownArray(int(*_pPlayerArray)[5])
{
	bool bIsBingo = false;
	int iBingo = 0;
	 
	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			if (_pPlayerArray[j][i] == 0)
			{
				bIsBingo = true;
			}
			else
			{
				bIsBingo = false;
				break;
			}
		}

		if(bIsBingo == true)
		{
			iBingo++;
		}
	}

	return iBingo;
}

int CheckLeftRightArray(int(*_pPlayerArray)[5])
{
	bool bIsBingo = false;
	int iBingo = 0;

	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			if (_pPlayerArray[i][j] == 0)
			{
				bIsBingo = true;
			}
			else
			{
				bIsBingo = false;
				break;
			}
		}

		if (bIsBingo == true)
		{
			iBingo++;
		}
	}

	return iBingo;

}
int CheckDiagonalArray(int(*_pPlayerArray)[5])
{
	bool bIsBingo = false;
	int iBingo = 0;

	for (int i = 0; 5 > i; ++i)
	{
		if (_pPlayerArray[i][i] == 0)
		{
			bIsBingo = true;
		}
		else
		{
			bIsBingo = false;
			break;
		}
	}

	if (bIsBingo)
	{
		iBingo++;
	}

	for (int i = 0; 5 > i; ++i)
	{
		if (_pPlayerArray[4-i][i] == 0)
		{
			bIsBingo = true;
		}
		else
		{
			bIsBingo = false;
			break;
		}
	}

	if (bIsBingo)
	{
		iBingo++;
	}

	return iBingo;
}

int CheckComputerTopDownArray(int(*_pComputerArray)[5])
{
	bool bIsBingo = false;
	int iBingo = 0;

	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			if (_pComputerArray[j][i] == 0)
			{
				bIsBingo = true;
			}
			else
			{
				bIsBingo = false;
				break;
			}
		}

		if (bIsBingo == true)
		{
			iBingo++;
		}
	}

	return iBingo;
}

int CheckComputerLeftRightArray(int(*_pComputerArray)[5])
{
	bool bIsBingo = false;
	int iBingo = 0;

	for (int i = 0; 5 > i; ++i)
	{
		for (int j = 0; 5 > j; ++j)
		{
			if (_pComputerArray[i][j] == 0)
			{
				bIsBingo = true;
			}
			else
			{
				bIsBingo = false;
				break;
			}
		}

		if (bIsBingo == true)
		{
			iBingo++;
		}
	}

	return iBingo;

}
int CheckComputerDiagonalArray(int(*_pComputerArray)[5])
{
	bool bIsBingo = false;
	int iBingo = 0;

	for (int i = 0; 5 > i; ++i)
	{
		if (_pComputerArray[i][i] == 0)
		{
			bIsBingo = true;
		}
		else
		{
			bIsBingo = false;
			break;
		}
	}

	if (bIsBingo)
	{
		iBingo++;
	}

	for (int i = 0; 5 > i; ++i)
	{
		if (_pComputerArray[4 - i][i] == 0)
		{
			bIsBingo = true;
		}
		else
		{
			bIsBingo = false;
			break;
		}
	}

	if (bIsBingo)
	{
		iBingo++;
	}

	return iBingo;
}