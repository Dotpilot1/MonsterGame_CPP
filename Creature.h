#pragma once
#include <iostream>
#include <string>

using namespace std;

class Creature
{
public:
	Creature();
	Creature(string&);

	Creature(const string&, const char, int, int, int);
	
	Creature(const Creature&);

	string getName()const;
	char getSymbol()const;
	int getHealth()const;
	int getDamage()const;
	int getGold() const;


	void reduceHealth(int);
	bool isDead();
	void addGold(int);

protected:
	string c_name;
	char c_symbol;
	int c_health;
	int c_damage;
	int c_gold;
};