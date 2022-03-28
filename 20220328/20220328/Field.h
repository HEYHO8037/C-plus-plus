#pragma once
#include "Define.h"
#include "Warrior.h"
#include "Thief.h"
#include "Wizard.h"
#include "Store.h"
#include "LowerMonst.h"
#include "HighMonst.h"
#include "MiddleMonst.h"


class CField
{
private:
	CMonster* m_pMonster;
	CPlayer* m_pPlayer;
	CStore* m_pStore;

public:
	CField();
	~CField();

public:
	void SetPlayer(CPlayer* _pPlayer);
	void Fight();
	void InitStore();
	void ReleaseStore();
	void InitMonster();

public:
	void Update();
	void Release();
};

