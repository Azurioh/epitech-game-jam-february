/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** RedMob
*/

#ifndef REDMOB_HPP_
#define REDMOB_HPP_

#include "../AMob.hpp"


class RedMob : public Game::Mob::AMob {
    public:
        RedMob();
        ~RedMob();

    protected:
    private:
    int move_mob();
};

#endif /* !REDMOB_HPP_ */
