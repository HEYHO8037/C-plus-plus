// 20220401.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "QueueManager.h"
#include "LinkedListManager.h"


int main()
{
	// 1. ����⸮��Ʈ(LinkedList) �����غ���
	
	//CQueueManager<int> t;

	//t.Offer(10);
	//t.Offer(20);
	//t.Offer(30);

	//t.Poll();
	//t.Poll();
	//t.Poll();

	CLinkedListManager<int> t;
	t.Push_Back(10);
	t.Push_Back(20);
	t.Push_Back(30);
	t.Push_Back(40);
	t.Select_Push(2, 25);
	t.Push_Front(100);

	t.Swap();

	t.Find(200);
	t.FindPos(20);

	t.DeleteAll();
	
	return 0;
}