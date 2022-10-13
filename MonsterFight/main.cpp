#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Creature.h"
#include "Monster.h"
#include "Player.h"


bool isEscape()
{
    // 50% to fleeing successfully
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return ( 1 + static_cast<int>((2 - 1 + 1) * (std::rand() * fraction)) == 1 );
}

// handles the monster attacking the player
void attackPlayer(Monster& monster, Player& player)
{
    if (monster.isDead())
        return;

    std::cout << "The " << monster.getName() << " hit you for " << monster.getDamagePerAttack() << " damage.\n";
    player.reduceHealth(monster.getDamagePerAttack());

    if (player.isDead())
    {
        std::cout << "You died at level " << player.getLevel() << " with " << player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }
}

// handles the player attacking the monster
void attackMonster(Player& player, Monster& monster)
{
    if (player.isDead())
        return;

    std::cout << "You hit the " << monster.getName() << " for " << player.getDamagePerAttack() << " damage.\n";
    monster.reduceHealth(player.getDamagePerAttack());

    if (monster.isDead())
    {
        std::cout << "You killed the " << monster.getName() << '\n';
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << '\n';
        player.addGold(monster.getGold());
        std::cout << "You found " << monster.getGold() << " gold\n";
    }
}

// hadles the fight beetween the Player and a single Monster
void fightMonster(Player& player)
{
    Monster monster{ Monster::getRandomMonster() };
    std::cout << "You have encountered a " << monster.getName() << "(" << monster.getSymbol() << ")\n";

    while ( !player.isDead() && !monster.isDead() )
    {
        std::cout << "(R)un or (F)ight: ";
        char action{};
        std::cin >> action;

        if ( action == 'R' or action == 'r')
        {
            if ( isEscape() )
            {
                std::cout << "You successfully fled.\n";
                return;
            }
            else
            {
                std::cout << "You failed to flee\n";
                attackPlayer(monster, player);
                continue;
            }
        }
        else if (action == 'F' or action == 'f')
        {
            attackMonster(player, monster);
            attackPlayer(monster, player);
        }
    }
}


int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // get rid of first result

	std::cout << "Enter your name: ";
    std::string pName{};
    std::cin >> pName;
    Player player{ pName };
    std::cout << "Welcome, " << player.getName() << ".\n";
    std::cout << "You have " << player.getHealth() << " health and are carrying " << player.getGold() << " gold.\n";

	while ( !player.isDead() && !player.hasWon() )
        fightMonster(player);

    if ( player.hasWon() )
        std::cout << "You won the game with " << player.getGold() << " gold.\n";


    return 0;
}
