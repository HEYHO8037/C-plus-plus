#include "stdafx.h"
#include "Warrior.h"


void CWarrior::RenderPlayer()
{
	cout << "���� : ����" << endl;;
	cout << "ü�� : " << m_iCurrentHP << endl;
	cout << "���ݷ� : " << m_iAttack << endl;
}


CWarrior::CWarrior()
	: CPlayer(10, 200, 200)
{
	m_classType = WARRIOR;
}


CWarrior::~CWarrior()
{
}
