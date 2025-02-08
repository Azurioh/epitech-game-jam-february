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


namespace Game {
    namespace Mob {
        class AMob : public IMob {
            public:
                AMob(int hp = 1, int gold = 5);
                virtual ~AMob() = default;
                void setHp(int hp);
                int getHp();
                int getSpeed();
                void setSpeed(int speed);
                void setPos(int pos_x, int pos_y);
                int takeDamage(int hp);

                std::tuple<int, int> getPosition(void);
                int getGold(void) const;

                void setPosition(std::tuple<int, int> pos);
                void setGold(int gold);

                void drawMob(void) const;

            protected:
                int _hp;
                int _speed;
                int _gold;
                std::tuple<unsigned int, unsigned int> _position;
                Texture2D _mobTexture;
            private:
        };
    }
}
#endif /* !AMOB_HH_ */
