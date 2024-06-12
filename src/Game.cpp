#include "Game.h"
#include "Managers/Graphics.h"
#include "Entities/Characters/Player.h"

using namespace Managers;
using namespace Entities::Characters;
Game::Game():
GraphicManager(Graphics::get_instance())
{
    exec();
}

Game::~Game(){
}

void Game::exec(){
    while(GraphicManager->isWindowOpen()){
        GraphicManager->updateDeltaTime();
        GraphicManager->clear();

        /*TODO*/
        /*update all and render all*/

        GraphicManager->display();
    }
}