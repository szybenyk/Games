#include "Player.h"

Player::Player(const std::string& name, char symbol, int health, int damagePerAttack, int gold, int level)
    : Creature{name, symbol, health, damagePerAttack, gold}, m_level{ level }
{
}

int Player::getLevel() const
{
    return m_level;
}

void Player::levelUp()
{
    ++m_level;
    ++m_damagePerAttack;
}

bool Player::hasWon()
{
    return ( m_level >= 20 );
}
