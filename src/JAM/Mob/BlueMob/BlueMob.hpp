/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** BlueMob
*/

#ifndef BLUEMOB_HPP_
#define BLUEMOB_HPP_

#include "../AMob.hpp"

class BlueMob : public Game::Mob::AMob {
    public:
        BlueMob();
        ~BlueMob();

    protected:
    private:
    void moveMobb(Map &map);

};

#endif /* !BLUEMOB_HPP_ */
