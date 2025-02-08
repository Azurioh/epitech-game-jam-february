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
    _mapPos = {-1, -1};
    _mapValue = 2;
    _visible = true;
}

YellowMob::~YellowMob()
{
    UnloadTexture(_texture);
}

void YellowMob::move_mob(Map &map)
{
    if (!_visible) {
        return;
    }

    std::vector<std::vector<std::shared_ptr<Case>>> mapVector = map.getMap();

    if (_mapPos.x == -1 && _mapPos.y == -1) {
        std::tuple<char, char> start = map.getStart();

        _mapPos = {
            (float)std::get<0>(start),
            (float)std::get<1>(start),
        };
        _offset = map.findPath(_mapPos.x, _mapPos.y, 2);
    }

    Vector2 position = mapVector[_mapPos.x][_mapPos.y]->getPosition();

    drawMob(position);

    _offset = map.getNextCase(_mapPos, std::get<0>(_offset), std::get<1>(_offset), _mapValue);
    if (std::get<0>(_offset) == -1 && std::get<1>(_offset) == -1) {
        _visible = false;
        return;
    }
    _mapValue += 1;
    _mapPos = {
        _mapPos.x + std::get<0>(_offset),
        _mapPos.y + std::get<1>(_offset)
    };
}