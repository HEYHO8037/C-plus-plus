#include "stdafx.h"
#include "Field.h"


CField::CField()
	: m_pMonster(nullptr),
	  m_pPlayer(nullptr),
	  m_pStore(nullptr)
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

		cout << "1. ����, 2. ����ġ��" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			m_pPlayer->AttackMonster(m_pMonster->GetAttack());
			m_pMonster->AttackPlayer(m_pPlayer->GetAttack());
			if (0 >= m_pMonster->GetHP())
			{
				SAFE_DELETE(m_pMonster);
				break;
			}
			else if (0 >= m_pPlayer->GetHP())
			{
				system("cls");
				cout << "�÷��̾ ����߽��ϴ�." << endl;
				break;
			}
		}
		else if (2 == iInput)
		{
			SAFE_DELETE(m_pMonster);
			break;
		}
		else
		{
			continue;
		}
	}
}

void CField::InitStore()
{
	m_pStore = new CStore;
}

void CField::ReleaseStore()
{
	if (m_pStore)
	{
		delete m_pStore;
		m_pStore = nullptr;
	}
}

void CField::InitMonster()
{
	int iInput = 0;

	while (true)
	{
		system("cls");

		cout << "1. �ϱ�, 2. �߱�, 3. ���, 4. ����" << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster = new CLowerMonst;
			break;

		case 2:
			m_pMonster = new CMiddleMonst;
			break;

		case 3:
			m_pMonster = new CHighMonst;
			break;

		case 4:
			break;

		default:
			continue;
		}

		break;
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

		cout << "1. �����, 2.���� 3. ����, 4. ����" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			InitMonster();

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
			InitStore();
			m_pStore->SetPlayer(m_pPlayer);
			m_pStore->RenderStore();
			ReleaseStore();
		}
		else if (3 == iInput)
		{
			m_pPlayer->SavePlayer();
			continue;
		}
		else if (4 == iInput)
		{
			Release();
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
	m_pPlayer = nullptr;
	ReleaseStore();
}
