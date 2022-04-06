#pragma once

#include "Player.h"

class CWizard :
	public CPlayer
{
public:
	virtual void RenderPlayer();

public:
	CWizard();
	~CWizard();
};

