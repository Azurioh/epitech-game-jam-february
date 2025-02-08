/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** SceneFactory
*/

#include "LevelsMenu.hpp"

LevelsPage::LevelsPage() : _selectedLevel(-1), _backgroundColor(LIME)
{
    LoadLevels();
    _backButtonArea = {10, 10, 100, 40};
}

LevelsPage::~LevelsPage()
{
    for (auto& level : _levels) {
        UnloadTexture(level.image);
    }
}

void LevelsPage::LoadLevels()
{
    for (size_t i = 0; i < _levelNames.size(); ++i) {
        _levels.push_back({
            _levelNames[i],
            LoadTexture("asset/levels/default-featured-image.jpg"),
            _levelAreas[i],
            {1.0f, 1.0f}
        });
    }

    for (auto& level : _levels) {
        level.SetTextureScale(0.7f, 0.7f);
    }
}

void LevelsPage::Draw()
{
    ClearBackground(_backgroundColor);

    DrawRectangleRec(_backButtonArea, DARKGRAY);
    DrawText("Retour", _backButtonArea.x + 10, _backButtonArea.y + 10, 20, WHITE);

    for (Level &level : _levels) {
        level.Draw();

        if (&level == &_levels[_selectedLevel]) {
            DrawRectangleLines(level.area.x, level.area.y, level.area.width, level.area.height, RED);
        }
    }
}

void LevelsPage::Update()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(mousePos, _backButtonArea)) {
            // mettre le moyen de retour ici
        }

        for (size_t i = 0; i < _levels.size(); ++i) {
            if (CheckCollisionPointRec(mousePos, _levels[i].area)) {
                _selectedLevel = i;
            }
        }
    }
}

int LevelsPage::GetSelectedLevel() const
{
    return _selectedLevel;
}

bool LevelsPage::BackButtonPressed() const
{
    Vector2 mousePos = GetMousePosition();
    return CheckCollisionPointRec(mousePos, _backButtonArea) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void Level::SetTextureScale(float x, float y)
{
    scale = {x, y};
}

void Level::Draw() const
{
    DrawTextureEx(image, {area.x, area.y}, 0.0f, scale.x, WHITE);
    DrawText(name.c_str(), area.x + 10, area.y + area.height + 10, 20, BLACK);
}
