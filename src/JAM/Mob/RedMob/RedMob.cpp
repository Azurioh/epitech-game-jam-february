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
    _widthScale = 1.2041 * 0.7;
    _heightScale = 1.2063 * 0.7;
    _rotation = 0;

    _speed = 3.2 - (3);
    _mapValue = 2;

    _mapPos = {-1, -1};
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;

    _visible = true;
    _stopMoving = false;

    _type = Game::Mob::RED_MOB;
}

RedMob::~RedMob()
{
    UnloadTexture(_texture);
}
