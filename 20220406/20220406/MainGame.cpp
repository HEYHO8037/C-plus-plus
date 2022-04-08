#include "stdafx.h"
#include "MainGame.h"


CMainGame::CMainGame()
	: m_pPlayer(nullptr),
	  m_pField(nullptr)
{
}

CMainGame::~CMainGame()
{
}

void CMainGame::InitPlayer()
{
	int iInput = 0;

	while (true)
	{
		system("cls");

		cout << "1. 전사, 2. 마법사, 3. 도적, 4. 불러오기 5. 종료" << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pPlayer = new CWarrior;
			break;

		case 2:
			m_pPlayer = new CWizard;
			break;

		case 3:
			m_pPlayer = new CThief;
			break;

		case 4:
		{
			m_pPlayer = new CPlayer;
			classType saveType = m_pPlayer->FindClass();

			if (saveType == WARRIOR)
			{
				delete m_pPlayer;
				m_pPlayer = new CWarrior;
			}
			else if (saveType == WIZARD)
			{
				delete m_pPlayer;
				m_pPlayer = new CWizard;
			}
			else
			{
				delete m_pPlayer;
				m_pPlayer = new CThief;
			}

			m_pPlayer->LoadPlayer();

			if (!m_pPlayer->GetAttack())
			{
				continue;
			}

			break;
		}

		case 5:
			return;

		default:
			continue;
		}

		break;
	}
}

void CMainGame::Initalize()
{
	m_pField = new CField;
	m_pPlayer = new CPlayer;

	InitPlayer();	
}

void CMainGame::Update()
{
	if (!m_pPlayer->GetAttack())
	{
		return;
	}

	m_pField->SetPlayer(m_pPlayer);
	m_pField->Update();
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pField);
}
