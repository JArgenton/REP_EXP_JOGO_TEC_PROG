#include "Entities/MovingEntity.h"


namespace Entities{

MovingEntity::MovingEntity(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty, Math::CoordF velocity = Math::CoordF(0.f, 0.f)):
            Entity(position, size, id),
            velocity(velocity),
            active(true),
            facing_right(true)
            {
            }
            MovingEntity::~MovingEntity(){

            }
            void MovingEntity::render(){
                /*TODO*/
            }           

            const bool MovingEntity::isActive() const{
                return active;
            }
            const bool MovingEntity::isFacingRight() const{
                return facing_right;
            }
            void MovingEntity::setFacingRight(const bool right){
                facing_right = right;
            }
            void MovingEntity::setFacingRight(){
                facing_right = velocity.x <= 0 ? false : true;
            }
            void setActive(const bool active);
            void setVelocity(const Math::CoordF velocity);
            Math::CoordF getVelocity();
            void moveOnColision(const Math::CoordF intersection, Entity* other);

}
