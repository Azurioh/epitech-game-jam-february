/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** AMob
*/

#include "AMob.hpp"

Game::Mob::AMob::AMob(int hp, int gold): _hp(hp), _gold(gold)
{
}

void Game::Mob::AMob::setHp(int hp)
{
    _hp = hp;
}

int Game::Mob::AMob::getHp()
{
    return _hp;
}

int Game::Mob::AMob::getSpeed()
{
    return _speed;
}

void Game::Mob::AMob::setSpeed(int speed)
{
    _speed = speed;
}

void Game::Mob::AMob::setPos(int pos_x, int pos_y)
{
    _pos_x = pos_x;
    _pos_y = pos_y;
}

int Game::Mob::AMob::takeDamage(int hp)
{
    return _hp -= hp;
}

std::tuple<int, int> Game::Mob::AMob::getPosition(void)
{
    return std::make_tuple(_pos_x, _pos_y);
}

int Game::Mob::AMob::getGold(void) const
{
    return _gold;
}

void Game::Mob::AMob::setPosition(std::tuple<int, int> pos)
{
    _pos_x = std::get<0>(pos);
    _pos_y = std::get<1>(pos);
}

void Game::Mob::AMob::setGold(int gold)
{
    _gold = gold;
}
