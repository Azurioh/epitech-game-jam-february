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
    _returnButton("test button", "asset/menu/button_background.png", GetScreenWidth() / 2. - 150, GetScreenHeight() / 2. - 200, 30),
    _background(LoadTextureFromImage(LoadImage("asset/menu/Menu_background.png")))
{
}

Game::SettingsScene::~SettingsScene()
{
    UnloadTexture(_background);
}

void Game::SettingsScene::exec(std::size_t &currentScene)
{
    _returnButton.Event();
    return;
}

void Game::SettingsScene::display()
{
    DrawTexturePro(this->_background, {0, 0, (float)this->_background.width, (float)this->_background.height},
    {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
    {0, 0}, 0.0f, WHITE);
    this->_returnButton.Display();
}
