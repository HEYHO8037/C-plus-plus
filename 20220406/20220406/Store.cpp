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
		cout << "1. ���� , 2. �� , 3. ����, 4. �Ǹ�, 5. ����" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			PITEM saveItem = WeaponBuy();

			if (saveItem)
			{
				m_pPlayer->GetInven()->GetItemInven().push_back(saveItem);
			}
		}
		else if (2 == iInput)
		{
			PITEM saveItem = ArmorBuy();

			if (saveItem)
			{
				m_pPlayer->GetInven()->GetItemInven().push_back(saveItem);
			}

		}
		else if (3 == iInput)
		{
			PITEM saveItem = PortionBuy();
			if (saveItem)
			{
				m_pPlayer->GetInven()->GetItemInven().push_back(saveItem);
			}
		}
		else if (4 == iInput)
		{
			Sellitem();
		}
		else if (5 == iInput)
		{
			break;
		}
		else
		{
			continue;
		}


	}
}

PITEM CStore::WeaponBuy()
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
			cout << "Į�� �����ϼ̽��ϴ�." << endl;
			PITEM pKnife = new ITEM("Į", WEAPON, 10, 0, 0);
			system("pause");
			return pKnife;
		}
		else if (2 == iInput)
		{
			cout << "Ȱ�� �����ϼ̽��ϴ�." << endl;
			PITEM pBow = new ITEM("Ȱ", WEAPON, 25, 0, 0);
			system("pause");
			return pBow;
		}
		else if (3 == iInput)
		{
			cout << "���� �����ϼ̽��ϴ�." << endl;
			PITEM pGun = new ITEM("��", WEAPON, 50, 0, 0);
			system("pause");
			return pGun;
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

	return nullptr;
}

PITEM CStore::ArmorBuy()
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
			cout << "�ϱ� ���� �����ϼ̽��ϴ�." << endl;
			PITEM pLowArmor = new ITEM("�ϱ� ��", ARMOR, 0, 10, 0);
			system("pause");
			return pLowArmor;
		}
		else if (2 == iInput)
		{
			cout << "�߱� ���� �����ϼ̽��ϴ�." << endl;
			PITEM pMiddleArmor = new ITEM("�߱� ��", ARMOR, 0, 25, 0);
			system("pause");
			return pMiddleArmor;

		}
		else if (3 == iInput)
		{
			cout << "��� ���� �����ϼ̽��ϴ�." << endl;
			PITEM pHighArmor = new ITEM("��� ��", ARMOR, 0, 50, 0);
			system("pause");
			return pHighArmor;
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

	return nullptr;
}

PITEM CStore::PortionBuy()
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
			cout << "ü�� ������ �����ϼ̽��ϴ�." << endl;
			PITEM pHPportion = new ITEM("ü�¹���", PORTION, 0, 0, m_pPlayer->GetMaxHP());
			system("pause");
			return pHPportion;
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

	return nullptr;
}

void CStore::Sellitem()
{
	int iInput = 0;

	if (0 == m_pPlayer->GetInven()->GetItemInven().size())
	{
		cout << "�ƹ��͵� �����ϴ�." << endl;
		system("pause");
		return;
	}

	vector<PITEM>::iterator iter = m_pPlayer->GetInven()->GetItemInven().begin();
	vector<PITEM>::iterator iterEnd = m_pPlayer->GetInven()->GetItemInven().end();

	for (iter; iter != iterEnd;)
	{
		system("cls");
		cout << "Player�� �κ��丮" << endl;
		cout << "=========================================" << endl;
		cout << (*iter)->strName.c_str() << endl;
		cout << "���ݷ� : " << (*iter)->iAttack << endl;
		cout << "���� : " << (*iter)->iArmor << endl;
		cout << "����ȿ�� : " << (*iter)->iPortion << endl;

		cout << "1. �Ǹ�, 2. ����, 3. �ڷΰ���" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			if (m_pPlayer->GetInven()->GetItemInven().size() != 1)
			{
				delete *iter;
				iter = m_pPlayer->GetInven()->GetItemInven().erase(iter);
				iterEnd = m_pPlayer->GetInven()->GetItemInven().end();
			}
			else
			{
				delete *iter;
				m_pPlayer->GetInven()->GetItemInven().erase(iter);
				break;
			}
		}
		else if (2 == iInput)
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
