/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** MoabRedMob
*/

#ifndef MOABREDMOB_HPP_
#define MOABREDMOB_HPP_

#include "../AMob.hpp"

class MoabRedMob : public Game::Mob::AMob {
    public:
        MoabRedMob();
        ~MoabRedMob();

    protected:
    private:
    int move_mob();
};

#endif /* !MOABREDMOB_HPP_ */
