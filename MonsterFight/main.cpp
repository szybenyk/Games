#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Creature.h"
#include "Monster.h"
#include "Player.h"


int main()
{
    std::cout << "Enter your name: ";
    std::string pName{};
    std::cin >> pName;
    Player player{ pName };
    std::cout << "Welcome, " << player.getName() << ".\n";
    std::cout << "You have " << player.getHealth() << " health and are carrying " << player.getGold() << " gold.\n";


    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand(); // get rid of first result

    for (int i{ 0 }; i < 10; ++i)
    {
        Monster m{ Monster::getRandomMonster() };
        std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
    }

    return 0;
}
