/*
** EPITECH PROJECT, 2025
** SettingsScene
** File description:
** SettingsScene
*/

#pragma once

#include <raylib.h>
#include "../IScene.hh"
#include "../Buttons/Buttons.hh"
#include "JAM/JAM.hpp"

namespace Game{
    class SettingsScene : public Game::IScene {
        public:
            SettingsScene();
            ~SettingsScene();
            void exec(std::size_t &currentScene, int &playingMusic, ...);
            void display();

        protected:
        private:
            Buttons _returnButton;
            Buttons _volumeUp;
            Buttons _volumeDown;
            Texture2D _background;
            Font _font;
    };
};
