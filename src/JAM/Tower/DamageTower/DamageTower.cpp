/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** DamageTower
*/

#include "DamageTower.hh"

Game::Tower::DamageTower::DamageTower(std::tuple<std::size_t, std::size_t> position):
    ATower(position, 150, 110, 8, 15)
{
    Image towerImage = LoadImage("asset/towers/damage.png");
    std::vector<std::tuple<unsigned int, unsigned int>> rangeSkillPricing = {{120, 20}, {240, 20}, {350, 25}};
    std::vector<std::tuple<unsigned int, unsigned int>> damageSkillPricing = {{140, 10}, {250, 10}, {500, 20}};
    std::vector<std::tuple<unsigned int, unsigned int>> attackSpeedSkillPricing = {{150, 5}, {300, 5}, {450, 5}};

    _towerTexture = LoadTextureFromImage(towerImage);
    _displayHitbox = false;
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
