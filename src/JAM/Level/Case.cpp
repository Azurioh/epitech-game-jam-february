/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Case
*/

#include "Case.hpp"

Case::Case(CaseType type, int value):
    _type(type), _value(value)
{
	if (type == UNKNOWN) {
		return;
	}
	if (type == PATH) {
		_texture = LoadTexture("asset/map/Path.png");
	} else {
		_texture = LoadTexture("asset/map/Ground.png");
	}
}

Case::~Case()
{
	if (_type == UNKNOWN) {
		return;
	}
	UnloadTexture(_texture);
}

unsigned char Case::getValue()
{
	return _value;
}

void Case::setValue(unsigned char value)
{
	_value = value;
}

Texture2D Case::getTexture()
{
	return _texture;
}

Vector2 Case::getPosition()
{
	return _position;
}

void Case::drawCase(float scale, Vector2 pos)
{
	_position = pos;
	DrawTexturePro(
		_texture,
		(Rectangle) {0, 0, (float)_texture.width, (float)_texture.height},
		(Rectangle) {pos.x, pos.y, (float)_texture.width * scale, (float)_texture.height * scale},
		(Vector2) {((float)_texture.width * scale) / 2, ((float)_texture.width * scale) / 2},
		0, WHITE
	);
}
