/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** AMob
*/

#ifndef AMOB_HH_
#define AMOB_HH_

    #include <raylib.h>

    #include "IMob.hh"
    #include "../Level/Map.hpp"

class AMob : public Game::Mob::IMob {
    public:
        AMob() {};
        ~AMob() {};

        void setHp(int hp);
        int getHp();
        int getSpeed();
        void setSpeed(int speed);
        int takeDamage(int hp);

        void moveMob(Map &map);

        void drawMob(Vector2 position);

        const float scale = 0.7;

    protected:
        int _hp;
        int _speed;

        Texture2D _texture;
        Vector2 _position;

        std::tuple<char, char> _offset;
        Vector2 _mapPos;
        unsigned char _mapValue;

        bool _visible;

    private:
};

#endif /* !AMOB_HH_ */
