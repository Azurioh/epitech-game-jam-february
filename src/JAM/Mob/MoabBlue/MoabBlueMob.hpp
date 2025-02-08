/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** MoabBlue
*/

#ifndef MOABBLUE_HPP_
#define MOABBLUE_HPP_

#include "../AMob.hpp"

class MoabBlueMob : public AMob{
    public:
        MoabBlueMob();
        ~MoabBlueMob();

    protected:
    private:
    void move_mob(Map &map);

};

#endif /* !MOABBLUE_HPP_ */
