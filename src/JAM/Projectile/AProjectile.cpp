#include "AProjectile.hh"
#include <iostream>

Game::Projectile::AProjectile::AProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed):
	_position(towerPos),
	_target(target),
	_speed(speed),
	_attackStatus(TRACKING)
{
	_angle = _calculAngle();
}

void Game::Projectile::AProjectile::move()
{
	int x1 = std::get<0>(_position);
    int y1 = std::get<1>(_position);
    int x2 = _target->getPosition().x;
    int y2 = _target->getPosition().y;
    int dx = x2 - x1;
    int dy = y2 - y1;
    float distance = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
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
    if (distance <= _speed + 3 || distance == 0) {
		_attackStatus = HIT;
		return;
    }
    _position = std::make_tuple(newX, newY);
	_angle = _calculAngle();
}

void Game::Projectile::AProjectile::draw(void) const
{
	float posX = std::get<0>(_position);
	float posY = std::get<1>(_position);
	DrawTexturePro(_arrowTexture, {0, 0,
		(float)_arrowTexture.width, (float)_arrowTexture.height},
		{posX, posY, 25, 25},
		{25, 12.5}, _angle, WHITE);
}

std::shared_ptr<Game::Mob::IMob>Game::Projectile::AProjectile::getTarget(void) const
{
	return _target;
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

void Game::Projectile::AProjectile::setTarget(std::shared_ptr<Game::Mob::IMob> target)
{
	_target = target;
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
    int x2 = _target->getPosition().x;
    int y2 = _target->getPosition().y;

    double deltaX = static_cast<double>(x2 - x1);
    double deltaY = static_cast<double>(y2 - y1);

    double angleRad = std::atan2(deltaY, deltaX);
    double angleDeg = angleRad * (180.0 / PI);

    return static_cast<float>(angleDeg);
}
