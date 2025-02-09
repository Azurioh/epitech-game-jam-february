/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** CloseRangeTower
*/

#include "CloseRangeTower.hh"

Game::Tower::CloseRangeTower::CloseRangeTower(std::tuple<std::size_t, std::size_t> position):
    ATower(position, 140, 130, 10, 35)
{
    Image towerImage = LoadImage("asset/towers/close.png");
    std::vector<std::tuple<unsigned int, unsigned int>> rangeSkillPricing = {{100, 20}, {250, 20}, {350, 20}};
    std::vector<std::tuple<unsigned int, unsigned int>> damageSkillPricing = {{120, 5}, {275, 5}, {400, 10}};
    std::vector<std::tuple<unsigned int, unsigned int>> attackSpeedSkillPricing = {{150, 20}, {250, 20}, {450, 20}};

    _towerTexture = LoadTextureFromImage(towerImage);
    _displayHitbox = false;
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
