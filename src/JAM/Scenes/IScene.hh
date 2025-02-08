/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** IScene
*/

#pragma once

#include <cstddef>
namespace Game {
    class IScene {
        public:
            IScene() = default;
            virtual ~IScene() = default;

            virtual void exec(std::size_t &currentScene) = 0;
            virtual void display(void) = 0;
    };
}
