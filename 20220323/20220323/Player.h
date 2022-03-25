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
	void SetAttack(int iAttack);
	void SetHP(int iHP);

public:
	int GetAttack() const;
	int GetHP() const;

private:
	void LoadPlayer();

public:
	void RenderPlayer();
	void AttackMonster(int _iMonsterAttack);
	void InitPlayer();
	void SavePlayer();
	void HealPlayer();
};

