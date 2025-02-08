/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** YellowMob
*/

#include "YellowMob.hpp"

YellowMob::YellowMob()
{
    _texture = LoadTexture("asset/bloons/yellow.png");
    _speed = 3.2 - (3);
    _mapPos = {-1, -1};
    _mapValue = 2;
    _visible = true;
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;
    _stopMoving = false;
}

YellowMob::~YellowMob()
{
    UnloadTexture(_texture);
}

void YellowMob::initMobMovement(Map &map)
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

void YellowMob::moveMobb(Map &map)
{
    if (!_visible) {
        return;
    }

    std::vector<std::vector<std::shared_ptr<Case>>> mapVector = map.getMap();

    if (_mapPos.x == -1 && _mapPos.y == -1) {
        initMobMovement(map);
    }
    if (_nextPosition.x == -1 && _nextPosition.y == -1) {
        _visible = false;
        return;
    }

    Vector2 direction = { _nextPosition.x - _position.x, _nextPosition.y - _position.y };

    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    drawMob(_position);

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