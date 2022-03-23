#pragma once

class CMonster
{
public:
	CMonster();
	~CMonster();

private:
	int m_iClass;
	int m_iAttack;
	int m_iHP;

public:
	int GetAttack() const;
	int GetHP() const;;

public:
	void RenderMonster();
	void AttackPlayer(int _iPlayerAttack);
	void InitMonster();


};

