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

        bool open(std::string filepath);

        std::tuple<char, char> findStart();
        std::tuple<char, char> findPath(size_t y, size_t x);
        bool isOffsetValid(std::tuple<char, char> &offset, char offsetY, char offsetX);
        void createPath();
        void createMap();

        void displayMap();

    protected:
    private:
        std::stringstream _buffer;
        std::vector<std::vector<std::unique_ptr<Case>>> _map;
};

#endif /* !MAP_HPP_ */
