/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** IProjectile
*/

#pragma once

#include <tuple>

namespace Game {
    namespace Projectile {
        class IProjectile {
            public:
                virtual void move(std::tuple<unsigned int, unsigned int> const direction) = 0;
                virtual void draw(void) const = 0;
        };
    }
}

