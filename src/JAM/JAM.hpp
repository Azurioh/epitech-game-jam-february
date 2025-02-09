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
        GAME_SCENE_ONE,
        GAME_SCENE_TWO,
        GAME_SCENE_THREE,
        GAME_SCENE_FOUR,
        GAME_SCENE_FIVE,
        GAME_SCENE_SIX,
        GAME_SCENE_SEVEN,
        GAME_SCENE_EIGHT,
        GAME_SCENE_NINE,
        SETTINGS_SCENE,
    };

class JAM {
    public:
        JAM();
        ~JAM();
        void gameLoop(void);
        void setVolumeDown();
        void setVolumeUp();
        void setVolume();
        void UpdateWindowSize();

    private:
        std::size_t _currentScene;
        std::vector<std::unique_ptr<Game::IScene>> _scenes;
        Music _menuMusic;
        Music _inGameMusic;
        float _MusicValue;
};

#endif /* !JAM_HPP_ */
