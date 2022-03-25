#include "stdafx.h"
#include "Store.h"
#include "Player.h"


CStore::CStore()
{
}


CStore::~CStore()
{
	m_pPlayer = nullptr;
}

void CStore::SetPlayer(CPlayer * pPlayer)
{
	m_pPlayer = pPlayer;
}

void CStore::RenderStore()
{
	int iInput;

	while (true)
	{
		system("cls");
		m_pPlayer->RenderPlayer();
		cout << "========================================" << endl;
		cout << "1. 무기 , 2. 방어구 , 3. 포션, 4. 이전" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			WeaponBuy();
		}
		else if (2 == iInput)
		{
			ArmorBuy();
		}
		else if (3 == iInput)
		{
			PortionBuy();
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

void CStore::WeaponBuy()
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->RenderPlayer();
		cout << "========================================" << endl;
		cout << "1. 칼 , 2. 활 , 3. 총, 4. 이전" << endl;
		cin >> iInput;


		if (1 == iInput)
		{
			m_pPlayer->SetAttack(m_pPlayer->GetAttack() + 10);
			cout << "칼을 구매하셨습니다." << endl;
			system("pause");
		}
		else if (2 == iInput)
		{
			m_pPlayer->SetAttack(m_pPlayer->GetAttack() + 25);
			cout << "활을 구매하셨습니다." << endl;
			system("pause");
		}
		else if (3 == iInput)
		{
			m_pPlayer->SetAttack(m_pPlayer->GetAttack() + 40);
			cout << "총을 구매하셨습니다." << endl;
			system("pause");
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

void CStore::ArmorBuy()
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->RenderPlayer();
		cout << "========================================" << endl;
		cout << "1. 하급 방어구 , 2. 중급 방어구 , 3. 상급 방어구, 4. 이전" << endl;
		cin >> iInput;


		if (1 == iInput)
		{
			m_pPlayer->SetHP(m_pPlayer->GetHP() + 25);
			cout << "하급 방어구를 구매하셨습니다." << endl;
			system("pause");
		}
		else if (2 == iInput)
		{
			m_pPlayer->SetHP(m_pPlayer->GetHP() + 50);
			cout << "중급 방어구를 구매하셨습니다." << endl;
			system("pause");

		}
		else if (3 == iInput)
		{
			m_pPlayer->SetHP(m_pPlayer->GetHP() + 100);
			cout << "상급 방어구를 구매하셨습니다." << endl;
			system("pause");
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

void CStore::PortionBuy()
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->RenderPlayer();
		cout << "========================================" << endl;
		cout << "1. 체력물약 , 2. 마나물약 , 3. 버프물약, 4. 이전" << endl;
		cin >> iInput;


		if (1 == iInput)
		{
			m_pPlayer->HealPlayer();
			cout << "체력 물약을 구매하셨습니다." << endl;
			system("pause");
		}
		else if (2 == iInput)
		{
			//생략
		}
		else if (3 == iInput)
		{
			//생략
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
