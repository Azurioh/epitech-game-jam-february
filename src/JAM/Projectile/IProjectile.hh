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
                enum AttackResultType {
                    TRACKING,
                    HIT,
                    MISSED
                };

                IProjectile() = default;
                virtual ~IProjectile() = default;
                virtual void move() = 0;
                virtual void draw(void) = 0;
                virtual AttackResultType getAttackStatus(void) const = 0;
        };
    }
}

