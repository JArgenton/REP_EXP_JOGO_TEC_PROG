#pragma once 
#include "Entities/MovingEntity.h"

namespace Entities{

    namespace Characters{
        
        class Character : public MovingEntity{

            private:
                int health;
            public:
                Character(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty, int health = 100);
                ~Character();

                const int getHealth() const;
                void reciveDemage(const int damage);
                virtual void collide(const Entity* other, Math::CoordF intersection);
                virtual void updateSprite() = 0;
                virtual void reciveDamage(const int damage);


        };  // class Character
    }
}