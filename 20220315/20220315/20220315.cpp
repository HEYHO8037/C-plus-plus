#include "Core.h"

int main(void)
{

	// 1. ���� Ǯ���� �ڵ带 ������� �����Ҵ����� Text RPG �����
	Player* player = nullptr;
	Monster* monster = nullptr;
	bool bIsCheck = 0;

	player = Init(player);

	if (player == nullptr)
	{
		player = ReleasePlayer(player);
		monster = ReleaseMonster(monster);
		return 0;
	}

	bIsCheck = Update(player, monster);

	if (!bIsCheck)
	{
		player = ReleasePlayer(player);
		monster = ReleaseMonster(monster);
		return 0;
	}

	player = ReleasePlayer(player);
	monster = ReleaseMonster(monster);
	return 0;
}

Player* CreatePlayer(int _iInput)
{
	Player* player = new Player;

	switch (_iInput)
	{
	case WARRIOR:
		player->m_iClass = WARRIOR;
		player->m_iAttack = 10;
		player->m_iMaxHP = 200;
		player->m_iCurrentHP = 200;
		break;
	case MAGICIAN:
		player->m_iClass = MAGICIAN;
		player->m_iAttack = 100;
		player->m_iMaxHP = 100;
		player->m_iCurrentHP = 200;
		break;
	case THIEF:
		player->m_iClass = THIEF;
		player->m_iAttack = 20;
		player->m_iMaxHP = 50;
		player->m_iCurrentHP = 200;
		break;
	}

	return player;
}

Monster* CreateMonster(int _iInput)
{
	Monster* monster = new Monster;

	switch (_iInput)
	{
	case LOW:
		monster->m_iClass = LOW;
		monster->m_iAttack = 5;
		monster->m_iHP = 30;
		break;

	case MIDDLE:
		monster->m_iClass = MIDDLE;
		monster->m_iAttack = 50;
		monster->m_iHP = 60;
		break;

	case HIGH:
		monster->m_iClass = HIGH;
		monster->m_iAttack = 200;
		monster->m_iHP = 90;
		break;
	}



	return monster;
}

Player* ReleasePlayer(Player* _player)
{
	if (_player != nullptr)
	{
		delete _player;
		_player = nullptr;
	}

	return _player;
}

Monster* ReleaseMonster(Monster* _monster)
{
	if (_monster != nullptr)
	{
		delete _monster;
		_monster = nullptr;
	}

	return _monster;
}

Player* Init(Player* _player)
{
	int iInput = 0;
	FILE* pFile = nullptr;
	Player pGetPlayer;

	while (true)
	{
		system("cls");

		cout << "1. ����, 2. ������, 3. ����, 4. �ҷ�����, 5. ����" << endl;
		cin >> iInput;

		if (5 == iInput)
		{
			break;
		}
		else if (4 == iInput)
		{
			errno_t err = fopen_s(&pFile, "../Data/Save.txt", "rb");
			if (NULL == err)
			{
				fread(&pGetPlayer, sizeof(Player), 1, pFile);
				fclose(pFile);

				_player = new Player;
				_player->m_iAttack = pGetPlayer.m_iAttack;
				_player->m_iClass = pGetPlayer.m_iClass;
				_player->m_iCurrentHP = pGetPlayer.m_iCurrentHP;
				_player->m_iMaxHP = pGetPlayer.m_iMaxHP;
				break;
			}
			else
			{
				cout << "���� �ҷ����⸦ �����߽��ϴ�." << endl;
			}
		}
		else if (iInput > 0 && iInput < 4)
		{
			_player = CreatePlayer(iInput);
			break;
		}
		else
		{
			continue;
		}
	}

	return _player;
}

void ShowPlayerState(Player * _player)
{
	cout << "���� : ";

	switch (_player->m_iClass)
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

	cout << "ü�� : " << _player->m_iCurrentHP << endl;
	cout << "���ݷ� : " << _player->m_iAttack << endl;
}

void ShowMonsterState(Monster * _monster)
{
	cout << "����Ŭ���� : ";

	switch (_monster->m_iClass)
	{
	case LOW:
		cout << "�ϱ�" << endl;
		break;
	case MIDDLE:
		cout << "�߱�" << endl;
		break;
	case HIGH:
		cout << "���" << endl;
		break;
	}

	cout << "ü�� : " << _monster->m_iHP << endl;
	cout << "���ݷ� : " << _monster->m_iAttack << endl;
}

bool Update(Player * _player, Monster * _monster)
{
	bool bIsCheck = false;
	int iReturn = 0;

	while (true)
	{
		system("cls");

		ShowPlayerState(_player);
		bIsCheck = Field(_player);

		if (!bIsCheck)
		{
			return bIsCheck;
		}

		_monster = ChooseMonster(_monster);

		if (_monster == nullptr)
		{
			continue;
		}

		Fight(_player, _monster);
	}


}

bool Field(Player* _player)
{
	int iInput = 0;
	bool bIsCheck = false;
	FILE* pFile = nullptr;
	Player savePlayer;

	while (true)
	{
		cout << "1. �����, 2. ����, 3. ����" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			bIsCheck = true;
			break;
		}
		else if (2 == iInput)
		{
			savePlayer.m_iAttack = _player->m_iAttack;
			savePlayer.m_iClass = _player->m_iClass;
			savePlayer.m_iCurrentHP = _player->m_iCurrentHP;
			savePlayer.m_iMaxHP = _player->m_iMaxHP;

			errno_t err = fopen_s(&pFile, "../Data/Save.txt", "wb");
			if (NULL == err)
			{
				fwrite(&savePlayer, sizeof(Player), 1, pFile);
				fclose(pFile);
				cout << "������ ���� ����" << endl;
			}
			else
			{
				cout << "������ ���� ����" << endl;
			}

			continue;
		}
		else if (3 == iInput)
		{
			break;
		}
		else
		{
			continue;
		}
	}


	return bIsCheck;
}

Monster* ChooseMonster(Monster * _monster)
{
	int iInput = 0;

	while (true)
	{
		system("cls");

		cout << "1. �ϱ�, 2. �߱�, 3. ���, 4. ����" << endl;
		cin >> iInput;

		if (0 < iInput && iInput < 4)
		{
			_monster = CreateMonster(iInput);
			break;
		}
		else if (4 == iInput)
		{
			break;
		}
		else
		{
			continue;
		}
	}

	return _monster;
}

void Fight(Player * _player, Monster * _monster)
{
	int iInput = 0;

	while (true)
	{
		system("cls");

		ShowPlayerState(_player);
		ShowMonsterState(_monster);

		cout << "1. ����, 2. ����ġ��" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			_player->m_iCurrentHP -= _monster->m_iAttack;
			_monster->m_iHP -= _player->m_iAttack;

			if (0 >= _player->m_iCurrentHP)
			{
				system("cls");
				cout << "�÷��̾ ����߽��ϴ�." << endl;

				_player->m_iCurrentHP = _player->m_iMaxHP;
				system("pause");

				break;
			}
			else if (0 >= _monster->m_iHP)
			{
				system("cls");
				cout << "�¸��Ͽ����ϴ�." << endl;
				_monster = ReleaseMonster(_monster);
				system("pause");
				break;
			}
		}
		else if (2 == iInput)
		{
			_monster = ReleaseMonster(_monster);
			break;
		}
		else
		{
			continue;
		}
	}
}
