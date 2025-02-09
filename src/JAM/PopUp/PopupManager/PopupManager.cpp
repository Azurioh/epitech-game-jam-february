/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** PopupManager
*/

#include "PopupManager.hpp"
#include "raylib.h"

Game::PopupManager::PopupManager() : _showPopup(false) {}

Game::PopupManager::~PopupManager() {}

void Game::PopupManager::handleEvent()
{
    if (IsKeyPressed(KEY_T)) {
        _showPopup = !_showPopup;
    }
}

void Game::PopupManager::draw()
{
    if (_showPopup) {
        _popup.draw();
    }
}
