#pragma once
#include "Define.h"
#include "Field.h"

class CMainGame
{
private:
	CPlayer* m_pPlayer;
	CField* m_pField;

public:
	CMainGame();
	~CMainGame();

private:
	void InitPlayer();

public:
	void Initalize();
	void Update();
	void Release();
};

