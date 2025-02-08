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

int main(void)
{
    Map map1("maps/map_1.txt");
    Map map2("maps/map_2.txt");


    InitWindow(GetScreenWidth(), GetScreenHeight(), "TEST PATH");

    map1.createMap();
    map2.createMap();
    while (!WindowShouldClose()) {
        BeginDrawing();
        // map1.drawMap();
        map2.drawMap();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
