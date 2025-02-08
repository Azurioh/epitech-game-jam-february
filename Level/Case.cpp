/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Case
*/

#include "Case.hpp"

Case::Case(CaseType type, int value):
    _type(type), _value(value)
{}

Case::~Case()
{}

unsigned char Case::getValue()
{
	return _value;
}

void Case::setValue(unsigned char value)
{
	_value = value;
}
