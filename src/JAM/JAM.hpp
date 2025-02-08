/*
** EPITECH PROJECT, 2025
** JAM
** File description:
** JAM
*/

#ifndef JAM_HPP_
#define JAM_HPP_

    #include <memory>
    #include <vector>
    #include <raylib.h>
    #include <memory>

    #include "Scenes/IScene.hh"

    enum SceneType {
        MAIN_MENU,
        LEVELS_SCENE,
        LEVEL_ONE_SCENE,
        LEVEL_TWO_SCENE,
        LEVEL_THREE_SCENE,
        LEVEL_FOUR_SCENE,
        LEVEL_FIVE_SCENE,
        LEVEL_SIX_SCENE,
        LEVEL_SEVEN_SCENE,
        LEVEL_EIGHT_SCENE,
        LEVEL_NINE_SCENE,
        SETTINGS_SCENE
    };

class JAM {
    public:
        JAM();
        ~JAM();
        void gameLoop(void);
        void UpdateWindowSize();

    private:
        std::size_t _currentScene;
        std::vector<std::unique_ptr<Game::IScene>> _scenes;
};

#endif /* !JAM_HPP_ */
