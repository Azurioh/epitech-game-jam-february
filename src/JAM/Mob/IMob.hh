/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** IMob
*/

#pragma once

#include <tuple>

namespace Game {
    namespace Mob {
        class IMob {
            public:
                IMob() {};
                ~IMob() {};

                virtual std::tuple<int, int> getPosition() const = 0;
                virtual int getGold() const = 0;
                virtual int move_mob() = 0;
                virtual void drawMob() = 0;

            protected:
            private:
        };
    }
}
