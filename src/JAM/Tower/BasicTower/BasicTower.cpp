/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** BasicTower
*/

#include "BasicTower.hh"

Game::Tower::BasicTower::BasicTower(std::tuple<std::size_t, std::size_t> position):
    ATower(position, 25, 10, 5, 2)
{
    std::vector<std::tuple<unsigned int, unsigned int>> rangeSkillPricing = {{50, 5}, {100, 5}, {150, 5}};
    std::vector<std::tuple<unsigned int, unsigned int>> damageSkillPricing = {{50, 5}, {150, 10}, {300, 20}};
    std::vector<std::tuple<unsigned int, unsigned int>> attackSpeedSkillPricing = {{100, 2}, {200, 5}, {500, 10}};

    setRangeSkillPricing(rangeSkillPricing);
    setDamageSkillPricing(damageSkillPricing);
    setAttackSpeedSkillPricing(attackSpeedSkillPricing);
}

Game::Tower::BasicTower::~BasicTower()
{
}

std::unique_ptr<Game::Projectile::IProjectile> Game::Tower::BasicTower::createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed)
{
    return Game::Projectile::ProjectileFactory::createArrow(towerPos, target, speed);
}
