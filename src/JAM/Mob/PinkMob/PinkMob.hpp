/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** PinkMob
*/

#ifndef PINKMOB_HPP_
#define PINKMOB_HPP_

#include "../AMob.hpp"

class PinkMob : public AMob{
    public:
        PinkMob();
        ~PinkMob();

    protected:
    private:
    void move_mob(Map &map);
};

#endif /* !PINKMOB_HPP_ */
