#include "Core.h"

int main(void)
{

	// 1. 오늘 풀이한 코드를 기반으로 동적할당으로 Text RPG 만들기
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

		cout << "1. 전사, 2. 마법사, 3. 도적, 4. 불러오기, 5. 종료" << endl;
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
				cout << "파일 불러오기를 실패했습니다." << endl;
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
	cout << "직업 : ";

	switch (_player->m_iClass)
	{
	case WARRIOR:
		cout << "전사" << endl;
		break;
	case MAGICIAN:
		cout << "마법사" << endl;
		break;
	case THIEF:
		cout << "도적" << endl;
		break;
	}

	cout << "체력 : " << _player->m_iCurrentHP << endl;
	cout << "공격력 : " << _player->m_iAttack << endl;
}

void ShowMonsterState(Monster * _monster)
{
	cout << "몬스터클래스 : ";

	switch (_monster->m_iClass)
	{
	case LOW:
		cout << "하급" << endl;
		break;
	case MIDDLE:
		cout << "중급" << endl;
		break;
	case HIGH:
		cout << "상급" << endl;
		break;
	}

	cout << "체력 : " << _monster->m_iHP << endl;
	cout << "공격력 : " << _monster->m_iAttack << endl;
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
		cout << "1. 사냥터, 2. 저장, 3. 종료" << endl;
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
				cout << "데이터 저장 성공" << endl;
			}
			else
			{
				cout << "데이터 저장 실패" << endl;
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

		cout << "1. 하급, 2. 중급, 3. 상급, 4. 이전" << endl;
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

		cout << "1. 공격, 2. 도망치기" << endl;
		cin >> iInput;

		if (1 == iInput)
		{
			_player->m_iCurrentHP -= _monster->m_iAttack;
			_monster->m_iHP -= _player->m_iAttack;

			if (0 >= _player->m_iCurrentHP)
			{
				system("cls");
				cout << "플레이어가 사망했습니다." << endl;

				_player->m_iCurrentHP = _player->m_iMaxHP;
				system("pause");

				break;
			}
			else if (0 >= _monster->m_iHP)
			{
				system("cls");
				cout << "승리하였습니다." << endl;
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
