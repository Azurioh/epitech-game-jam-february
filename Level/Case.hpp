/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** Case
*/

#ifndef CASE_HPP_
#define CASE_HPP_

    #include <iostream>

class Case {
    public:
        enum CaseType {
            PATH,
            TOWER_ZONE
        };

        Case(CaseType type = PATH, int value = 0);
        ~Case();

        unsigned char getValue();
        void setValue(unsigned char value);

    protected:
    private:
        CaseType _type;
        unsigned char _value;
};

#endif /* !CASE_HPP_ */
