#include "stdafx.h"
#include "Warrior.h"


void CWarrior::RenderPlayer()
{
	cout << "직업 : 전사" << endl;;
	cout << "체력 : " << m_iCurrentHP << endl;
	cout << "공격력 : " << m_iAttack << endl;
}


CWarrior::CWarrior()
	: CPlayer(10, 200, 200)
{
	m_classType = WARRIOR;
}


CWarrior::~CWarrior()
{
}
