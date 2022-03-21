// 20220321.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MainProgram.h"


int main()
{
	// 1. 성적표 프로그램을 클래스화 시키기(2개의 클래스 필요, 학생과 메인) +  동적 배열, 추가입력 기능 구현

	CMainProgram mainProgram;

	mainProgram.ProgramMain();

    return 0;
}