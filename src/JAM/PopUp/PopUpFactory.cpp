/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** PopUpFactory
*/

#include "PopUpFactory.hh"
#include "StartPopUp/StartPopUp.hh"

Game::PopUp::PopUpFactory::PopUpFactory()
{
}

Game::PopUp::PopUpFactory::~PopUpFactory()
{
}

std::shared_ptr<Game::PopUp::IPopUp> Game::PopUp::PopUpFactory::createStartPopUp()
{
    return std::shared_ptr<Game::PopUp::StartPopUp>(new Game::PopUp::StartPopUp());
}
