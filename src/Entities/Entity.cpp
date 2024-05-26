#include "include/Entities/Entity.h"

using namespace Entities;
    
    
    Entity::Entity(Math::CoordF pos, Math::CoordF size, ID id):
    position(pos),
    size(size),
    id(id)   { }
    Entity::~Entity(){ }

    void Entity::set_position(Math::CoordF pos){
        this->position = pos;
    }
    Math::CoordF Entity::get_positon(){
        return position;
    }
    Math::CoordF Entity::get_size(){
        return size;
    }
    ID Entity::get_Id() const{
        return id;
    }
        // classes virtuais chamam a instancia mais "profunda" delas
        // o prefixo virtual nao é apresentado na implementaçao do metodo
        
    void Entity::render(){

    }