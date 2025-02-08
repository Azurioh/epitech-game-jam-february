/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** AMob
*/

#ifndef AMOB_HH_
#define AMOB_HH_
#include "IMob.hh"
#include <raylib.h>
#include <tuple>



class AMob : public Game::Mob::IMob {
    public:
        AMob() {};
        virtual ~AMob() = default;
        void setHp(int hp);
        int getHp();
        int getSpeed();
        void setSpeed(int speed);
        void setPos(int pos_x, int pos_y);
        int takeDamage(int hp);
        void draw(void) const;

    protected:
        int _hp;
        int _speed;
        int _pos_x;
        int _pos_y;
        std::tuple<unsigned int, unsigned int> _position;
        Texture2D _mobTexture;
        int _speed;

    private:
};

#endif /* !AMOB_HH_ */
