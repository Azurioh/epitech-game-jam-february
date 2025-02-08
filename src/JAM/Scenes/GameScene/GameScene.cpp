/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** GameScene
*/

#include "GameScene.hpp"

Game::GameScene::GameScene()
{
    Image frameImg = LoadImage("asset/gameUI/cadre.png");
    _frame = LoadTextureFromImage(frameImg);
    Image heartImg = LoadImage("asset/gameUI/heart.png");
    _heart = LoadTextureFromImage(heartImg);
    Image coinImg = LoadImage("asset/gameUI/coin.png");
    _coin = LoadTextureFromImage(coinImg);
    Image baordImg = LoadImage("asset/gameUI/test.png");
    _board = LoadTextureFromImage(baordImg);

    _player = std::unique_ptr<Player>(new Player());
    _hp = _player->getHP();
    _gold = _player->getGolds();
}

Game::GameScene::~GameScene()
{
    UnloadTexture(_frame);
    UnloadTexture(_board);
    UnloadTexture(_heart);
    UnloadTexture(_coin);
}

void Game::GameScene::exec(std::size_t &currentScene, ...)
{
    return;
}

void Game::GameScene::display()
{
    Rectangle sourceRec = {0, 0, (float)_board.width, (float)_board.height};

    DrawTexturePro(_board, sourceRec, {(float)GetScreenWidth() - 200, 0, 200, (float)GetScreenHeight()}, {0, 0}, 0.0f, WHITE);
    DrawTexturePro(_board, sourceRec, {-15, (float)GetScreenHeight() - 200, (float)GetScreenWidth(), 200}, {0, 0}, 0.0f, WHITE);
    DrawTexturePro(_frame,
        {0, 0, (float)_frame.width, (float)_frame.height},
        {50, 0, 150, 150},
        {0, 0}, 0.0f, WHITE);
    DrawTexturePro(_heart,
        {0, 0, (float)_heart.width, (float)_heart.height},
        {70, 55, 50, 50},
        {0, 0}, 0.0f, WHITE);
    DrawText("test", 140 - ((MeasureText("test", 20) / 2)), 65, 20, WHITE);
    DrawTexturePro(_frame,
        {0, 0, (float)_frame.width, (float)_frame.height},
        {200, 0, 150, 150},
        {0, 0}, 0.0f, WHITE);
    DrawTexturePro(_coin,
        {0, 0, (float)_coin.width, (float)_coin.height},
        {220, 50, 50, 50},
        {0, 0}, 0.0f, WHITE);
    DrawText("test", 290 - ((MeasureText("test", 20) / 2)), 65, 20, WHITE);
}
