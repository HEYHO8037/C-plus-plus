#include "stdafx.h"
#include "Thief.h"


void CThief::RenderPlayer()
{
	cout << "���� : ����" << endl;;
	cout << "ü�� : " << m_iCurrentHP << endl;
	cout << "���ݷ� : " << m_iAttack << endl;
}

CThief::CThief()
	: CPlayer(20, 50, 50)
{
	m_classType = THIEF;
}


CThief::~CThief()
{
}
