/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** CloseRangeTower
*/

#include "CloseRangeTower.hh"

Game::Tower::CloseRangeTower::CloseRangeTower(std::tuple<std::size_t, std::size_t> position):
    ATower(position, 140, 25, 4, 5)
{
    std::vector<std::tuple<unsigned int, unsigned int>> rangeSkillPricing = {{100, 2}, {250, 3}, {350, 5}};
    std::vector<std::tuple<unsigned int, unsigned int>> damageSkillPricing = {{120, 3}, {275, 5}, {400, 10}};
    std::vector<std::tuple<unsigned int, unsigned int>> attackSpeedSkillPricing = {{150, 3}, {250, 5}, {450, 10}};

    setRangeSkillPricing(rangeSkillPricing);
    setDamageSkillPricing(damageSkillPricing);
    setAttackSpeedSkillPricing(attackSpeedSkillPricing);
}

Game::Tower::CloseRangeTower::~CloseRangeTower()
{
    UnloadTexture(_towerTexture);
}

std::unique_ptr<Game::Projectile::IProjectile> Game::Tower::CloseRangeTower::createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed)
{
    return Game::Projectile::ProjectileFactory::createArrow(towerPos, target, speed);
}