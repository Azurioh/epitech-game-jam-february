/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Player
*/

#pragma once

#include <vector>
#include "JAM/Tower/ITower.hh"

namespace Game {
    class Player {
        public:
            Player();
            ~Player();

            unsigned int getHP() const;
            unsigned int getGolds() const;
            std::vector<std::shared_ptr<Game::Tower::ITower>> getTowers() const;

            void setHP(unsigned int hp);
            void setGolds(unsigned int golds);
            void addTower(std::shared_ptr<Game::Tower::ITower> &tower);
            void sellTower(std::shared_ptr<Game::Tower::ITower> &tower);

        private:
            unsigned int _hp;
            unsigned int _golds;
            std::vector<std::shared_ptr<Game::Tower::ITower>> _towers;
    };
}
