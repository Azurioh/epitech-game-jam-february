/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** GreenMob
*/

#include "GreenMob.hpp"

GreenMob::GreenMob()
{
    _texture = LoadTexture("asset/bloons/green.png");
    load();
}

GreenMob::~GreenMob()
{
    UnloadTexture(_texture);
}

void GreenMob::load()
{
    _widthScale = 1.0351 * 0.7;
    _heightScale = 1.0556 * 0.7;
    _rotation = 0;

    _speed = 3.2 - (2.6);
    _mapValue = 2;

    _mapPos = {-1, -1};
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;

    _visible = true;
    _stopMoving = false;

    _hp = 1;
    _type = Game::Mob::GREEN_MOB;
}
