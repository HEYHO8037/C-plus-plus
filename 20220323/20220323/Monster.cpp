#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
	: m_iClass(0),
	  m_iAttack(0),
	  m_iHP(0)
{
}


CMonster::~CMonster()
{
}

int CMonster::GetAttack() const
{
	return m_iAttack;
}

int CMonster::GetHP() const
{
	return m_iHP;
}

void CMonster::RenderMonster()
{
	cout << "����Ŭ���� : ";

	switch (m_iClass)
	{
	case 1:
		cout << "�ϱ�" << endl;
		break;
	case 2:
		cout << "�߱�" << endl;
		break;
	case 3:
		cout << "���" << endl;
		break;
	}

	cout << "ü�� : " << m_iHP << endl;
	cout << "���ݷ� : " << m_iAttack << endl;
}

void CMonster::AttackPlayer(int _iPlayerAttack)
{
	m_iHP -= _iPlayerAttack;

	if (0 >= m_iHP)
	{
		system("cls");
		cout << "�¸��Ͽ����ϴ�." << endl;
		system("pause");
	}
}

void CMonster::InitMonster()
{
	int iInput = 0;

	while (true)
	{
		system("cls");

		cout << "1. �ϱ�, 2. �߱�, 3. ���, 4. ����" << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_iClass = 1;
			m_iAttack = 5;
			m_iHP = 30;
			break;

		case 2:
			m_iClass = 2;
			m_iAttack = 50;
			m_iHP = 60;
			break;

		case 3:
			m_iClass = 3;
			m_iAttack = 200;
			m_iHP = 90;
			break;

		case 4:
			break;

		default:
			continue;
		}

		break;
	}
}
