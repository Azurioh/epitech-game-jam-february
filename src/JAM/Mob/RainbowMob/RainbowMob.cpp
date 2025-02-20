/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** RainbowMob
*/

#include "RainbowMob.hpp"

RainbowMob::RainbowMob()
{
    _texture = LoadTexture("asset/bloons/rainbow.png");
    load();
}

RainbowMob::~RainbowMob()
{
    UnloadTexture(_texture);
}

void RainbowMob::load()
{
    _widthScale = 0.9365 * 0.7;
    _heightScale = 0.95 * 0.7;
    _rotation = 0;

    _speed = 3.2 - (2.6);
    _mapValue = 2;

    _mapPos = {-1, -1};
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;

    _visible = true;
    _stopMoving = false;

    _hp = 47;
    _type = Game::Mob::RAINBOW_MOB;
}
