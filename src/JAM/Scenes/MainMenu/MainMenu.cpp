/*
** EPITECH PROJECT, 2025
** JAM
** File description:
** MainMenu
*/

#include "MainMenu.hpp"

Game::MainMenu::MainMenu()
{
    Image backgroundImg = LoadImage("asset/menu/Menu_background.png");
    _background = LoadTextureFromImage(backgroundImg);
}

Game::MainMenu::~MainMenu()
{
    UnloadTexture(_background);
}

void Game::MainMenu::exec()
{
    return;
}

void Game::MainMenu::display()
{
    DrawTexturePro(_background,
        {0, 0, (float)_background.width, (float)_background.height},
        {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
        {0, 0}, 0.0f, WHITE);
}
