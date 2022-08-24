#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"

#include <array>
#include <random>


class Monster : public Creature
{
    public:
        enum class Type
        {
            dragon,
            orc,
            slime,

            max_types
        };

        Monster(const Type type);


    private:
        static const Creature& getDefaultCreature(Type type)
        {
            static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
            {   { "dragon", 'D', 20, 4, 100 },
                { "orc", 'o', 4, 2, 25 },
                { "slime", 's', 1, 1, 10 }
            }};
            return monsterData.at(static_cast<std::size_t>(type));
        };

        static int getRandomNumber(int min, int max)
        {
            static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; // static used for efficiency, so we only calculate this value once
            // evenly distribute the random number across our range
            return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
        };

};

#endif // MONSTER_H
