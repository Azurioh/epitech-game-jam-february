/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** SceneFactory
*/

#pragma once

    #include <memory>
    #include "MainMenu/MainMenu.hpp"
    #include "levels/LevelsMenu.hpp"

namespace Game {
    class SceneFactory {
        public:
            SceneFactory();
            ~SceneFactory();
            static std::unique_ptr<Game::IScene>createMainMenu();
            static std::unique_ptr<Game::IScene>createLevels();
    };
}
