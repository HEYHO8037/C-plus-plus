#include "stdafx.h"
#include "Field.h"


CField::CField()
	: m_pMonster(nullptr),
	  m_pPlayer(nullptr)
{
}


CField::~CField()
{
}

void CField::SetPlayer(CPlayer* _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CField::Fight()
{
	int iInput = 0;

	while (true)
	{
		system("cls");

		m_pPlayer->RenderPlayer();
		cout << "===========================" << endl;
		m_pMonster->RenderMonster();

		cout << "1. 공격, 2. 도망치기" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			m_pPlayer->AttackMonster(m_pMonster->GetAttack());
			m_pMonster->AttackPlayer(m_pPlayer->GetAttack());
			if (0 >= m_pMonster->GetHP())
			{
				Release();
				break;
			}
			else if (0 >= m_pPlayer->GetHP())
			{
				break;
			}
		}
		else if (2 == iInput)
		{
			Release();
			break;
		}
		else
		{
			continue;
		}
	}
}


void CField::Update()
{
	int iInput = 0;
	bool bIsCheck = false;

	while (true)
	{
		system("cls");

		m_pPlayer->RenderPlayer();

		cout << "1. 사냥터, 2. 저장, 3. 종료" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			m_pMonster = new CMonster;
			m_pMonster->InitMonster();

			if (!m_pMonster->GetAttack())
			{
				Release();
				continue;
			}

			Fight();
			continue;
		}
		else if (2 == iInput)
		{
			m_pPlayer->SavePlayer();
			continue;
		}
		else if (3 == iInput)
		{
			return;
		}
		else
		{
			continue;
		}
	}
}

void CField::Release()
{
	SAFE_DELETE(m_pMonster);
}
