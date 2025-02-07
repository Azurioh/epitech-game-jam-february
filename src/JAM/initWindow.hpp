/*
** EPITECH PROJECT, 2025
** JAM
** File description:
** window
*/

#ifndef WINDOW_HPP
    #define WINDOW_HPP

    #include <raylib.h>

class Window {
    public:
        Window(const char* title);
        ~Window();
        void Begin();
        void End();
        void UpdateWindowSize();

    private:
        int screenWidth;
        int screenHeight;
        Texture2D background;
};

#endif
