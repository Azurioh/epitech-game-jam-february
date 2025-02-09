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

namespace Game {
    class GameScene : public Game::IScene {
        public:
            GameScene(int levelNumber);
            ~GameScene();
            void display();
            void exec(std::size_t &currentScene, ...);

            void createMobs();
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

            std::shared_ptr<Map> _map;
            std::vector<std::shared_ptr<Game::Mob::IMob>> _mobs;

            double _time;
            size_t _maxDisplay;
            size_t _numberOfMobs;
            size_t _wave;

            int _levelNumber;
            std::shared_ptr<Game::PopUp::IPopUp> _popUp;
    };
}
#endif /* !GAMESCENE_HPP_ */
