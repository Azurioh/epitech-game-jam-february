/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** FakeTower
*/

#ifndef FAKETOWER_HH_
#define FAKETOWER_HH_

#include "../ATower.hh"

namespace Game {
    namespace Tower {
        class FakeTower : public ATower{
            public:
                FakeTower(std::tuple<std::size_t, std::size_t> position);
                ~FakeTower();

                std::unique_ptr<Game::Projectile::IProjectile> createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed);

            protected:
            private:
        };
    }
}

#endif /* !FAKETOWER_HH_ */
