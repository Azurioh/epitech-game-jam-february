/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Arrow
*/

#pragma once

#include "../AProjectile.hh"

namespace Game {
    namespace Projectile {
        class Arrow : public AProjectile {
            public:
                Arrow(std::tuple<unsigned int, unsigned int> position, std::tuple<unsigned int, unsigned int> targetPosition, float speed);
                ~Arrow();
        };
    }
}
