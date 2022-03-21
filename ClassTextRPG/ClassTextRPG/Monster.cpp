#include "stdafx.h"
#include "Monster.h"

int CMonster::GetHP() const
{
	return m_iHP;
}

int CMonster::GetAttack() const
{
	return m_iAttack;
}

void CMonster::InitMonster(int _iInput)
{
	switch (_iInput)
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