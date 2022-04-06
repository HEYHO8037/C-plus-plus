#pragma once

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if(p) { delete[] p; p = nullptr; }

enum _tagItemType
{
	WEAPON,
	ARMOR,
	PORTION
};

enum classType
{
	WARRIOR,
	WIZARD,
	THIEF
};

typedef struct _tagItem
{
	string strName;
	_tagItemType eType;
	int iAttack;
	int iArmor;
	int iPortion;

	_tagItem()
	{
	}

	_tagItem(string name, _tagItemType type, int attack, int armor, int portion)
	{
		strName = name;
		eType = type;
		iAttack = attack;
		iArmor = armor;
		iPortion = portion;
	}

}ITEM, *PITEM;