#pragma once
#include "Entities/Characters/Player.h"

class Game {
private:
    //todo grapic manager
    Entities::Characters::Player Player1;
 
public:
    Game(/* args */);
    ~Game();
    void executar();
};
