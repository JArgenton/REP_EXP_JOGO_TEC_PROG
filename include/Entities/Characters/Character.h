#include "MovingEntity.h"

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
                void moveOnCOlision(const Math::CoordF intersection, Entity* other);


        };  // class Character
    }
}