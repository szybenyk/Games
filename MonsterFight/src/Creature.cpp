#include "Creature.h"

Creature::Creature(const std::string& name, char symbol, int health, int damagePerAttack, int gold)
    : m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damagePerAttack{ damagePerAttack }, m_gold{ gold }
{
}

const std::string& Creature::getName() const
{
    return m_name;
}

char Creature::getSymbol() const
{
    return m_symbol;
}

int Creature::getHealth() const
{
    return m_health;
}

int Creature::getDamagePerAttaack() const
{
    return m_damagePerAttack;
}

int Creature::getGold() const
{
    return m_gold;
}

void Creature::reduceHealth(int amount)
{
    m_health -= amount;
}

bool Creature::isDead()
{
    return ( m_health <= 0 );
}

void Creature::addGold(int amount)
{
    m_gold += amount;
}
