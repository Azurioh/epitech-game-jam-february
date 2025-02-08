/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Player
*/

#include "Player.hh"
#include <algorithm>

Game::Player::Player()
{
}

Game::Player::~Player()
{
}

unsigned int Game::Player::getHP() const
{
	return _hp;
}

unsigned int Game::Player::getGolds() const
{
	return _golds;
}

std::vector<std::shared_ptr<Game::Tower::ITower>> Game::Player::getTowers() const
{
	return _towers;
}

void Game::Player::setHP(unsigned int hp)
{
    _hp = hp;
}

void Game::Player::setGolds(unsigned int golds)
{
    _golds = golds;
}

void Game::Player::addTower(std::shared_ptr<Game::Tower::ITower> &tower)
{
    _towers.push_back(tower);
}

void Game::Player::sellTower(std::shared_ptr<Game::Tower::ITower> &tower)
{
    _towers.erase(std::remove(_towers.begin(), _towers.end(), tower), _towers.end());
}
