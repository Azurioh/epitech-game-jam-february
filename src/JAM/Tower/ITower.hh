/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** ITower
*/

#pragma once

#include <tuple>
#include <memory>
#include "../Projectile/IProjectile.hh"
#include "../Mob/IMob.hh"

namespace Game {
    namespace Tower {
        class ITower {
            public:
                ITower() {};
                virtual ~ITower() = default;

                enum AttackType {
                    FIRST,
                    CLOSEST,
                };

                virtual void draw() const = 0;

                virtual std::tuple<std::size_t, std::size_t> getPosition(void) const = 0;
                virtual unsigned int getCost(void) const = 0;

                virtual Game::Projectile::IProjectile::AttackResultType attack(void) = 0;
                virtual std::shared_ptr<Game::Projectile::IProjectile> getProjectile(void) = 0;
                virtual void changeAttackType(void) = 0;
                virtual std::shared_ptr<Game::Mob::IMob> getMobToAttack(std::vector<std::shared_ptr<Game::Mob::IMob>> mobs) = 0;
                virtual std::shared_ptr<Game::Mob::IMob> getTarget(void) = 0;

                virtual int getNextRangeSkillPricing(void) const = 0;
                virtual int getNextDamageSkillPricing(void) const = 0;
                virtual int getNextAttackSpeedSkillPricing(void) const = 0;

                virtual void upgradeRangeSkill(void) = 0;
                virtual void upgradeDamageSkill(void) = 0;
                virtual void upgradeAttackSpeedSkill(void) = 0;
        };
    }
}
