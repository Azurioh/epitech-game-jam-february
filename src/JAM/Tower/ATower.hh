/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** ATower
*/

#pragma once

#include "ITower.hh"
#include "../Projectile/ProjectileFactory.hh"
#include <vector>
#include <cmath>

namespace Game {
    namespace Tower {
        class ATower : public ITower {
            public:
                ATower(std::tuple<std::size_t, std::size_t> position,
                    unsigned int cost,
                    unsigned int range,
                    unsigned int damageSkill,
                    unsigned int attackSpeed);
                ~ATower();

                void draw(void) const;

                std::tuple<std::size_t, std::size_t> getPosition(void) const;
                unsigned int getCost(void) const;
                unsigned int getRangeSkill(void) const;
                unsigned int getDamageSkill(void) const;
                unsigned int getAttackSpeedSkill(void) const;
                AttackType getAttackType(void) const;
                std::shared_ptr<Game::Mob::IMob> getMobToAttack(std::vector<std::shared_ptr<Game::Mob::IMob>> mobs);

                void setPosition(std::tuple<std::size_t, std::size_t> pos);
                void setCost(unsigned int cost);

                Game::Projectile::IProjectile::AttackResultType attack(void);
                void changeAttackType(void);
                virtual std::unique_ptr<Game::Projectile::IProjectile> createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed) = 0;

                void setRangeSkill(unsigned int value);
                void setDamageSkill(unsigned int value);
                void setAttackSpeedSkill(unsigned int value);
                void setAttackType(AttackType type);

                void setRangeSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices);
                void setDamageSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices);
                void setAttackSpeedSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices);

                int getNextRangeSkillPricing(void) const;
                int getNextDamageSkillPricing(void) const;
                int getNextAttackSpeedSkillPricing(void) const;

                void upgradeRangeSkill(void);
                void upgradeDamageSkill(void);
                void upgradeAttackSpeedSkill(void);

            protected:
                std::tuple<std::size_t, std::size_t> _position;
                unsigned int _cost;

                unsigned int _range;
                unsigned int _damage;
                unsigned int _attackSpeed;

                unsigned int _rangeSkill;
                unsigned int _damageSkill;
                unsigned int _attackSpeedSkill;
                std::vector<std::tuple<unsigned int, unsigned int>> _rangeSkillPricing;
                std::vector<std::tuple<unsigned int, unsigned int>> _damageSkillPricing;
                std::vector<std::tuple<unsigned int, unsigned int>> _attackSpeedSkillPricing;

                AttackType _attackType;
                std::shared_ptr<Game::Mob::IMob> _target;
                std::unique_ptr<Game::Projectile::IProjectile> _projectile;

                bool _mobIsClosest(Game::Mob::IMob *mob1, Game::Mob::IMob *mob2);

        };
    }
}

