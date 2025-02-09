/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** TextPopUp
*/

#include "TextPopUp.hh"

Game::PopUp::TextPopUp::TextPopUp(std::string title, std::string text):
    _title(title),
    _text(text),
    _hidden(false),
    _closeButton("", "asset/gameUI/close.png", 700, 540, 5)
{
}

Game::PopUp::TextPopUp::~TextPopUp()
{
}

Game::PopUp::IPopUp::PopUpAction Game::PopUp::TextPopUp::exec(void)
{
    _closeButton.Event();

    if (_closeButton.isPressed()) {
        return CLOSE;
    } else {
        return NOTHING;
    }
}

void Game::PopUp::TextPopUp::draw(void)
{
    DrawRectangle(550, 250, 350, 350, WHITE);
    DrawText(_title.c_str(), 600, 350, 20, BLACK);
    DrawText(_text.c_str(), 600, 390, 20, BLACK);
    _closeButton.Display();
}

void Game::PopUp::TextPopUp::toggleHidden(void)
{
    _hidden = !_hidden;
}

bool Game::PopUp::TextPopUp::isHidden(void) const
{
    return _hidden;
}
