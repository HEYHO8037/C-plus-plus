#pragma once
#include "Define.h"
#include "Player.h"
#include "Monster.h"


class CField
{
private:
	CMonster* m_pMonster;
	CPlayer* m_pPlayer;

public:
	CField();
	~CField();

public:
	void SetPlayer(CPlayer* _pPlayer);
	void Fight();

public:
	void Update();
	void Release();
};

