#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature
{
    public:
        Creature(const std::string& m_name, char m_symbol, int m_health, int m_damagePerAttack, int m_gold);

        const std::string& getName() const;
        char getSymbol() const;
        int getHealth() const;
        int getDamagePerAttaack() const;
        int getGold() const;

        void reduceHealth(int amount);
        bool isDead();
        void addGold(int amount);


    protected:
        std::string m_name{};
        char m_symbol{};
        int m_health{};
        int m_damagePerAttack{};
        int m_gold{};
};

#endif // CREATURE_H
