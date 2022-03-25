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
		cout << "1. ���� , 2. �� , 3. ����, 4. ����" << endl;
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
		cout << "1. Į , 2. Ȱ , 3. ��, 4. ����" << endl;
		cin >> iInput;


		if (1 == iInput)
		{
			m_pPlayer->SetAttack(m_pPlayer->GetAttack() + 10);
			cout << "Į�� �����ϼ̽��ϴ�." << endl;
			system("pause");
		}
		else if (2 == iInput)
		{
			m_pPlayer->SetAttack(m_pPlayer->GetAttack() + 25);
			cout << "Ȱ�� �����ϼ̽��ϴ�." << endl;
			system("pause");
		}
		else if (3 == iInput)
		{
			m_pPlayer->SetAttack(m_pPlayer->GetAttack() + 40);
			cout << "���� �����ϼ̽��ϴ�." << endl;
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
		cout << "1. �ϱ� �� , 2. �߱� �� , 3. ��� ��, 4. ����" << endl;
		cin >> iInput;


		if (1 == iInput)
		{
			m_pPlayer->SetHP(m_pPlayer->GetHP() + 25);
			cout << "�ϱ� ���� �����ϼ̽��ϴ�." << endl;
			system("pause");
		}
		else if (2 == iInput)
		{
			m_pPlayer->SetHP(m_pPlayer->GetHP() + 50);
			cout << "�߱� ���� �����ϼ̽��ϴ�." << endl;
			system("pause");

		}
		else if (3 == iInput)
		{
			m_pPlayer->SetHP(m_pPlayer->GetHP() + 100);
			cout << "��� ���� �����ϼ̽��ϴ�." << endl;
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
		cout << "1. ü�¹��� , 2. �������� , 3. ��������, 4. ����" << endl;
		cin >> iInput;


		if (1 == iInput)
		{
			m_pPlayer->HealPlayer();
			cout << "ü�� ������ �����ϼ̽��ϴ�." << endl;
			system("pause");
		}
		else if (2 == iInput)
		{
			//����
		}
		else if (3 == iInput)
		{
			//����
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
