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
            void exec(std::size_t &currentScene, ...);

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
                {70, 80, 200, 100}, {70, 355, 200, 100}, {70, 630, 200, 100},
                {560, 80, 200, 100}, {560, 355, 200, 100}, {560, 630, 200, 100},
                {1050, 80, 200, 100}, {1050, 355, 200, 100}, {1050, 630, 200, 100}
            };
    };
}
#endif // LEVELS_HPP
