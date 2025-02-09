/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** main
*/

#include "JAM/Level/Map.hpp"
#include "JAM/Mob/MobFactory.hh"
#include <unistd.h>
#include "./JAM/Tower/ITower.hh"

// int main(void)
// {
//     Map map1("maps/map_1.txt");
//     Map map2("maps/map_2.txt");
//     Map map3("maps/map_3.txt");
//     Map map4("maps/map_4.txt");
//     Map map5("maps/map_5.txt");
//     Map map6("maps/map_6.txt");
//     Map map7("maps/map_7.txt");
//     Map map8("maps/map_8.txt");
//     Map map9("maps/map_9.txt");

//     InitWindow(GetScreenWidth(), GetScreenHeight(), "TEST PATH");

//     std::vector<std::shared_ptr<Game::Mob::IMob>> mobs;

//     mobs.resize(10);
//     mobs[0] = c;
//     mobs[1] = Game::Mob::MobFactory::createWhiteMob();
    // mobs[2] = Game::Mob::MobFactory::createRedMob();
//     mobs[3] = Game::Mob::MobFactory::createRainbowMob();
//     mobs[4] = Game::Mob::MobFactory::createPinkMob();
//     mobs[5] = Game::Mob::MobFactory::createMoabRedMob();
//     mobs[6] = Game::Mob::MobFactory::createMoabBlueMob();
//     mobs[7] = Game::Mob::MobFactory::createGreenMob();
//     mobs[8] = Game::Mob::MobFactory::createBlueMob();
//     mobs[9] = Game::Mob::MobFactory::createBlackMob();

//     map1.createMap();
//     // map2.createMap();
//     // map3.createMap();
//     // map4.createMap();
//     // map5.createMap();
//     // map6.createMap();
//     // map7.createMap();
//     // map8.createMap();
//     // map9.createMap();
//     std::shared_ptr<Game::Tower::ITower> tower;

//     while (!WindowShouldClose()) {
//         ClearBackground(BLACK);
//         BeginDrawing();
//         tower = map1.getMap()[5][23]->getTower();
//         tower->getMobToAttack(mobs);
//         map1.drawMap();

//         for (int i = 0; i < 10; i++) {
//             mobs[i]->moveMob(map1);
//         }

//         EndDrawing();
//     }
//     CloseWindow();
// }

#include "JAM/JAM.hpp"

int main(void)
{
    JAM start;
    return 0;
}
