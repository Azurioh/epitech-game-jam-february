/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** AProjectile
*/

#pragma once

#include <tuple>
#include <cmath>
#include "IProjectile.hh"

namespace Game {
    namespace Projectile {
        class AProjectile : public IProjectile {
            public:
                AProjectile(std::tuple<unsigned int, unsigned int> position, std::tuple<unsigned int, unsigned int> targetPosition, float speed);
                virtual ~AProjectile() = default;

                void move(std::tuple<unsigned int, unsigned int> const direction);
                void draw(void) const;

                std::tuple<unsigned int, unsigned int> getTargetPosition(void) const;
                std::tuple<unsigned int, unsigned int> getPosition(void) const;
                float getAngle(void) const;
                float getSpeed(void) const;
                bool isTargetDestroyed(void) const;

                void setTargetPosition(std::tuple<unsigned int, unsigned int> position);
                void setPosition(std::tuple<unsigned int, unsigned int> position);
                void setAngle(float angle);
                void setSpeed(float speed);
                void setTargetDestroyed(bool destroyed);

            protected:
                std::tuple<unsigned int, unsigned int> _position;
                std::tuple<unsigned int, unsigned int> _targetPosition;
                float _angle;
                float _speed;
                bool _targetDestroyed;

                float _calculAngle() const;
        };
    }
}
