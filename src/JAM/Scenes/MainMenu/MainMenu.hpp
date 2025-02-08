/*
** EPITECH PROJECT, 2025
** JAM
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
    #define MAINMENU_HPP_

    #include "JAM/JAM.hpp"
    #include "../Buttons/Buttons.hh"

namespace Game {
    class MainMenu : public Game::IScene {
        public:
            MainMenu();
            ~MainMenu();
            void display();
            void exec(std::size_t &currentScene);

        protected:
        private:
            Font _font;
            Texture2D _background;
            Buttons _start;
            Buttons _settings;
            Buttons _quit;
    };
}

#endif /* !MAINMENU_HPP_ */
