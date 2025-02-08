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
                void takeDamage(int hp);

                Vector2 getPosition(void) const;
                int getGold(void) const;

                void setPosition(Vector2 pos);
                void setGold(int gold);

                void handleRotation(std::tuple<char, char> offset);
                void initMobMovement(Map &map);
                void moveMob(Map &map);
                void drawMob() const;

                bool isVisible(void) const;


            protected:
                int _hp;
                float _speed;
                int _gold;

                Vector2 _position;
                Texture2D _texture;

                float _widthScale;
                float _heightScale;
                float _rotation;

                std::tuple<char, char> _offset;
                Vector2 _mapPos;
                Vector2 _nextPosition;
                unsigned char _mapValue;

                double _time;

                bool _visible;
                bool _stopMoving;

                MobType _type;
            private:
        };
    }
}
#endif /* !AMOB_HH_ */
