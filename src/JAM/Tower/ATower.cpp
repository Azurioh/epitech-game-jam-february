/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** ATower
*/

#include "ATower.hh"

Game::Tower::ATower::ATower(std::tuple<std::size_t, std::size_t> position,
    unsigned int cost,
    unsigned int range,
    unsigned int damage,
    unsigned int attackSpeed):
    _position(position), _cost(cost), _range(range), _damage(damage), _attackSpeed(attackSpeed),
    _rangeSkill(0), _damageSkill(0), _attackSpeedSkill(0), _target(nullptr), _projectile(nullptr)
{
}

Game::Tower::ATower::~ATower()
{
}

void Game::Tower::ATower::draw(void) const
{
    std::size_t posX = std::get<0>(_position);
    std::size_t posY = std::get<1>(_position);

    if (_displayHitbox) {
        DrawCircle(posX, posY, _range, {255, 255, 255, 50});
    }
    if (_projectile && _projectile.get() != nullptr) {
        _projectile->draw();
        if (_projectile->getAttackStatus() == Game::Projectile::IProjectile::TRACKING) {
            _projectile->move();
        }
    }
    DrawTexturePro(
		_towerTexture,
		(Rectangle) {0, 0, (float)_towerTexture.width, (float)_towerTexture.height},
		(Rectangle) {(float)posX, (float)posY, (float)_towerTexture.width, (float)_towerTexture.height},
		(Vector2) {((float)_towerTexture.width) / 2, ((float)_towerTexture.height) / 2},
		0, WHITE
	);
    return;
}

std::tuple<std::size_t, std::size_t> Game::Tower::ATower::getPosition(void) const
{
	return _position;
}

unsigned int Game::Tower::ATower::getCost(void) const
{
    return _cost;
}

unsigned int Game::Tower::ATower::getRangeSkill(void) const
{
	return _rangeSkill;
}

unsigned int Game::Tower::ATower::getDamageSkill(void) const
{
	return _damageSkill;
}

unsigned int Game::Tower::ATower::getAttackSpeedSkill(void) const
{
	return _attackSpeedSkill;
}


std::shared_ptr<Game::Mob::IMob> Game::Tower::ATower::getMobToAttack(std::vector<std::shared_ptr<Game::Mob::IMob>> mobs)
{
    std::shared_ptr<Game::Mob::IMob> mobToAttack = nullptr;

    if (mobs.size() == 0) {
        return mobToAttack;
    }
    if (_projectile && _projectile->getAttackStatus() == Game::Projectile::IProjectile::TRACKING) {
        return _target;
    }
    for (auto it = mobs.begin(); it != mobs.end(); it++) {
        if (!_mobIsInRange((*it).get()) || !(*it)->isVisible()) {
            continue;
        }
        if (!mobToAttack && (*it)->isVisible()) {
            mobToAttack = *it;
            continue;
        }
        if (mobToAttack && _mobIsClosest((*it).get(), mobToAttack.get())) {
            mobToAttack = *it;
        }
    }
    _target = mobToAttack;
    return mobToAttack;
}

std::shared_ptr<Game::Mob::IMob> Game::Tower::ATower::getTarget(void)
{
    return _target;
}

void Game::Tower::ATower::toggleHitboxDisplay(void)
{
    _displayHitbox = !_displayHitbox;
}

void Game::Tower::ATower::setPosition(std::tuple<std::size_t, std::size_t> pos)
{
	_position = pos;
}

void Game::Tower::ATower::setCost(unsigned int cost)
{
    _cost = cost;
}

void Game::Tower::ATower::attack(void)
{
    Game::Projectile::IProjectile::AttackResultType attackType;

    if (!_target) {
        return;
    }
    if (!_projectile || _projectile.get() == nullptr) {
        _projectile = std::move(createProjectile(_position, _target, _attackSpeed));
        return;
    }
    attackType = _projectile->getAttackStatus();
    if (attackType == Game::Projectile::IProjectile::TRACKING) {
        return;
    }
    _target->takeDamage(_damage);
    _projectile.reset();
}

std::shared_ptr<Game::Projectile::IProjectile> Game::Tower::ATower::getProjectile(void)
{
    return _projectile;
}

void Game::Tower::ATower::setRangeSkill(unsigned int value)
{
	_rangeSkill = value;
}

void Game::Tower::ATower::setDamageSkill(unsigned int value)
{
	_damageSkill = value;
}

void Game::Tower::ATower::setAttackSpeedSkill(unsigned int value)
{
	_attackSpeedSkill = value;
}

void Game::Tower::ATower::setRangeSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices)
{
    _rangeSkillPricing = prices;
}

void Game::Tower::ATower::setDamageSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices)
{
    _damageSkillPricing = prices;
}

void Game::Tower::ATower::setAttackSpeedSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices)
{
    _attackSpeedSkillPricing = prices;
}

int Game::Tower::ATower::getNextRangeSkillPricing(void) const
{
    if (_rangeSkill == 3) {
        return -1;
    }
    return std::get<0>(_rangeSkillPricing[_rangeSkill]);
}

int Game::Tower::ATower::getNextDamageSkillPricing(void) const
{
    if (_damageSkill == 3) {
        return -1;
    }
    return std::get<0>(_damageSkillPricing[_damageSkill]);
}

int Game::Tower::ATower::getNextAttackSpeedSkillPricing(void) const
{
    if (_attackSpeedSkill == 3) {
        return -1;
    }
    return std::get<0>(_attackSpeedSkillPricing[_attackSpeedSkill]);
}

void Game::Tower::ATower::upgradeRangeSkill(void)
{
    _rangeSkill++;
    _range += std::get<1>(_rangeSkillPricing[_rangeSkill - 1]);
}

void Game::Tower::ATower::upgradeDamageSkill(void)
{
    _damageSkill++;
    _damage += std::get<1>(_damageSkillPricing[_damageSkill - 1]);
}

void Game::Tower::ATower::upgradeAttackSpeedSkill(void)
{
    _attackSpeedSkill++;
    _attackSpeed += std::get<1>(_attackSpeedSkillPricing[_attackSpeedSkill - 1]);
}

bool Game::Tower::ATower::_mobIsClosest(Game::Mob::IMob *mob1, Game::Mob::IMob *mob2)
{
    int posX = std::get<0>(_position);
    int posY = std::get<1>(_position);
    int posMob1X = mob1->getPosition().x;
    int posMob1Y = mob1->getPosition().y;
    int posMob2X = mob2->getPosition().x;
    int posMob2Y = mob2->getPosition().y;

    int distance1x = posMob1X - posX;
    int distance1y = posMob1Y - posY;
    int distance2x = posMob2X - posX;
    int distance2y = posMob2Y - posY;
    float distance1 = std::sqrt(std::pow(distance1x, 2) + std::pow(distance1y, 2));
    float distance2 = std::sqrt(std::pow(distance2x, 2) + std::pow(distance2y, 2));

    if (distance1 < distance2) {
        return true;
    } else {
        return false;
    }
}

bool Game::Tower::ATower::_mobIsInRange(Game::Mob::IMob *mob)
{
    Vector2 mobPos = mob->getPosition();
    float distance = std::sqrt(std::pow(mobPos.x - std::get<0>(_position), 2) + std::pow(mobPos.y - std::get<1>(_position), 2));

    return distance <= _range;
}
