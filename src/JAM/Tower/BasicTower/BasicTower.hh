/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** BasicTower
*/

#pragma once

#include "../ATower.hh"

namespace Game {
    namespace Tower {
        class BasicTower : public ATower {
            public:
                BasicTower(std::tuple<std::size_t, std::size_t> position);
                ~BasicTower();

                std::unique_ptr<Game::Projectile::IProjectile> createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed);
        };
    }
}
