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
	int m_iAttack = 0;
	int m_iClass = 0;
	int m_iMaxHP = 0;
	int m_iCurrentHP = 0;

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
	void InitPlayer(int _iInput);
	void ShowPlayerState();
	void HealPlayer();

};