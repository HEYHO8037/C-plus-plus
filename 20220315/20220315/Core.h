#pragma once

#include <iostream>

using namespace std;

enum PlayerClass
{
	WARRIOR = 1,
	MAGICIAN,
	THIEF
};

enum MonsterClass
{
	LOW = 1,
	MIDDLE,
	HIGH
};

struct Player
{
	int m_iClass;
	int m_iCurrentHP;
	int m_iMaxHP;
	int m_iAttack;
};

struct Monster
{
	int m_iClass;
	int m_iHP;
	int m_iAttack;
};

Player* CreatePlayer(int _iInput);
Monster* CreateMonster(int _iInput);
Player* ReleasePlayer(Player* _player);
Monster* ReleaseMonster(Monster* _monster);

Player* Init(Player* _player);

void ShowPlayerState(Player* _player);
void ShowMonsterState(Monster* _monster);

bool Update(Player* _player, Monster* _monster);
bool Field(Player* _player);
Monster* ChooseMonster(Monster* _monster);
void Fight(Player* _player, Monster* _monster);