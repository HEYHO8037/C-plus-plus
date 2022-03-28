#include "stdafx.h"
#include "MiddleMonst.h"


CMiddleMonst::CMiddleMonst()
	: CMonster(50, 60)
{
}


CMiddleMonst::~CMiddleMonst()
{
}

void CMiddleMonst::RenderMonster()
{
	cout << "몬스터클래스 : 중급" << endl;
	cout << "체력 : " << m_iHP << endl;
	cout << "공격력 : " << m_iAttack << endl;
}
