#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

#include <string>


class Player : public Creature
{
    public:
        Player(const std::string& m_name, char m_symbol='@', int m_health=10, int m_damagePerAttack=1, int m_gold=0, int level=1);

        int getLevel() const;
        void levelUp();
        bool hasWon();

    private:
        int m_level{};
};

#endif // PLAYER_H
