/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** levels.hpp
*/

#ifndef LEVELSCENE_HPP
    #define LEVELSCENE_HPP

#include "../IScene.hh"
#include "raylib.h"
#include "unistd.h"
#include "../../Level/Map.hpp"

namespace Game {
    namespace Mob {
        class IMob;
    }
}

namespace Game {
    class LevelScene : public IScene {
        public:
            LevelScene(int levelNumber);
            ~LevelScene() = default;

            void display() override;
            void exec(std::size_t &currentScene, ...) override;

            void createMobs();
            void runWave();
            bool isWaveOver();
            void reloadWave();

        private:
            int _levelNumber;
            Color _backgroundColor;
            Rectangle _backButtonArea;

            std::shared_ptr<Map> _map;
            std::vector<std::shared_ptr<Game::Mob::IMob>> _mobs;

            double _time;
            size_t _maxDisplay;
            size_t _numberOfMobs;
            size_t _wave;
    };
}

#endif // LEVELSCENE_HPP
