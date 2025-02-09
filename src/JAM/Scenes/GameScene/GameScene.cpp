/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** GameScene
*/

#include "GameScene.hpp"
#include "JAM/PopUp/PopUpFactory.hh"

Game::GameScene::GameScene():
    REF_WIDTH(1920.0f), REF_HEIGHT(1080.0f),
    _T1("", "asset/gameUI/tower.png", ((float)GetScreenWidth() * 0.1f), ((float)GetScreenHeight() * 0.8f), 5),
    _T2("", "asset/gameUI/tower.png", ((float)GetScreenWidth() * 0.3f), ((float)GetScreenHeight() * 0.8f), 5),
    _T3("", "asset/gameUI/tower.png", ((float)GetScreenWidth() * 0.5f), ((float)GetScreenHeight() * 0.8f), 5),
    _T4("", "asset/gameUI/tower.png", ((float)GetScreenWidth() * 0.7f), ((float)GetScreenHeight() * 0.8f), 5),
    _T5("", "asset/gameUI/tower.png", ((float)GetScreenWidth() * 0.9f), ((float)GetScreenHeight() * 0.8f), 5),
    _P1("", "asset/gameUI/plus.png", ((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.2f), 5),
    _P2("", "asset/gameUI/plus.png", ((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.4f), 5),
    _P3("", "asset/gameUI/plus.png", ((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.6f), 5),
    _popUp(Game::PopUp::PopUpFactory::createStartPopUp())

{
    Image frameImg = LoadImage("asset/gameUI/cadre.png");
    _frame = LoadTextureFromImage(frameImg);
    Image heartImg = LoadImage("asset/gameUI/heart.png");
    _heart = LoadTextureFromImage(heartImg);
    Image coinImg = LoadImage("asset/gameUI/coin.png");
    _coin = LoadTextureFromImage(coinImg);
    Image baordImg = LoadImage("asset/gameUI/test.png");
    _board = LoadTextureFromImage(baordImg);

    _T1.SetPosition(((float)GetScreenWidth() * 0.1f), ((float)GetScreenHeight() * 0.8f), 0);
    _T2.SetPosition(((float)GetScreenWidth() * 0.3f), ((float)GetScreenHeight() * 0.8f), 0);
    _T3.SetPosition(((float)GetScreenWidth() * 0.5f), ((float)GetScreenHeight() * 0.8f), 0);
    _T4.SetPosition(((float)GetScreenWidth() * 0.7f), ((float)GetScreenHeight() * 0.8f), 0);
    _T5.SetPosition(((float)GetScreenWidth() * 0.9f), ((float)GetScreenHeight() * 0.8f), 0);
    _P1.SetPosition(((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.2f), 0);
    _P2.SetPosition(((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.4f), 0);
    _P3.SetPosition(((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.6f), 0);
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
    if (IsWindowResized()) {
        _T1.SetPosition(((float)GetScreenWidth() * 0.1f), ((float)GetScreenHeight() * 0.8f), 0);
        _T2.SetPosition(((float)GetScreenWidth() * 0.3f), ((float)GetScreenHeight() * 0.8f), 0);
        _T3.SetPosition(((float)GetScreenWidth() * 0.5f), ((float)GetScreenHeight() * 0.8f), 0);
        _T4.SetPosition(((float)GetScreenWidth() * 0.7f), ((float)GetScreenHeight() * 0.8f), 0);
        _T5.SetPosition(((float)GetScreenWidth() * 0.9f), ((float)GetScreenHeight() * 0.8f), 0);
        _P1.SetPosition(((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.2f), 0);
        _P2.SetPosition(((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.4f), 0);
        _P3.SetPosition(((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.6f), 0);
    }
    if (!_popUp->isHidden()) {
        Game::PopUp::IPopUp::PopUpAction output = _popUp->exec();

        if (output == Game::PopUp::IPopUp::CLOSE) {
            _popUp->toggleHidden();
        }
        return;
    }
    _T1.Event();
    _T2.Event();
    _T3.Event();
    _T4.Event();
    _T5.Event();
    if (_T1.isPressed()) {
        //action pour tour 1
    }
    if (_T2.isPressed()) {
        //action pour tour 2
    }
    if (_T3.isPressed()) {
        //action pour tour 3
    }
    if (_T4.isPressed()) {
        //action pour tour 4
    }
    if (_T5.isPressed()) {
        //action pour tour 5
    }
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
    std::string hpText = std::to_string(_hp);
    DrawText(hpText.c_str(), 140 - (MeasureText(hpText.c_str(), 20) / 2), 65, 20, WHITE);
    DrawTexturePro(_frame,
        {0, 0, (float)_frame.width, (float)_frame.height},
        {200, 0, 150, 150},
        {0, 0}, 0.0f, WHITE);
    DrawTexturePro(_coin,
        {0, 0, (float)_coin.width, (float)_coin.height},
        {220, 50, 50, 50},
        {0, 0}, 0.0f, WHITE);
    std::string goldText = std::to_string(_gold);
    DrawText(goldText.c_str(), 290 - (MeasureText(goldText.c_str(), 20) / 2), 65, 20, WHITE);
    DrawText("Range", ((float)GetScreenWidth() * 0.92f) - (MeasureText("Range", 20) / 2), ((float)GetScreenHeight() * 0.23f), 20, WHITE);
    DrawText("Attack\nspeed", ((float)GetScreenWidth() * 0.92f) - (MeasureText("Attack\nspeed", 20) / 2), ((float)GetScreenHeight() * 0.42f), 20, WHITE);
    DrawText("Damage", ((float)GetScreenWidth() * 0.92f) - (MeasureText("Damage", 20) / 2), ((float)GetScreenHeight() * 0.63f), 20, WHITE);
    _T1.Display();
    _T2.Display();
    _T3.Display();
    _T4.Display();
    _T5.Display();
    if (!_popUp->isHidden()) {
        _popUp->draw();
    }
    _P1.Display();
    _P2.Display();
    _P3.Display();
}
