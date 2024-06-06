#include "include/Entities/Characters/Character.h"
namespace Entities{
    namespace Characters{
        Character::Character(Math::CoordF position, Math::CoordF size, ID id, int health):
        MovingEntity(position, size, id),
        health(health)
        {
        }

        Character::~Character(){
        }

        const int Character::getHealth() const{
            return health;
        }

        void Character::reciveDemage(const int damage){
            health -= damage;
        }
    }   // namespace Characters
}   // namespace Entities