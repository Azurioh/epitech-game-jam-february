/*
** EPITECH PROJECT, 2025
** JAM
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
    #define MAINMENU_HPP_

    #include "JAM/JAM.hpp"

namespace Game {
    class MainMenu : public Game::IScene {
        public:
            MainMenu();
            ~MainMenu();
            void display();
            void exec();

        protected:
        private:
            Texture2D _background;
    };
}

#endif /* !MAINMENU_HPP_ */
