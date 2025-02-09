/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** LongRangeTower
*/

#include "LongRangeTower.hh"

Game::Tower::LongRangeTower::LongRangeTower(std::tuple<std::size_t, std::size_t> position):
    ATower(position, 130, 200, 15, 20)
{
    Image towerImage = LoadImage("asset/towers/long.png");
    std::vector<std::tuple<unsigned int, unsigned int>> rangeSkillPricing = {{100, 30}, {200, 30}, {500, 30}};
    std::vector<std::tuple<unsigned int, unsigned int>> damageSkillPricing = {{150, 8}, {300, 10}, {500, 15}};
    std::vector<std::tuple<unsigned int, unsigned int>> attackSpeedSkillPricing = {{180, 15}, {300, 10}, {450, 10}};

    _towerTexture = LoadTextureFromImage(towerImage);
    _displayHitbox = false;
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
