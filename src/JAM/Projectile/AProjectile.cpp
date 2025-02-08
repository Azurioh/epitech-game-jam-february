#include "AProjectile.hh"

Game::Projectile::AProjectile::AProjectile(std::tuple<unsigned int, unsigned int> position, std::tuple<unsigned int, unsigned int> targetPosition, float speed):
	_position(position),
	_targetPosition(targetPosition),
	_speed(speed),
	_targetDestroyed(false)
{
	_angle = _calculAngle();
}

void Game::Projectile::AProjectile::move(std::tuple<unsigned int, unsigned int> const direction)
{
	(void) direction;
	return;
}

void Game::Projectile::AProjectile::draw(void) const
{
	return;
}

std::tuple<unsigned int, unsigned int> Game::Projectile::AProjectile::getTargetPosition(void) const
{
	return _targetPosition;
}

std::tuple<unsigned int, unsigned int> Game::Projectile::AProjectile::getPosition(void) const
{
	return _position;
}

float Game::Projectile::AProjectile::getAngle(void) const
{
	return _angle;
}

float Game::Projectile::AProjectile::getSpeed(void) const
{
	return _speed;
}

bool Game::Projectile::AProjectile::isTargetDestroyed(void) const
{
	return _targetDestroyed;
}

void Game::Projectile::AProjectile::setTargetPosition(std::tuple<unsigned int, unsigned int> position)
{
	_targetPosition = position;
}

void Game::Projectile::AProjectile::setPosition(std::tuple<unsigned int, unsigned int> position)
{
	_position = position;
}

void Game::Projectile::AProjectile::setAngle(float angle)
{
	_angle = angle;
}

void Game::Projectile::AProjectile::setSpeed(float speed)
{
	_speed = speed;
}

void Game::Projectile::AProjectile::setTargetDestroyed(bool destroyed)
{
	_targetDestroyed = destroyed;
}

float Game::Projectile::AProjectile::_calculAngle(void) const
{
	int x1 = std::get<0>(_position);
    int y1 = std::get<1>(_position);
    int x2 = std::get<0>(_targetPosition);
    int y2 = std::get<1>(_targetPosition);

    double deltaX = static_cast<float>(x2) - static_cast<float>(x1);
    double deltaY = static_cast<float>(y2) - static_cast<float>(y1);

    return std::atan2(deltaY, deltaX);
}
