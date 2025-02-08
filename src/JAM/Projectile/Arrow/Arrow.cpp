/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Arrow
*/

#include "Arrow.hh"

Game::Projectile::Arrow::Arrow(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed):
    Game::Projectile::AProjectile(towerPos, target, speed)
{
    Image arrowImg = LoadImage("asset/projectiles/arrow.png");
	_arrowTexture = LoadTextureFromImage(arrowImg);
}

Game::Projectile::Arrow::~Arrow()
{
    UnloadTexture(_arrowTexture);
}
