/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** IScene
*/

#pragma once

namespace Game {
    class IScene {
        public:
            IScene() = default;
            virtual ~IScene() = default;

            virtual void exec(void) = 0;
            virtual void display(void) = 0;
    };
}
