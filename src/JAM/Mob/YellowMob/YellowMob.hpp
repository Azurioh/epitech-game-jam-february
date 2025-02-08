/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** YellowMob
*/

#ifndef YELLOWMOB_HPP_
#define YELLOWMOB_HPP_

    #include <filesystem>

#include "../AMob.hpp"

class YellowMob : public AMob{
    public:
        YellowMob();
        ~YellowMob();

        void move_mob(Map &map);

    protected:
    private:
};

#endif /* !YELLOWMOB_HPP_ */
