#pragma once

template<typename T>
struct LinkedList
{
	LinkedList<T>* pPrev;
	T data;
	LinkedList<T>* pNext;
};

template <typename T>
class CLinkedListManager
{
private:
	LinkedList<T>* m_pLinked;
	int m_iSum;

public:
	CLinkedListManager()
		: m_pLinked(nullptr), m_iSum(0)
	{
	}

	~CLinkedListManager()
	{
		DeleteAll();
	}

public:
	void Push_Back(T _data)
	{
		LinkedList<T>* pLinked = m_pLinked;
		m_pLinked = new LinkedList<T>;

		if (!m_iSum)
		{
			m_pLinked->pPrev = nullptr;
			m_pLinked->data = _data;
			m_pLinked->pNext = nullptr;
		}
		else
		{
			m_pLinked->pPrev = nullptr;
			m_pLinked->data = _data;
			m_pLinked->pNext = pLinked;
			pLinked->pPrev = m_pLinked;
		}

		m_iSum++;
	}

	void Select_Push(int _iPos, T _data)
	{
		LinkedList<T>* pushData = new LinkedList<T>;
		LinkedList<T>* saveLink = m_pLinked;

		pushData->data = _data;

		for (int i = 0; i < _iPos; ++i)
		{
			m_pLinked = m_pLinked->pNext;
		}

		m_pLinked->pPrev->pNext = pushData;
		m_pLinked->pPrev = pushData;

		pushData->pPrev = m_pLinked->pPrev;
		pushData->pNext = m_pLinked;

		m_iSum++;

		m_pLinked = saveLink;
	}

	void Push_Front(T _data)
	{
		LinkedList<T>* pLinked;
		LinkedList<T>* saveLinked = m_pLinked;

		pLinked = new LinkedList<T>;
		pLinked->data = _data;

		while (m_pLinked->pNext != nullptr)
		{
			m_pLinked = m_pLinked->pNext;
		}

		m_pLinked->pNext = pLinked;
		pLinked->pPrev = m_pLinked;
		pLinked->pNext = nullptr;

		m_iSum++;

		m_pLinked = saveLinked;
	}

	bool Delete(T _data)
	{
		if (!m_iSum)
		{
			return false;
		}

		LinkedList<T>* pLinked = m_pLinked;

		while (m_pLinked->data != _data)
		{
			m_pLinked = m_pLinked->pNext;

			if (m_pLinked == nullptr)
			{
				return false;
			}
		}

		m_pLinked->pNext->pPrev = m_pLinked->pPrev;
		m_pLinked->pPrev->pNext = m_pLinked->pNext;

		delete m_pLinked;

		m_iSum--;
		m_pLinked = pLinked;
		
		return true;
	}

	void DeleteFront()
	{
		if (!m_iSum)
		{
			return;
		}

		LinkedList<T>* pLinked = m_pLinked->pNext;

		delete m_pLinked;

		m_pLinked = pLinked;

		if (m_iSum != 1)
		{
			m_pLinked->pPrev = nullptr;
		}

		m_iSum--;
	}

	void DeleteBack()
	{
		if (!m_iSum)
		{
			return;
		}

		LinkedList<T>* pLinked = m_pLinked;
		LinkedList<T>* savepLinked;

		while (m_pLinked->pNext != nullptr)
		{
			m_pLinked = m_pLinked->pNext;
		}

		if (m_iSum != 1)
		{
			m_pLinked->pPrev->pNext = nullptr;
		}

		savepLinked = m_pLinked;
		m_pLinked = pLinked;

		delete savepLinked;
		m_iSum--;
	}

	void DeleteAll()
	{
		LinkedList<T>* saveList = nullptr;

		if (m_iSum)
		{
			while (m_pLinked->pNext != nullptr)
			{
				m_pLinked->pNext->pPrev = nullptr;
				saveList = m_pLinked->pNext;

				delete m_pLinked;

				m_pLinked = saveList;
				m_iSum--;
			}
		}

		delete m_pLinked;
		m_pLinked = nullptr;
		m_iSum--;
	}

	T Find(T _data)
	{
		LinkedList<T>* pLinked = m_pLinked;
		LinkedList<T>* pSaveLinked;

		while (m_pLinked->data != _data)
		{
			m_pLinked = m_pLinked->pNext;

			if (m_pLinked == nullptr)
			{
				m_pLinked = pLinked;
				return NULL;
			}
		}

		pSaveLinked = m_pLinked;
		m_pLinked = pLinked;

		return pSaveLinked->data;
	}

	int FindPos(T _data)
	{
		LinkedList<T>* pLinked = m_pLinked;
		int iNum = 0;

		while (m_pLinked->data != _data)
		{
			m_pLinked = m_pLinked->pNext;
			iNum++;

			if (m_pLinked == nullptr)
			{
				m_pLinked = pLinked;
				return -1;
			}
		}

		m_pLinked = pLinked;

		return iNum;
	}


	void Swap()
	{
		T* saveData = new T[m_iSum];
		LinkedList<T>* pLinked = m_pLinked;
		int iNum = 0;

		while (m_pLinked != nullptr)
		{
			saveData[iNum] = m_pLinked->data;
			m_pLinked = m_pLinked->pNext;
			iNum++;
		}

		for (int i = 0; i < (m_iSum / 2); ++i)
		{
			T saveArrData = NULL;

			saveArrData = saveData[i];
			saveData[i] = saveData[m_iSum - i - 1];
			saveData[m_iSum - i - 1] = saveArrData;
		}

		iNum = 0;
		m_pLinked = pLinked;

		while (m_pLinked != nullptr)
		{
			m_pLinked->data = saveData[iNum];
			m_pLinked = m_pLinked->pNext;
			iNum++;
		}

		delete[] saveData;
		saveData = nullptr;
		m_pLinked = pLinked;
	}
};