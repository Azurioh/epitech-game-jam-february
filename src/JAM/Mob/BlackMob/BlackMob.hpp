/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** BlackMob
*/

#ifndef BLACKMOB_HPP_
#define BLACKMOB_HPP_

#include "../AMob.hpp"

class BlackMob : public Game::Mob::AMob {
    public:
        BlackMob();
        ~BlackMob();

    protected:
    private:
    int move_mob();
};

#endif /* !BLACKMOB_HPP_ */
