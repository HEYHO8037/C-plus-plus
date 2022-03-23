#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
	: m_iAttack(0),
	  m_iCurrentHP(0),
	  m_iMaxHP(0),
	  m_iClass(0)
{
}


CPlayer::~CPlayer()
{

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
	cout << "직업 : ";

	switch (m_iClass)
	{
	case 1:
		cout << "전사" << endl;
		break;
	case 2:
		cout << "마법사" << endl;
		break;
	case 3:
		cout << "도적" << endl;
		break;
	}

	cout << "체력 : " << m_iCurrentHP << endl;
	cout << "공격력 : " <<  m_iAttack << endl;
	
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

void CPlayer::InitPlayer()
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
			m_iClass = 1;
			m_iAttack = 10;
			m_iCurrentHP = 200;
			m_iMaxHP = 200;
			break;

		case 2:
			m_iClass = 2;
			m_iAttack = 100;
			m_iCurrentHP = 100;
			m_iMaxHP = 100;
			break;

		case 3:
			m_iClass = 3;
			m_iAttack = 20;
			m_iCurrentHP = 50;
			m_iMaxHP = 50;
			break;

		case 4:
			LoadPlayer();

			if (!m_iClass)
			{
				continue;
			}

			break;

		case 5:
			return;

		default:
			continue;
		}

		break;
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
		m_iClass = GetPlayer.m_iClass;
		m_iMaxHP = GetPlayer.m_iMaxHP;
		m_iCurrentHP = GetPlayer.m_iCurrentHP;

	}
	else
	{
		cout << "파일 불러오기를 실패했습니다." << endl;
		system("pause");
	}
}

void CPlayer::SavePlayer()
{
	FILE* pFile = nullptr;
	CPlayer savePlayer;

	savePlayer.m_iAttack = m_iAttack;
	savePlayer.m_iClass = m_iClass;
	savePlayer.m_iCurrentHP = m_iCurrentHP;
	savePlayer.m_iMaxHP = m_iMaxHP;

	errno_t err = fopen_s(&pFile, "../Data/Save.txt", "wb");
	if (NULL == err)
	{
		fwrite(&savePlayer, sizeof(CPlayer), 1, pFile);
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
	system("cls");
	cout << "플레이어가 사망했습니다." << endl;

	m_iCurrentHP = m_iMaxHP;
}
