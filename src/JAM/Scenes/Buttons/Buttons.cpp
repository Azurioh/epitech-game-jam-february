/*
** EPITECH PROJECT, 2025
** Buttons
** File description:
** Buttons
*/

#include "Buttons.hh"
#include <iostream>

Buttons::Buttons(std::string text, std::string assetPath, float x, float y, int textSize, bool hoverEffect):
    _btnState(0), _btnAction(false), _text(text), _textSize(textSize), _hoverEffect(hoverEffect)
{
    _button = LoadTexture(assetPath.c_str());
    _frameHeight = _button.height / NUM_FRAMES;
    _sourceRec = {0, 0, (float)_button.width, hoverEffect ? _frameHeight : _button.height};
    _btnBounds = {x, y, (float)_button.width, hoverEffect ? _frameHeight : _button.height};
}

void Buttons::SetPosition(float x, float y, float spacing)
{
    _btnBounds.x = x - (_btnBounds.width / 2);
    _btnBounds.y = y + spacing;
}

Rectangle Buttons::GetSize()
{
    return _btnBounds;
}

void Buttons::Display()
{
    float textPosX = _btnBounds.x + (_btnBounds.width - MeasureText(_text.c_str(), _textSize)) / 2;
    float textPosY = _btnBounds.y + (_btnBounds.height - MeasureTextEx(GetFontDefault(), _text.c_str(), _textSize, 0).y) / 2;

    if (_hoverEffect) {
        _sourceRec.y = _btnState * _frameHeight;
    }
    DrawTextureRec(_button, _sourceRec, {_btnBounds.x, _btnBounds.y}, RAYWHITE);
    DrawText(_text.c_str(), textPosX, textPosY, _textSize, WHITE);
}

void Buttons::Event()
{
    _mousePos = GetMousePosition();
    _btnState = 0;

    if (CheckCollisionPointRec(_mousePos, _btnBounds)) {
        _btnState = 1;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            _btnState = 2;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            _btnAction = true;
    }
}

bool Buttons::isPressed()
{
    if (_btnAction == true) {
        _btnAction = false;
        return true;
    }
    return false;
}

Texture2D Buttons::getTexture(void) const
{
    return _button;
}
