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
	cout << "����Ŭ���� : �ϱ�" << endl;
	cout << "ü�� : " << m_iHP << endl;
	cout << "���ݷ� : " << m_iAttack << endl;
}
