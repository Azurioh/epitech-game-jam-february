/*
** EPITECH PROJECT, 2025
** Buttons
** File description:
** Buttons
*/

#pragma once

#include <raylib.h>
#include <string>

#define NUM_FRAMES 3

class Buttons {
    public:
        Buttons(std::string text, std::string assetPath, float x = 0, float y = 0, int textSize = 15, bool hoverEffect = true);
        void Display();
        void Event();
        bool isPressed();
        void SetPosition(float x, float y, float spacing);
        Texture2D getTexture(void) const;
        Rectangle GetSize();

    private:
        int _btnState;
        bool _btnAction;
        std::string _text;
        Texture2D _button;
        Rectangle _sourceRec;
        Rectangle _btnBounds;
        Vector2 _mousePos;
        float _frameHeight;
        int _textSize;
        bool _hoverEffect;
};
