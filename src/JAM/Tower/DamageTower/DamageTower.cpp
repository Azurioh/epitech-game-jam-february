/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** DamageTower
*/

#include "DamageTower.hh"

Game::Tower::DamageTower::DamageTower(std::tuple<std::size_t, std::size_t> position):
    ATower(position, 85, 30, 5, 2)
{
    std::vector<std::tuple<unsigned int, unsigned int>> rangeSkillPricing = {{40, 5}, {60, 5}, {100, 5}};
    std::vector<std::tuple<unsigned int, unsigned int>> damageSkillPricing = {{70, 5}, {250, 10}, {500, 20}};
    std::vector<std::tuple<unsigned int, unsigned int>> attackSpeedSkillPricing = {{40, 2}, {60, 5}, {100, 10}};

    setRangeSkillPricing(rangeSkillPricing);
    setDamageSkillPricing(damageSkillPricing);
    setAttackSpeedSkillPricing(attackSpeedSkillPricing);
}

Game::Tower::DamageTower::~DamageTower()
{
}

std::unique_ptr<Game::Projectile::IProjectile> Game::Tower::DamageTower::createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed)
{
    return Game::Projectile::ProjectileFactory::createArrow(towerPos, target, speed);
}