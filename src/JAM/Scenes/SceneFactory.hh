/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** SceneFactory
*/

#pragma once

#include <memory>

namespace Game {
    class SceneFactory {
        public:
            SceneFactory();
            ~SceneFactory();

            static std::unique_ptr<void> testFunction();
    };
}
