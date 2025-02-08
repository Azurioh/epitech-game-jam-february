/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** AMob
*/

#include "AMob.hpp"

Game::Mob::AMob::AMob(int hp, int gold): _hp(hp), _gold(gold), _visible(true), _stopMoving(false)
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
    _hp -= hp;
    if (_hp <= 0) {
        _stopMoving = true;
        _visible = false;
    }
}

void Game::Mob::AMob::drawMob() const
{
    DrawTexturePro(
		_texture,
		(Rectangle) {0, 0, (float)_texture.width, (float)_texture.height},
		(Rectangle) {_position.x, _position.y, (float)_texture.width * _widthScale, (float)_texture.height * _heightScale},
		(Vector2) {((float)_texture.width * _widthScale) / 2, ((float)_texture.height * _heightScale) / 2},
		_rotation, WHITE
	);
}

bool Game::Mob::AMob::isVisible() const
{
    return _visible;
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

void Game::Mob::AMob::handleRotation(std::tuple<char, char> offset)
{
    char offsetY = std::get<0>(offset);
    char offsetX = std::get<1>(offset);

    if (offsetY == -1 && offsetX == 0) {
        _rotation = 270;
    }
    if (offsetY == 0 && offsetX == -1) {
        _rotation = 180;
    }
    if (offsetY == 1 && offsetX == 0) {
        _rotation = 90;
    }
    if (offsetY == 0 && offsetX == 1) {
        _rotation = 0;
    }
}

void Game::Mob::AMob::initMobMovement(Map &map)
{
    std::vector<std::vector<std::shared_ptr<Case>>> mapVector = map.getMap();
    std::tuple<char, char> start = map.getStart();

    _mapPos = {
        (float)std::get<0>(start),
        (float)std::get<1>(start),
    };
    _offset = map.findPath(_mapPos.x, _mapPos.y, 2);
    _position = mapVector[_mapPos.x][_mapPos.y]->getPosition();

    _offset = map.getNextCase(_mapPos, std::get<0>(_offset), std::get<1>(_offset), _mapValue);
    if (std::get<0>(_offset) == -1 && std::get<1>(_offset) == -1) {
        _visible = false;
        return;
    }
    _mapValue += 1;
    _nextPosition = mapVector[_mapPos.x + std::get<0>(_offset)][_mapPos.y + std::get<1>(_offset)]->getPosition();
}

void Game::Mob::AMob::moveMob(Map &map)
{
    if (!_visible) {
        return;
    }

    std::vector<std::vector<std::shared_ptr<Case>>> mapVector = map.getMap();

    if (_mapPos.x == -1 && _mapPos.y == -1) {
        initMobMovement(map);
    }
    if (_nextPosition.x == -1 && _nextPosition.y == -1) {
        map.addMobPassed();
        _visible = false;
        return;
    }

    Vector2 direction = { _nextPosition.x - _position.x, _nextPosition.y - _position.y };

    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    if (_type == MOAB_RED_MOB || _type == MOAB_BLUE_MOB) {
        handleRotation(_offset);
    }
    drawMob();

    if (_time + 0.005 > GetTime() || _stopMoving) {
        return;
    }
    _time = GetTime();
    if (distance > 2) {
        direction.x /= distance;
        direction.y /= distance;

        _position.x += direction.x * _speed;
        _position.y += direction.y * _speed;
        return;
    }

    _offset = map.getNextCase(_mapPos, std::get<0>(_offset), std::get<1>(_offset), _mapValue);
    if (std::get<0>(_offset) == -1 && std::get<1>(_offset) == -1) {
        map.addMobPassed();
        _visible = false;
        return;
    }
    _nextPosition = mapVector[_mapPos.x + std::get<0>(_offset)][_mapPos.y + std::get<1>(_offset)]->getPosition();
    _mapValue += 1;
    _mapPos = {
        _mapPos.x + std::get<0>(_offset),
        _mapPos.y + std::get<1>(_offset)
    };
}
