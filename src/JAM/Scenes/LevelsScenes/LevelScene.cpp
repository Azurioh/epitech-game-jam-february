/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** levels.hpp
*/

#include "LevelScene.hpp"
#include "../SceneFactory.hh"
#include "../../Mob/MobFactory.hh"

Game::LevelScene::LevelScene(int levelNumber)
    : _levelNumber(levelNumber), _backgroundColor(RAYWHITE), _backButtonArea({10, 10, 100, 40})
{
    _map = std::shared_ptr<Map>(new Map("maps/map_" + std::to_string(levelNumber) + ".txt"));
    createMobs();

    _time = GetTime();
    _maxDisplay = 1;
    _wave = 1;
    _numberOfMobs = 8;
}

void Game::LevelScene::display()
{
    ClearBackground(_backgroundColor);

    DrawRectangleRec(_backButtonArea, DARKGRAY);
    DrawText("Retour", _backButtonArea.x + 10, _backButtonArea.y + 10, 20, WHITE);

    DrawText(("Level " + std::to_string(_levelNumber)).c_str(), 500, 300, 40, BLACK);
    _map->drawMap();
    runWave();
}

void Game::LevelScene::exec(std::size_t &currentScene, ...)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(mousePos, _backButtonArea)) {
            currentScene = LEVELS_SCENE;
        }
    }
}

void Game::LevelScene::createMobs()
{
    size_t index = 0;

    _mobs.resize(80);
    for (; index < (8 * 1); index++) {
        _mobs[index] = Game::Mob::MobFactory::createRedMob();
    }
    for (; index < (8 * 2); index++) {
        _mobs[index] = Game::Mob::MobFactory::createBlueMob();
    }
    for (; index < (8 * 3); index++) {
        _mobs[index] = Game::Mob::MobFactory::createGreenMob();
    }
    for (; index < (8 * 4); index++) {
        _mobs[index] = Game::Mob::MobFactory::createYellowMob();
    }
    for (; index < (8 * 5); index++) {
        _mobs[index] = Game::Mob::MobFactory::createPinkMob();
    }
    for (; index < (8 * 6); index++) {
        _mobs[index] = Game::Mob::MobFactory::createWhiteMob();
    }
    for (; index < (8 * 7); index++) {
        _mobs[index] = Game::Mob::MobFactory::createBlackMob();
    }
    for (; index < (8 * 8); index++) {
        _mobs[index] = Game::Mob::MobFactory::createRainbowMob();
    }
    for (; index < (8 * 9); index++) {
        _mobs[index] = Game::Mob::MobFactory::createMoabBlueMob();
    }
    for (; index < (8 * 10); index++) {
        _mobs[index] = Game::Mob::MobFactory::createMoabRedMob();
    }
}

void Game::LevelScene::runWave()
{
    std::shared_ptr<Game::Tower::ITower> tower;

    tower = _map->getMap()[5][23]->getTower();
    tower->getMobToAttack(_mobs);
    for (size_t i = 0; i < _numberOfMobs && i < _maxDisplay; i++) {
        _mobs[i]->moveMob(*_map);
    }
    if (_time + 0.4 < GetTime()) {
        _maxDisplay++;
        _time = GetTime();
    }
    if (isWaveOver() && _wave != 20) {
        reloadWave();
    }
}

bool Game::LevelScene::isWaveOver()
{
    for (size_t i = 0; i < _numberOfMobs; i++) {
        if (_mobs[i]->isVisible()) {
            return false;
        }
    }
    return true;
}

void Game::LevelScene::reloadWave()
{
    for (size_t i = 0; i < _numberOfMobs; i++) {
        _mobs[i]->load();
    }
    _maxDisplay = 0;
    if (_wave % 2 == 0) {
        _numberOfMobs += 8;
    }
    _wave += 1;
}
