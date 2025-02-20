/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** levels.hpp
*/

#ifndef LEVELS_HPP
    #define LEVELS_HPP

    #include <raylib.h>
    #include <vector>
    #include <string>

    #include "../IScene.hh"
    #include "JAM/JAM.hpp"

namespace Game {
    struct Level {
        std::string name;
        Texture2D image;
        Rectangle area;
        Vector2 scale;

        void SetTextureScale(float x, float y);
        void Draw() const;
    };

    class LevelsPage : public Game::IScene {
        public:
            LevelsPage();
            ~LevelsPage();
            void LoadLevels();
            void display();
            void exec(std::size_t &currentScene, int &playingMusic, ...);

            int GetSelectedLevel() const;

            bool BackButtonPressed() const;

        private:
            std::vector<Level> _levels;
            int _selectedLevel;
            Color _backgroundColor;
            Rectangle _backButtonArea;

            std::vector<std::string> _levelNames = {
                "Level 1", "Level 2", "Level 3", "Level 4", "Level 5",
                "Level 6", "Level 7", "Level 8", "Level 9"
            };

            std::vector<Rectangle> _levelAreas = {
                {10, 80, 200, 100}, {10, 355, 200, 100}, {10, 630, 200, 100},
                {510, 80, 200, 100}, {510, 355, 200, 100}, {510, 630, 200, 100},
                {1010, 80, 200, 100}, {1010, 355, 200, 100}, {1010, 630, 200, 100}
            };
    };
}
#endif // LEVELS_HPP
