#include "Monster.h"

Monster::Monster(const Type type)
    : Creature{ getDefaultCreature(type) }
{
}
