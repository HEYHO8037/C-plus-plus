#pragma once
#include "Player.h"
#include "Monster.h"

class CTextRPG
{
private:
	CPlayer* m_pPlayer;
	CMonster* m_pMonster;

public:
	CTextRPG();
	~CTextRPG();

public:
	void ChooseMonster();
	bool GoField();
	void Fight();
	bool AttackCheckHP();
	void SavePlayer();
	void LoadPlayer();
	
public:
	void Init();
	void Update();
	void Release();

public:
	void MainFrame();

};