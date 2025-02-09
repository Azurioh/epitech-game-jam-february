/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** PinkMob
*/

#include "PinkMob.hpp"

PinkMob::PinkMob()
{
    _texture = LoadTexture("asset/bloons/pink.png");
    load();
}

PinkMob::~PinkMob()
{
    UnloadTexture(_texture);
}

void PinkMob::load()
{
    _widthScale = 0.9365 * 0.7;
    _heightScale = 0.95 * 0.7;
    _rotation = 0;

    _speed = 3.2 - (1.6);
    _mapValue = 2;

    _mapPos = {-1, -1};
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;

    _visible = true;
    _stopMoving = false;

    _hp = 5;
    _type = Game::Mob::PINK_MOB;
}
