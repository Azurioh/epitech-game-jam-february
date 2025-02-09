/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** SceneFactory
*/

#include "SceneFactory.hh"
#include "LevelsScenes/LevelScene.hpp"
#include "SettingsScene/SettingsScene.hh"

Game::SceneFactory::SceneFactory()
{
}

Game::SceneFactory::~SceneFactory()
{
}

std::unique_ptr<Game::IScene> Game::SceneFactory::createMainMenu()
{
    return std::unique_ptr<Game::MainMenu>(new Game::MainMenu);
}

std::unique_ptr<Game::IScene> Game::SceneFactory::SettingsScene()
{
    return std::unique_ptr<Game::SettingsScene>(new Game::SettingsScene);
}

std::unique_ptr<Game::IScene> Game::SceneFactory::createLevels()
{
    return std::unique_ptr<Game::LevelsPage>(new Game::LevelsPage);
}

std::unique_ptr<Game::IScene> Game::SceneFactory::createLevelScene(int levelNumber)
{
    return std::make_unique<Game::LevelScene>(levelNumber);
}

std::unique_ptr<Game::IScene> Game::SceneFactory::createGameScene(int levelNumber)
{
    return std::unique_ptr<Game::GameScene>(new Game::GameScene(levelNumber));
}
