/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** IMob
*/

#ifndef IMOB_HH_
#define IMOB_HH_

    #include "../Level/Map.hpp"

namespace Game {
    namespace Mob {
        class IMob {
            public:
                IMob() {};
                ~IMob() {};

                virtual void setHp(int hp) = 0;
                virtual int getHp() = 0;
                virtual int getSpeed() = 0;
                virtual void setSpeed(int speed) = 0;
                virtual int takeDamage(int hp) = 0;

                virtual void move_mob(Map &map) = 0;

            protected:
            private:
        };
    }
}

#endif /* !IMOB_HH_ */
