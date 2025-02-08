/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Arrow
*/

#pragma once

#include <memory>
#include "../AProjectile.hh"

namespace Game {
    namespace Projectile {
        class Arrow : public AProjectile {
            public:
                Arrow(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed);
                ~Arrow();
        };
    }
}
