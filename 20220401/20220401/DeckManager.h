#pragma once

#include "stdafx.h"

template<typename T>
struct Deck
{
	Queue<T>* pPrev;
	T data;
	Queue<T>* pNext;
};

template <typename T>
class CDeckManager
{
private:
	Deck<T>* m_pDeck;

public:
	CDeckManager()
	{

	}

	~CDeckManager()
	{

	}

};

