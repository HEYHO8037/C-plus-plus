#include "stdafx.h"
#include "Thief.h"


void CThief::RenderPlayer()
{
	cout << "직업 : 도적" << endl;;
	cout << "체력 : " << m_iCurrentHP << endl;
	cout << "공격력 : " << m_iAttack << endl;
}

CThief::CThief()
	: CPlayer(20, 50, 50)
{
	m_classType = THIEF;
}


CThief::~CThief()
{
}
