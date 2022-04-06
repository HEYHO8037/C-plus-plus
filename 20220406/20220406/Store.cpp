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
		cout << "1. 무기 , 2. 방어구 , 3. 포션, 4. 판매, 5. 이전" << endl;
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
		cout << "1. 칼 , 2. 활 , 3. 총, 4. 이전" << endl;
		cin >> iInput;


		if (1 == iInput)
		{
			cout << "칼을 구매하셨습니다." << endl;
			PITEM pKnife = new ITEM("칼", WEAPON, 10, 0, 0);
			system("pause");
			return pKnife;
		}
		else if (2 == iInput)
		{
			cout << "활을 구매하셨습니다." << endl;
			PITEM pBow = new ITEM("활", WEAPON, 25, 0, 0);
			system("pause");
			return pBow;
		}
		else if (3 == iInput)
		{
			cout << "총을 구매하셨습니다." << endl;
			PITEM pGun = new ITEM("총", WEAPON, 50, 0, 0);
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
		cout << "1. 하급 방어구 , 2. 중급 방어구 , 3. 상급 방어구, 4. 이전" << endl;
		cin >> iInput;


		if (1 == iInput)
		{
			cout << "하급 방어구를 구매하셨습니다." << endl;
			PITEM pLowArmor = new ITEM("하급 방어구", ARMOR, 0, 10, 0);
			system("pause");
			return pLowArmor;
		}
		else if (2 == iInput)
		{
			cout << "중급 방어구를 구매하셨습니다." << endl;
			PITEM pMiddleArmor = new ITEM("중급 방어구", ARMOR, 0, 25, 0);
			system("pause");
			return pMiddleArmor;

		}
		else if (3 == iInput)
		{
			cout << "상급 방어구를 구매하셨습니다." << endl;
			PITEM pHighArmor = new ITEM("상급 방어구", ARMOR, 0, 50, 0);
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
		cout << "1. 체력물약 , 2. 마나물약 , 3. 버프물약, 4. 이전" << endl;
		cin >> iInput;


		if (1 == iInput)
		{
			cout << "체력 물약을 구매하셨습니다." << endl;
			PITEM pHPportion = new ITEM("체력물약", PORTION, 0, 0, m_pPlayer->GetMaxHP());
			system("pause");
			return pHPportion;
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

	return nullptr;
}

void CStore::Sellitem()
{
	int iInput = 0;

	if (0 == m_pPlayer->GetInven()->GetItemInven().size())
	{
		cout << "아무것도 없습니다." << endl;
		system("pause");
		return;
	}

	vector<PITEM>::iterator iter = m_pPlayer->GetInven()->GetItemInven().begin();
	vector<PITEM>::iterator iterEnd = m_pPlayer->GetInven()->GetItemInven().end();

	for (iter; iter != iterEnd;)
	{
		system("cls");
		cout << "Player의 인벤토리" << endl;
		cout << "=========================================" << endl;
		cout << (*iter)->strName.c_str() << endl;
		cout << "공격력 : " << (*iter)->iAttack << endl;
		cout << "방어력 : " << (*iter)->iArmor << endl;
		cout << "포션효과 : " << (*iter)->iPortion << endl;

		cout << "1. 판매, 2. 다음, 3. 뒤로가기" << endl;
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
