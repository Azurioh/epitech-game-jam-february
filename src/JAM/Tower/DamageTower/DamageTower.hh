/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** DamageTower
*/

#ifndef DAMAGETOWER_HH_
#define DAMAGETOWER_HH_

#include "../ATower.hh"

namespace Game {
    namespace Tower {
        class DamageTower : public ATower{
            public:
                DamageTower(std::tuple<std::size_t, std::size_t> position);
                ~DamageTower();

                std::unique_ptr<Game::Projectile::IProjectile> createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed);

        };
    }
}

#endif /* !DAMAGETOWER_HH_ */
