#include "Entity.h"

namespace Entities{
    class StaticEntity : public Entity
    {
        protected:
        /*TODO*/
        //Animation
        public:
            StaticEntity(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty);
            virtual ~StaticEntity();
            virtual void render();
            virtual void update(const float dt);
            virtual void initialize();
            virtual void colide(Entity* other, Math::CoordF intersection);
    };
}