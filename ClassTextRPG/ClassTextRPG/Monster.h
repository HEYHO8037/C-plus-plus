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
	int m_iClass = 0;
	int m_iHP = 0;
	int m_iAttack = 0;

public:
	int GetHP() const;
	int GetAttack() const;

public:
	void InitMonster(int _iInput);
	void Attack(int _iPlayerAttack);
	void ShowMonsterState();
};