/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** MoabBlue
*/

#include "MoabBlueMob.hpp"

MoabBlueMob::MoabBlueMob()
{
    _texture = LoadTexture("asset/bloons/MOAB_blue.png");
    _widthScale = 0.8;
    _heightScale = 0.8;
    _rotation = 0;

    _speed = 3.2 - (3);
    _mapValue = 2;

    _mapPos = {-1, -1};
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;

    _visible = true;
    _stopMoving = false;

    _hp = 5000;
    _type = Game::Mob::MOAB_BLUE_MOB;
}

MoabBlueMob::~MoabBlueMob()
{
    UnloadTexture(_texture);
}
