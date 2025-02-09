/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** SceneFactory
*/

#pragma once

    #include <memory>
    #include "MainMenu/MainMenu.hpp"
    #include "Levels/LevelsMenu.hpp"
    #include "GameScene/GameScene.hpp"

namespace Game {
    class SceneFactory {
        public:
            SceneFactory();
            ~SceneFactory();
            static std::unique_ptr<Game::IScene>createMainMenu();
            static std::unique_ptr<Game::IScene>createLevels();
            static std::unique_ptr<Game::IScene>createLevelScene(int levelNumber);
            static std::unique_ptr<Game::IScene>SettingsScene();
            static std::unique_ptr<Game::IScene>createGameScene();
    };
}
