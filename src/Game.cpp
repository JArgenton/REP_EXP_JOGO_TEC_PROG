#include "Game.h"

using namespace Managers;
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