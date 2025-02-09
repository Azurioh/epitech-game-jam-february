/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

    #include <fstream>
    #include <sstream>
    #include <vector>
    #include <memory>
    #include <tuple>
    #include <algorithm>

    #include "Case.hpp"

class Map: public Case {
    public:
        Map(std::string filepath);
        ~Map();

        std::vector<std::vector<std::shared_ptr<Case>>> getMap();
        std::tuple<char, char> getStart();
        size_t getMobPassed();
        void addMobPassed();

        bool open(std::string filepath);

        std::tuple<char, char> findStart();
        std::tuple<char, char> findPath(size_t y, size_t x, char value);
        bool isOffsetValid(Vector2 &pos, char offsetY, char offsetX, unsigned char &value, bool change);
        void createPath();
        std::tuple<char, char> getNextCase(Vector2 pos, char offsetY, char offsetX, unsigned char &value);
        void createMap();

        void drawMap();
        void displayMap();

        const float scale = 0.25f;

    protected:
    private:
        std::vector<std::vector<std::shared_ptr<Case>>> _map;
        std::stringstream _buffer;
        std::tuple<char, char> _start;

        size_t _mobPassed;

};

#endif /* !MAP_HPP_ */
