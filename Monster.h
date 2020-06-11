#pragma once
#include "Creature.h"
#include <array>
#include <string_view>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
	
	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}



class Monster :public Creature
{
public:
	enum  Type
	{
		DRAGON,
		ORG,
		SLIME,
		MAX_TYPES
	};
	
private:
	struct MonsterData
	{
		string_view name;
		char symbol;
		int health;
		int damage;
		int gold;
	};
	static constexpr array<MonsterData, Monster::MAX_TYPES>
		monsterData{
			{{"dragon",'D',20,4,100},
			 {"orc",'o',4,2,25},
			 {"slime",'s',1,1,10}}
	};

public:
	Monster(Type type)
		:Creature{
			monsterData[type].name.data(),
			monsterData[type].symbol,
			monsterData[type].health,
			monsterData[type].damage,
			monsterData[type].gold
	}
	{
	}
	static Monster getRandomMonster()
	{
		int num{ getRandomNumber(0,MAX_TYPES - 1) };
		return Monster{ static_cast<Type>(num) };
	}
};
