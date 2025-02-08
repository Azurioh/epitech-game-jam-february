/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** IMob
*/

#pragma once

#include "../Level/Map.hpp"

#include <tuple>
#include <math.h>

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

                virtual void initMobMovement(Map &map) = 0;
                virtual void moveMobb(Map &map) = 0;
                virtual void drawMob(Vector2 position) const  = 0;

                virtual Vector2 getPosition() const = 0;
                virtual int getGold() const = 0;

            protected:
            private:
        };
    }
}
