/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** TowerFactory
*/

#pragma once

#include <memory>
#include "ITower.hh"

namespace Game {
    namespace Tower {
        class TowerFactory {
            public:
                TowerFactory();
                ~TowerFactory();

                static std::unique_ptr<ITower> createBasicTower(std::tuple<std::size_t, std::size_t> pos);
        };
    }
}
