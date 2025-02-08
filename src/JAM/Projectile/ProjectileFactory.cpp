/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** ProjectileFactory
*/

#include "ProjectileFactory.hh"
#include "Arrow/Arrow.hh"

Game::Projectile::ProjectileFactory::ProjectileFactory()
{
}

Game::Projectile::ProjectileFactory::~ProjectileFactory()
{
}

std::unique_ptr<Game::Projectile::IProjectile> Game::Projectile::ProjectileFactory::createArrow(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed)
{
    return std::unique_ptr<Game::Projectile::Arrow>(new Game::Projectile::Arrow(towerPos, target, speed));
}
