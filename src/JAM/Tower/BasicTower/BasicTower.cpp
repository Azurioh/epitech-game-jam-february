/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** BasicTower
*/

#include "BasicTower.hh"

Game::Tower::BasicTower::BasicTower(std::tuple<std::size_t, std::size_t> position):
    ATower(position, 100, 130, 5, 10)
{
    Image towerImage = LoadImage("asset/towers/basic.png");
    std::vector<std::tuple<unsigned int, unsigned int>> rangeSkillPricing = {{100, 20}, {200, 30}, {300, 40}};
    std::vector<std::tuple<unsigned int, unsigned int>> damageSkillPricing = {{100, 5}, {180, 5}, {300, 10}};
    std::vector<std::tuple<unsigned int, unsigned int>> attackSpeedSkillPricing = {{100, 2}, {200, 5}, {400, 5}};

    _towerTexture = LoadTextureFromImage(towerImage);
    _displayHitbox = false;
    setRangeSkillPricing(rangeSkillPricing);
    setDamageSkillPricing(damageSkillPricing);
    setAttackSpeedSkillPricing(attackSpeedSkillPricing);
}

Game::Tower::BasicTower::~BasicTower()
{
    UnloadTexture(_towerTexture);
}

std::unique_ptr<Game::Projectile::IProjectile> Game::Tower::BasicTower::createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed)
{
    return Game::Projectile::ProjectileFactory::createArrow(towerPos, target, speed);
}
