/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** RedMob
*/

#ifndef REDMOB_HPP_
#define REDMOB_HPP_

#include "../AMob.hpp"

class RedMob : public AMob {
    public:
        RedMob();
        ~RedMob();

    protected:
    private:
    void move_mob(Map &map);
};

#endif /* !REDMOB_HPP_ */
