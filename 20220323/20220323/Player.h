#pragma once

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

private:
	int m_iAttack;
	int m_iCurrentHP;
	int m_iMaxHP;
	int m_iClass;

public:
	int GetAttack() const;
	int GetHP() const;

private:
	void LoadPlayer();
	void HealPlayer();

public:
	void RenderPlayer();
	void AttackMonster(int _iMonsterAttack);
	void InitPlayer();
	void SavePlayer();
};

