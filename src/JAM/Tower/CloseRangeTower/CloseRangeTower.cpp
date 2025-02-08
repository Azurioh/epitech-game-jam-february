/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** CloseRangeTower
*/

#include "CloseRangeTower.hh"

Game::Tower::CloseRangeTower::CloseRangeTower(std::tuple<std::size_t, std::size_t> position):
    ATower(position, 65, 25, 5, 2)
{
    std::vector<std::tuple<unsigned int, unsigned int>> rangeSkillPricing = {{40, 5}, {80, 5}, {100, 5}};
    std::vector<std::tuple<unsigned int, unsigned int>> damageSkillPricing = {{50, 5}, {125, 10}, {250, 20}};
    std::vector<std::tuple<unsigned int, unsigned int>> attackSpeedSkillPricing = {{150, 2}, {350, 5}, {650, 10}};

    setRangeSkillPricing(rangeSkillPricing);
    setDamageSkillPricing(damageSkillPricing);
    setAttackSpeedSkillPricing(attackSpeedSkillPricing);
}

Game::Tower::CloseRangeTower::~CloseRangeTower()
{
}

std::unique_ptr<Game::Projectile::IProjectile> Game::Tower::CloseRangeTower::createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed)
{
    return Game::Projectile::ProjectileFactory::createArrow(towerPos, target, speed);
}