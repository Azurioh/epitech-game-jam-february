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
    _T1("", "asset/towers/basic.png", ((float)GetScreenWidth() * 0.1f), ((float)GetScreenHeight() * 0.8f), 5),
    _T2("", "asset/towers/close.png", ((float)GetScreenWidth() * 0.3f), ((float)GetScreenHeight() * 0.8f), 5),
    _T3("", "asset/towers/damage.png", ((float)GetScreenWidth() * 0.5f), ((float)GetScreenHeight() * 0.8f), 5),
    _T4("", "asset/towers/long.png", ((float)GetScreenWidth() * 0.7f), ((float)GetScreenHeight() * 0.8f), 5),
    _T5("", "asset/towers/fake.png", ((float)GetScreenWidth() * 0.9f), ((float)GetScreenHeight() * 0.8f), 5),
    _levelNumber(levelNumber),
    _P1("", "asset/gameUI/plus.png", ((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.2f), 5),
    _P2("", "asset/gameUI/plus.png", ((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.4f), 5),
    _P3("", "asset/gameUI/plus.png", ((float)GetScreenWidth() * 0.97f), ((float)GetScreenHeight() * 0.6f), 5),
    _haveSelectedTower(false),
    _popUp(Game::PopUp::PopUpFactory::createStartPopUp()),
    _defeatPopUp(Game::PopUp::PopUpFactory::createTextPopUp("Défaite", "Vous avez perdu")),
    _victoryPopUp(Game::PopUp::PopUpFactory::createTextPopUp("Victoire", "Vous avez gagné"))
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
    _levelNumber = levelNumber;

    if (levelNumber > 0) {
        _map = std::shared_ptr<Map>(new Map("maps/map_" + std::to_string(levelNumber) + ".txt"));
        createMobs();
        createIllusionMobs();

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

void Game::GameScene::exec(std::size_t &currentScene, int &playingMusic, ...)
{
    (void)playingMusic;
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
    if (_gold >= 100) {
        _T1.Event();
    }
    if (_gold >= 130) {
        _T2.Event();
    }
    if (_gold >= 140) {
        _T3.Event();
    }
    if (_gold >= 150) {
        _T4.Event();
    }
    if (_gold >= 800) {
        _T5.Event();
    }
    if (_towerSelected && _towerSelected.get()) {
        if (_towerSelected->getNextRangeSkillPricing() <= _gold && _towerSelected->getNextRangeSkillPricing() != -1) {
            _P1.Event();
        }
        if (_towerSelected->getNextDamageSkillPricing() <= _gold && _towerSelected->getNextDamageSkillPricing() != -1) {
            _P2.Event();
        }
        if (_towerSelected->getNextAttackSpeedSkillPricing() <= _gold && _towerSelected->getNextAttackSpeedSkillPricing() != -1) {
            _P3.Event();
        }
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        _hideAllHitbox();
        for (size_t i = 0; i < _map->getMap().size(); i++) {
            for (size_t j = 0; j < _map->getMap()[i].size(); j++) {
                Case *tmp = (_map->getMap()[i][j]).get();

                if (_haveSelectedTower) {
                    if (_isCaseClicked(tmp)) {
                        if (!tmp->getTower()) {
                            (_map->getMap()[i][j])->setTower(_createTower());
                        }
                        _haveSelectedTower = false;
                        return;
                    }
                } else {
                    std::shared_ptr<Game::Tower::ITower> tower = (_map->getMap()[i][j])->getTower();
                    if (tower && _isCaseClicked(tmp)) {
                        tower->toggleHitboxDisplay();
                    }
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
        _selectedType = CLOSE_RANGE;
    }
    if (_T3.isPressed()) {
        _haveSelectedTower = true;
        _selectedTower = _T3.getTexture();
        _selectedType = DAMAGE_TOWER;
    }
    if (_T4.isPressed()) {
        _haveSelectedTower = true;
        _selectedTower = _T4.getTexture();
        _selectedType = LONG_RANGE_TOWER;
    }
    if (_T5.isPressed()) {
        _haveSelectedTower = true;
        _selectedTower = _T5.getTexture();
        _selectedType = FAKE_TOWER;
    }
    if (_P1.isPressed() && _towerSelected && _towerSelected.get()) {
        _gold -= _towerSelected->getNextRangeSkillPricing();
        _towerSelected->upgradeRangeSkill();
    }
    if (_P2.isPressed() && _towerSelected && _towerSelected.get()) {
        _gold -= _towerSelected->getNextDamageSkillPricing();
        _towerSelected->upgradeDamageSkill();
    }
    if (_P3.isPressed() && _towerSelected && _towerSelected.get()) {
        _gold -= _towerSelected->getNextAttackSpeedSkillPricing();
        _towerSelected->upgradeAttackSpeedSkill();
    }
    if (_player->getHP() <= 0) {
        currentScene = LEVELS_SCENE;
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

    _T1.Display();
    _T2.Display();
    _T3.Display();
    _T4.Display();
    _T5.Display();
    if (!_popUp->isHidden()) {
        _popUp->draw();
    } else {
        if (_levelNumber > 0) {
            _gold += _map->drawMap(_mobs);
            runWave();
        }
    }
    if (_haveSelectedTower) {
        DrawTexture(_selectedTower, GetMousePosition().x, GetMousePosition().y, WHITE);
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
    _P1.Display();
    _P2.Display();
    _P3.Display();
    if (_player->getHP() <= 0 && !_defeatPopUp->isHidden()) {
        _defeatPopUp->draw();
    }
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

void Game::GameScene::createIllusionMobs()
{
    _illusionMobs.resize(10);
    _illusionMobs[0] = Game::Mob::MobFactory::createRedMob();
    _illusionMobs[1] = Game::Mob::MobFactory::createBlueMob();
    _illusionMobs[2] = Game::Mob::MobFactory::createGreenMob();
    _illusionMobs[3] = Game::Mob::MobFactory::createYellowMob();
    _illusionMobs[4] = Game::Mob::MobFactory::createPinkMob();
    _illusionMobs[5] = Game::Mob::MobFactory::createWhiteMob();
    _illusionMobs[6] = Game::Mob::MobFactory::createBlackMob();
    _illusionMobs[7] = Game::Mob::MobFactory::createRainbowMob();
    _illusionMobs[8] = Game::Mob::MobFactory::createMoabBlueMob();
    _illusionMobs[9] = Game::Mob::MobFactory::createMoabRedMob();
    for (size_t i = 0; i < 10; i++) {
        _illusionMobs[i]->setIsIllusion(true);
    }
}

void Game::GameScene::runWave()
{
    for (size_t i = 0; i < _numberOfMobs && i < _maxDisplay; i++) {
        _mobs[i]->moveMob(*_map);
    }
    if (_wave > 2) {
        _illusionMobs[_random]->moveMob(*_map);
    }

    int newHp = 100 - (_map->getMobPassed() * 5);

    if (newHp < 0) {
        newHp = 0;
    }
    _hp = newHp;
    _player->setHP(newHp);
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
    _random = rand() % 10;
}


bool Game::GameScene::_isCaseClicked(Case *caseElement) {
    float scaleHeight = ((float)GetScreenHeight() / 1080) * 0.23;
    float scaleWidth = ((float)GetScreenWidth() / 1920) * 0.23;
    Texture2D caseTexture = caseElement->getTexture();
    Vector2 casePosition = caseElement->getPosition();
    Vector2 mousePosition = GetMousePosition();

    if ((mousePosition.x < casePosition.x || mousePosition.x > casePosition.x + (caseTexture.width * scaleWidth))
        || (mousePosition.y < casePosition.y|| mousePosition.y > casePosition.y + (caseTexture.height * scaleHeight))) {
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
        case CLOSE_RANGE:
            return Game::Tower::TowerFactory::createCloseRangeTower(pos);
        case DAMAGE_TOWER:
            return Game::Tower::TowerFactory::createDamageTower(pos);
        case LONG_RANGE_TOWER:
            return Game::Tower::TowerFactory::createLongRangeTower(pos);
        case FAKE_TOWER:
            return Game::Tower::TowerFactory::createFakeTower(pos);
        default:
            return nullptr;
    }
}


void Game::GameScene::_hideAllHitbox()
{
    for (size_t i = 0; i < _map->getMap().size(); i++) {
        for (size_t j = 0; j < _map->getMap()[i].size(); j++) {
            std::shared_ptr<Game::Tower::ITower> tower = (_map->getMap()[i][j])->getTower();
            if (tower && tower->isDisplayingHitbox()) {
                tower->toggleHitboxDisplay();
            }
        }
    }
}
