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
            void exec(std::size_t &currentScene, int &playingMusic, ...);

        protected:
        private:
            int _hp;
            int _gold;
            std::unique_ptr<Player> _player;
            Texture2D _frame;
            Texture2D _heart;
            Texture2D _coin;
            Texture2D _board;
    };
}
#endif /* !GAMESCENE_HPP_ */
