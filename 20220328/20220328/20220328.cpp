// 20220328.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MainGame.h"


int main()
{
	// 1. ����� �̿��Ͽ� TextRPG �����ϱ�
	CMainGame mainGame;

	mainGame.Initalize();
	mainGame.Update();
	mainGame.Release();
	return 0;
}