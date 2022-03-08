#include <iostream>
#include <stdlib.h>

using namespace std;

enum tagJobType
{
	WARRIOR = 1,
	MAGICIAN,
	THIEF,
	GUNNER
};

struct Monster
{
	int iAttack;
	int iHP;
};

struct Player
{
	int iJob;
	int iAttack;
	int iHP;
};

void Init(Player* player);
void Update(Monster* monster, Player* player);
void Release(Monster* monster, Player* player);

int InputText();

int GoDungen(Player* player);
int SelectMonster(Monster* monster, Player* player);
void RunOrAttack(Monster* monster, Player* player);
void Attack(Monster* monster, Player* player);


int main(void)
{
	// 1. TextRPG
	// ù ���۽� 1. ���� 2. ������, 3. ���� 4. ����
	// ����, ���ݷ�, ü�� ���
	// 1. ����� 2. ����
	// 1. �ʱ�, 2. �߱�, 3. ���
	// 1. ����, 2. ����
	// ���Ͱ� �����鼭 ��� ���� ���, �÷��̾� ����� ���ܰ�� �̵� �� �÷��̾� ǮHP
	Player* player = new Player;
	Monster* monster = new Monster;

	Init(player);
	Update(monster, player);
	Release(monster, player);

	return 0;
}

void Init(Player* player)
{
	int iChooseJob = 0;

	while (true)
	{
		system("cls");
		cout << "1. ����, 2. ������, 3. ����, 4. �ų�, 5. ����" << endl;
		iChooseJob = InputText();

		if (iChooseJob == WARRIOR)
		{
			player->iJob = WARRIOR;
			player->iAttack = 10;
			player->iHP = 200;
			break;
		}
		else if (iChooseJob == MAGICIAN)
		{
			player->iJob = MAGICIAN;
			player->iAttack = 100;
			player->iHP = 100;
			break;
		}
		else if (iChooseJob == THIEF)
		{
			player->iJob = THIEF;
			player->iAttack = 20;
			player->iHP = 50;
			break;
		}
		else if (iChooseJob == GUNNER)
		{
			player->iJob = GUNNER;
			player->iAttack = 150;
			player->iHP = 100;
			break;
		}
		else if (5 == iChooseJob)
		{
			cout << "�����մϴ�." << endl;
			exit(0);
		}
		else
		{
			cout << "�ٽ� �Է����ּ���" << endl;
			system("pause");
		}

	}
}

void Update(Monster* monster, Player* player)
{
	int select = 0;

	while (true)
	{
		system("cls");
		select = GoDungen(player);

		if (1 == select)
		{
			if (1 == SelectMonster(monster, player))
			{
				continue;
			}

			RunOrAttack(monster, player);
		}
		else if (2 == select)
		{
			Init(player);
			continue;
		}
		else if (3 == select)
		{
			exit(0);
		}
		else
		{
			continue;
		}
	}

}

void Release(Monster* monster, Player* player)
{
	delete player;
	delete monster;

	monster = nullptr;
	player = nullptr;
}

int InputText()
{
	int iInput = 0;
	cin >> iInput;

	return iInput;
}

int GoDungen(Player* player)
{
	cout << "�������� : ";

	if (player->iJob == WARRIOR)
	{
		cout << "����";
	}
	else if (player->iJob == MAGICIAN)
	{
		cout << "������";
	}
	else if (player->iJob == THIEF)
	{
		cout << "����";
	}
	else
	{
		cout << "�ų�";
	}

	cout << " HP : " << player->iHP << " ���ݷ� : " << player->iAttack << endl;
	cout << "=================================================================" << endl;
	cout << "1. �����, 2. �ڷΰ���, 3. ����" << endl;

	return InputText();
}

int SelectMonster(Monster* monster, Player * player)
{
	int iSelect = 0;
	while (true)
	{
		system("cls");
		cout << "Player HP : " << player->iHP << " Player Attack : " << player->iAttack << endl;
		cout << "=================================================================" << endl;
		cout << "1. �ʱ�, 2. �߱�, 3. ���, 4. �ڷΰ���" << endl;
		iSelect = InputText();

		if (1 == iSelect)
		{
			monster->iAttack = 5;
			monster->iHP = 30;
			break;
		}
		else if (2 == iSelect)
		{
			monster->iAttack = 50;
			monster->iHP = 60;
			break;
		}
		else if (3 == iSelect)
		{
			monster->iAttack = 200;
			monster->iHP = 90;
			break;
		}
		else if (4 == iSelect)
		{
			return 1;
		}
		else
		{
			continue;
		}
	}

	return 0;
}

void RunOrAttack(Monster * monster, Player * player)
{
	int iSelect = 0;
	int iPlayerHP = player->iHP;

	while (true)
	{
		system("cls");
		cout << "Player HP : " << player->iHP << " Player Attack : " << player->iAttack << endl;
		cout << "Monster HP : " << monster->iHP << " Monster Attack : " << monster->iAttack << endl;
		cout << "=================================================================" << endl;
		cout << "1. ����, 2. ����" << endl;
		iSelect = InputText();

		if (1 == iSelect)
		{
			Attack(monster, player);
		}
		else if (2 == iSelect)
		{
			return;
		}
		else
		{
			continue;
		}

		if (player->iHP <= 0)
		{
			system("cls");
			cout << "�÷��̾ ����߽��ϴ�." << endl;
			player->iHP = iPlayerHP;

			system("pause");
			break;
		}
		else if (monster->iHP <= 0)
		{
			system("cls");
			cout << "�÷��̾ �̰���ϴ�." << endl;
			system("pause");
			break;
		}
	}
}

void Attack(Monster * monster, Player * player)
{
	system("cls");
	player->iHP -= monster->iAttack;
	monster->iHP -= player->iAttack;
	cout << "����!" << endl;
	system("pause");
}