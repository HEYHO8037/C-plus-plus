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
	cout << "����Ŭ���� : ���" << endl;
	cout << "ü�� : " << m_iHP << endl;
	cout << "���ݷ� : " << m_iAttack << endl;
}
