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
    #include "../../Player/Player.hh"

namespace Game {
    class GameScene : public Game::IScene {
        public:
            GameScene();
            ~GameScene();
            void display();
            void exec(std::size_t &currentScene, ...);

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
            Texture2D _heart;
            Texture2D _coin;
            Texture2D _board;
            float _T1PercentX;
            float _T1PercentY;
    };
}
#endif /* !GAMESCENE_HPP_ */
