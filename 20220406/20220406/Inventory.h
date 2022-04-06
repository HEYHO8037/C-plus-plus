#pragma once

#include "stdafx.h"
#include "Define.h"


struct DestroyItem
{
	void operator()(ITEM* pItem)
	{
		if(pItem)
		{
			delete pItem;
		}
	}
};


class CInventory
{
private:
	vector<PITEM> m_vecItem;
	class CPlayer* m_pPlayer;

public:
	CInventory();
	CInventory(const CInventory& inven);
	~CInventory();

public:
	vector<PITEM>& GetItemInven();
	void GetPlayer(class CPlayer* pPlayer);

public:
	void ShowInventory();
	void SelectItem();
};

