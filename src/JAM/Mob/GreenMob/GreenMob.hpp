/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** GreenMob
*/

#ifndef GREENMOB_HPP_
#define GREENMOB_HPP_

#include "../AMob.hpp"

class GreenMob : public Game::Mob::AMob {
    public:
        GreenMob();
        ~GreenMob();

    protected:
    private:
    int move_mob();

};

#endif /* !GREENMOB_HPP_ */
