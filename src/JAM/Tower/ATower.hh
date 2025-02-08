/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** ATower
*/

#pragma once

#include "ITower.hh"
#include <vector>

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

                std::tuple<std::size_t, std::size_t> getPosition(void) const;
                unsigned int getRangeSkill(void) const;
                unsigned int getDamageSkill(void) const;
                unsigned int getAttackSpeedSkill(void) const;
                AttackType getAttackType(void) const;

                void setPosition(std::tuple<std::size_t, std::size_t> pos);
                void setCost(unsigned int cost);

                void attack(void);
                void changeAttackType(void);

                void setRangeSkill(unsigned int value);
                void setDamageSkill(unsigned int value);
                void setAttackSpeedSkill(unsigned int value);
                void setAttackType(AttackType type);

                void setRangeSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices);
                void setDamageSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices);
                void setAttackSpeedSkillPricing(std::vector<std::tuple<unsigned int, unsigned int>> &prices);

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
        };
    }
}

