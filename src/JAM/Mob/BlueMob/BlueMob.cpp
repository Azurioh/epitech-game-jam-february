/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** BlueMob
*/

#include "BlueMob.hpp"

BlueMob::BlueMob()
{
    _texture = LoadTexture("asset/bloons/blue.png");
    load();
}

BlueMob::~BlueMob()
{
    UnloadTexture(_texture);
}

void BlueMob::load()
{
    _widthScale = 1.1132 * 0.7;
    _heightScale = 1.1176 * 0.7;
    _rotation = 0;

    _speed = 3.2 - (2.6);
    _mapValue = 2;

    _mapPos = {-1, -1};
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;

    _visible = true;
    _stopMoving = false;

    _hp = 2;
    _type = Game::Mob::BLUE_MOB;
}
