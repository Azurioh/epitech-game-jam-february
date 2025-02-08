/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** SceneFactory
*/

#include "SceneFactory.hh"

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