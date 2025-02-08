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

int AMob::takeDamage(int hp)
{
    return _hp -= hp;
}

void AMob::moveMob(Map &map)
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

void AMob::drawMob(Vector2 position)
{
    DrawTexturePro(
		_texture,
		(Rectangle) {0, 0, (float)_texture.width, (float)_texture.height},
		(Rectangle) {position.x, position.y, (float)_texture.width * scale, (float)_texture.height * scale},
		(Vector2) {((float)_texture.width * scale) / 2, ((float)_texture.height * scale) / 2},
		0, WHITE
	);
}
