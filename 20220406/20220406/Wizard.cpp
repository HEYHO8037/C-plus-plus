#include "stdafx.h"
#include "Wizard.h"


void CWizard::RenderPlayer()
{
	cout << "���� : ������" << endl;;
	cout << "ü�� : " << m_iCurrentHP << endl;
	cout << "���ݷ� : " << m_iAttack << endl;
}

CWizard::CWizard()
	: CPlayer(100, 100, 100)
{
	m_classType = WIZARD;
}

CWizard::~CWizard()
{
}
