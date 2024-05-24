#pragma once 
#include "Math/Coord.hpp"


namespace Entities{

class Entity
{
private:
    Math::CoordF position;
    Math::CoordF size;
public:
    Entity(/* args */);
    ~Entity();
};
}