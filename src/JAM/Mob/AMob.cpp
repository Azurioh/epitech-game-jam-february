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

int Game::Mob::AMob::takeDamage(int hp)
{
    return _hp -= hp;
}

void Game::Mob::AMob::moveMob(Map &map)
{
    std::vector<std::vector<std::shared_ptr<Case>>> mapVector = map.getMap();
    std::tuple<char, char> start = map.getStart();

    Vector2 position = mapVector[std::get<0>(start)][std::get<1>(start)]->getPosition();

	DrawTexturePro(
		_texture,
		(Rectangle) {0, 0, (float)_texture.width, (float)_texture.height},
		(Rectangle) {position.x, position.y, (float)_texture.width, (float)_texture.height},
		(Vector2) {(float)_texture.width / 2, (float)_texture.height / 2},
		0, WHITE
	);
}

void Game::Mob::AMob::drawMob(Vector2 position) const
{
    DrawTexturePro(
		_texture,
		(Rectangle) {0, 0, (float)_texture.width, (float)_texture.height},
		(Rectangle) {position.x, position.y, (float)_texture.width * scale, (float)_texture.height * scale},
		(Vector2) {((float)_texture.width * scale) / 2, ((float)_texture.height * scale) / 2},
		0, WHITE
	);
}

Vector2 Game::Mob::AMob::getPosition(void) const
{
    return _position;
}

int Game::Mob::AMob::getGold(void) const
{
    return _gold;
}

void Game::Mob::AMob::setPosition(Vector2 pos)
{
    _position = pos;
}

void Game::Mob::AMob::setGold(int gold)
{
    _gold = gold;
}
