// 20220331.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "String.h"


int main()
{
	// 1. ��Ʈ�� Ŭ������ ����µ� ==(strcmp) ,+(strcat), =(strcpy) �� 3���� ����� �����ض�
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