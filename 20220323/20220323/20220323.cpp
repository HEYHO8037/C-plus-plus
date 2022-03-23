// 20220323.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MainGame.h"

int main()
{
	CMainGame mainGame;

	mainGame.Initalize();
	mainGame.Update();
	mainGame.Release();
	return 0;
}