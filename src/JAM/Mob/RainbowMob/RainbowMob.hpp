/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** RainbowMob
*/

#ifndef RAINBOWMOB_HPP_
#define RAINBOWMOB_HPP_

#include "../AMob.hpp"

class RainbowMob : public Game::Mob::AMob {
    public:
        RainbowMob();
        ~RainbowMob();

    protected:
    private:
    int move_mob();

};

#endif /* !RAINBOWMOB_HPP_ */
