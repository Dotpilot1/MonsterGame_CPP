#include "Creature.h"
#include <stdexcept>

Creature::Creature()
{

}

Creature::Creature(string& m_name)
	:c_name{m_name},c_symbol{'a'},c_health{10},
	c_damage{1},c_gold{0}
{
}

Creature::Creature(const string& m_name, const char m_symbol,
	int m_health, int m_damage, int m_gold)
{
	if ((m_name == "\0") || (m_symbol == '\0') || (m_health == 0)
		|| (m_damage == 0) || (m_gold == 0))
		Creature();
	else {
		c_name = m_name;
		c_symbol = m_symbol;
		c_health = m_health;
		c_damage = m_damage;
		c_gold = m_gold;
	}
}

Creature::Creature(const Creature& o)
{
	c_name = o.c_name;
	c_symbol = o.c_symbol;
	c_health = o.c_health;
	c_damage = o.c_damage;
	c_gold = o.c_gold;
}

string Creature::getName() const
{
	return c_name ;
}

char Creature::getSymbol() const
{
	return c_symbol;
}

int Creature::getHealth() const
{
	return c_health;
}

int Creature::getDamage() const
{
	return c_damage;
}

int Creature::getGold() const
{
	return c_gold;
}

void Creature::reduceHealth(int m_health)
{
	c_health-=m_health;
}

bool Creature::isDead()
{
	return (c_health <= 0);
}

void Creature::addGold(int gold)
{
	c_gold += gold;
}
