#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#pragma once

using namespace std;

void Redo();

#pragma region structs
struct Player
{
	float health;
	float damage;
};

struct Enemy
{
	string name;
	float health;
	float damage;
};

struct Furniture
{
	string name;
	float health;
	bool ugly;
};

struct Maze
{
	int type;
	Enemy Rat;
	Furniture Chair;
};

struct Water
{
	string name;
	bool water;
};

struct FloodedRoom
{
	Furniture Chair;
	Water water;
	Maze Room;
};

struct TalkingRoom
{
	Enemy yapper;
	Maze room;
};

struct RatRoom
{
	Enemy Rat;
	Maze room;
};

#pragma endregion

Maze room[4][4];
RatRoom Rroom[4][4];
TalkingRoom Troom[4][4];
FloodedRoom Froom[4][4];
Player player;
Enemy ratAmount[15];
int ratVar;
int x;
int y;

#pragma region classes
class Movement
{
private:
	char input;
	int selection;
public:
	void moveEast()
	{
		x++;
		cout << "You went East" << endl;
		Redo();
	}
	void moveNorth()
	{
		y++;
		cout << "You went North" << endl;
		Redo();
	}

	void move()
	{
		if (x == 3)
		{
			cout << "You can only go north!" << endl;
			moveNorth();
		}
		else if (y == 3)
		{
			cout << "You can only go East!" << endl;
			moveEast();
		}
		else
		{
			cout << "Where will you go?" << endl;
			cout << "\n1. North";
			cout << "\n2. East" << endl;
			cin >> selection;
			switch (selection)
			{
			case 1:
				moveNorth();
				break;
			case 2:
				moveEast();
				break;
			default:
				cout << "INVALID CHOICE, YOU SHALL DIE NOW" << endl;
			}
		}
	}
};
Movement movement;


class battle
{
private:
	int selection;
	float damage;
	Movement movement;
public:
	void fight()
	{
		srand(static_cast<unsigned int>(time(0)));
	}

	void runAway()
	{
		int choice = rand() % 2;

		if (choice == 0)
		{
			movement.moveNorth();
		}
		else
		{
			movement.moveEast();
		}
	}

	void preFightDialogue()
	{
		if (room[x][y].type == '0')
		{
			cout << "This rat seems like a rat" << endl;
		}
		else if (room[x][y].type == '1')
		{
			cout << "This room is flooded" << endl;
		}
		else if (room[x][y].type == '2')
		{
			cout << "Theres an old chatter box toy in the corner" << endl;
		}
		cout << "A rat has jumped you" << endl;
		battleScreen();
	}

	void battleScreen()
	{
		cout << "\n1. Attack";
		cout << "\n2. Run Away" << endl;
		cin >> selection;

		switch (selection)
		{
		case 1:
			cout << "You delt 5 damage!" << endl;
			if (room[x][y].Rat.health <= 0)
			{
				cout << "The rats been done in" << endl;
				movement.move();
			}
			break;
		case 2:
			cout << "You ran off in a random direction screaming with your arms in the air" << endl;
			runAway();
			break;
		default:
			cout << "INVALID CHOICE, YOU SHALL DIE NOW" << endl;
		}
	}

	void playerAttack()
	{
		damage = player.damage;
	}

	void enemyVariables()
	{
		{
			room[x][y].Rat.health = 10;
			room[x][y].Rat.damage = 1;
		}
	}
};

battle Battle;
#pragma endregion
void Redo()
{
	Battle.preFightDialogue();
}

int main()
{
	char hero;

	cout << "Thank god! It's you isn't it, the legendary Tony Oakden, it's been foretold that you would save us from this cursed place" << endl;
	cout << "Please save us!" << endl;
	cout << "y/n" << endl;
	cin >> hero;

	hero = tolower(hero);

	if (hero == 'y')
	{
		cout << "THANK YOU! YOUR KINDNESS WILL NOT BE FORGOTTEN!" << endl;
		cout << "Please hurry, I hear things in the other room." << endl;

		room[0][1].type = '0';
		room[1][1].type = '0';
		room[2][1].type = '2';
		room[3][1].type = '1';
		room[0][2].type = '1';
		room[1][2].type = '0';
		room[2][2].type = '0';
		room[3][2].type = '0';
		room[0][3].type = '2';
		room[1][3].type = '2';
		room[2][3].type = '1';
		room[3][3].type = '0';
		room[0][4].type = '0';
		room[1][4].type = '1';
		room[2][4].type = '0';
		room[3][4].type = '2';

		movement.move();
	}
	else if (hero == 'n')
	{
		cout << "Oh... Ok..." << endl;
		exit(0);
	}
}
