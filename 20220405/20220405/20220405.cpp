// 20220405.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "GradeProgram.h"


int main()
{
	// 1. 벡터를 이용해서 성적표 프로그램 제작하기
	// 1. 입력, 2. 전체 출력 3. 검색 출력, 4. 검색 삭제(erase 함수 -> iterator을 이용하여 삭제)

	CGradeProgram Pro;

	Pro.Menu();

	return 0;
}