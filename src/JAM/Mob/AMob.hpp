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
                int takeDamage(int hp);

                Vector2 getPosition(void) const;
                int getGold(void) const;

                void setPosition(Vector2 pos);
                void setGold(int gold);

                void moveMob(Map &map);
                void drawMob(Vector2 position) const;

                const float scale = 0.7f;

            protected:
                int _hp;
                int _speed;
                int _gold;

                Vector2 _position;
                Texture2D _texture;

                std::tuple<char, char> _offset;
                Vector2 _mapPos;
                unsigned char _mapValue;

                bool _visible;
            private:
        };
    }
}
#endif /* !AMOB_HH_ */
