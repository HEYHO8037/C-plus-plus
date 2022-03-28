#pragma once

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

public:
	void SetAttack(int iAttack);
	void SetHP(int iHP);

public:
	int GetAttack() const;
	int GetHP() const;

public:
	virtual void RenderPlayer();
	void AttackMonster(int _iMonsterAttack);
	void SavePlayer();
	void HealPlayer();
	void LoadPlayer();
};

