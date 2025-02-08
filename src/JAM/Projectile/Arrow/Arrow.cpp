/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Arrow
*/

#include "Arrow.hh"

Game::Projectile::Arrow::Arrow(std::tuple<unsigned int, unsigned int> position, std::tuple<unsigned int, unsigned int> targetPosition, float speed):
    Game::Projectile::AProjectile(position, targetPosition, speed)
{
}

Game::Projectile::Arrow::~Arrow()
{
}
