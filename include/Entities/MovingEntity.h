#ifndef _MOVINGENTITY_H_
#define _MOVINGENTITY_H_
#include "Entity.h"


namespace Entities{

    class MovingEntity : public Entity
    {
        protected:
            /*TODO*/
             //Animation
            Math::CoordF velocity;
            bool active;
            bool facing_right;

        public:
            MovingEntity(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty, Math::CoordF velocity = Math::CoordF(0.f, 0.f));
            virtual ~MovingEntity();
            virtual void render();
            virtual void update(const float dt) = 0;
            virtual void collide(Entity* other, Math::CoordF intersection) = 0;
            virtual void updateSprite(const float dt) = 0;
            const bool isActive() const;
            const bool isFacingRight() const;
            void setFacingRight(const bool right);
            void setFacingRight();
            void setActive(const bool active);
            void setVelocity(const Math::CoordF velocity);
            Math::CoordF getVelocity();
            void moveOnColision(const Math::CoordF intersection, Entity* other);

    };
}
#endif