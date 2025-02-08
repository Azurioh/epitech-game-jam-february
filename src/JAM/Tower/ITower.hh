/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** ITower
*/

#pragma once

#include <tuple>

namespace Game {
    namespace Tower {
        class ITower {
            public:
                ITower() {};
                virtual ~ITower() = default;

                enum AttackType {
                    FIRST,
                    CLOSEST,
                };

                virtual void attack(void) = 0;
                virtual void changeAttackType(void) = 0;
                // virtual std::shared_ptr<IMob> getMobToAttack(std::vector<std::shared_ptr<IMob>> mobs) = 0;
        };
    }
}
