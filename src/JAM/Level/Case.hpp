/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Case
*/

#ifndef CASE_HPP_
#define CASE_HPP_

    #include <iostream>
    #include <raylib.h>

class Case {
    public:
        enum CaseType {
            UNKNOWN,
            PATH,
            TOWER_ZONE
        };

        Case(CaseType type = UNKNOWN, int value = 0);
        ~Case();

        unsigned char getValue();
        void setValue(unsigned char value);
        Texture2D getTexture();
        Vector2 getPosition();

        void drawCase(float scale, Vector2 pos);

    protected:
    private:
        CaseType _type;
        unsigned char _value;

        Texture2D _texture;
        Vector2 _position;
};

#endif /* !CASE_HPP_ */
