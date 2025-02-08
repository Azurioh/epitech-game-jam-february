#include "AProjectile.hh"
#include <iostream>

Game::Projectile::AProjectile::AProjectile(std::tuple<unsigned int, unsigned int> position, std::tuple<unsigned int, unsigned int> targetPosition, float speed):
	_position(position),
	_targetPosition(targetPosition),
	_speed(speed),
	_attackStatus(TRACKING)
{
	_angle = _calculAngle();
}

void Game::Projectile::AProjectile::move()
{
	int x1 = std::get<0>(_position);
    int y1 = std::get<1>(_position);
    int x2 = std::get<0>(_targetPosition);
    int y2 = std::get<1>(_targetPosition);
    int dx = x2 - x1;
    int dy = y2 - y1;
    float distance = std::sqrt(dx * dx + dy * dy);
	float ratio = _speed / distance;
	int newX = x1 + dx * ratio;
    int newY = y1 + dy * ratio;

	if (y1 + dy * ratio > 0 && y1 + dy * ratio < 1) {
		newY = 1;
	}

	if (x2 < 0 || y2 < 0 || x2 > GetScreenWidth() || y2 > GetScreenHeight()) {
		_attackStatus = MISSED;
		return;
	}
    if (distance <= _speed || distance == 0) {
		_attackStatus = HIT;
		return;
    }
    _position = std::make_tuple(newX, newY);
	_targetPosition = std::make_tuple(x2 + 3, y2);
	_angle = _calculAngle();
}

void Game::Projectile::AProjectile::draw(void) const
{
	float posX = std::get<0>(_position);
	float posY = std::get<1>(_position);
	DrawTexturePro(_arrowTexture, {0, 0,
		(float)_arrowTexture.width, (float)_arrowTexture.height},
		{posX, posY, 100, 100},
		{0, 0}, _angle, WHITE);
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

Game::Projectile::IProjectile::AttackResultType Game::Projectile::AProjectile::getAttackStatus(void) const
{
	return _attackStatus;
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

float Game::Projectile::AProjectile::_calculAngle(void) const
{
	int x1 = std::get<0>(_position);
    int y1 = std::get<1>(_position);
    int x2 = std::get<0>(_targetPosition);
    int y2 = std::get<1>(_targetPosition);

    double deltaX = static_cast<double>(x2 - x1);
    double deltaY = static_cast<double>(y2 - y1);

    double angleRad = std::atan2(deltaY, deltaX);
    double angleDeg = angleRad * (180.0 / PI);

	std::cout << "NEW ANGLE: " << angleDeg << std::endl;

    return static_cast<float>(angleDeg);
}
