// 20220406.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MainGame.h"


int main()
{
	// 1. TextRPG, 인벤토리 구현(vector), 구매, 적용, 판매, 구현
	CMainGame mainGame;

	mainGame.Initalize();
	mainGame.Update();
	mainGame.Release();
	
	return 0;
}