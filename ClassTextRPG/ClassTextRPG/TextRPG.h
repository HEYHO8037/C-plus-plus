#pragma once
#include "Player.h"
#include "Monster.h"

class CTextRPG
{
private:
	CPlayer* m_pPlayer = nullptr;
	CMonster* m_pMonster = nullptr;

public:
	void ChooseMonster();
	bool GoField();
	void Fight();
	bool AttackCheckHP();
	void SavePlayer();
	void LoadPlayer();
	
public:
	void ChoosePlayer();
	bool Update();
	void AllRelease();

public:
	void InitPlayer(int _iInput);
	void InitMonster(int _iInput);
	void MonsterRelease();
	void PlayerRelease();

public:
	void MainFrame();

};