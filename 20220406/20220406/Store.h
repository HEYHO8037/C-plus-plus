#pragma once

#include "Define.h"
#include "stdafx.h"

class CStore
{
private:
	class CPlayer* m_pPlayer;
	
public:
	CStore();
	~CStore();

public:
	void SetPlayer(CPlayer* pPlayer);

public:
	void RenderStore();
	PITEM ArmorBuy();
	PITEM WeaponBuy();
	PITEM PortionBuy();
	void Sellitem();

};

