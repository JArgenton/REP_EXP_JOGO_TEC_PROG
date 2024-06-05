#pragma once 
#include "../include/Math/Coord.h"


namespace Entities{
    enum ID{ // muito foda
        empty = 0,
        player ,
        plataform
    };

    class Entity{
        protected:
            Math::CoordF position;
            Math::CoordF size;
            ID id;
        public:


            Entity(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty);
            virtual ~Entity();
            void set_position(Math::CoordF pos);
            Math::CoordF get_positon();
            Math::CoordF get_size();
            ID get_Id() const;
            virtual void render();


            virtual void update(float dt) = 0;
            virtual void initialize() = 0;

            virtual void collide(Entity* other, Math::CoordF intersection) = 0;

        };
}