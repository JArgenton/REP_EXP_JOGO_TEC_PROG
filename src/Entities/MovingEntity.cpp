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
                facing_right = velocity.x <= 0.0f ? false : true;
            }
            void MovingEntity::setActive(const bool active){
                this->active = active;
            }
            void MovingEntity::setVelocity(const Math::CoordF velocity){
                this->velocity = velocity;
            }
            Math::CoordF getVelocity();
            void MovingEntity::moveOnColision(const Math::CoordF intersection, Entity* other){
                Math::CoordF otherPos = other->get_position();

                if(intersection.x > intersection.y){ // colision on x
                    if(position.x > intersection.y){
                        position.x += intersection.x;
                    }
                    else{
                        position.x -= intersection.x;
                    }
                    velocity.x *= 0.0f;
             }
                else{ //colision on y
                    if(position.y > otherPos.y){
                        position.y += intersection.y;
                    }
                    else{
                        position.y -= intersection.y;
                    }
                    velocity.y *= 0.0f;
                }
            }

}
