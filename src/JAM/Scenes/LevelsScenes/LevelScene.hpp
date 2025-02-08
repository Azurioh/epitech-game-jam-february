/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** levels.hpp
*/

#ifndef LEVELSCENE_HPP
    #define LEVELSCENE_HPP

#include "../IScene.hh"
#include "raylib.h"
#include "../../Level/Map.hpp"

namespace Game {
    class LevelScene : public IScene {
        public:
            LevelScene(int levelNumber);
            ~LevelScene() = default;

            void display() override;
            void exec(std::size_t &currentScene, ...) override;

        private:
            int _levelNumber;
            Color _backgroundColor;
            Rectangle _backButtonArea;
            std::unique_ptr<Map> _map;
    };
}

#endif // LEVELSCENE_HPP
