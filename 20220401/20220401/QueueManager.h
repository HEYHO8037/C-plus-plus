#pragma once

#include "stdafx.h"

template<typename T>
struct Queue
{
	Queue<T>* pPrev;
	T data;
	Queue<T>* pNext;
};

template <typename T>
class CQueueManager
{
private:
	Queue<T>* m_pQueue;
	int m_iSum;

public:
	CQueueManager()
		: m_pQueue(nullptr), m_iSum(0)
	{
	}

	~CQueueManager()
	{
		Queue<T>* saveQueue = nullptr;

		if (m_iSum)
		{
			while (m_pQueue->pNext != nullptr)
			{
				m_pQueue->pNext->pPrev = nullptr;
				saveQueue = m_pQueue->pNext;

				delete m_pQueue;

				m_pQueue = saveQueue;
				m_iSum--;
			}
		}

		delete m_pQueue;
		m_pQueue = nullptr;
		m_iSum--;
	}

public:
	void Offer(T _data)
	{
		Queue<T>* pQueue = m_pQueue;
		m_pQueue = new Queue<T>;

		if (!m_iSum)
		{
			m_pQueue->pPrev = nullptr;
			m_pQueue->data = _data;
			m_pQueue->pNext = nullptr;
		}
		else
		{
			m_pQueue->pPrev = nullptr;
			m_pQueue->data = _data;
			m_pQueue->pNext = pQueue;
			pQueue->pPrev = m_pQueue;
		}

		m_iSum++;
	}

	void Poll()
	{
		if (!m_iSum)
		{
			return;
		}

		Queue<T>* pQueue = m_pQueue;

		while (m_pQueue->pNext != nullptr)
		{	
			m_pQueue = m_pQueue->pNext;
		}

		if (m_iSum != 1)
		{
			m_pQueue->pPrev->pNext = nullptr;
			m_pQueue->pPrev = nullptr;
		}

		delete m_pQueue;


		m_iSum--;
		m_pQueue = pQueue;

	}

	T Find(T _data)
	{
		Queue<T>* pQueue = m_pQueue;
		Queue<T>* pSaveQueue;

		while (m_pQueue->pNext == nullptr)
		{
			if (m_pQueue->data == _data)
			{
				pSaveQueue = m_pQueue;
				m_pQueue = pQueue;
				return pSaveQueue->data;
			}
			else
			{
				m_pQueue = m_pQueue->pNext;
			}
		}

		m_pQueue = pQueue;
		return nullptr;

	}
};

