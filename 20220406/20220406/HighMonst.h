#pragma once
#include "Monster.h"

class CHighMonst :
	public CMonster
{
public:
	CHighMonst();
	~CHighMonst();

public:
	virtual void RenderMonster();
};

