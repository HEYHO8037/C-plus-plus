#include "stdafx.h"
#include "Inventory.h"
#include "Player.h"


CInventory::CInventory()
{
	m_vecItem.reserve(5);
}

CInventory::CInventory(const CInventory & inven)
{
	if (!m_vecItem.empty())
	{
		vector<PITEM>::iterator iter = m_vecItem.begin();
		vector<PITEM>::iterator iterEnd = m_vecItem.end();

		for_each(iter, iterEnd, DestroyItem());

		m_vecItem.clear();
	}

	vector<PITEM>::const_iterator iter = inven.m_vecItem.begin();
	vector<PITEM>::const_iterator iterEnd = inven.m_vecItem.end();

	for (iter; iter != iterEnd; ++iter)
	{
		m_vecItem.push_back(*iter);
	}
}


CInventory::~CInventory()
{
	if (!m_vecItem.empty())
	{
		vector<PITEM>::iterator iter = m_vecItem.begin();
		vector<PITEM>::iterator iterEnd = m_vecItem.end();

		for_each(iter, iterEnd, DestroyItem());
		m_vecItem.clear();
	}

	m_vecItem.clear();
	m_pPlayer = nullptr;
}

vector<PITEM>& CInventory::GetItemInven()
{
	return m_vecItem;
}

void CInventory::GetPlayer(CPlayer * pPlayer)
{
	m_pPlayer = pPlayer;
}

void CInventory::ShowInventory()
{
	cout << "Player�� �κ��丮" << endl;

	vector<PITEM>::iterator iter = m_vecItem.begin();
	vector<PITEM>::iterator iterEnd = m_vecItem.end();

	for (iter; iter != iterEnd; ++iter)
	{
		cout << "=========================================" << endl;
		cout << (*iter)->strName.c_str() << endl;
		cout << "���ݷ� : " << (*iter)->iAttack << endl;
		cout << "���� : " << (*iter)->iArmor << endl;
		cout << "����ȿ�� : " << (*iter)->iPortion << endl;
	}

	system("pause");

}

void CInventory::SelectItem()
{
	int iInput = 0;

	if (0 == m_vecItem.size())
	{
		cout << "�ƹ��͵� �����ϴ�." << endl;
		system("pause");
		return;
	}

	vector<PITEM>::iterator iter = m_vecItem.begin();
	vector<PITEM>::iterator iterEnd = m_vecItem.end();

	for (iter; iter != iterEnd; )
	{
		system("cls");
		cout << "Player�� �κ��丮" << endl;
		cout << "=========================================" << endl;
		cout << (*iter)->strName.c_str() << endl;
		cout << "���ݷ� : " << (*iter)->iAttack << endl;
		cout << "���� : " << (*iter)->iArmor << endl;
		cout << "����ȿ�� : " << (*iter)->iPortion << endl;

		cout << "1. ���, 2. ����, 3. �ڷΰ���" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			if ((*iter)->eType == PORTION)
			{
				m_pPlayer->SetHP((*iter)->iPortion);
			}
			else if ((*iter)->eType == WEAPON)
			{
				m_pPlayer->SetAttack(m_pPlayer->GetAttack() + (*iter)->iAttack);
			}
			else
			{
				m_pPlayer->SetHP(m_pPlayer->GetMaxHP() + (*iter)->iArmor);
				m_pPlayer->SetMaxHP(m_pPlayer->GetHP());
			}

			if (m_vecItem.size() != 1)
			{
				delete *iter;
				iter = m_vecItem.erase(iter);
				iterEnd = m_vecItem.end();
			}
			else
			{
				delete *iter;
				m_vecItem.erase(iter);
				break;
			}

		}
		else if(2 == iInput)
		{
			++iter;
		}
		else
		{
			system("pause");
			return;
		}
	}
}