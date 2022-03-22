#pragma once
#include "stdafx.h"

enum _tagMonsterClass
{
	LOW = 1,
	MIDDLE,
	HIGH
};


class CMonster
{
private:
	int m_iClass;
	int m_iHP;
	int m_iAttack;

public:
	CMonster();
	CMonster(int _iClass);
	~CMonster();

public:
	int GetHP() const;
	int GetAttack() const;

public:
	void Attack(int _iPlayerAttack);
	void ShowMonsterState();
};