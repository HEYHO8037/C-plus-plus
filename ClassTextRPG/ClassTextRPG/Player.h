#pragma once
#include "stdafx.h"

enum _tagPlayerClass
{
	WARRIOR = 1,
	MAGICIAN,
	THIEF
};

class CPlayer
{
private:
	int m_iAttack;
	int m_iClass;
	int m_iMaxHP;
	int m_iCurrentHP;

public:
	CPlayer();
	CPlayer(int _iClass);
	~CPlayer();

public:
	int GetHP() const;
	int GetAttack() const;
	int GetClass() const;
	int GetMaxHP() const;

public:
	void SetHP(int _iCurrentHP);
	void SetAttack(int _iAttack);
	void SetClass(int _iClass);
	void SetMaxHP(int _iMaxHP);

public:
	void Attack(int _iMonsterAttack);
	void ShowPlayerState();
	void HealPlayer();

};