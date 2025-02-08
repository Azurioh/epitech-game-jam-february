/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(std::string filepath)
{
    _map.resize(13);
    for (auto it = _map.begin(); it != _map.end(); it++) {
        (*it).resize(27);
    }
    if (!open(filepath)) {
        throw std::exception();
    }
}

Map::~Map()
{
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

std::tuple<char, char> Map::findPath(size_t y, size_t x)
{
    if (y > 0 && (*_map[y - 1][x]).getValue() == 'x') { // Check top
        return std::make_tuple(-1, 0);
    }
    if (x > 0 && (*_map[y][x - 1]).getValue() == 'x') { // Check left
        return std::make_tuple(0, -1);
    }
    if (y < _map.size() && (*_map[y + 1][x]).getValue() == 'x') { // Check bottom
        return std::make_tuple(1, 0);
    }
    if (x < _map[0].size() && (*_map[y][x + 1]).getValue() == 'x') { // Check right
        return std::make_tuple(0, 1);
    }
    return std::make_tuple(-1, -1);
}


bool Map::isOffsetValid(std::tuple<char, char> &offset, char offsetY, char offsetX)
{
    if (offsetY == -1 && offsetX == -1) {
        return false;
    }

    std::tuple<char, char> offsetTmp(
        std::get<0>(offset) + offsetY,
        std::get<1>(offset) + offsetX
    );
    if (std::get<0>(offsetTmp) < 0 || size_t(std::get<0>(offsetTmp)) >= _map.size() ||
        std::get<1>(offsetTmp) < 0 || size_t(std::get<1>(offsetTmp)) >= _map[0].size()) {
        return false;
    }
    if ((*_map[std::get<0>(offsetTmp)][std::get<1>(offsetTmp)]).getValue() != 'x' &&
        (*_map[std::get<0>(offsetTmp)][std::get<1>(offsetTmp)]).getValue() == '\0') {
        return false;
    }
    if ((*_map[std::get<0>(offsetTmp)][std::get<1>(offsetTmp)]).getValue() != 'x' &&
        (*_map[std::get<0>(offsetTmp)][std::get<1>(offsetTmp)]).getValue() > 0) {
        offset = offsetTmp;
        return true;
    }
    return true;
}

void Map::createPath()
{
    std::tuple<char, char> start = findStart();
    std::tuple<char, char> offset(std::get<0>(start), std::get<1>(start));
    std::tuple<char, char> nextCase;

    char offsetY = -1;
    char offsetX = -1;
    size_t index = 2;

    if (std::get<0>(start) == -1 || std::get<1>(start) == -1) {
        return;
    }

    (*_map[std::get<0>(start)][std::get<1>(start)]).setValue(1);
    while (1) {
        if (!isOffsetValid(offset, offsetY, offsetX)) {
            nextCase = findPath(std::get<0>(offset), std::get<1>(offset));
        }

        offsetY = std::get<0>(nextCase);
        offsetX = std::get<1>(nextCase);
        if (offsetY == -1 && offsetX == -1) {
            break;
        }

        offset = std::make_tuple(
            std::get<0>(offset) + offsetY,
            std::get<1>(offset) + offsetX
        );
        (*_map[std::get<0>(offset)][std::get<1>(offset)]).setValue(index);

        index++;
    }
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
    Vector2 pos = {200.0f, 200.0f};

    for (auto lines_it = _map.begin(); lines_it != _map.end(); lines_it++) {
        for (auto cols_it = (*lines_it).begin(); cols_it != (*lines_it).end(); cols_it++) {
            (*cols_it)->drawCase(scale, pos);
            pos.x += (*cols_it)->getTexture().width * scale;
        }
        pos.x = 200;
        pos.y += (*(*lines_it).begin())->getTexture().height * scale;
    }
}
