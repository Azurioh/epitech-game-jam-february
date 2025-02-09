/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** TextPopUp
*/

#pragma once

#include "../IPopUp.hh"
#include "../../Scenes/Buttons/Buttons.hh"
#include <string>
#include <raylib.h>

namespace Game {
    namespace PopUp {
        class TextPopUp : public IPopUp {
            public:
                TextPopUp(std::string title, std::string text);
                ~TextPopUp();

                PopUpAction exec(void);
                void draw(void);
                void toggleHidden(void);
                bool isHidden(void) const;

            private:
                std::string _title;
                std::string _text;
                bool _hidden;
                Buttons _closeButton;
        };
    }
}
