/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** FakeTower
*/

#include "FakeTower.hh"

Game::Tower::FakeTower::FakeTower(std::tuple<std::size_t, std::size_t> position):
    ATower(position, 800, 5, 1, 1)
{
    Image towerImage = LoadImage("asset/towers/fake.png");
    std::vector<std::tuple<unsigned int, unsigned int>> rangeSkillPricing = {{100, 1}, {300, 1}, {600, 1}};
    std::vector<std::tuple<unsigned int, unsigned int>> damageSkillPricing = {{200, 2}, {500, 3}, {1000, 3}};
    std::vector<std::tuple<unsigned int, unsigned int>> attackSpeedSkillPricing = {{250, 1}, {550, 1}, {1100, 1}};

    _towerTexture = LoadTextureFromImage(towerImage);
    _displayHitbox = true;
    setRangeSkillPricing(rangeSkillPricing);
    setDamageSkillPricing(damageSkillPricing);
    setAttackSpeedSkillPricing(attackSpeedSkillPricing);
}

Game::Tower::FakeTower::~FakeTower()
{
    UnloadTexture(_towerTexture);
}

std::unique_ptr<Game::Projectile::IProjectile> Game::Tower::FakeTower::createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed)
{
    return Game::Projectile::ProjectileFactory::createArrow(towerPos, target, speed);
}
