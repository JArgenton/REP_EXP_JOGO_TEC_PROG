#pragma once
#include "Character.h"
#define PLAYER_SIZE_X 100.0f
#define PLAYER_SIZE_Y 100.0f


namespace Entities{
    namespace Characters{
            class Player: public Character
            {
            private:
                bool isPlayer1;
            public:

                Player(Math::CoordF pos = Math::CoordF(0.f, 0.f), bool isPlayer1 = true);

                ~Player();

                void update(float dt);

                void initialize();

            };  

    }
}