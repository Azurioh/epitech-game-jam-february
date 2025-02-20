/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

    #include "JAM/JAM.hpp"
    #include "../Buttons/Buttons.hh"
    #include "../../Level/Map.hpp"
    #include "JAM/Player/Player.hh"
    #include "JAM/PopUp/IPopUp.hh"
    #include <cmath>

namespace Game {
    class GameScene : public Game::IScene {
        public:
            GameScene(int levelNumber);
            ~GameScene();

            enum TowerType {
                BASIC_TOWER,
                CLOSE_RANGE,
                DAMAGE_TOWER,
                LONG_RANGE_TOWER,
                FAKE_TOWER,
            };

            void display();
            void exec(std::size_t &currentScene, int &playingMusic, ...);


            void createMobs();
            void createIllusionMobs();
            void runWave();
            bool isWaveOver();
            void reloadWave();

        protected:
        private:
            int _hp;
            int _gold;
            const float REF_WIDTH;
            const float REF_HEIGHT;
            std::unique_ptr<Player> _player;
            Texture2D _frame;
            Buttons _T1;
            Buttons _T2;
            Buttons _T3;
            Buttons _T4;
            Buttons _T5;
            Buttons _P1;
            Buttons _P2;
            Buttons _P3;
            Texture2D _heart;
            Texture2D _coin;
            Texture2D _board;
            float _T1PercentX;
            float _T1PercentY;
            bool _haveSelectedTower;
            Texture2D _selectedTower;
            TowerType _selectedType;
            std::shared_ptr<Game::Tower::ITower> _towerSelected;

            std::shared_ptr<Map> _map;
            std::vector<std::shared_ptr<Game::Mob::IMob>> _mobs;
            std::vector<std::shared_ptr<Game::Mob::IMob>> _illusionMobs;

            double _time;
            size_t _maxDisplay;
            size_t _numberOfMobs;
            size_t _wave;

            size_t _random;

            int _levelNumber;
            std::shared_ptr<Game::PopUp::IPopUp> _popUp;
            std::shared_ptr<Game::PopUp::IPopUp> _defeatPopUp;
            std::shared_ptr<Game::PopUp::IPopUp> _victoryPopUp;

            bool _isCaseClicked(Case *caseElement);
            std::shared_ptr<Game::Tower::ITower> _createTower();
            void _hideAllHitbox();
    };
}
#endif /* !GAMESCENE_HPP_ */
