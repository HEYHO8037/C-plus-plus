#pragma once
#include "Monster.h"

class CMiddleMonst :
	public CMonster
{
public:
	CMiddleMonst();
	~CMiddleMonst();

public:
	virtual void RenderMonster();
};

