#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
	: m_iClass(0),
	  m_iHP(0),
	  m_iAttack(0)
{
}

CMonster::CMonster(int _iClass)
{
	switch (_iClass)
	{
	case LOW:
		m_iClass = LOW;
		m_iAttack = 5;
		m_iHP = 30;
		break;

	case MIDDLE:
		m_iClass = MIDDLE;
		m_iAttack = 50;
		m_iHP = 60;
		break;

	case HIGH:
		m_iClass = HIGH;
		m_iAttack = 200;
		m_iHP = 90;
		break;
	}
}

CMonster::~CMonster()
{
}

int CMonster::GetHP() const
{
	return m_iHP;
}

int CMonster::GetAttack() const
{
	return m_iAttack;
}


void CMonster::Attack(int _iPlayerAttack)
{
	m_iHP -= _iPlayerAttack;
}

void CMonster::ShowMonsterState()
{
	cout << "����Ŭ���� : ";

	switch (m_iClass)
	{
	case LOW:
		cout << "�ϱ�" << endl;
		break;
	case MIDDLE:
		cout << "�߱�" << endl;
		break;
	case HIGH:
		cout << "���" << endl;
		break;
	}

	cout << "ü�� : " << m_iHP << endl;
	cout << "���ݷ� : " << m_iAttack << endl;
}