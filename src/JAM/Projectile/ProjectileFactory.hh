/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** ProjectileFactory
*/

#pragma once

#include <memory>
#include "IProjectile.hh"

namespace Game {
    namespace Projectile {
        class ProjectileFactory {
            public:
                ProjectileFactory();
                ~ProjectileFactory();

                static std::unique_ptr<Game::Projectile::IProjectile> createArrow(std::tuple<unsigned int, unsigned int> position, std::tuple<unsigned int, unsigned int> targetPosition, float speed);
        };
    }
}
