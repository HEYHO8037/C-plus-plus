#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
	: m_iAttack(0),
	  m_iCurrentHP(0),
	  m_iMaxHP(0)
{
	m_Inven = new CInventory();
	m_Inven->GetPlayer(this);
}

CPlayer::CPlayer(int _iAttack, int _iCurrentHP, int _iMaxHP)
{
	m_iAttack = _iAttack;
	m_iCurrentHP = _iCurrentHP;
	m_iMaxHP = _iMaxHP;

	m_Inven = new CInventory();
	m_Inven->GetPlayer(this);
}


CPlayer::~CPlayer()
{
	if (m_Inven)
	{
		delete m_Inven;
		m_Inven = nullptr;
	}
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

void CPlayer::SetMaxHP(int iMaxHP)
{
	m_iMaxHP = iMaxHP;
}

int CPlayer::GetAttack() const
{
	return m_iAttack;;
}

int CPlayer::GetHP() const
{
	return m_iCurrentHP;
}

int CPlayer::GetMaxHP() const
{
	return m_iMaxHP;
}

CInventory * CPlayer::GetInven() const
{
	return m_Inven;
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
	delete GetPlayer.m_Inven;
	GetPlayer.m_Inven = nullptr;

	_tagItemType m_iItemType[5];
	int m_iItemAttack[5];
	int m_iItemArmor[5];
	int m_iItemPortion[5];
	char m_ItemName[5][100] = { 0 };


	errno_t err = fopen_s(&pFile, "../Data/Save.txt", "rb");
	if (NULL == err)
	{
		fread(&GetPlayer, sizeof(CPlayer), 1, pFile);
		fread(&m_ItemName, sizeof(m_ItemName), 1, pFile);
		fread(&m_iItemType, sizeof(m_iItemType), 1, pFile);
		fread(&m_iItemAttack, sizeof(m_iItemAttack), 1, pFile);
		fread(&m_iItemArmor, sizeof(m_iItemArmor), 1, pFile);
		fread(&m_iItemPortion, sizeof(m_iItemPortion), 1, pFile);

		fclose(pFile);

		m_iAttack = GetPlayer.m_iAttack;
		m_iMaxHP = GetPlayer.m_iMaxHP;
		m_iCurrentHP = GetPlayer.m_iCurrentHP;

		for (int i = 0; 5 > i; ++i)
		{
			string saveString = m_ItemName[i];
			m_Inven->GetItemInven().push_back(new ITEM(saveString, m_iItemType[i], m_iItemAttack[i], m_iItemArmor[i], m_iItemPortion[i]));
		}
	}
	else
	{
		cout << "파일 불러오기를 실패했습니다." << endl;
		system("pause");
	}

	GetPlayer.m_Inven = nullptr;
}

classType CPlayer::FindClass()
{
	FILE* pFile = nullptr;
	CPlayer GetPlayer;
	delete GetPlayer.m_Inven;

	errno_t err = fopen_s(&pFile, "../Data/Save.txt", "rb");
	if (NULL == err)
	{
		fread(&GetPlayer, sizeof(CPlayer), 1, pFile);
	}

	if (GetPlayer.m_classType == WARRIOR)
	{
		GetPlayer.m_Inven = nullptr;
		return WARRIOR;
	}
	else if (GetPlayer.m_classType == WIZARD)
	{
		GetPlayer.m_Inven = nullptr;
		return WIZARD;
	}
	else
	{
		GetPlayer.m_Inven = nullptr;
		return THIEF;
	}
}


void CPlayer::SavePlayer()
{
	FILE* pFile = nullptr;
	CPlayer savePlayer;

	int m_iItemAttack[5];
	int m_iItemArmor[5];
	int m_iItemPortion[5];
	_tagItemType m_iItemType[5];
	char m_ItemName[5][100] = { 0 };

	for (int i = 0; i < m_Inven->GetItemInven().size(); ++i)
	{
		m_iItemAttack[i] = m_Inven->GetItemInven()[i]->iAttack;
		m_iItemArmor[i] = m_Inven->GetItemInven()[i]->iArmor;
		m_iItemPortion[i] = m_Inven->GetItemInven()[i]->iPortion;
		m_iItemType[i] = m_Inven->GetItemInven()[i]->eType;

		for (int j = 0; j < m_Inven->GetItemInven()[i]->strName.size(); ++j)
		{
			m_ItemName[i][j] = m_Inven->GetItemInven()[i]->strName.c_str()[j];
		}
	}

	savePlayer.m_iAttack = m_iAttack;
	savePlayer.m_iCurrentHP = m_iCurrentHP;
	savePlayer.m_iMaxHP = m_iMaxHP;

	errno_t err = fopen_s(&pFile, "../Data/Save.txt", "wb");
	if (NULL == err)
	{
		fwrite(&savePlayer, sizeof(CPlayer), 1, pFile);
		fwrite(&m_ItemName, sizeof(m_ItemName), 1, pFile);
		fwrite(&m_iItemType, sizeof(m_iItemType), 1, pFile);
		fwrite(&m_iItemAttack, sizeof(m_iItemAttack), 1, pFile);
		fwrite(&m_iItemArmor, sizeof(m_iItemArmor), 1, pFile);
		fwrite(&m_iItemPortion, sizeof(m_iItemPortion), 1, pFile);
		fclose(pFile);
		cout << "데이터 저장 성공" << endl;
		system("pause");
	}
	else
	{
		cout << "데이터 저장 실패" << endl;
		system("pause");
	}
}

void CPlayer::HealPlayer()
{
	m_iCurrentHP = m_iMaxHP;
}
