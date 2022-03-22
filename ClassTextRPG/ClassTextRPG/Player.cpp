#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
	: m_iAttack(0),
	  m_iClass(0),
	  m_iMaxHP(0),
	  m_iCurrentHP(0)
{
}

CPlayer::CPlayer(int _iClass)
{
	switch (_iClass)
	{
	case WARRIOR:
		m_iClass = WARRIOR;
		m_iAttack = 10;
		m_iMaxHP = 200;
		m_iCurrentHP = 200;
		break;

	case MAGICIAN:
		m_iClass = MAGICIAN;
		m_iAttack = 100;
		m_iMaxHP = 100;
		m_iCurrentHP = 200;
		break;

	case THIEF:
		m_iClass = THIEF;
		m_iAttack = 20;
		m_iMaxHP = 50;
		m_iCurrentHP = 200;
		break;
	}
}

CPlayer::~CPlayer()
{
}

int CPlayer::GetHP() const
{
	return m_iCurrentHP;
}

int CPlayer::GetAttack() const
{
	return m_iAttack;
}

int CPlayer::GetClass() const
{
	return m_iClass;
}

int CPlayer::GetMaxHP() const
{
	return m_iMaxHP;
}

void CPlayer::SetHP(int _iCurrentHP)
{
	m_iCurrentHP = _iCurrentHP;
}

void CPlayer::SetAttack(int _iAttack)
{
	m_iAttack = _iAttack;
}

void CPlayer::SetClass(int _iClass)
{
	m_iClass = _iClass;
}

void CPlayer::SetMaxHP(int _iMaxHP)
{
	m_iMaxHP = _iMaxHP;
}

void CPlayer::Attack(int _iMonsterAttack)
{
	m_iCurrentHP -= _iMonsterAttack;
}

void CPlayer::ShowPlayerState()
{
	cout << "���� : ";

	switch (m_iClass)
	{
	case WARRIOR:
		cout << "����" << endl;
		break;
	case MAGICIAN:
		cout << "������" << endl;
		break;
	case THIEF:
		cout << "����" << endl;
		break;
	}

	cout << "ü�� : " << m_iCurrentHP << endl;
	cout << "���ݷ� : " << m_iAttack << endl;
}

void CPlayer::HealPlayer()
{
	m_iCurrentHP = m_iMaxHP;
}
