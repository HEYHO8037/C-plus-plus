// 20220328.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MainGame.h"


int main()
{
	// 1. 상속을 이용하여 TextRPG 수정하기
	CMainGame mainGame;

	mainGame.Initalize();
	mainGame.Update();
	mainGame.Release();
	return 0;
}