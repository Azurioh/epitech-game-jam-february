/*
** EPITECH PROJECT, 2025
** SettingsScene
** File description:
** SettingsScene
*/

#include "SettingsScene.hh"
#include <raylib.h>
#include <iostream>

Game::SettingsScene::SettingsScene():
    _returnButton("Go back", "asset/menu/button_background.png", GetScreenWidth() / 2. - 100, GetScreenHeight() / 2. - 200, 30),
    _volumeUp("Volume Up", "asset/menu/button_background.png", GetScreenWidth() / 2. - 100, GetScreenHeight() / 2. - 100, 30),
    _volumeDown("Volume Down", "asset/menu/button_background.png", GetScreenWidth() / 2. - 100, GetScreenHeight() / 2., 30),
    _background(LoadTextureFromImage(LoadImage("asset/menu/Menu_background.png"))),
    _font(LoadFont("asset/fonts/Super_Pancake.ttf"))
{
}

Game::SettingsScene::~SettingsScene()
{
    UnloadTexture(_background);
}

void Game::SettingsScene::exec(std::size_t &currentScene, int &playingMusic,  ...)
{
    (void)playingMusic;
    va_list args;
    va_start(args, currentScene);

    _returnButton.Event();
    _volumeDown.Event();
    _volumeUp.Event();
    if (_returnButton.isPressed()){
        currentScene = MAIN_MENU;
        va_end(args);
        return;
    }
    if (_volumeUp.isPressed()){
        float *volume = va_arg(args, float *);
        if (*volume >= 1){
            *volume = 1;
            va_end(args);
            return;
        }
        *volume += 0.1;
        va_end(args);
        return;
    }
    if (_volumeDown.isPressed()){
        float *volume = va_arg(args, float *);
        if (*volume <= 0){
            *volume = 0;
            va_end(args);
            return;
        }
        *volume -= 0.1;
        va_end(args);
        return;
    }
    return;
}

void Game::SettingsScene::display()
{
    DrawTexturePro(this->_background, {0, 0, (float)this->_background.width, (float)this->_background.height},
    {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
    {0, 0}, 0.0f, WHITE);
    this->_returnButton.Display();
    this->_volumeDown.Display();
    this->_volumeUp.Display();
    DrawTextEx(_font, "Settings", {((float)GetScreenWidth() / 2) - MeasureText("Settings", 30) / 2, 100}, 30, 0, BLACK);
}
