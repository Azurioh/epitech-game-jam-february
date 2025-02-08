/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** BlackMob
*/

#include "BlackMob.hpp"

BlackMob::BlackMob()
{
    _texture = LoadTexture("asset/bloons/black.png");
    _widthScale = 0.8;
    _heightScale = 0.8;
    _rotation = 0;

    _speed = 3.2 - (2);
    _mapValue = 2;

    _mapPos = {-1, -1};
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;

    _visible = true;
    _stopMoving = false;

    _type = Game::Mob::BLACK_MOB;
}

BlackMob::~BlackMob()
{
    UnloadTexture(_texture);
}
