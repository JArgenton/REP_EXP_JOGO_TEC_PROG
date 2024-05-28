#pragma once
#include "Entities/Characters/Player.h"
#include "Managers/Graphics.h"


class Game {
private:
    Managers::Graphics* GraphicManager;
    Entities::Characters::Player Player1;
 
public:
    Game();
    ~Game();
    void exec();
};
