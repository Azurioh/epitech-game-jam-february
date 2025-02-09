/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** SceneFactory
*/

#include "LevelsMenu.hpp"

Game::LevelsPage::LevelsPage() : _selectedLevel(-1), _backgroundColor(LIGHTGRAY)
{
    LoadLevels();
    _backButtonArea = {10, 10, 100, 40};
}

Game::LevelsPage::~LevelsPage()
{
    for (auto& level : _levels) {
        UnloadTexture(level.image);
    }
}

void Game::LevelsPage::LoadLevels()
{
    for (size_t i = 0; i < _levelNames.size(); ++i) {
        Texture2D img = LoadTexture(std::string("asset/levels/" + std::to_string(i + 1) + ".png").c_str());
        float scale = 0.7f;

        _levels.push_back({
            _levelNames[i],
            img,
            {
                _levelAreas[i].x,
                _levelAreas[i].y,
                img.width * scale,
                img.height * scale
            },
            {scale, scale}
        });
    }
}

void Game::LevelsPage::display()
{
    ClearBackground(_backgroundColor);

    DrawRectangleRec(_backButtonArea, DARKGRAY);
    DrawText("Retour", _backButtonArea.x + 10, _backButtonArea.y + 10, 20, WHITE);

    for (Level &level : _levels) {
        level.Draw();
    }
}

void Game::LevelsPage::exec(std::size_t &currentScene, ...)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(mousePos, _backButtonArea)) {
            currentScene = MAIN_MENU;
        }

        for (size_t i = 0; i < _levels.size(); ++i) {
            if (CheckCollisionPointRec(mousePos, _levels[i].area)) {
                _selectedLevel = i;
                currentScene = GAME_SCENE_ONE + i;
            }
        }
    }
}

int Game::LevelsPage::GetSelectedLevel() const
{
    return _selectedLevel;
}

bool Game::LevelsPage::BackButtonPressed() const
{
    Vector2 mousePos = GetMousePosition();
    return CheckCollisionPointRec(mousePos, _backButtonArea) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void Game::Level::SetTextureScale(float x, float y)
{
    scale = {x, y};
}

void Game::Level::Draw() const
{
    DrawTextureEx(image, {area.x, area.y}, 0.0f, scale.x, WHITE);
    DrawText(name.c_str(), area.x + 10, area.y + area.height + 10, 20, BLACK);
}
