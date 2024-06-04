#include "include/List/EntityList.h"

namespace List{

    EntityList::EntityList(){ }

    EntityList::~EntityList(){
        list.clear();
    }
    void EntityList::add(Entity* entity){
        if(entity != nullptr)
            list.push(entity);
        else
            std::cout << "EntityList::add() - entity is nullptr" << std::endl;
    }

    Entity* EntityList::remove(Entity* entity){
        if(entity != nullptr)
            return list.pop(entity);
        else
            std::cout << "EntityList::remove() - entity is nullptr" << std::endl;
    }
    Entity* EntityList::remove(int index){
        list.pop(index);
    }
    Entity* EntityList::operator[](int index){
        return list[index];
    }
    void EntityList::deleteEntity(int index){
        Entity* temp = nullptr;
        temp = list.pop(index);
        if(temp != nullptr){
            delete temp;
        }
    }
    void EntityList::deleteEntity(Entity* entity){
        Entity* temp = nullptr;
        temp = list.pop(entity);
        if(temp != nullptr){
            delete temp;
        }
    }
    int EntityList::getsize(){
        list.getsize();
    }
    void EntityList::clear(){
        list.clear();
    }

}