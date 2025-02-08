/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** IMob
*/

#ifndef IMOB_HH_
#define IMOB_HH_


namespace Game {
    namespace Mob {
        class IMob {
            public:
                IMob() {};
                ~IMob() {};
                virtual int move_mob() = 0;

            protected:
            private:
        };
    }
}

#endif /* !IMOB_HH_ */
