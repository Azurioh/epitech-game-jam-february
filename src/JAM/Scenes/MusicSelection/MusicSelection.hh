/*
** EPITECH PROJECT, 2025
** musicSelection
** File description:
** MusicSelection
*/

#pragma once

#include "JAM/JAM.hpp"
#include "../Buttons/Buttons.hh"

namespace Game{
    class MusicSelection : public Game::IScene {
        public:
            MusicSelection();
            ~MusicSelection();
            void display();
            void exec(std::size_t &currentScene, int &playingMusic, ...);

        protected:
        private:
            Texture2D _background;
            Font _font;
            Buttons _returnButton;
            Buttons _previousMusic;
            Buttons _nextMusic;
            Buttons _pauseMusic;
    };
};
