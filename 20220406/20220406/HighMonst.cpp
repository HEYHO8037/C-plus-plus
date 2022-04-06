#include "stdafx.h"
#include "HighMonst.h"


CHighMonst::CHighMonst()
	: CMonster(200, 90)
{
}


CHighMonst::~CHighMonst()
{
}

void CHighMonst::RenderMonster()
{
	cout << "몬스터클래스 : 상급" << endl;
	cout << "체력 : " << m_iHP << endl;
	cout << "공격력 : " << m_iAttack << endl;
}
