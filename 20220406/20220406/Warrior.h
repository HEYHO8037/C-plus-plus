#pragma once

#include "Player.h"

class CWarrior :
	public CPlayer
{
public:
	virtual void RenderPlayer();

public:
	CWarrior();
	~CWarrior();
};

