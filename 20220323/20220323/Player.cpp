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
	cout << "���� : ";

	switch (m_iClass)
	{
	case 1:
		cout << "����" << endl;
		break;
	case 2:
		cout << "������" << endl;
		break;
	case 3:
		cout << "����" << endl;
		break;
	}

	cout << "ü�� : " << m_iCurrentHP << endl;
	cout << "���ݷ� : " <<  m_iAttack << endl;
	
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

		cout << "1. ����, 2. ������, 3. ����, 4. �ҷ����� 5. ����" << endl;
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
		cout << "���� �ҷ����⸦ �����߽��ϴ�." << endl;
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
	system("cls");
	cout << "�÷��̾ ����߽��ϴ�." << endl;

	m_iCurrentHP = m_iMaxHP;
}
