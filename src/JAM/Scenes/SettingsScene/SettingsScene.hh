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

namespace Game{
    class SettingsScene : public Game::IScene {
        public:
            SettingsScene();
            ~SettingsScene();
            void exec(std::size_t &currentScene);
            void display();

        protected:
        private:
            Buttons _returnButton;
            Texture2D _background;
    };
};
