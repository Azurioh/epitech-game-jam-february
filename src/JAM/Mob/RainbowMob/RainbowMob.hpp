/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** RainbowMob
*/

#ifndef RAINBOWMOB_HPP_
#define RAINBOWMOB_HPP_

#include "../AMob.hpp"

class RainbowMob : public AMob{
    public:
        RainbowMob();
        ~RainbowMob();

    protected:
    private:
    void move_mob(Map &map);

};

#endif /* !RAINBOWMOB_HPP_ */
