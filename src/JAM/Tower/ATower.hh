/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** ATower
*/

#pragma once

#include <raylib.h>
#include "ITower.hh"
#include "../Projectile/ProjectileFactory.hh"
#include <vector>
#include <cmath>
#include <tuple>

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
                std::shared_ptr<Game::Mob::IMob> getMobToAttack(std::vector<std::shared_ptr<Game::Mob::IMob>> mobs);
                std::shared_ptr<Game::Mob::IMob> getTarget(void);
                void toggleHitboxDisplay(void);
                bool isDisplayingHitbox(void);

                void setPosition(std::tuple<std::size_t, std::size_t> pos);
                void setCost(unsigned int cost);

                int attack(void);
                std::shared_ptr<Game::Projectile::IProjectile> getProjectile(void);
                virtual std::unique_ptr<Game::Projectile::IProjectile> createProjectile(std::tuple<std::size_t, std::size_t> towerPos, std::shared_ptr<Game::Mob::IMob> target, unsigned int speed) = 0;

                void setRangeSkill(unsigned int value);
                void setDamageSkill(unsigned int value);
                void setAttackSpeedSkill(unsigned int value);

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
                bool _displayHitbox;
                Texture2D _towerTexture;

                unsigned int _range;
                unsigned int _damage;
                unsigned int _attackSpeed;

                unsigned int _rangeSkill;
                unsigned int _damageSkill;
                unsigned int _attackSpeedSkill;
                std::vector<std::tuple<unsigned int, unsigned int>> _rangeSkillPricing;
                std::vector<std::tuple<unsigned int, unsigned int>> _damageSkillPricing;
                std::vector<std::tuple<unsigned int, unsigned int>> _attackSpeedSkillPricing;

                std::shared_ptr<Game::Mob::IMob> _target;
                std::shared_ptr<Game::Projectile::IProjectile> _projectile;

                bool _mobIsClosest(Game::Mob::IMob *mob1, Game::Mob::IMob *mob2);
                bool _mobIsInRange(Game::Mob::IMob *mob);

        };
    }
}

