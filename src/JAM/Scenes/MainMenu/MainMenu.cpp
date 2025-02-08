/*
** EPITECH PROJECT, 2025
** JAM
** File description:
** MainMenu
*/

#include "MainMenu.hpp"

Game::MainMenu::MainMenu():
    _start("Start", "asset/menu/button_background.png", ((float)GetScreenWidth() / 2), ((float)GetScreenHeight() / 2) - 100, 20),
    _settings("Settings", "asset/menu/button_background.png", ((float)GetScreenWidth() / 2), ((float)GetScreenHeight() / 2) - 50, 20),
    _quit("Quit", "asset/menu/button_background.png", ((float)GetScreenWidth() / 2), ((float)GetScreenHeight() / 2), 20)
{
    Image backgroundImg = LoadImage("asset/menu/Menu_background.png");
    _background = LoadTextureFromImage(backgroundImg);
    _font = LoadFont("asset/fonts/Super_Pancake.ttf");
}

Game::MainMenu::~MainMenu()
{
    UnloadTexture(_background);
    UnloadFont(_font);
}

void Game::MainMenu::exec(std::size_t &currentScene)
{
    _start.Event();
    _settings.Event();
    _quit.Event();

    if (_start.isPressed()) {
        currentScene = LEVELS_SCENE;
        return;
    }
    if (_settings.isPressed()) {
        currentScene = SETTINGS_SCENE;
        return;
    }
    if (_quit.isPressed()) {
        CloseWindow();
        exit(0);
    }
}

void Game::MainMenu::display()
{
    DrawTexturePro(_background,
        {0, 0, (float)_background.width, (float)_background.height},
        {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
        {0, 0}, 0.0f, WHITE);
    DrawTextEx(_font, "Bloons Illusion Tower Defense 7+", {((float)GetScreenWidth() / 2) - MeasureText("Bloons Illusion Tower Defense 7+", 30) / 2, 100}, 30, 0, BLACK);
    DrawTextEx(_font,"Premium Deluxe Definitive Edition Collector Reloaded", {((float)GetScreenWidth() / 2) - MeasureText("Premium Deluxe Definitive Edition Collector Reloaded", 25) / 2, 130}, 25, 0, BLACK);
    _start.Display();
    _settings.Display();
    _quit.Display();
}
