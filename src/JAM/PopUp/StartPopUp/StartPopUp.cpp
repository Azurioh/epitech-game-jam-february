/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** StartPopUp
*/

#include "StartPopUp.hh"

Game::PopUp::StartPopUp::StartPopUp():
    _title("Title"),
    _text("Text"),
    _hidden(false),
    _closeButton("", "asset/gameUI/close.png", 700, 540, 5)
{
}

Game::PopUp::StartPopUp::~StartPopUp()
{
}

Game::PopUp::IPopUp::PopUpAction Game::PopUp::StartPopUp::exec(void)
{
    _closeButton.Event();

    if (_closeButton.isPressed()) {
        return CLOSE;
    } else {
        return NOTHING;
    }
}

void Game::PopUp::StartPopUp::draw(void)
{
    DrawRectangle(550, 250, 350, 350, WHITE);
    DrawText(_title.c_str(), 600, 350, 20, BLACK);
    DrawText(_text.c_str(), 600, 390, 20, BLACK);
    _closeButton.Display();
}

void Game::PopUp::StartPopUp::toggleHidden(void)
{
    _hidden = !_hidden;
}

bool Game::PopUp::StartPopUp::isHidden(void) const
{
    return _hidden;
}
