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
    InitAudioDevice();
    InitWindow(1920, 1080, "Bloons Illusion Tower Defense 7+ Premium Deluxe Definitive Edition Collector Reloaded");
    SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);
    SetTargetFPS(60);
    _scenes.push_back(Game::SceneFactory::createMainMenu());
    _scenes.push_back(Game::SceneFactory::createLevels());
    for (int i = 1; i <= 9; i++) {
        _scenes.push_back(Game::SceneFactory::createGameScene(i));
    }
    _scenes.push_back(Game::SceneFactory::SettingsScene());
    _menuMusic = LoadMusicStream("asset/musics/menuMusic.mp3");
    _inGameMusic = LoadMusicStream("asset/musics/inGameMusic.mp3");
    _MusicValue = 1.0;
    gameLoop();
}

JAM::~JAM()
{
    CloseWindow();
}

void JAM::setVolumeDown()
{
    if (this->_MusicValue== 0)
        return;
    this->_MusicValue -= 0.1;
    SetMusicVolume(this->_menuMusic, this->_MusicValue);
    SetMusicVolume(this->_inGameMusic, this->_MusicValue);
    return;
}

void JAM::setVolumeUp()
{
    if (this->_MusicValue == 1)
        return;
    this->_MusicValue += 0.1;
    SetMusicVolume(this->_menuMusic, this->_MusicValue);
    SetMusicVolume(this->_inGameMusic, this->_MusicValue);
    return;
}

void JAM::setVolume()
{
    SetMusicVolume(this->_inGameMusic, this->_MusicValue);
}

void JAM::gameLoop()
{
    PlayMusicStream(_inGameMusic);
    SetMusicVolume(_menuMusic, 1.0);
    SetMusicVolume(_inGameMusic, 1.0);
    while (!WindowShouldClose()) {
        UpdateMusicStream(_menuMusic);
        UpdateMusicStream(_inGameMusic);
        _scenes[_currentScene]->exec(_currentScene, &this->_MusicValue);
        setVolume();
        ClearBackground(BLACK);
        BeginDrawing();
        _scenes[_currentScene]->display();
        EndDrawing();
    }
}
