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

    Monster m{ Monster::Type::orc };
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

    return 0;
}
