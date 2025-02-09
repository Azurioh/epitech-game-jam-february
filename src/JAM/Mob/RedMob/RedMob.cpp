/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** RedMob
*/

#include "RedMob.hpp"

RedMob::RedMob()
{
    _texture = LoadTexture("asset/bloons/red.png");
    load();
}

RedMob::~RedMob()
{
    UnloadTexture(_texture);
}

void RedMob::load()
{
    _widthScale = 1.2041 * 0.7;
    _heightScale = 1.2063 * 0.7;
    _rotation = 0;

    _speed = 3.2 - (2.9);
    _mapValue = 2;

    _mapPos = {-1, -1};
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;

    _visible = true;
    _stopMoving = false;

    _type = Game::Mob::RED_MOB;
}
