// 20220406.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MainGame.h"


int main()
{
	// 1. TextRPG, �κ��丮 ����(vector), ����, ����, �Ǹ�, ����
	CMainGame mainGame;

	mainGame.Initalize();
	mainGame.Update();
	mainGame.Release();
	
	return 0;
}