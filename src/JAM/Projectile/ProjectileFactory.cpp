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

std::unique_ptr<Game::Projectile::IProjectile> Game::Projectile::ProjectileFactory::createArrow(std::tuple<unsigned int, unsigned int> position, std::tuple<unsigned int, unsigned int> targetPosition, float speed)
{
    return std::unique_ptr<Game::Projectile::Arrow>(new Game::Projectile::Arrow(position, targetPosition, speed));
}
