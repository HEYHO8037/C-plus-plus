#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
	: m_iAttack(0),
	  m_iCurrentHP(0),
	  m_iMaxHP(0)
{
}

CPlayer::CPlayer(int _iAttack, int _iCurrentHP, int _iMaxHP)
{
	m_iAttack = _iAttack;
	m_iCurrentHP = _iCurrentHP;
	m_iMaxHP = _iMaxHP;
}


CPlayer::~CPlayer()
{
}

void CPlayer::SetAttack(int iAttack)
{
	m_iAttack = iAttack;
}

void CPlayer::SetHP(int iHP)
{
	m_iMaxHP = iHP;
	m_iCurrentHP = iHP;
}

int CPlayer::GetAttack() const
{
	return m_iAttack;;
}

int CPlayer::GetHP() const
{
	return m_iCurrentHP;
}


void CPlayer::RenderPlayer()
{
}

void CPlayer::AttackMonster(int _iMonsterAttack)
{
	m_iCurrentHP -= _iMonsterAttack;

	if (0 >= m_iCurrentHP)
	{
		HealPlayer();
		system("pause");
	}
}


void CPlayer::LoadPlayer()
{
	FILE* pFile = nullptr;
	CPlayer GetPlayer;

	errno_t err = fopen_s(&pFile, "../Data/Save.txt", "rb");
	if (NULL == err)
	{
		fread(&GetPlayer, sizeof(CPlayer), 1, pFile);
		fclose(pFile);

		m_iAttack = GetPlayer.m_iAttack;
		m_iMaxHP = GetPlayer.m_iMaxHP;
		m_iCurrentHP = GetPlayer.m_iCurrentHP;

	}
	else
	{
		cout << "���� �ҷ����⸦ �����߽��ϴ�." << endl;
		system("pause");
	}
}

void CPlayer::SavePlayer()
{
	FILE* pFile = nullptr;
	CPlayer savePlayer;

	savePlayer.m_iAttack = m_iAttack;
	savePlayer.m_iCurrentHP = m_iCurrentHP;
	savePlayer.m_iMaxHP = m_iMaxHP;

	errno_t err = fopen_s(&pFile, "../Data/Save.txt", "wb");
	if (NULL == err)
	{
		fwrite(&savePlayer, sizeof(CPlayer), 1, pFile);
		fclose(pFile);
		cout << "������ ���� ����" << endl;
		system("pause");
	}
	else
	{
		cout << "������ ���� ����" << endl;
		system("pause");
	}
}

void CPlayer::HealPlayer()
{
	m_iCurrentHP = m_iMaxHP;
}
