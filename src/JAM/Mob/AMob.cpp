/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** AMob
*/

#include "AMob.hpp"

void AMob::setHp(int hp)
{
    _hp = hp;
}

int AMob::getHp()
{
    return _hp;
}

int AMob::getSpeed()
{
    return _speed;
}

void AMob::setSpeed(int speed)
{
    _speed = speed;
}

void AMob::setPos(int pos_x, int pos_y)
{
    _pos_x = pos_x;
    _pos_y = pos_y;
}

int AMob::takeDamage(int hp)
{
    return _hp -= hp;
}