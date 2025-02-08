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

void Game::Mob::AMob::drawMob(void) const
{
    float posX = std::get<0>(_position);
	float posY = std::get<1>(_position);
	DrawTexturePro(_mobTexture, {0, 0,
		(float)_mobTexture.width, (float)_mobTexture.height},
		{posX, posY, 100, 100},
        {0, 0}, _speed, WHITE);
}

std::tuple<int, int> Game::Mob::AMob::getPosition(void) const
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
