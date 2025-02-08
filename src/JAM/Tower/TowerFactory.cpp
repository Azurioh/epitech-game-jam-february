/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** TowerFactory
*/

#include "TowerFactory.hh"
#include "ITower.hh"
#include "BasicTower/BasicTower.hh"

Game::Tower::TowerFactory::TowerFactory()
{
}

Game::Tower::TowerFactory::~TowerFactory()
{
}

std::unique_ptr<Game::Tower::ITower> Game::Tower::TowerFactory::createBasicTower(std::tuple<std::size_t, std::size_t> pos)
{
    return std::unique_ptr<BasicTower>(new Game::Tower::BasicTower(pos));
}
