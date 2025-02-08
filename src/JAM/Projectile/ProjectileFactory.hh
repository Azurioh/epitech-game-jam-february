/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** ProjectileFactory
*/

#pragma once

#include <memory>
#include "IProjectile.hh"
#include "../Mob/IMob.hh"

namespace Game {
    namespace Projectile {
        class ProjectileFactory {
            public:
                ProjectileFactory();
                ~ProjectileFactory();

                static std::unique_ptr<Game::Projectile::IProjectile> createArrow(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed);
        };
    }
}
