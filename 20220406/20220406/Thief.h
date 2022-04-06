#pragma once

#include "Player.h"

class CThief :
	public CPlayer
{
public:
	virtual void RenderPlayer();

public:
	CThief();
	~CThief();
};

