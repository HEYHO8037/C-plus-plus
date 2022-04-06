#include "stdafx.h"
#include "LowerMonst.h"


CLowerMonst::CLowerMonst()
	: CMonster(5, 30)
{
}


CLowerMonst::~CLowerMonst()
{
}

void CLowerMonst::RenderMonster()
{
	cout << "몬스터클래스 : 하급" << endl;
	cout << "체력 : " << m_iHP << endl;
	cout << "공격력 : " << m_iAttack << endl;
}
