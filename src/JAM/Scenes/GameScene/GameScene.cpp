/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** GameScene
*/

#include "GameScene.hpp"
#include "../../Mob/MobFactory.hh"
#include "JAM/PopUp/PopUpFactory.hh"
#include "JAM/Tower/TowerFactory.hh"

Game::GameScene::GameScene(int levelNumber):
    REF_WIDTH(1920.0f), REF_HEIGHT(1080.0f),
    _T1("", "asset/gameUI/tower.png", ((float)GetScreenWidth() * 0.1f), ((float)GetScreenHeight() * 0.8f), 5),
    _T2("", "asset/gameUI/tower.png", ((float)GetScreenWidth() * 0.3f), ((float)GetScreenHeight() * 0.8f), 5),
    _T3("", "asset/gameUI/tower.png", ((float)GetScreenWidth() * 0.5f), ((float)GetScreenHeight() * 0.8f), 5),
    _T4("", "asset/gameUI/tower.png", ((float)GetScreenWidth() * 0.7f), ((float)GetScreenHeight() * 0.8f), 5),
    _T5("", "asset/gameUI/tower.png", ((float)GetScreenWidth() * 0.9f), ((float)GetScreenHeight() * 0.8f), 5),
    _levelNumber(levelNumber),
    _P1("", "asset/gameUI/plus.png", ((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.2f), 5),
    _P2("", "asset/gameUI/plus.png", ((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.4f), 5),
    _P3("", "asset/gameUI/plus.png", ((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.6f), 5),
    _haveSelectedTower(false),
    _popUp(Game::PopUp::PopUpFactory::createStartPopUp())

{
    Image frameImg = LoadImage("asset/gameUI/Cadre.png");
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

    if (levelNumber > 0) {
        _map = std::shared_ptr<Map>(new Map("maps/map_" + std::to_string(levelNumber) + ".txt"));
        createMobs();

        _time = GetTime();
        _maxDisplay = 1;
        _wave = 1;
        _numberOfMobs = 8;
    }
}

Game::GameScene::~GameScene()
{
    UnloadTexture(_frame);
    UnloadTexture(_board);
    UnloadTexture(_heart);
    UnloadTexture(_coin);
}

void Game::GameScene::exec(std::size_t &currentScene, int &playingMuysic, ...)
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
    _P1.Event();
    _P2.Event();
    _P3.Event();
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && _haveSelectedTower) {
        for (int i = 0; i < _map->getMap().size(); i++) {
            for (int j = 0; j < _map->getMap()[i].size(); j++) {
                Case *tmp = (_map->getMap()[i][j]).get();

                if (_isCaseClicked(tmp)) {
                    if (!tmp->getTower()) {
                        (_map->getMap()[i][j])->setTower(_createTower());
                    }
                    _haveSelectedTower = false;
                    return;
                }
            }
        }
        _haveSelectedTower = false;
    }
    if (_T1.isPressed()) {
        _haveSelectedTower = true;
        _selectedTower = _T1.getTexture();
        _selectedType = BASIC_TOWER;
    }
    if (_T2.isPressed()) {
        _haveSelectedTower = true;
        _selectedTower = _T2.getTexture();
        _selectedType = BIG_TOWER;
    }
    if (_T3.isPressed()) {
        _haveSelectedTower = true;
        _selectedTower = _T3.getTexture();
        _selectedType = BASIC_TOWER;
    }
    if (_T4.isPressed()) {
        _haveSelectedTower = true;
        _selectedTower = _T4.getTexture();
        _selectedType = BASIC_TOWER;
    }
    if (_T5.isPressed()) {
        _haveSelectedTower = true;
        _selectedTower = _T5.getTexture();
        _selectedType = BASIC_TOWER;
    }
    if (_P1.isPressed()) {
    }
    if (_P2.isPressed()) {
    }
    if (_P3.isPressed()) {
    }
}

void Game::GameScene::display()
{
    Rectangle sourceRec = {0, 0, (float)_board.width, (float)_board.height};


    DrawTexturePro(_board, sourceRec, {(float)GetScreenWidth() - 200, 0, 200, (float)GetScreenHeight()}, {0, 0}, 0.0f, WHITE);
    DrawTexturePro(_board, sourceRec, {-15, (float)GetScreenHeight() - 200, (float)GetScreenWidth(), 200}, {0, 0}, 0.0f, WHITE);
    std::string hpText = std::to_string(_hp);
    _T1.Display();
    _T2.Display();
    _T3.Display();
    _T4.Display();
    _T5.Display();

    if (_levelNumber > 0) {
        _map->drawMap();
        runWave();
    }
    DrawTexturePro(_frame,
        {0, 0, (float)_frame.width, (float)_frame.height},
        {50, 0, 150, 150},
        {0, 0}, 0.0f, WHITE);
    DrawTexturePro(_heart,
        {0, 0, (float)_heart.width, (float)_heart.height},
        {70, 55, 50, 50},
        {0, 0}, 0.0f, WHITE);
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
    if (_haveSelectedTower) {
        DrawTexture(_selectedTower, GetMousePosition().x, GetMousePosition().y, WHITE);
    }
    _P1.Display();
    _P2.Display();
    _P3.Display();
}


void Game::GameScene::createMobs()
{
    size_t index = 0;

    _mobs.resize(80);
    for (; index < (8 * 1); index++) {
        _mobs[index] = Game::Mob::MobFactory::createRedMob();
    }
    for (; index < (8 * 2); index++) {
        _mobs[index] = Game::Mob::MobFactory::createBlueMob();
    }
    for (; index < (8 * 3); index++) {
        _mobs[index] = Game::Mob::MobFactory::createGreenMob();
    }
    for (; index < (8 * 4); index++) {
        _mobs[index] = Game::Mob::MobFactory::createYellowMob();
    }
    for (; index < (8 * 5); index++) {
        _mobs[index] = Game::Mob::MobFactory::createPinkMob();
    }
    for (; index < (8 * 6); index++) {
        _mobs[index] = Game::Mob::MobFactory::createWhiteMob();
    }
    for (; index < (8 * 7); index++) {
        _mobs[index] = Game::Mob::MobFactory::createBlackMob();
    }
    for (; index < (8 * 8); index++) {
        _mobs[index] = Game::Mob::MobFactory::createRainbowMob();
    }
    for (; index < (8 * 9); index++) {
        _mobs[index] = Game::Mob::MobFactory::createMoabBlueMob();
    }
    for (; index < (8 * 10); index++) {
        _mobs[index] = Game::Mob::MobFactory::createMoabRedMob();
    }
}

void Game::GameScene::runWave()
{
    std::shared_ptr<Game::Tower::ITower> tower;

    tower = _map->getMap()[5][23]->getTower();
    tower->getMobToAttack(_mobs);
    for (size_t i = 0; i < _numberOfMobs && i < _maxDisplay; i++) {
        _mobs[i]->moveMob(*_map);
    }
    if (_time + 0.4 < GetTime()) {
        _maxDisplay++;
        _time = GetTime();
    }
    if (isWaveOver() && _wave != 20) {
        reloadWave();
    }
}

bool Game::GameScene::isWaveOver()
{
    for (size_t i = 0; i < _numberOfMobs; i++) {
        if (_mobs[i]->isVisible()) {
            return false;
        }
    }
    return true;
}

void Game::GameScene::reloadWave()
{
    for (size_t i = 0; i < _numberOfMobs; i++) {
        _mobs[i]->load();
    }
    _maxDisplay = 0;
    if (_wave % 2 == 0) {
        _numberOfMobs += 8;
    }
    _wave += 1;
}


bool Game::GameScene::_isCaseClicked(Case *caseElement) {
    float scaleHeight = ((float)GetScreenHeight() / 1080) * 0.23;
    float scaleWidth = ((float)GetScreenWidth() / 1920) * 0.23;
    Texture2D caseTexture = caseElement->getTexture();
    Vector2 casePosition = caseElement->getPosition();
    Vector2 mousePosition = GetMousePosition();

    if ((mousePosition.x < casePosition.x || mousePosition.x > casePosition.x + caseTexture.width * scaleWidth)
        || (mousePosition.y < casePosition.y || mousePosition.y > casePosition.y + caseTexture.height * scaleHeight)) {
        return false;
    }
    return true;
}

std::shared_ptr<Game::Tower::ITower> Game::GameScene::_createTower()
{
    std::tuple<std::size_t, std::size_t> pos(static_cast<std::size_t>(GetMousePosition().x), static_cast<std::size_t>(GetMousePosition().y));

    switch (_selectedType) {
        case BASIC_TOWER:
            return Game::Tower::TowerFactory::createBasicTower(pos);
        case BIG_TOWER:
            return Game::Tower::TowerFactory::createFakeTower(pos);
        default:
            return nullptr;
    }
}
