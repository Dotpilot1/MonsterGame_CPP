#pragma once
#include "Creature.h"

class Player :public Creature
{
public:
	Player(string&);

	Player(const string&,const char, int, int, int, int);

	void levelUp();

	int getLevel()const;

	bool hasWon();
private:
	int c_level;
};