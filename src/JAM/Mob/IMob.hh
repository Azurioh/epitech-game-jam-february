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
        enum MobType {
            YELLOW_MOB,
            WHITE_MOB,
            RED_MOB,
            RAINBOW_MOB,
            PINK_MOB,
            MOAB_RED_MOB,
            MOAB_BLUE_MOB,
            GREEN_MOB,
            BLUE_MOB,
            BLACK_MOB,
        };

        class IMob {
            public:
                IMob() {};
                ~IMob() {};

                virtual void setHp(int hp) = 0;
                virtual int getHp() = 0;
                virtual int getSpeed() = 0;
                virtual void setSpeed(int speed) = 0;
                virtual void takeDamage(int hp) = 0;

                virtual void handleRotation(std::tuple<char, char> offset) = 0;
                virtual void initMobMovement(Map &map) = 0;
                virtual void moveMob(Map &map) = 0;
                virtual void drawMob() const  = 0;

                virtual Vector2 getPosition() const = 0;
                virtual int getGold() const = 0;
                virtual void setPosition(Vector2 pos) = 0;

                virtual bool isVisible(void) const = 0;

                virtual void load() = 0;

            protected:
            private:
        };
    }
}
