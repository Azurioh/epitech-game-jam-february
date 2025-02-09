/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** PopUpFactory
*/

#include "PopUpFactory.hh"
#include "StartPopUp/StartPopUp.hh"
#include "TextPopUp/TextPopUp.hh"

Game::PopUp::PopUpFactory::PopUpFactory()
{
}

Game::PopUp::PopUpFactory::~PopUpFactory()
{
}

std::shared_ptr<Game::PopUp::IPopUp> Game::PopUp::PopUpFactory::createStartPopUp()
{
    return std::shared_ptr<Game::PopUp::IPopUp>(new Game::PopUp::StartPopUp());
}

std::shared_ptr<Game::PopUp::IPopUp> Game::PopUp::PopUpFactory::createTextPopUp(std::string title, std::string text)
{
    return std::shared_ptr<Game::PopUp::IPopUp>(new Game::PopUp::TextPopUp(title, text));
}
