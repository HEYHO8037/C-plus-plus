// 20220331.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "String.h"


int main()
{
	// 1. 스트링 클래스를 만드는데 ==(strcmp) ,+(strcat), =(strcpy) 이 3개의 기능을 구현해라
	CString A("abc");
	CString B("bbc");

	CString C;
	C = A + "ccd";
	bool a = (C == A);
	bool b = (C == "abc");
	C = A;
	a = (C == A);
	b = (C == "abc");


    return 0;
}