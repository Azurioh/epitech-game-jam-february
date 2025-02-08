/*
** EPITECH PROJECT, 2025
** JAM
** File description:
** JAM
*/

#include "JAM.hpp"
#include "Scenes/SceneFactory.hh"

JAM::JAM(): _currentScene(MAIN_MENU)
{
    InitWindow(1920, 1080, "Bloons Illusion Tower Defense 7+ Premium Deluxe Definitive Edition Collector Reloaded");
    SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);
    SetTargetFPS(60);
    _scenes.push_back(Game::SceneFactory::createMainMenu());
    _scenes.push_back(Game::SceneFactory::createLevels());
    _scenes.push_back(Game::SceneFactory::SettingsScene());
    gameLoop();
}

JAM::~JAM()
{
    CloseWindow();
}

void JAM::gameLoop()
{
    while (!WindowShouldClose()) {
        _scenes[_currentScene]->exec(_currentScene);
        BeginDrawing();
        _scenes[_currentScene]->display();
        EndDrawing();
    }
}
