#include <iostream>

using namespace std;

int main(void)
{
	//3. for���� �̿��ؼ� �ܰ� ���� �Է¹޾Ƽ� �������� ���  -> 5�� 6�� -> 2�ܺ��� 5�ܱ���, ? * 6 �� ���� ����ϰ� ������ ��

	int iDan = 0;
	int iGop = 0;

	cout << "�ִ������ ���� �Է��ϼ��� : ";
	cin >> iDan;

	cout << "�ִ������ ���� �Է��ϼ��� : ";
	cin >> iGop;

	for (int i = 2; i <= iDan; ++i)
	{
		for (int j = 1; j <= iGop; ++j)
		{
			cout << i << " * " << j << " = " << i*j << endl;
		}
		cout << endl;
	}

	return 0;
}