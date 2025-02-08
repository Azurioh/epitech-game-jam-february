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

std::shared_ptr<Game::Tower::ITower> Game::Tower::TowerFactory::createBasicTower(std::tuple<std::size_t, std::size_t> pos)
{
    return std::shared_ptr<BasicTower>(new Game::Tower::BasicTower(pos));
}

std::shared_ptr<Game::Tower::ITower> Game::Tower::TowerFactory::createLongRangeTower(std::tuple<std::size_t, std::size_t> pos)
{
    return std::shared_ptr<LongRangeTower>(new Game::Tower::LongRangeTower(pos));
}

std::shared_ptr<Game::Tower::ITower> Game::Tower::TowerFactory::createCloseRangeTower(std::tuple<std::size_t, std::size_t> pos)
{
    return std::shared_ptr<CloseRangeTower>(new Game::Tower::CloseRangeTower(pos));
}

std::shared_ptr<Game::Tower::ITower> Game::Tower::TowerFactory::createDamageTower(std::tuple<std::size_t, std::size_t> pos)
{
    return std::shared_ptr<DamageTower>(new Game::Tower::DamageTower(pos));
}