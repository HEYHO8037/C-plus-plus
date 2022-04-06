#pragma once

#include "Define.h"
#include "Inventory.h"

class CPlayer
{
public:
	CPlayer();
	CPlayer(int _iAttack, int _iCurrentHP, int _iMaxHP);
	~CPlayer();

protected:
	int m_iAttack;
	int m_iCurrentHP;
	int m_iMaxHP;

private:
	CInventory* m_Inven;

public:
	void SetAttack(int iAttack);
	void SetHP(int iHP);
	void SetMaxHP(int iMaxHP);

public:
	int GetAttack() const;
	int GetHP() const;
	int GetMaxHP() const;
	CInventory* GetInven() const;

public:
	virtual void RenderPlayer();
	void AttackMonster(int _iMonsterAttack);
	void SavePlayer();
	void HealPlayer();
	void LoadPlayer();
};

