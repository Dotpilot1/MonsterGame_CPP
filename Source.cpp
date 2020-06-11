#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>

using namespace std;
void attackMonster(Player& p, Monster& m) {

    if (p.isDead())
        return;

    cout << "You hit the" << m.getName() << "for"
        << p.getDamage() << " damage. \n";

    m.reduceHealth(p.getDamage());

    if (m.isDead())
    {
        cout << "You killed the" << m.getName() << ".\n";
        p.levelUp();
        cout << "You are now level" << p.getLevel() << ".\n";
        cout << "You found" << m.getGold() << "gold.\n";
        p.addGold(m.getGold());
    }
}
void attackPlayer(Monster& m, Player& p)
{
    if (m.isDead())
        return;

    p.reduceHealth(m.getDamage());
    cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}
void fightMonster(Player& p)
{

    Monster m{ Monster::getRandomMonster() };
    cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";


    while (!m.isDead() && !p.isDead())
    {
        cout << "(R)un or (F)ight: ";
        char input;
        cin >> input;
        if (input == 'R' || input == 'r')
        {

            if (getRandomNumber(1, 2) == 1)
            {
                cout << "You successfully fled.\n";
                return;
            }
            else
            {

                cout << "You failed to flee.\n";
                attackPlayer(m, p);
                continue;
            }
        }

        if (input == 'F' || input == 'f')
        {

            attackMonster(p, m);
            attackPlayer(m, p);
        }
    }
}



int main() {

    srand(static_cast<unsigned int>(time(nullptr))); 
    rand(); 

    cout << "Enter your name: ";
    string playerName;
    cin >> playerName;

    Player p{ playerName };
    cout << "Welcome, " << p.getName() << '\n';

   
    while (!p.isDead() && !p.hasWon())
        fightMonster(p);

    
    if (p.isDead())
    {
        cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
        cout << "Too bad you can't take it with you!\n";
    }
    else
    {
        cout << "You won the game with " << p.getGold() << " gold!\n";
    }



	return 0;
}

