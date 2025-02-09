/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** PopupManager
*/

#ifndef POPUPMANAGER_HPP
    #define POPUPMANAGER_HPP

#include "StartPopUp.hh"

namespace Game {
    class PopupManager {
    public:
        PopupManager();
        ~PopupManager();

        void handleEvent();
        void draw();

    private:
        PopUp::StartPopUp _popup;
        bool _showPopup;
    };
}

#endif // POPUPMANAGER_HPP
