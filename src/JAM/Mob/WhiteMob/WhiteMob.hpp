/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** WhiteMob
*/

#ifndef WHITEMOB_HPP_
#define WHITEMOB_HPP_

#include "../AMob.hpp"

class WhiteMob : public AMob{
    public:
        WhiteMob();
        ~WhiteMob();

    protected:
    private:
    int move_mob();
};

#endif /* !WHITEMOB_HPP_ */
