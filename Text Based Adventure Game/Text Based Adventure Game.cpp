#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#pragma once

using namespace std;

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

struct Maze
{
	Enemy Rat;
};
#pragma endregion

Maze room[4][4];
Player player;
Enemy ratAmount[15];
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
	}
	void moveNorth()
	{
		y++;
		cout << "You went North" << endl;
	}

	void move()
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
};
Movement movement;

class battle
{
private:
	int selection;
	float damage;
	Movement movement;
public:
	battle()
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

	void battleScreen()
	{
		cout << "\n1. Attack";
		cout << "\n2. Run Away" << endl;
		cin >> selection;

		switch (selection)
		{
		case 1:
			cout << "You delt 5 damage!" << endl;
			break;
		case 2:
			cout << "You ran off in a random direction screaming with your arms in the air" << endl;
			runAway();
			break;
		default:
			cout << "INVALID CHOICE, YOU SHALL DIE NOW" << endl;
		}
	}
};
#pragma endregion

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
		movement.move();
	}
	else if (hero == 'n')
	{
		cout << "Oh... Ok..." << endl;
		exit(0);
	}
}
