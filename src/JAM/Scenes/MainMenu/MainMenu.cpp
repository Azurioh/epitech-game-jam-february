/*
** EPITECH PROJECT, 2025
** JAM
** File description:
** MainMenu
*/

#include "MainMenu.hpp"

Game::MainMenu::MainMenu():
    REF_WIDTH(1920.0f), REF_HEIGHT(1080.0f),
    _start("Start", "asset/menu/button_background.png", ((float)GetScreenWidth() / 2), ((float)GetScreenHeight() / 2) - 100, 20),
    _settings("Settings", "asset/menu/button_background.png", ((float)GetScreenWidth() / 2), ((float)GetScreenHeight() / 2) - 50, 20),
    _musicSelection("Music Selection", "asset/menu/button_background.png", ((float)GetScreenWidth() / 2), ((float)GetScreenHeight() / 2), 20),
    _quit("Quit", "asset/menu/button_background.png", ((float)GetScreenWidth() / 2), ((float)GetScreenHeight() / 2) + 50, 20)
{
    Image backgroundImg = LoadImage("asset/menu/Menu_background.png");
    _background = LoadTextureFromImage(backgroundImg);
    Image logoImg = LoadImage("asset/menu/Logo.png");
    _logo = LoadTextureFromImage(logoImg);
    _font = LoadFont("asset/fonts/Super_Pancake.ttf");
}

Game::MainMenu::~MainMenu()
{
    UnloadTexture(_background);
    UnloadFont(_font);
}

void Game::MainMenu::exec(std::size_t &currentScene, int &playingMusic, ...)
{
    (void)playingMusic;
    _start.Event();
    _settings.Event();
    _musicSelection.Event();
    _quit.Event();
    if (IsWindowResized()) {
        float scaleY = GetScreenHeight() / REF_HEIGHT;
        float spacing = _start.GetSize().height + 50 * scaleY;

        _start.SetPosition((float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 - 100 * scaleY, 0);
        _settings.SetPosition((float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 - 100 * scaleY + spacing, 0);
        _musicSelection.SetPosition((float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 - 100 * scaleY + 2 * spacing, 0);
        _quit.SetPosition((float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 - 100 * scaleY + 3 * spacing, 0);
    }
    if (_start.isPressed()) {
        currentScene = LEVELS_SCENE;
        return;
    }
    if (_settings.isPressed()) {
        currentScene = SETTINGS_SCENE;
        return;
    }
    if (_musicSelection.isPressed()) {
        currentScene = MUSIC_SELECTION;
        return;
    }
    if (_quit.isPressed()) {
        CloseWindow();
        exit(0);
    }
}

void Game::MainMenu::display()
{
    float scaleX = GetScreenWidth() / REF_WIDTH;
    float scaleY = GetScreenHeight() / REF_HEIGHT;
    float titleFontSize = 30 * scaleX;
    float subtitleFontSize = 25 * scaleX;

    DrawTexturePro(_background,
        {0, 0, (float)_background.width, (float)_background.height},
        {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
        {0, 0}, 0.0f, WHITE);
    DrawTexturePro(_logo,
        {0, 0, (float)_logo.width, (float)_logo.height},
        {scaleX * 50, scaleY * 20, scaleX * 250, scaleY * 250},
        {0, 0}, 0.0f, WHITE);
    DrawTextEx(_font, "Bloons Illusion Tower Defense 7+",
        {((float)GetScreenWidth() / 2) - MeasureText("Bloons Illusion Tower Defense 7+", titleFontSize) / 2, scaleY * 100},
        titleFontSize, 0, BLACK);
    DrawTextEx(_font, "Premium Deluxe Definitive Edition Collector Reloaded",
        {((float)GetScreenWidth() / 2) - MeasureText("Premium Deluxe Definitive Edition Collector Reloaded", subtitleFontSize) / 2, scaleY * 130},
        subtitleFontSize, 0, BLACK);
    _start.Display();
    _settings.Display();
    _musicSelection.Display();
    _quit.Display();
}
