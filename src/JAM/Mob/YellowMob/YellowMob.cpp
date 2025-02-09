/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** YellowMob
*/

#include "YellowMob.hpp"

YellowMob::YellowMob()
{
    _texture = LoadTexture("asset/bloons/yellow.png");
    load();
}

YellowMob::~YellowMob()
{
    UnloadTexture(_texture);
}

void YellowMob::load()
{
    _widthScale = 0.7;
    _heightScale = 0.7;
    _rotation = 0;

    _speed = 3.2 - (1.8);
    _mapValue = 2;

    _mapPos = {-1, -1};
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;

    _visible = true;
    _stopMoving = false;

    _type = Game::Mob::YELLOW_MOB;
}
