/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** ATower
*/

#include "ATower.hh"

Game::Tower::ATower::ATower(std::tuple<std::size_t, std::size_t> position,
    unsigned int cost,
    unsigned int range,
    unsigned int damage,
    unsigned int attackSpeed):
    _position(position), _cost(cost), _range(range), _damage(damage), _attackSpeed(attackSpeed),
    _rangeSkill(0), _damageSkill(0), _attackSpeedSkill(0), _attackType(FIRST)
{
}

Game::Tower::ATower::~ATower()
{
}


std::tuple<std::size_t, std::size_t> Game::Tower::ATower::getPosition(void) const
{
	return _position;
}

unsigned int Game::Tower::ATower::getRangeSkill(void) const
{
	return _rangeSkill;
}

unsigned int Game::Tower::ATower::getDamageSkill(void) const
{
	return _damageSkill;
}

unsigned int Game::Tower::ATower::getAttackSpeedSkill(void) const
{
	return _attackSpeedSkill;
}

Game::Tower::ITower::AttackType Game::Tower::ATower::getAttackType(void) const
{
	return _attackType;
}

void Game::Tower::ATower::setPosition(std::tuple<std::size_t, std::size_t> pos)
{
	_position = pos;
}

void Game::Tower::ATower::setCost(unsigned int cost)
{
    _cost = cost;
}

void Game::Tower::ATower::attack(void)
{
    return;
}

void Game::Tower::ATower::changeAttackType(void)
{
    _attackType = _attackType == FIRST ? CLOSEST : FIRST;
}

void Game::Tower::ATower::setRangeSkill(unsigned int value)
{
	_rangeSkill = value;
}

void Game::Tower::ATower::setDamageSkill(unsigned int value)
{
	_damageSkill = value;
}

void Game::Tower::ATower::setAttackSpeedSkill(unsigned int value)
{
	_attackSpeedSkill = value;
}

void Game::Tower::ATower::setAttackType(AttackType type)
{
	_attackType = type;
}

void Game::Tower::ATower::setRangeSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices)
{
    _rangeSkillPricing = prices;
}

void Game::Tower::ATower::setDamageSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices)
{
    _damageSkillPricing = prices;
}

void Game::Tower::ATower::setAttackSpeedSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices)
{
    _attackSpeedSkillPricing = prices;
}


