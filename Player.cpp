#include "Player.h"

Player::Player(string& m_name)
	:Creature(m_name,'@',10,1,0)
{
	c_level = 1;
}

Player::Player(const string& m_name,const char m_symbol, int m_health, int m_damage, int m_gold, int m_level=1)
	:Creature(m_name , m_symbol , m_health , m_damage , m_gold )
{
	c_level = m_level;
}

void Player::levelUp() 
{
	c_level += 1;
	c_damage += 1;

}

int Player::getLevel() const
{
	return c_level;
}

bool Player::hasWon() 
{
	return c_level >= 20;
}
