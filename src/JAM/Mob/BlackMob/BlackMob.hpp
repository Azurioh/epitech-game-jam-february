/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** BlackMob
*/

#ifndef BLACKMOB_HPP_
#define BLACKMOB_HPP_

#include "../AMob.hpp"

class BlackMob : public AMob{
    public:
        BlackMob();
        ~BlackMob();

    protected:
    private:
    void move_mob(Map &map);
};

#endif /* !BLACKMOB_HPP_ */
