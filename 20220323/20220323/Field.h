#pragma once
#include "Define.h"
#include "Player.h"
#include "Store.h"
#include "Monster.h"


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

public:
	void Update();
	void Release();
};

