/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** PopUpFactory
*/

#pragma once

#include <memory>
#include "IPopUp.hh"

namespace Game {
    namespace PopUp {
        class PopUpFactory {
            public:
                PopUpFactory();
                ~PopUpFactory();

                static std::shared_ptr<IPopUp> createStartPopUp();
                static std::shared_ptr<IPopUp> createTextPopUp(std::string title, std::string text);
        };
    }
}
