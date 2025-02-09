/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Map
*/

#include "Map.hpp"
#include "../Tower/ITower.hh"
#include "../Tower/TowerFactory.hh"

Map::Map(std::string filepath)
{
    _map.resize(13);
    for (auto it = _map.begin(); it != _map.end(); it++) {
        (*it).resize(27);
    }
    if (!open(filepath)) {
        throw std::exception();
    }
    _mobPassed = 0;
    createMap();
    scaleHeight = 0.25;
    scaleWidth = 0.25;
}

Map::~Map()
{
}

std::vector<std::vector<std::shared_ptr<Case>>> Map::getMap()
{
    return _map;
}

std::tuple<char, char> Map::getStart()
{
    return _start;
}

bool Map::open(std::string filepath)
{
    std::ifstream stream;

    stream.open(filepath);
    if (!stream) {
        return false;
    }
    _buffer << stream.rdbuf();
    stream.close();
    return true;
}

size_t Map::getMobPassed()
{
	return _mobPassed;
}

void Map::addMobPassed()
{
	_mobPassed += 1;
}

/* Map handling */

std::tuple<char, char> Map::findStart()
{
    for (size_t lines = 0; lines < _map.size(); lines++) {
        for (size_t cols = 0; cols < _map[lines].size(); cols++) {
            if ((*_map[lines][cols]).getValue() == 'S') {
                return std::make_tuple(lines, cols);
            }
        }
    }
    return std::make_tuple(-1, -1);
}

std::tuple<char, char> Map::findPath(size_t y, size_t x, char value)
{
    if (y > 0 && (*_map[y - 1][x]).getValue() == value) { // Check top
        return std::make_tuple(-1, 0);
    }
    if (x > 0 && (*_map[y][x - 1]).getValue() == value) { // Check left
        return std::make_tuple(0, -1);
    }
    if (y + 1 < _map.size() && (*_map[y + 1][x]).getValue() == value) { // Check bottom
        return std::make_tuple(1, 0);
    }
    if (x + 1 < _map[0].size() && (*_map[y][x + 1]).getValue() == value) { // Check right
        return std::make_tuple(0, 1);
    }
    return std::make_tuple(-1, -1);
}

bool Map::isOffsetValid(Vector2 &pos, char offsetY, char offsetX, unsigned char &value, bool change)
{
    if (offsetY == -1 && offsetX == -1) {
        return false;
    }

    Vector2 posTmp = {
        (float)(pos.x + offsetY),
        (float)(pos.y + offsetX)
    };
    if (posTmp.x < 0 || size_t(posTmp.x) >= _map.size() ||
        posTmp.y < 0 || size_t(posTmp.y) >= _map[0].size()) {
        return false;
    }
    if ((*_map[posTmp.x][posTmp.y]).getValue() != value &&
        (*_map[posTmp.x][posTmp.y]).getValue() == '\0') {
        return false;
    }
    if ((*_map[posTmp.x][posTmp.y]).getValue() != value &&
        (*_map[posTmp.x][posTmp.y]).getValue() > 0) {
        if (change) {
            value--;
        }
        pos = posTmp;
        return true;
    }
    return true;
}


void Map::createPath()
{
    Vector2 offset = {(float)std::get<0>(_start), (float)std::get<1>(_start)};
    std::tuple<char, char> nextCase;

    unsigned char path = 'x';

    char offsetY = -1;
    char offsetX = -1;
    size_t index = 2;

    if (std::get<0>(_start) == -1 || std::get<1>(_start) == -1) {
        throw std::exception();
    }

    (*_map[std::get<0>(_start)][std::get<1>(_start)]).setValue(1);
    while (1) {
        if (!isOffsetValid(offset, offsetY, offsetX, path, false)) {
            nextCase = findPath(offset.x, offset.y, path);
        }

        offsetY = std::get<0>(nextCase);
        offsetX = std::get<1>(nextCase);
        if (offsetY == -1 && offsetX == -1) {
            break;
        }

        offset = {
            offset.x + offsetY,
            offset.y + offsetX
        };
        (*_map[offset.x][offset.y]).setValue(index);

        index++;
    }
}

std::tuple<char, char> Map::getNextCase(Vector2 pos, char offsetY, char offsetX, unsigned char &value)
{
    if (!isOffsetValid(pos, offsetY, offsetX, value, true)) {
        return findPath(pos.x, pos.y, value);
    }
    return std::make_tuple(offsetY, offsetX);
}

void Map::createMap()
{
    std::string content = _buffer.str();
    size_t index = 0;

    std::replace(content.begin(), content.end(), '.', '\0');
    for (auto lines_it = _map.begin(); lines_it != _map.end(); lines_it++) {
        for (auto cols_it = (*lines_it).begin(); cols_it != (*lines_it).end(); cols_it++) {
            if (content[index] == '\0') {
                (*cols_it) = std::unique_ptr<Case>(new Case(TOWER_ZONE, content[index]));
            } else {
                (*cols_it) = std::unique_ptr<Case>(new Case(PATH, content[index]));
            }
            index++;
            if (index >= content.size()) {
                return;
            }
        }
        index++;
    }
    _start = findStart();
    (*_map[5][23]).setTower(Game::Tower::TowerFactory::createBasicTower(std::make_tuple(0, 0)));
    (*_map[5][23]).getTower()->toggleHitboxDisplay();
    createPath();
}

void Map::displayMap()
{
    for (auto lines_it = _map.begin(); lines_it != _map.end(); lines_it++) {
        for (auto cols_it = (*lines_it).begin(); cols_it != (*lines_it).end(); cols_it++) {
            if ((*cols_it)->getValue() == '\0') {
                std::cout << '.' << "\t";
            }  else if ((*cols_it)->getValue() == 'x') {
                std::cout << 'x' << "\t";
            } else {
                std::cout << int((*cols_it)->getValue()) << "\t";
            }
        }
        std::cout << std::endl;
    }
}

void Map::drawMap()
{
    Vector2 pos = {0.0f, 0.0f};
    std::shared_ptr<Game::Tower::ITower> tower;

    scaleHeight = ((float)GetScreenHeight() / 1080) * 0.23;
    scaleWidth = ((float)GetScreenWidth() / 1920) * 0.23;

    std::cout << scaleHeight << std::endl;
    std::cout << scaleWidth << std::endl << std::endl;
    for (auto lines_it = _map.begin(); lines_it != _map.end(); lines_it++) {
        for (auto cols_it = (*lines_it).begin(); cols_it != (*lines_it).end(); cols_it++) {
            (*cols_it)->drawCase({scaleWidth, scaleHeight}, pos);

            tower = (*cols_it)->getTower();
            if ((*cols_it)->getType() == Case::TOWER_ZONE && tower != nullptr) {
                (*(*cols_it)->getTower()).setPosition(std::make_tuple(pos.x, pos.y));
            }
            pos.x += (*cols_it)->getTexture().width * scaleWidth;
        }
        pos.x = 0;
        pos.y += (*(*lines_it).begin())->getTexture().height * scaleHeight;
    }

    for (auto lines_it = _map.begin(); lines_it != _map.end(); lines_it++) {
        for (auto cols_it = (*lines_it).begin(); cols_it != (*lines_it).end(); cols_it++) {
            tower = (*cols_it)->getTower();
            if ((*cols_it)->getType() == Case::TOWER_ZONE && tower != nullptr) {
                (*tower).draw();
                tower->attack();
            }
        }
    }
}
