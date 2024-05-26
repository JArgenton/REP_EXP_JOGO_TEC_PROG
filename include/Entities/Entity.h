#pragma once 
#include "Math/Coord.hpp"


namespace Entities{
    enum ID{ // muito foda
        empty = 0,
        player ,
        plataform
    };

class Entity
{
private:
    Math::CoordF position;
    Math::CoordF size;
    ID id;
public:
    Entity(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty);
    ~Entity();
    void set_position(Math::CoordF pos);
    Math::CoordF get_positon();
    Math::CoordF get_size();
    ID get_Id() const;

    // classes virtuais chamam a instancia mais "profunda" delas
    virtual void render();
    /* as classes virtuais igualadas a 0 sao chamadas de virtuais puros, e fazem com que a classe seja abstrata, ou seja, a classe entity nao pode ser 
    criada sozinha, mas apenas por seus filhos que OBRIGATORIAMENTE necessitam ter metodos com os mesmos nomes (nao virtuais)
    */
    virtual void update(float dt) = 0;
    virtual void initialize() = 0;

};
}