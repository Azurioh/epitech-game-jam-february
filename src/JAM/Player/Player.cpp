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

void Game::Player::addTower(std::shared_ptr<Game::Tower::ITower> tower)
{
    _towers.push_back(tower);
}

void Game::Player::sellTower(std::shared_ptr<Game::Tower::ITower> tower)
{
    _towers.erase(std::remove(_towers.begin(), _towers.end(), tower), _towers.end());
}

void Game::Player::attack(std::vector<std::shared_ptr<Game::Mob::IMob>> mobs)
{
    std::shared_ptr<Game::Mob::IMob> destroyedMob;

    for (auto it = _towers.begin(); it != _towers.end(); it++) {
        (*it)->attack();
        (*it)->getMobToAttack(mobs);
    }
}

bool Game::Player::upgradeTowerRange(std::shared_ptr<Game::Tower::ITower> tower)
{
    int pricing = tower->getNextRangeSkillPricing();

    if (pricing == -1 || _golds < static_cast<unsigned int>(pricing)) {
        return false;
    }
    tower->upgradeRangeSkill();
    _golds -= pricing;
    return true;
}

bool Game::Player::upgradeTowerDamage(std::shared_ptr<Game::Tower::ITower> tower)
{
    int pricing = tower->getNextDamageSkillPricing();

    if (pricing == -1 || _golds < static_cast<unsigned int>(pricing)) {
        return false;
    }
    tower->upgradeDamageSkill();
    _golds -= pricing;
    return true;
}

bool Game::Player::upgradeTowerAttackSpeed(std::shared_ptr<Game::Tower::ITower> tower)
{
    int pricing = tower->getNextAttackSpeedSkillPricing();

    if (pricing == -1 || _golds < static_cast<unsigned int>(pricing)) {
        return false;
    }
    tower->upgradeAttackSpeedSkill();
    _golds -= pricing;
    return true;
}
