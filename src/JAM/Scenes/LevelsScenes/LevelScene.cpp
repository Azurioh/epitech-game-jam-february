/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** levels.hpp
*/

#include "LevelScene.hpp"
#include "../SceneFactory.hh"

Game::LevelScene::LevelScene(int levelNumber)
    : _levelNumber(levelNumber), _backgroundColor(RAYWHITE), _backButtonArea({10, 10, 100, 40})
{
}

void Game::LevelScene::display()
{
    ClearBackground(_backgroundColor);

    DrawRectangleRec(_backButtonArea, DARKGRAY);
    DrawText("Retour", _backButtonArea.x + 10, _backButtonArea.y + 10, 20, WHITE);

    DrawText(("Level " + std::to_string(_levelNumber)).c_str(), 500, 300, 40, BLACK);
}

void Game::LevelScene::exec(std::size_t &currentScene, int &playingMusic, ...)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(mousePos, _backButtonArea)) {
            currentScene = LEVELS_SCENE;
        }
    }
}

