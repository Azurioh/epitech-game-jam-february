// /*
// ** EPITECH PROJECT, 2025
// ** epitech-game-jam-january
// ** File description:
// ** main
// */

// #include "JAM/JAM.hpp"

// int main(void)
// {
//     JAM start;
//     return 0;
// }

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

    std::unique_ptr<Game::Mob::IMob> mob = Game::Mob::MobFactory::createYellowMob();

    map1.createMap();
    while (!WindowShouldClose()) {
        BeginDrawing();
        map1.drawMap();
        mob->move_mob(map1);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
