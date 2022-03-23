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

void CMainGame::Initalize()
{
	m_pField = new CField;
	m_pPlayer = new CPlayer;

	m_pPlayer->InitPlayer();
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
