/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** IPopUp
*/

#pragma once

namespace Game {
    namespace PopUp {
        class IPopUp {
            public:
                IPopUp() {};
                virtual ~IPopUp() = default;

                enum PopUpAction {
                    CLOSE,
                    MULTIPLY_GAIN,
                    QUIT_GAME,
                    NOTHING,
                };

                virtual PopUpAction exec(void) = 0;
                virtual void draw(void) = 0;
                virtual void toggleHidden(void) = 0;
                virtual bool isHidden(void) const = 0;
        };
    }
}
