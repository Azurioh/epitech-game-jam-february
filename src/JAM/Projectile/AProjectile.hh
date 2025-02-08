/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** AProjectile
*/

#pragma once

#include <tuple>
#include <cmath>
#include <memory>
#include <raylib.h>
#include "IProjectile.hh"
#include "../Mob/IMob.hh"

namespace Game {
    namespace Projectile {
        class AProjectile : public IProjectile {
            public:
                AProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed);
                virtual ~AProjectile() = default;

                void move();
                void draw(void) const;

                std::shared_ptr<Game::Mob::IMob> getTarget(void) const;
                std::tuple<unsigned int, unsigned int> getPosition(void) const;
                float getAngle(void) const;
                float getSpeed(void) const;
                AttackResultType getAttackStatus(void) const;

                void setTarget(std::shared_ptr<Game::Mob::IMob> target);
                void setPosition(std::tuple<unsigned int, unsigned int> position);
                void setAngle(float angle);
                void setSpeed(float speed);

            protected:
                std::tuple<std::size_t, std::size_t> _position;
                std::shared_ptr<Game::Mob::IMob> _target;
                float _angle;
                unsigned int _speed;
                AttackResultType _attackStatus;
                Texture2D _arrowTexture;

                float _calculAngle() const;
        };
    }
}
