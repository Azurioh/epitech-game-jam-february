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
        _scenes.push_back(Game::SceneFactory::createLevelScene(i));
    }
    _scenes.push_back(Game::SceneFactory::SettingsScene());
    _scenes.push_back(Game::SceneFactory::createGameScene());
    _scenes.push_back(Game::SceneFactory::MusicSelection());
    _musics.push_back(LoadMusicStream("asset/musics/menuMusic.mp3"));
    _musics.push_back(LoadMusicStream("asset/musics/inGameMusic.mp3"));
    _playingMusic = 0;
    _playingMusicSave = 0;
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
    SetMusicVolume(_musics[_playingMusic], this->_MusicValue);
}

void JAM::setMusic()
{
    if (this->_playingMusic == -100){
        if (IsMusicStreamPlaying(_musics[_playingMusicSave])){
            PauseMusicStream(_musics[_playingMusicSave]);
            _playingMusic = _playingMusicSave;
            return;
        }
        ResumeMusicStream(_musics[_playingMusicSave]);
        _playingMusic = _playingMusicSave;
        return;
    }
    if (this->_playingMusic == this->_playingMusicSave)
        return;
    StopMusicStream(_musics[_playingMusicSave]);
    if (this->_playingMusic < 0)
        this->_playingMusic = (int)_musics.size() - 1;
    if (this->_playingMusic > (int)_musics.size() - 1)
        _playingMusic = 0;
    PlayMusicStream(_musics[_playingMusic]);
    _playingMusicSave = _playingMusic;
    return;
}

void JAM::gameLoop()
{
    PlayMusicStream(_musics[_playingMusic]);
    SetMusicVolume(_musics[_playingMusic], 1.0);
    while (!WindowShouldClose()) {
        UpdateMusicStream(_musics[_playingMusic]);
        _scenes[_currentScene]->exec(_currentScene, this->_playingMusic ,&this->_MusicValue);
        setMusic();
        setVolume();
        ClearBackground(BLACK);
        BeginDrawing();
        _scenes[_currentScene]->display();
        EndDrawing();
    }
}
