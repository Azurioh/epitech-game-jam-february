/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** LongRangeTower
*/

#ifndef LONGRANGETOWER_HH_
#define LONGRANGETOWER_HH_

#include "../ATower.hh"


namespace Game {
    namespace Tower {
        class LongRangeTower : public ATower {
            public:
                LongRangeTower(std::tuple<std::size_t, std::size_t> position);
                ~LongRangeTower();

                std::unique_ptr<Game::Projectile::IProjectile> createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed);

        };
    }
}

#endif /* !LONGRANGETOWER_HH_ */
