/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** TowerFactory
*/

#pragma once

#include <memory>
#include "ITower.hh"
#include "CloseRangeTower/CloseRangeTower.hh"
#include "DamageTower/DamageTower.hh"
#include "LongRangeTower/LongRangeTower.hh"
#include "FakeTower/FakeTower.hh"

namespace Game {
    namespace Tower {
        class TowerFactory {
            public:
                TowerFactory();
                ~TowerFactory();

                static std::unique_ptr<ITower> createBasicTower(std::tuple<std::size_t, std::size_t> pos);
                static std::unique_ptr<ITower> createLongRangeTower(std::tuple<std::size_t, std::size_t> pos);
                static std::unique_ptr<ITower> createCloseRangeTower(std::tuple<std::size_t, std::size_t> pos);
                static std::unique_ptr<ITower> createDamageTower(std::tuple<std::size_t, std::size_t> pos);
                static std::unique_ptr<ITower> createFakeTower(std::tuple<std::size_t, std::size_t> pos);
        };
    }
}
