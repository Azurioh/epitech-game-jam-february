/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** CloseRangeTower
*/

#ifndef CLOSERANGETOWER_HH_
#define CLOSERANGETOWER_HH_

#include "../ATower.hh"


namespace Game {
    namespace Tower {
        class CloseRangeTower : public ATower {
            public:
                CloseRangeTower(std::tuple<std::size_t, std::size_t> position);
                ~CloseRangeTower();

                std::unique_ptr<Game::Projectile::IProjectile> createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed);

        };
    }
}

#endif /* !CLOSERANGETOWER_HH_ */
