#include "stdafx.h"
#include "Wizard.h"


void CWizard::RenderPlayer()
{
	cout << "직업 : 마법사" << endl;;
	cout << "체력 : " << m_iCurrentHP << endl;
	cout << "공격력 : " << m_iAttack << endl;
}

CWizard::CWizard()
	: CPlayer(100, 100, 100)
{
	m_classType = WIZARD;
}

CWizard::~CWizard()
{
}
