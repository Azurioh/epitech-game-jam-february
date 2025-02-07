/*
** EPITECH PROJECT, 2025
** JAM
** File description:
** test
*/

#include "initWindow.hpp"

Window::Window(const char* title) {
    InitWindow(1920, 1080, title);
    SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);
    UpdateWindowSize();
    background = LoadTexture("src/background.png");
    SetTargetFPS(60);
}

Window::~Window() {
    UnloadTexture(background);
    CloseWindow();
}

void Window::UpdateWindowSize() {
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
}

void Window::Begin() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexturePro(background,
                   {0, 0, (float)background.width, (float)background.height},
                   {0, 0, (float)screenWidth, (float)screenHeight},
                   {0, 0}, 0.0f, WHITE);
}

void Window::End() {
    EndDrawing();
}
