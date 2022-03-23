#include "stdafx.h"
#include "TextRPG.h"

CTextRPG::CTextRPG()
	: m_pPlayer(nullptr),
	  m_pMonster(nullptr)
{ 
}

CTextRPG::~CTextRPG()
{
	Release();
}

void CTextRPG::ChooseMonster()
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->ShowPlayerState();
		cout << "1. �ϱ�, 2. �߱�, 3. ���, 4. ����" << endl;
		cin >> iInput;

		if (0 < iInput && iInput < 4)
		{
			m_pMonster = new CMonster(iInput);
			break;
		}
		else if (4 == iInput)
		{
			break;
		}
		else
		{
			continue;
		}
	}

}

bool CTextRPG::GoField()
{
	int iInput = 0;
	bool bIsCheck = false;


	while (true)
	{
		system("cls");
		m_pPlayer->ShowPlayerState();
		cout << "1. �����, 2. ����, 3. ����" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			bIsCheck = true;
			break;
		}
		else if (2 == iInput)
		{
			SavePlayer();
			system("pause");
			continue;
		}
		else if (3 == iInput)
		{
			break;
		}
		else
		{
			continue;
		}
	}

	return bIsCheck;
}

void CTextRPG::Fight()
{
	int iInput = 0;

	while (true)
	{
		system("cls");

		m_pPlayer->ShowPlayerState();
		cout << "================================" << endl;
		m_pMonster->ShowMonsterState();

		cout << "1. ����, 2. ����ġ��" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			m_pPlayer->Attack(m_pMonster->GetAttack());
			m_pMonster->Attack(m_pPlayer->GetAttack());
			
			if (!AttackCheckHP())
			{
				break;
			}
		}
		else if (2 == iInput)
		{
			delete m_pMonster;
			m_pMonster = nullptr;
			break;
		}
		else
		{
			continue;
		}
	}
}

bool CTextRPG::AttackCheckHP()
{
	if (0 >= m_pPlayer->GetHP())
	{
		system("cls");
		cout << "�÷��̾ ����߽��ϴ�." << endl;

		m_pPlayer->HealPlayer();
		system("pause");

		return 0;
	}
	else if (0 >= m_pMonster->GetHP())
	{
		system("cls");
		cout << "�¸��Ͽ����ϴ�." << endl;

		delete m_pMonster;
		m_pMonster = nullptr;

		system("pause");

		return 0;
	}

	return 1;
}

void CTextRPG::SavePlayer()
{
	FILE* pFile = nullptr;
	CPlayer savePlayer;

	savePlayer.SetAttack(m_pPlayer->GetAttack());
	savePlayer.SetClass(m_pPlayer->GetClass());
	savePlayer.SetHP(m_pPlayer->GetHP());
	savePlayer.SetMaxHP(m_pPlayer->GetMaxHP());

	errno_t err = fopen_s(&pFile, "../Data/Save.txt", "wb");
	
	if (NULL == err)
	{
		fwrite(&savePlayer, sizeof(CPlayer), 1, pFile);
		fclose(pFile);
		cout << "������ ���� ����" << endl;
	}
	else
	{
		cout << "������ ���� ����" << endl;
	}
}

void CTextRPG::LoadPlayer()
{
	FILE* pFile = nullptr;
	CPlayer pGetPlayer;

	errno_t err = fopen_s(&pFile, "../Data/Save.txt", "rb");
	if (NULL == err)
	{
		fread(&pGetPlayer, sizeof(CPlayer), 1, pFile);
		fclose(pFile);

		m_pPlayer = new CPlayer;
		m_pPlayer->SetAttack(pGetPlayer.GetAttack());
		m_pPlayer->SetClass(pGetPlayer.GetClass());
		m_pPlayer->SetHP(pGetPlayer.GetHP());
		m_pPlayer->SetMaxHP(pGetPlayer.GetMaxHP());
	}
	else
	{
		cout << "���� �ҷ����⸦ �����߽��ϴ�." << endl;
	}
}

void CTextRPG::Init()
{
	int iInput = 0;

	while (true)
	{
		system("cls");

		cout << "1. ����, 2. ������, 3. ����, 4. �ҷ�����, 5. ����" << endl;
		cin >> iInput;

		if (5 == iInput)
		{
			break;
		}
		else if (4 == iInput)
		{
			LoadPlayer();
			break;
		}
		else if (iInput > 0 && iInput < 4)
		{
			m_pPlayer = new CPlayer(iInput);
			break;
		}
		else
		{
			continue;
		}
	}
}

void CTextRPG::Update()
{
	bool bIsCheck = false;

	while (true)
	{
		system("cls");

		m_pPlayer->ShowPlayerState();
		bIsCheck = GoField();

		if (!bIsCheck)
		{
			break;
		}

		ChooseMonster();

		if (m_pMonster == nullptr)
		{
			continue;
		}

		Fight();
	}
}

void CTextRPG::Release()
{
	if (m_pMonster)
	{
		delete m_pMonster;
		m_pMonster = nullptr;
	}

	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}
}


void CTextRPG::MainFrame()
{
	Init();

	if (m_pPlayer == nullptr)
	{
		return;
	}

	Update();
	Release();
}