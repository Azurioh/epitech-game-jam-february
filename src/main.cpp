/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** main
*/

#include "JAM/Level/Map.hpp"
#include "JAM/Mob/MobFactory.hh"
#include <unistd.h>

int main(void)
{
    Map map1("maps/map_1.txt");
    Map map2("maps/map_2.txt");
    Map map3("maps/map_3.txt");


    InitWindow(GetScreenWidth(), GetScreenHeight(), "TEST PATH");

    std::unique_ptr<Game::Mob::IMob> mob1 = Game::Mob::MobFactory::createYellowMob();
    std::unique_ptr<Game::Mob::IMob> mob2 = Game::Mob::MobFactory::createWhiteMob();
    std::unique_ptr<Game::Mob::IMob> mob3 = Game::Mob::MobFactory::createRedMob();
    std::unique_ptr<Game::Mob::IMob> mob4 = Game::Mob::MobFactory::createRainbowMob();
    std::unique_ptr<Game::Mob::IMob> mob5 = Game::Mob::MobFactory::createPinkMob();
    std::unique_ptr<Game::Mob::IMob> mob6 = Game::Mob::MobFactory::createMoabRedMob();
    std::unique_ptr<Game::Mob::IMob> mob7 = Game::Mob::MobFactory::createMoabBlueMob();
    std::unique_ptr<Game::Mob::IMob> mob8 = Game::Mob::MobFactory::createGreenMob();
    std::unique_ptr<Game::Mob::IMob> mob9 = Game::Mob::MobFactory::createBlueMob();
    std::unique_ptr<Game::Mob::IMob> mob10 = Game::Mob::MobFactory::createBlackMob();

    int init = 0;


    double time = GetTime();

    std::cout << time << std::endl;
    map1.createMap();
    // map1.createMap();
    // map2.createMap();
    // map3.displayMap();
    while (!WindowShouldClose()) {
        ClearBackground(BLACK);
        BeginDrawing();
        map1.drawMap();

        if (GetTime() >= 1 || init >= 1) {
            mob1->moveMob(map1);
            init = 1;
        }
        if (GetTime() >= 3 || init >= 2) {
            mob2->moveMob(map1);
            init = 2;
        }
        if (GetTime() >= 5 || init >= 3) {
            mob3->moveMob(map1);
            init = 3;
        }
        if (GetTime() >= 7 || init >= 4) {
            mob4->moveMob(map1);
            init = 4;
        }
        if (GetTime() >= 9 || init >= 5) {
            mob5->moveMob(map1);
            init = 5;
        }
        if (GetTime() >= 11 || init >= 6) {
            mob6->moveMob(map1);
            init = 6;
        }
        if (GetTime() >= 13 || init >= 7) {
            mob7->moveMob(map1);
            init = 7;
        }
        if (GetTime() >= 15 || init >= 8) {
            mob8->moveMob(map1);
            init = 8;
        }
        if (GetTime() >= 17 || init >= 9) {
            mob9->moveMob(map1);
            init = 9;
        }
        if (GetTime() >= 19 || init >= 10) {
            mob10->moveMob(map1);
            init = 10;
        }
        std::cout << map1.getMobPassed() << std::endl;
        EndDrawing();
    }
    CloseWindow();
}

#include "JAM/JAM.hpp"

// int main(void)
// {
//     JAM start;
//     return 0;
// }
