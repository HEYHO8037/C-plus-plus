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
	cout << "몬스터클래스 : ";

	switch (m_iClass)
	{
	case LOW:
		cout << "하급" << endl;
		break;
	case MIDDLE:
		cout << "중급" << endl;
		break;
	case HIGH:
		cout << "상급" << endl;
		break;
	}

	cout << "체력 : " << m_iHP << endl;
	cout << "공격력 : " << m_iAttack << endl;
}