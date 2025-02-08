/*
** EPITECH PROJECT, 2025
** JAM
** File description:
** JAM
*/

#include "JAM.hpp"

JAM::JAM()
{
    InitWindow(1920, 1080, "Bloons Illusion Tower Defense 7+ Premium Deluxe Definitive Edition Collector Reloaded");
    SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);
    UpdateWindowSize();
    SetTargetFPS(60);
    gameLoop();
}

void JAM::UpdateWindowSize() {
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
}

JAM::~JAM()
{
    CloseWindow();
}

void JAM::gameLoop()
{
    while (!WindowShouldClose()) {
        BeginDrawing();
        EndDrawing();
    }
}
