/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** AProjectile
*/

#pragma once

#include <tuple>
#include <cmath>
#include <raylib.h>
#include "IProjectile.hh"

namespace Game {
    namespace Projectile {
        class AProjectile : public IProjectile {
            public:
                AProjectile(std::tuple<unsigned int, unsigned int> position, std::tuple<unsigned int, unsigned int> targetPosition, float speed);
                virtual ~AProjectile() = default;

                void move();
                void draw(void) const;

                std::tuple<unsigned int, unsigned int> getTargetPosition(void) const;
                std::tuple<unsigned int, unsigned int> getPosition(void) const;
                float getAngle(void) const;
                float getSpeed(void) const;
                AttackResultType getAttackStatus(void) const;

                void setTargetPosition(std::tuple<unsigned int, unsigned int> position);
                void setPosition(std::tuple<unsigned int, unsigned int> position);
                void setAngle(float angle);
                void setSpeed(float speed);

            protected:
                std::tuple<unsigned int, unsigned int> _position;
                std::tuple<unsigned int, unsigned int> _targetPosition;
                float _angle;
                float _speed;
                AttackResultType _attackStatus;
                Texture2D _arrowTexture;

                float _calculAngle() const;
        };
    }
}
