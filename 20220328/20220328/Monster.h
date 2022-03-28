#pragma once

class CMonster
{
public:
	CMonster();
	CMonster(int _iAttack, int _iHP);
	~CMonster();

protected:
	int m_iAttack;
	int m_iHP;

public:
	int GetAttack() const;
	int GetHP() const;;

public:
	virtual void RenderMonster();
	void AttackPlayer(int _iPlayerAttack);
};

