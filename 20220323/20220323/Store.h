#pragma once

enum WEAPON
{
	KNIFE = 1,
	ARROW,
	GUN
};

enum ARMOR
{
	LOW = 4,
	MIDDLE,
	HIGH
};

enum PORTION
{
	HP = 7,
	SP,
	BUFF
};


class CStore
{
private:
	class CPlayer* m_pPlayer;

public:
	CStore();
	~CStore();

public:
	void SetPlayer(class CPlayer* pPlayer);

public:
	void RenderStore();
	void ArmorBuy();
	void WeaponBuy();
	void PortionBuy();

};

