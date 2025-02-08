/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** LongRangeTower
*/

#include "LongRangeTower.hh"

Game::Tower::LongRangeTower::LongRangeTower(std::tuple<std::size_t, std::size_t> position):
    ATower(position, 45, 15, 5, 2)
{
    std::vector<std::tuple<unsigned int, unsigned int>> rangeSkillPricing = {{80, 5}, {130, 5}, {180, 5}};
    std::vector<std::tuple<unsigned int, unsigned int>> damageSkillPricing = {{50, 5}, {120, 10}, {250, 20}};
    std::vector<std::tuple<unsigned int, unsigned int>> attackSpeedSkillPricing = {{80, 2}, {150, 5}, {350, 10}};

    setRangeSkillPricing(rangeSkillPricing);
    setDamageSkillPricing(damageSkillPricing);
    setAttackSpeedSkillPricing(attackSpeedSkillPricing);
}

Game::Tower::LongRangeTower::~LongRangeTower()
{
}

std::unique_ptr<Game::Projectile::IProjectile> Game::Tower::LongRangeTower::createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed)
{
    return Game::Projectile::ProjectileFactory::createArrow(towerPos, target, speed);
}