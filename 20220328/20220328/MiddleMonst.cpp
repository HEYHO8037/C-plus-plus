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
	cout << "����Ŭ���� : �߱�" << endl;
	cout << "ü�� : " << m_iHP << endl;
	cout << "���ݷ� : " << m_iAttack << endl;
}
