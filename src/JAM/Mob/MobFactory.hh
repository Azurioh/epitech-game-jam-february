/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** MobFactory
*/

#ifndef MOBFACTORY_HH_
#define MOBFACTORY_HH_

#include <memory>
#include "AMob.hpp"
#include "RedMob/RedMob.hpp"
#include "BlueMob/BlueMob.hpp"
#include "GreenMob/GreenMob.hpp"
#include "YellowMob/YellowMob.hpp"
#include "PinkMob/PinkMob.hpp"
#include "BlackMob/BlackMob.hpp"
#include "WhiteMob/WhiteMob.hpp"
#include "RainbowMob/RainbowMob.hpp"
#include "MoabBlue/MoabBlueMob.hpp"
#include "MoabRed/MoabRedMob.hpp"
#include "IMob.hh"

namespace Game {
    namespace Mob {
        class MobFactory {
            public:
                MobFactory() {};
                ~MobFactory() {};
                static std::shared_ptr<Game::Mob::IMob> createRedMob();
                static std::shared_ptr<Game::Mob::IMob> createBlueMob();
                static std::shared_ptr<Game::Mob::IMob> createGreenMob();
                static std::shared_ptr<Game::Mob::IMob> createYellowMob();
                static std::shared_ptr<Game::Mob::IMob> createPinkMob();
                static std::shared_ptr<Game::Mob::IMob> createBlackMob();
                static std::shared_ptr<Game::Mob::IMob> createWhiteMob();
                static std::shared_ptr<Game::Mob::IMob> createRainbowMob();
                static std::shared_ptr<Game::Mob::IMob> createMoabBlueMob();
                static std::shared_ptr<Game::Mob::IMob> createMoabRedMob();

            protected:
            private:
        };
    }
}

#endif /* !MOBFACTORY_HH_ */
