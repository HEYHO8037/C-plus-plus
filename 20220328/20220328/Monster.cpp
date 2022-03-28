#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
	: m_iAttack(0),
	  m_iHP(0)
{
}

CMonster::CMonster(int _iAttack, int _iHP)
	: m_iAttack(_iAttack),
	  m_iHP(_iHP)
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
}

void CMonster::AttackPlayer(int _iPlayerAttack)
{
	m_iHP -= _iPlayerAttack;

	if (0 >= m_iHP)
	{
		system("cls");
		cout << "승리하였습니다." << endl;
		system("pause");
	}
}
