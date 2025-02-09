/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** WhiteMob
*/

#include "WhiteMob.hpp"

WhiteMob::WhiteMob()
{
    _texture = LoadTexture("asset/bloons/white.png");
    load();
}

WhiteMob::~WhiteMob()
{
    UnloadTexture(_texture);
}

void WhiteMob::load()
{
    _widthScale = 1.6389 * 0.7;
    _heightScale = 1.6170 * 0.7;
    _rotation = 0;

    _speed = 3.2 - (2.6);
    _mapValue = 2;

    _mapPos = {-1, -1};
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;

    _visible = true;
    _stopMoving = false;

    _hp = 11;
    _type = Game::Mob::WHITE_MOB;
}
