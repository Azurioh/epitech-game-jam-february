/*
** EPITECH PROJECT, 2025
** music selection
** File description:
** MusicSelection
*/

#include "MusicSelection.hh"

Game::MusicSelection::MusicSelection():
    _background(LoadTextureFromImage(LoadImage("asset/menu/Menu_background.png"))),
    _font(LoadFont("asset/fonts/Super_Pancake.ttf")),
    _returnButton("Go back", "asset/menu/button_background.png", (GetScreenWidth() / 2. - 125), (GetScreenHeight() / 2.) - 200, 20),
    _previousMusic("<<", "asset/menu/button_background.png", (GetScreenWidth() / 2. - 125), (GetScreenHeight() / 2.) - 100, 20),
    _nextMusic(">>", "asset/menu/button_background.png", (GetScreenWidth() / 2. - 125), (GetScreenHeight() / 2.) + 100, 20),
    _pauseMusic("Play/ Pause", "asset/menu/button_background.png", (GetScreenWidth() / 2. - 125), (GetScreenHeight() / 2.), 20)
{
}

Game::MusicSelection::~MusicSelection()
{
    UnloadTexture(_background);
    UnloadFont(_font);
}

void Game::MusicSelection::exec(std::size_t &currentScene, int &playingmusic, ...)
{
    _returnButton.Event();
    _previousMusic.Event();
    _pauseMusic.Event();
    _nextMusic.Event();
    if (_returnButton.isPressed()){
        currentScene = MAIN_MENU;
        return;
    }
    if (_nextMusic.isPressed()){
        playingmusic++;
        return;
    }
    if (_previousMusic.isPressed()){
        playingmusic--;
        return;
    }
    if (_pauseMusic.isPressed()){
        playingmusic = -100;
        return;
    }
}

void Game::MusicSelection::display()
{
    DrawTexturePro(_background, {0, 0, (float)_background.width, (float)_background.height},
        {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
        {0, 0}, 0.0f, WHITE);
    _returnButton.Display();
    _previousMusic.Display();
    _pauseMusic.Display();
    _nextMusic.Display();
    DrawTextEx(_font, "Music Selection", {((float)GetScreenWidth() / 2) - MeasureText("Music Selection", 30) / 2, 100}, 30, 0, BLACK);
}
