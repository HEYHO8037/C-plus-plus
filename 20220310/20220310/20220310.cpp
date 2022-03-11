#include <iostream>

	using namespace std;

	enum PlayerClass
	{
		WARRIOR = 1,
		MAGICIAN,
		THIEF
	};

	enum MonsterClass
	{
		LOW = 1,
		MIDDLE,
		HIGH
	};

	struct Player
	{
		int m_iClass;
		int m_iCurrentHP;
		int m_iMaxHP;
		int m_iAttack;
	};

	struct Monster
	{
		int m_iClass;
		int m_iHP;
		int m_iAttack;
	};

	Player* CreatePlayer(int _iInput);
	Monster* CreateMonster(int _iInput);
	Player* ReleasePlayer(Player* _player);
	Monster* ReleaseMonster(Monster* _monster);

	Player* Init(Player* _player);

	void ShowPlayerState(Player* _player);
	void ShowMonsterState(Monster* _monster);

	bool Update(Player* _player, Monster* _monster);
	bool Field();
	Monster* ChooseMonster(Monster* _monster);
	void Fight(Player* _player, Monster* _monster);


	int main(void)
	{
		// 1. Text RPG ����� �ҷ����� ����� �����Ͻÿ�.

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

		while (true)
		{
			system("cls");

			cout << "1. ����, 2. ������, 3. ����, 4. ����" << endl;
			cin >> iInput;

			if (4 == iInput)
			{
				break;
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
			bIsCheck = Field();

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

	bool Field()
	{
		int iInput = 0;
		bool bIsCheck = false;

		while (true)
		{
			cout << "1. �����, 2. ����" << endl;
			cin >> iInput;

			if (1 == iInput)
			{
				bIsCheck = true;
				break;
			}
			else if (2 == iInput)
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