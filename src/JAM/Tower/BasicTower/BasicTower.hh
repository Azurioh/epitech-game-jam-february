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
        };
    }
}
